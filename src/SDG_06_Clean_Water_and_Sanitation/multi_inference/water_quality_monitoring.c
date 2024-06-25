#include "sample_data.h"

#define PH_MIN 6.5
#define PH_MAX 8.5

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;

char potable_check(double pH) {
  return (pH < PH_MAX && pH > PH_MIN);
}

char Read_Sensor_Values_Run() {
  double pH;
  char potable, golden_reference;

  unsigned short data_sample;
  char GPIO;

  for (data_sample = 0; data_sample < Num_Data_Samples; data_sample++) {
    pH = pH_Sensor_Input_Vector[data_sample];
    potable = potable_check(pH);
    golden_reference = Golden_Reference_Potability[data_sample];

    if (potable != golden_reference) {
      // Failure case - this really shouldn't happen for basic thresholding
      GPIO = 0;
      return GPIO;
    }
  }

  GPIO = 1;
  return GPIO;
}

int main() {
  correct_result = Read_Sensor_Values_Run();
  return 0;
}
