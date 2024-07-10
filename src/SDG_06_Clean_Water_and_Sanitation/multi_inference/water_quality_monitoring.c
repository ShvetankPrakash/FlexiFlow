#include "sample_data.h"

#define PH_MIN 6.5
#define PH_MAX 8.5
#define O2_MIN 6
#define TDS_MAX 600

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;

char potable_check(double o2, double pH, double tds) {
  return o2 > O2_MIN && (pH < PH_MAX && pH > PH_MIN) && tds < TDS_MAX;
}

char Read_Sensor_Values_Run() {
  double pH, o2, tds;
  char potable, golden_reference;

  unsigned short data_sample;
  char GPIO;

  for (data_sample = 0; data_sample < Num_Data_Samples; data_sample++) {
    pH = pH_Sensor_Input_Vector[data_sample];
    o2 = O2_Sensor_Input_Vector[data_sample];
    tds = TDS_Sensor_Input_Vector[data_sample];
    potable = potable_check(o2, pH, tds);
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
