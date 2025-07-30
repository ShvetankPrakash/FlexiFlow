#include "sample_data.h"
// #include <stdio.h>
#define INPUT_DIM  5
#define HIDDEN_DIM_1 20
#define HIDDEN_DIM_2 10
#define OUTPUT_DIM 3

#define INPUT_LAYER_ZERO_POINT -128
const signed char layer_one_weights[INPUT_DIM*HIDDEN_DIM_1] = {
    3,-43,-26,3,-14,
    13,38,-6,31,56,
    -8,36,-4,-16,-12,
    125,12,15,75,20,
    -7,113,121,28,11,
    7,-37,-34,13,-36,
    127,46,45,23,103,
    -2,0,0,0,8,
    57,51,-40,79,60,
    64,-1,79,98,47,
    -8,0,0,0,0,
    44,113,18,89,72,
    12,-60,-35,22,-19,
    0,0,-5,0,-5,
    44,11,94,71,105,
    9,-9,20,-5,0,
    -35,82,43,121,84,
    -50,-42,-31,17,21,
    -34,13,-33,-1,-31,
    -10,0,-13,-1,-11

};
#define LAYER_ONE_WEIGHTS_ZERO_POINT 0
const int layer_one_bias[HIDDEN_DIM_1] = {
    18655,  12505,  -3345, -14849, -14788,  19729, -12320,  -2316, -20467,  -6987,
    -2239, -17472,  18947,      0,  -3783,  -3842,  19403,  19277,  18555,      0
};
#define LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT -128
const signed char layer_two_weights[HIDDEN_DIM_1*HIDDEN_DIM_2] = {
    90,33,0,-38,-37,77,11,9,-18,-26,0,-49,76,0,24,0,11,62,63,0,
    -59,24,9,61,110,-40,8,0,47,82,0,12,-110,0,89,-8,-11,-60,-96,0,
    0,0,0,6,0,10,-2,-3,4,-4,0,-2,0,0,0,0,0,1,0,-2,
    -47,38,11,94,94,-57,31,0,100,86,0,95,-92,0,27,11,26,-121,-50,0,
    1,-5,0,-1,0,5,0,0,5,0,10,-17,17,0,0,1,12,-3,-2,0,
    -38,-31,3,22,45,-36,43,7,46,13,0,47,-44,0,22,-1,-5,-43,-38,2,
    0,0,0,-4,-8,0,0,5,0,0,-8,0,0,0,0,3,0,0,0,0,
    75,36,-6,-91,-95,127,-66,-2,-17,-66,0,-11,83,-1,-95,0,43,124,115,0,
    -35,-17,0,3,26,-23,84,0,42,69,0,45,-61,-2,75,9,96,-21,-53,-7,
    54,55,0,-79,-37,50,-79,-9,-107,73,-5,-66,57,0,90,0,109,41,101,1
};
#define LAYER_TWO_WEIGHTS_ZERO_POINT 0
const int layer_two_bias[HIDDEN_DIM_2] = {
    5975, -5591, -1055, -4408, -2196, -3471,  -756,  4082,  -644,  6259
};
#define LAYER_TWO_OUTPUT_ACTIVATIONS_ZERO_POINT -128
const signed char layer_three_weights[HIDDEN_DIM_2*OUTPUT_DIM] = {
    92,-90,-21,-96,0,-17,0,116,-112,59,
    -6,-39,0,-51,30,-45,0,-117,102,127,
    -64,113,-20,65,0,45,0,-73,83,-110
};
#define LAYER_THREE_WEIGHTS_ZERO_POINT 0
const int layer_three_bias[OUTPUT_DIM] = {
    1992,  2151, -2183
};
#define OUTPUT_LAYER_ZERO_POINT 13

#define M0_1 1428873344
#define N_1 8
#define M0_2 1890307072
#define N_2 10
#define M0_3 1217779456
#define N_3 8

