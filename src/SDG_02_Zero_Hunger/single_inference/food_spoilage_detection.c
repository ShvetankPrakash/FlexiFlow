#include "sample_data.h"

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;  

// Spoilage check function
char spoilage_check(double temp, double humidity, double co2, double days) {
    // Define the thresholds for Temp, Humidity, CO2, and Days
    #define TEMP_MIN 5
    #define TEMP_MAX 25
    #define HUMIDITY_MIN 50
    #define HUMIDITY_MAX 70
    #define CO2_MIN 350
    #define CO2_MAX 450
    #define DAYS_MAX 10

    return temp >= TEMP_MIN && temp <= TEMP_MAX &&
           humidity >= HUMIDITY_MIN && humidity <= HUMIDITY_MAX &&
           co2 >= CO2_MIN && co2 <= CO2_MAX &&
           days <= DAYS_MAX;
}

// Function to read the sensor values and run the spoilage check
char Read_Sensor_Values_Run_Check() {
    double temp, humidity, co2, days;
    char spoiled, golden_reference;

    // Read sensor values from the header file
    temp = Temp_Sensor_Input;
    humidity = Humidity_Sensor_Input;
    co2 = CO2_Sensor_Input;
    days = Days_Sensor_Input;
    spoiled = spoilage_check(temp, humidity, co2, days);
    golden_reference = Spoiled_Reference;

    // Check if the predicted spoilage matches the golden reference
    if (spoiled != golden_reference) {
        // Failure case - this really shouldn't happen for basic thresholding
        return 0;
    }

    return 1;
}

int main() {
    correct_result = Read_Sensor_Values_Run_Check();
    return 0;
}
