#include <stdio.h>
#include "random_forest_data.h"

#define NUM_FEATURES 7

int main() {
    int16_t predictions[Num_Data_Samples];

    // Perform inference for each sample
    for (int i = 0; i < Num_Data_Samples; i++) {
        float weighted_sum = 0.0;

        // Calculate weighted sum based on feature importances
        for (int j = 0; j < NUM_FEATURES; j++) {
            weighted_sum += inference_data[i][j] * feature_importances[j];
        }

        // Convert weighted sum to integer prediction (simplified example)
        predictions[i] = (int16_t)weighted_sum/10;

        // Print the prediction
        printf("Prediction for sample %d: %d\n", i, predictions[i]);
    }

    return 0;
}
