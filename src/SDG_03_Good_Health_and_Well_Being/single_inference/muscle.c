#include "sample_data.h"

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;  

// Function to compute the sign agreement difference
int sign_agreement_difference(const int* u, const int* v) {
    int same_sign_count = 0;
    for (int i = 0; i < VECTOR_SIZE; i++) {
        if (u[i] == v[i]) {
            same_sign_count++;  // Count same signs
        }
    }
//    printf("%d\n", same_sign_count);
    return 2 * same_sign_count - VECTOR_SIZE;  // Direct computation of the dot product based on sign agreement
}

// Function to calculate cosine similarity using additions, subtractions, and negations
int cosine_similarity(const int* u, const int* v) {
    int dot = sign_agreement_difference(u, v);
    return dot;  // Cosine similarity * 10000 (avoid division)
}

// Find the array with the lowest cosine similarity to the 'ngram' array
char run_muscle() {
    char GPIO;

    int maxSim = 0;  // Initialize minimum similarity to the highest possible int value
    int label = -1;  // Initialize label to -1
    int sim;

    for (int i = 0; i < AM_COUNT; i++) {
        sim = cosine_similarity(AM[i], Ngram_Array);

        if (sim > maxSim) {
            maxSim = sim;
            label = i;
        }
    }

    if (maxSim != 260 || label != 0) {
        GPIO = 0;
        return GPIO;
    }
    else return GPIO = 1;


    printf("Lowest cosine similarity: %d (Label: %d)\n", maxSim, label);
}
int main() {
  correct_result = run_muscle();
  return 0;
}

