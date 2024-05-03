#include <stdio.h>
#include "static_data.h"

// Function to calculate the dot product of two vectors
int dot_product(const int* u, const int* v) {
    int sum = 0;
    for (int i = 0; i < VECTOR_SIZE; i++) {
        sum += u[i] * v[i];
    }
    return sum;
}

// Function to calculate the squared magnitude of a vector
int magnitude_squared(const int* vec) {
    int sum = 0;
    for (int i = 0; i < VECTOR_SIZE; i++) {
        sum += vec[i] * vec[i];
    }
    return sum;
}

// Function to calculate the cosine similarity between two vectors
float cosine_similarity(const int* u, const int* v) {
    int dot = dot_product(u, v);
    int mag_u_squared = magnitude_squared(u);
    int mag_v_squared = magnitude_squared(v);

    // To prevent division by zero, which is undefined
    if (mag_u_squared == 0 || mag_v_squared == 0) {
        return 0;  // Could alternatively set an error flag or return an impossible value
    }

    // Assuming that cosine similarity needs to be returned as an integer percentage
    // We return 100 times the ratio of dot product to product of squared magnitudes
    // This avoids floating point arithmetic by keeping values in integer space
    return (100.0f * dot) / (mag_u_squared * mag_v_squared);
}

// Find the array with the lowest cosine similarity to the 'ngram' array
void find_closest() {
    float maxSim = 0.0f;  // Initialize minimum similarity to the highest possible int value
    int label = -1;  // Initialize label to -1
    float sim;

    for (int i = 0; i < AM_COUNT; i++) {
        sim = cosine_similarity(AM[i], Ngram_Array);

        printf("Cosine similarity: %f (Label: %d)\n", sim, i);
        if (sim > maxSim) {
            maxSim = sim;
            label = i;
        }
    }

    printf("Highest cosine similarity: %f (Label: %d)\n", maxSim, label);
}

int main() {
    find_closest();
    return 0;
}
