#include "sample_data.h"
// #include <stdio.h>

#define K 3

// Global volatile variable to verify result is not optimized out
volatile char result = -1;

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

// Function to calculate Euclidean distance between two points
unsigned long euclidean_distance(const short *point1, const short *point2) {
  unsigned long sum = 0;
  int i;
  for (i = 0; i < Num_Features; i++) {
    short diff = point1[i] - point2[i];
    sum += diff * diff; // No need for a separate power function
  }
  return sum;
}

// Find the majority class among k neighbors
char majority_vote(short *labels) {
  char count[2] = {0, 0}; // Assuming binary classification (0 or 1)
  for (int i = 0; i < K; i++) {
    count[labels[i]]++;
  }
  return (count[0] > count[1]) ? 0 : 1;
}

// Custom implementation of KNN without standard library functions
int predict_classification(short *test_point) {
  unsigned long distances[Num_Training_Samples]; // Adjust the size based on your data
  short labels[Num_Training_Samples];

  // Calculate distances to each training point
  int i, j;
  for (i = 0; i < Num_Training_Samples; i++) {
    distances[i] =
        euclidean_distance((const short *)Training_Data_Vector[i], test_point);
    labels[i] = Training_Pump_Vector[i]; // Last column is label
  }

  // Simple selection sort to find k nearest neighbors
  for (i = 0; i < Num_Training_Samples - 1; i++) {
    for (j = i + 1; j < Num_Training_Samples; j++) {
      if (distances[i] > distances[j]) {
        // Swap distances
        unsigned long temp_dist = distances[i];
        distances[i] = distances[j];
        distances[j] = temp_dist;

        // Swap labels accordingly
        int temp_label = labels[i];
        labels[i] = labels[j];
        labels[j] = temp_label;
      }
    }
  }

  // Majority vote to decide the class
  return majority_vote(labels);
}

char Read_Sensor_Values_Run_KNN() {

  char predicted_pump;
  short sensor_inputs[Num_Features];
  unsigned short data_sample;
  char GPIO;

  // Fill in current sensor input
  for (int i = 0; i < Num_Features; ++i)
    sensor_inputs[i] = Testing_Data[i];

  predicted_pump = predict_classification(sensor_inputs);

  if (predicted_pump)
    GPIO = 1;
  else
    GPIO = 0;

  return GPIO;
}

int main() {
  result = Read_Sensor_Values_Run_KNN();
  // printf("Result: %d\n", result);
  return 0;
}
