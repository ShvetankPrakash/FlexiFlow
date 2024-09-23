#include "sample_data.h"
// #include <stdio.h>

#define K 3

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;
unsigned int num_incorrect = 0;

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
  unsigned long
      distances[Num_Training_Samples]; // Adjust the size based on your data
  short labels[Num_Training_Samples];

  // Calculate distances to each training point
  int i, j;
  for (i = 0; i < Num_Training_Samples; i++) {
    distances[i] =
        euclidean_distance((const short *)Training_Vector[i], test_point);
    labels[i] = (int)Training_Vector[i][Num_Features]; // Last column is label
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

char Read_Sensor_Values_Run_KNNs() {

  char golden_reference, predicted_pump;
  short sensor_inputs[Num_Features];
  unsigned short data_sample;
  char GPIO;

  for (data_sample = 0; data_sample < Num_Data_Samples; data_sample++) {

    // Fill in current sensor input
    for (int i = 0; i < Num_Features; ++i)
        sensor_inputs[i] = Data_Vector[data_sample][i];

    golden_reference = (char) Data_Vector[data_sample][Num_Features];

    predicted_pump = predict_classification(sensor_inputs);


    if (golden_reference != predicted_pump) {
      GPIO = 0;
      num_incorrect++;
    } else {
      // printf ("GPIO=%d for Data Sample:%d\n", GPIO, data_sample);
    }
  }

  return GPIO;
}

int main() {
    correct_result = Read_Sensor_Values_Run_KNNs();
    // printf("Num incorrect: %d / %d\n", num_incorrect, Num_Data_Samples);
    return 0;
}
