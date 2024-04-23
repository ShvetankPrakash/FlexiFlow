#include <stdio.h>
#include "static_data.h"

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
void find_closest() {
    int minSim = 99999999;  // Initialize minimum similarity to the highest possible int value
    int label = -1;  // Initialize label to -1
    int sim;

    for (int i = 0; i < AM_COUNT; i++) {
        sim = VECTOR_SIZE - cosine_similarity(AM[i], Ngram_Array);

  //      printf("Cosine similarity: %d (Label: %d)\n", sim, i);
        if (sim < minSim) {
            minSim = sim;
            label = i;
        }
    }

    printf("Lowest cosine similarity: %d (Label: %d)\n", minSim, label);
}

int main() {
    find_closest();
    return 0;
}
