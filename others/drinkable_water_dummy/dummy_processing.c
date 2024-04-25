#include <stdio.h>
#include "static_data.h"

#define DELAY 10000
#define PH_LOW 6.5
#define PH_HIGH 8.5

double read_sensor(int i) {
    return input_array[i];
}

void sensor_sleep() {
    for (int i = 0; i < DELAY; i++) {
        // no-op
    }
}

int predictions[SAMPLE_SIZE] = {0}; // is drinkable?

void run(int num_readings) {
    for (int i = 0; i < num_readings; i++) {
        double sensor_reading = read_sensor(i);
        if (sensor_reading >= 6.5 && sensor_reading <= 8.5) {
            predictions[i] = 1;
        }
        sensor_sleep();
    }
}

int main() {
    run(SAMPLE_SIZE);
    return 0;
}