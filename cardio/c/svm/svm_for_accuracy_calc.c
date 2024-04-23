#include <stdio.h>
#include <stdlib.h>
#include "static_params.h"
#include "static_data.h"

double dot_product(
    const double* svi,
    const double* input,
    int length
    ) {
    double result = 0.0;
    for (int i = 0; i < length; i++) {
        result += svi[i] * input[i];
    }
    return result;
}

void linear_kernel(
    const double (*sv)[NUM_INPUT_FEATURES],
    const double* input,
    double* result
    ) {
    for (int i = 0; i < TOTAL_SV_NUM; i++) {
        result[i] = dot_product(sv[i], input, NUM_INPUT_FEATURES);
    }
}

double kernel_array[TOTAL_SV_NUM] = {0};

void decision_function(
    const double (*sv)[NUM_INPUT_FEATURES],
    const int* nv,
    const double (*a)[TOTAL_SV_NUM],
    const double* b,
    const double* input,
    double* decision
    ) {
    
    // FILE *file = fopen("decision.csv", "a");

    // 1) kernel calculation
    linear_kernel(sv, input, kernel_array);

    int start[NUM_CLASSES];
    int end[NUM_CLASSES];
    start[0] = 0;
    for (int i = 1; i < NUM_CLASSES; i++) {
        start[i] = start[i - 1] + nv[i - 1];
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        end[i] = start[i] + nv[i];
    }

    // 2) decision function calculation
    int index = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = i + 1; j < NUM_CLASSES; j++) {
            decision[index] = 0.0;

            for (int p = start[j]; p < end[j]; p++) {
                decision[index] += a[i][p] * kernel_array[p];
            }

            for (int p = start[i]; p < end[i]; p++) {
                decision[index] += a[j - 1][p] * kernel_array[p];
            }

            decision[index] += b[index];

            index++;
        }
    }
    // fprintf(file, "%f, %f, %f\n", decision[0], decision[1], decision[2]);
    // fclose(file);
}

double decision_array[NUM_CLASSES] = {0.0}; // not sure if the size is always NUM_CLASSES, it works here but maybe should use a diff formula

int predict(
    const double (*sv)[NUM_INPUT_FEATURES],
    const int* nv,
    const double (*a)[TOTAL_SV_NUM],
    const double* b,
    const double* input
    ) {
    decision_function(sv, nv, a, b, input, decision_array);
    
    int votes[NUM_CLASSES] = {0};

    int index = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = i + 1; j < NUM_CLASSES; j++) {
            int predicted_class = (decision_array[index++] > 0.0) ? i : j;
            votes[predicted_class]++;
        }
    }

    int max_index = 0;
    for (int i = 1; i < NUM_CLASSES; i++) {
        if (votes[i] > votes[max_index]) {
            max_index = i;
        }
    }

    return max_index;
}

int main() {
    int correct = 0;

    for (int i = 0; i < SAMPLE_SIZE; i++) {
        int pred_index = predict(
            &support_vectors[0],
            num_support_vectors_per_class,
            &dual_coefs[0],
            intercepts,
            input_array[i]
            );
        if (output_array[i] == (pred_index+1)) {
            correct += 1;
        }
    }

    double accuracy = (double) correct / (double) SAMPLE_SIZE;
    printf("Accuracy: %f \n", accuracy);
    return 0;
}
