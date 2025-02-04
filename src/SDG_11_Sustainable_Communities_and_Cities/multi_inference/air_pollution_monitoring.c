#include "sample_data.h"
// #include <stdio.h>

// TODO: Move to another header file and add link to notebook for how these params were obtained
#define INPUT_DIM  2
#define HIDDEN_DIM 32
#define OUTPUT_DIM 1

// Regression based, keep error with TFLite model below reasonable value (2)
#define EPSILON 2

#define INPUT_LAYER_ZERO_POINT -128
const signed char layer_one_weights[INPUT_DIM*HIDDEN_DIM] = {
   98,  -73,   52,  -11,  -31,  -52,  125,  -61,  -70,   67,  -16,  -54,
  121,   49,  -91,   17,    5, -101,   29,    7,  -91,  -36,  -12,  -25,
  120,  109,   -7,  -20,   26,   16,   51,  -63, -106,  -83,  -58,   56,
   -7,   16,  -95,    1, -102, -104,   99,  -68,  110,   73,  -36,   90,
   97,   -6,  -82,  -41,   -8, -103,   14, -101,   32,   66,  -49,   80,
  -64,  -27,  127,   58
};
#define LAYER_ONE_WEIGHTS_ZERO_POINT 0
const int layer_one_bias[HIDDEN_DIM] = {
  3679,  -680,     0,  4065, -3252, 10707,   679,  8886,     0, -5100,
     0,     0,   517,     0,  -259, -1294,     0, -1436, -2625,  -354,
     0,  3627,   165,   831,   610,     0,     0,     0,   544,    22,
     0,   106
};
#define LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT -128
const signed char layer_two_weights[HIDDEN_DIM*OUTPUT_DIM] = {
  127,   14,   53,   76,   64, -106,   52,  -42,  -85,  -44,  -55,    3,
   33,   28,   10,  -92,   47,   67,  -70,   12,   55,  124,   21,   91,
   48,   71,   -7,  -57,   33,    6,  -50,   21
};
#define LAYER_TWO_WEIGHTS_ZERO_POINT 0
const int layer_two_bias[OUTPUT_DIM] = {
  1006
};
#define OUTPUT_LAYER_ZERO_POINT -128

#define M0_1 1260531456
#define N_1 7
#define M0_2 1165263744
#define N_2 7

// Declare arrays for intermediate activations
int input_activations[INPUT_DIM];
int weights_shifted[INPUT_DIM*HIDDEN_DIM]; // TODO: Refactor
int weights_two_shifted[HIDDEN_DIM*OUTPUT_DIM];  // TODO: Refactor
int layer_one_activations[HIDDEN_DIM];
int output_activations[OUTPUT_DIM];

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;  
volatile int num_incorrect = 0;

// Software implementation of integer multiplication adapted from: https://github.com/gcc-mirror/gcc/blob/master/libgcc/config/epiphany/mulsi3.c
int __mulsi3(int a, int b) {
    int result = 0;
    int negative = 0;

    // Handle sign and convert to positive
    if (a < 0) {
        a = -a;
        negative = !negative;
    }
    if (b < 0) {
        b = -b;
        negative = !negative;
    }

    // Perform shift-and-add multiplication
    while (b != 0) {
        if (b & 1) {
            result += a; // Add multiplicand if LSB of multiplier is 1
        }
        b >>= 1; // Shift multiplier to the right by 1 bit
        a <<= 1; // Shift multiplicand to the left by 1 bit
    }

    // Apply sign
    return negative ? -result : result;
}

long long __muldi3(long long a, long long b) {
    long long result = 0;
    int negative = 0;

    // Handle sign and convert to positive
    if (a < 0) {
        a = -a;
        negative = !negative;
    }
    if (b < 0) {
        b = -b;
        negative = !negative;
    }

    // Perform shift-and-add multiplication
    while (b != 0) {
        if (b & 1) {
            result += a; // Add multiplicand if LSB of multiplier is 1
        }
        b >>= 1; // Shift multiplier to the right by 1 bit
        a <<= 1; // Shift multiplicand to the left by 1 bit
    }

    // Apply sign
    return negative ? -result : result;
}