// Declare arrays for intermediate activations
int input_activations[INPUT_DIM];
int weights_shifted[INPUT_DIM*HIDDEN_DIM_1]; // TODO: Refactor
int weights_two_shifted[HIDDEN_DIM_1*HIDDEN_DIM_2];  // TODO: Refactor
int weights_three_shifted[HIDDEN_DIM_2*OUTPUT_DIM];  // TODO: Refactor
int layer_one_activations[HIDDEN_DIM_1];
int layer_two_activations[HIDDEN_DIM_2];
int output_activations[OUTPUT_DIM];

// Global volatile variable to verify result is not optimized out
volatile signed char result = -1;  

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

// Implementation of integer only neural network inference for 8-bit quantized model trained on UCI cardiotocography dataset with Tensorflow 
char nn_inference(
        unsigned char no2,
        unsigned char o3,
        unsigned char temp,
        unsigned char humidity,
        unsigned char wind_speed
        ) {
    char predicted_class;

    // (Inputs - Zero Point of Inputs)
    input_activations[0] = no2 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[1] = o3 - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[2] = temp - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[3] = humidity - INPUT_LAYER_ZERO_POINT - 128;
    input_activations[4] = wind_speed - INPUT_LAYER_ZERO_POINT - 128;

    // (Weights - Zero Point of Weights)
    // TODO: Optimize this by preprocessing weight offset offline
    for (int i = 0; i < INPUT_DIM * HIDDEN_DIM_1; i++) {
        weights_shifted[i] = (int)layer_one_weights[i] - LAYER_ONE_WEIGHTS_ZERO_POINT;
    }

    // (Inputs * Layer 1 Weights) + Bias followed by ReLU
    for (int i = 0; i < HIDDEN_DIM_1; i++) {
        for (int j = 0; j < INPUT_DIM; j++){
            // TODO: Optimize to not read layer_one_activations[i] each time
            layer_one_activations[i] += (int)input_activations[j] * (int)weights_shifted[i*INPUT_DIM + j]; 
        }
        layer_one_activations[i] += layer_one_bias[i];
        if (layer_one_activations[i] < 0) layer_one_activations[i] = 0;
    }

    // Requantization pipeline
    for (int i = 0; i < HIDDEN_DIM_1; i++) {
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
    for (int i = 0; i < HIDDEN_DIM_1; i++) {
        layer_one_activations[i] = layer_one_activations[i] - LAYER_ONE_OUTPUT_ACTIVATIONS_ZERO_POINT;
    }


    // (Layer 2 Weights - Zero Point of Layer 2 Weights)
    // TODO: Optimize this by preprocessing weight offset offline and hardcode for loop lengths?
    for (int i = 0; i < HIDDEN_DIM_1 * HIDDEN_DIM_2; i++) {
        weights_two_shifted[i] = (int)layer_two_weights[i] - LAYER_TWO_WEIGHTS_ZERO_POINT;
    }

    // (Layer 1 Activations * Layer 2 Weights) + Bias
    for (int i = 0; i < HIDDEN_DIM_2; i++) {
        for (int j = 0; j < HIDDEN_DIM_1; j++){
            // TODO: Optimize to not read output_activations[i] each time
            layer_two_activations[i] += (int)layer_one_activations[j] * (int)weights_two_shifted[i*HIDDEN_DIM_1 + j]; 
        }
        layer_two_activations[i] += layer_two_bias[i];
    }

    // Requantization pipeline
    for (int i = 0; i < HIDDEN_DIM_2; i++) {
        // Multiply by layer_one_multiplier
        long long temp = (long long)layer_two_activations[i] * M0_2;

        // Divide by 2^31 and round
        if (temp >= 0) {
            temp = (temp + (1LL << 30)) >> 31; // Add 2^30 for rounding, then shift
        } else {
            temp = (temp - (1LL << 30)) >> 31; // Subtract 2^30 for rounding, then shift
        }

        // Divide by 2^layer_one_shift and round
        if (temp >= 0) {
            temp = (temp + (1LL << (N_1 - 1))) >> N_2;
        } else {
            temp = (temp - (1LL << (N_1 - 1))) >> N_2;
        }

        // Add the zero point
        temp += (int)LAYER_TWO_OUTPUT_ACTIVATIONS_ZERO_POINT;

        // Clip to the 8-bit signed range
        if (temp > 127) temp = 127;
        if (temp < -128) temp = -128;

        // Store the result back
        layer_two_activations[i] = (int)temp;
    }

    // (Layer 2 Activations - Zero Point of Layer 2 Activations)
    // TODO: Optimize this by folding offset into previous statement
    for (int i = 0; i < HIDDEN_DIM_2; i++) {
        layer_two_activations[i] = layer_two_activations[i] - LAYER_TWO_OUTPUT_ACTIVATIONS_ZERO_POINT;
    }

    // (Layer 3 Weights - Zero Point of Layer 3 Weights)
    // TODO: Optimize this by preprocessing weight offset offline and hardcode for loop lengths?
    for (int i = 0; i < HIDDEN_DIM_2 * OUTPUT_DIM; i++) {
        weights_three_shifted[i] = (int)layer_three_weights[i] - LAYER_THREE_WEIGHTS_ZERO_POINT;
    }

    // (Layer 2 Activations * Layer 3 Weights) + Bias
    for (int i = 0; i < OUTPUT_DIM; i++) {
        for (int j = 0; j < HIDDEN_DIM_2; j++){
            // TODO: Optimize to not read output_activations[i] each time
            output_activations[i] += (int)layer_two_activations[j] * (int)weights_three_shifted[i*HIDDEN_DIM_2 + j]; 
        }
        output_activations[i] += layer_three_bias[i];
    }

    // Requantization pipeline
    for (int i = 0; i < OUTPUT_DIM; i++) {
        // Multiply by layer_one_multiplier
        long long temp = (long long)output_activations[i] * M0_3;

        // Divide by 2^31 and round
        if (temp >= 0) {
            temp = (temp + (1LL << 30)) >> 31; // Add 2^30 for rounding, then shift
        } else {
            temp = (temp - (1LL << 30)) >> 31; // Subtract 2^30 for rounding, then shift
        }

        // Divide by 2^layer_one_shift and round
        if (temp >= 0) {
            temp = (temp + (1LL << (N_2 - 1))) >> N_3;
        } else {
            temp = (temp - (1LL << (N_2 - 1))) >> N_3;
        }

        // Add the zero point
        temp += (int)OUTPUT_LAYER_ZERO_POINT;

        // Clip to the 8-bit signed range
        if (temp > 127) temp = 127;
        if (temp < -128) temp = -128;

        // Store the result back
        output_activations[i] = (int)temp;
    }

    // Return argmax for predicted class
    int max_activation = -128;
    for (int i = 0; i < OUTPUT_DIM; i++) {
        if (output_activations[i] >= max_activation) {
            max_activation = output_activations[i];
            predicted_class = i;
        }
    }
    return predicted_class;
}

char Read_Values_Run_Neural_Network() {

    // Run inference for all samples in the vectors and return the number of correct predictions
    int correct = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
        signed char no2 = NO2_Vector[i];
        signed char o3 = O3_Vector[i];
        signed char temp = Temp_Vector[i];
        signed char humidity = Humidity_Vector[i];
        signed char wind_speed = Wind_Speed_Vector[i];

        signed char c_model_prediction = nn_inference(no2, o3, temp, humidity, wind_speed);

        if (c_model_prediction == Label_Vector[i]) {
            correct++;
        }
    }
    return correct;
}

int main() {
    result = Read_Values_Run_Neural_Network();
    // printf("%d / %d\n", result, NUM_SAMPLES);
    return 0;
}
