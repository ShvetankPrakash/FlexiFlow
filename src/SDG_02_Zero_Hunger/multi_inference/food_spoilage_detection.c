#include "sample_data.h"

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;  

// Thresholds
#define TEMP_MIN 5
#define TEMP_MAX 25
#define HUMIDITY_MIN 50
#define HUMIDITY_MAX 70
#define CO2_MIN 350
#define CO2_MAX 450
#define DAYS_MAX 10

char spoilage_check(double temp, double humidity, double co2, double days) {
    return temp >= TEMP_MIN && temp <= TEMP_MAX &&
           humidity >= HUMIDITY_MIN && humidity <= HUMIDITY_MAX &&
           co2 >= CO2_MIN && co2 <= CO2_MAX &&
           days <= DAYS_MAX;
}

char Read_Sensor_Values_Run_Check() {
    double temp, humidity, co2, days;
    char spoiled, golden_reference;

    unsigned short data_sample;
    char GPIO;

    for (data_sample = 0; data_sample < Num_Data_Samples; data_sample++) {
        temp = Temp_Sensor_Input_Vector[data_sample];
        humidity = Humidity_Sensor_Input_Vector[data_sample];
        co2 = CO2_Sensor_Input_Vector[data_sample];
        days = Days_Sensor_Input_Vector[data_sample];
        spoiled = spoilage_check(temp, humidity, co2, days);
        golden_reference = Spoiled_Reference[data_sample];

        if (spoiled != golden_reference) {
            // Failure case - this really shouldn't happen for basic thresholding
            GPIO = 0;
            return GPIO;
        }
    }

    GPIO = 1;
    return GPIO;
}

int main() {
    correct_result = Read_Sensor_Values_Run_Check();
    return 0;
}
