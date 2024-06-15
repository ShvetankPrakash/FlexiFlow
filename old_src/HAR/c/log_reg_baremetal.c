#include "static_params.h"
#include "static_data.h"

int predictions[SAMPLE_SIZE] = {0};

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
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        predictions[i] = predict(input_array[i]);
    }
    return 0;
}