// Implementation of integer only neural network inference for 8-bit quantized model trained on UCI air quality dataset with Tensorflow 
char nn_inference(
		signed char co,  // carbon monoxide 
		signed char no2  // nitrogen dioxide
		) 
{
  signed char predicted_nox = -1;  // nitrogen oxide

  // (Inputs - Zero Point of Inputs)
  input_activations[0]  = (int)co       - INPUT_LAYER_ZERO_POINT;
  input_activations[1]  = (int)no2       - INPUT_LAYER_ZERO_POINT;

  // (Weights - Zero Point of Weights)
  // TODO: Optimize this by preprocessing weight offset offline
  for (int i = 0; i < INPUT_DIM * HIDDEN_DIM; i++) {
	  weights_shifted[i] = (int)layer_one_weights[i] - LAYER_ONE_WEIGHTS_ZERO_POINT;
  }

  // (Inputs * Layer 1 Weights) + Bias followed by ReLU
  for (int i = 0; i < HIDDEN_DIM; i++) {
	  for (int j = 0; j < INPUT_DIM; j++){
		  // TODO: Optimize to not read layer_one_activations[i] each time
		  layer_one_activations[i] += (int)input_activations[j] * (int)weights_shifted[i*INPUT_DIM + j]; 
	  }
	  layer_one_activations[i] += layer_one_bias[i];
	  if (layer_one_activations[i] < 0) layer_one_activations[i] = 0;
  }

  // Requantization pipeline
  for (int i = 0; i < HIDDEN_DIM; i++) {
      // Multiply by layer_one_multiplier
      long long temp = (long long)layer_one_activations[i] * M0_1;

      // Divide by 2^31 and round
      if (temp >= 0) {
          temp = (temp + (1LL << 30)) >> 31; // Add 2^30 for rounding, then shift
      } else {
          temp = (temp - (1LL << 30)) >> 31; // Subtract 2^30 for rounding, then shift
      }

      // Divide by 2^layer_one_shift and round
      if (temp >= 0) {
          temp = (temp + (1LL << (N_1 - 1))) >> N_1;
      } else {
          temp = (temp - (1LL << (N_1 - 1))) >> N_1;
      }

      // Add the zero point
      temp += (int)LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT;

      // Clip to the 8-bit signed range
      if (temp > 127) temp = 127;
      if (temp < -128) temp = -128;

      // Store the result back
      layer_one_activations[i] = (int)temp;
  }

  // (Layer 1 Activations - Zero Point of Layer 1 Activations)
  // TODO: Optimize this by folding offset into previous statement
  for (int i = 0; i < HIDDEN_DIM; i++) {
	  layer_one_activations[i] = layer_one_activations[i] - LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT;
  }


  // (Layer 2 Weights - Zero Point of Layer 2 Weights)
  // TODO: Optimize this by preprocessing weight offset offline and hardcode for loop lengths?
  for (int i = 0; i < HIDDEN_DIM * OUTPUT_DIM; i++) {
	  weights_two_shifted[i] = (int)layer_two_weights[i] - LAYER_TWO_WEIGHTS_ZERO_POINT;
  }

  // (Layer 1 Activations * Layer 2 Weights) + Bias
  for (int i = 0; i < OUTPUT_DIM; i++) {
	  for (int j = 0; j < HIDDEN_DIM; j++){
		  // TODO: Optimize to not read output_activations[i] each time
		  output_activations[i] += (int)layer_one_activations[j] * (int)weights_two_shifted[i*HIDDEN_DIM + j]; 
	  }
	  output_activations[i] += layer_two_bias[i];
  }

  // Requantization pipeline
  for (int i = 0; i < OUTPUT_DIM; i++) {
      // Multiply by layer_one_multiplier
      long long temp = (long long)output_activations[i] * M0_2;

      // Divide by 2^31 and round
      if (temp >= 0) {
          temp = (temp + (1LL << 30)) >> 31; // Add 2^30 for rounding, then shift
      } else {
          temp = (temp - (1LL << 30)) >> 31; // Subtract 2^30 for rounding, then shift
      }

      // Divide by 2^layer_one_shift and round
      if (temp >= 0) {
          temp = (temp + (1LL << (N_2 - 1))) >> N_2;
      } else {
          temp = (temp - (1LL << (N_2 - 1))) >> N_2;
      }

      // Add the zero point
      temp += (int)OUTPUT_LAYER_ZERO_POINT;

      // Clip to the 8-bit signed range
      if (temp > 127) temp = 127;
      if (temp < -128) temp = -128;

      // Store the result back
      output_activations[i] = (int)temp;
  }

  // Return output neuron for predicted nox
  predicted_nox = (signed char)output_activations[0];
  return predicted_nox;
}



// Read the values for the data sample and run the neural network to make a prediction
// Compare the predicted class made by this model to the predicted class made by the TFLite model for equivalence check
char Read_Values_Run_Neural_Network() {
  
  signed char co, no2, nox_golden_value;
  signed char tflite_model_prediction, c_model_prediction, error;
  char parity_with_python;


  for (int i = 0; i < Num_Data_Samples; ++i) {
    co = CO_Vector[i];
    no2 = NO2_Vector[i];
    nox_golden_value = NOx_Golden_Value_Vector[i];
    tflite_model_prediction = TFLite_Model_Prediction_Vector[i];

    c_model_prediction = nn_inference(co, no2);

    error = c_model_prediction - tflite_model_prediction;
    error = error < 0 ? -error : error;

    if (error > EPSILON) {
      parity_with_python = 0;
      num_incorrect++;
    }
  }
  return parity_with_python;
}

int main() {
  correct_result = Read_Values_Run_Neural_Network();
  // printf("Number incorrect: %d / %d\n", num_incorrect, Num_Data_Samples);
  return 0;
}
