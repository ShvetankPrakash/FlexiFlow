#include <stdio.h>
#include "static_params.h"
#include "static_data.h"

int predict(const double* input) {
    double class_reg[NUM_CLASSES] = {0};

    for (int cl = 0; cl < NUM_CLASSES; cl++) {
        // dot product
        for (int i = 0; i < NUM_INPUT_FEATURES; i++) {
            class_reg[cl] += input[i] * coefs[cl][i];
        }
    }

    int max_index = 0;
    double max_val = class_reg[0];
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (class_reg[i] > max_val) {
            max_index = i;
            max_val = class_reg[i];
        }
    }

    return max_index + 1;
}

int main() {
    int correct = 0;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        int pred = predict(input_array[i]);
        correct += pred == output_array[i];
    }

    double accuracy = (double) correct / (double) SAMPLE_SIZE;
    printf("Accuracy: %f\n", accuracy);
    return 0;
}