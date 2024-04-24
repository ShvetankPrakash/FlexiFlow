#ifndef STATIC_DATA_H
#define STATIC_DATA_H

#define VECTOR_SIZE 10  // Define the vector size
#define AM_COUNT 5  // Number of comparison arrays

// Define arrays here. You will need to fill these with actual data.
const int Ngram_Array[VECTOR_SIZE] = {
    // Populate this array with actual ngram data
    1, -1, 1, -1, 1, -1, 1, -1, 1, -1
};

// Simulated associative array 'AM' containing 5 arrays
const int AM[AM_COUNT][VECTOR_SIZE] = {
    {1, -1, 1, 1, 1, 1, 1, -1, -1, 1},  // AM[0]
    {-1, 1, -1, 1, -1, 1, -1, 1, -1, 1},  // AM[1]
    {1, 1, -1, -1, 1, 1, -1, -1, 1, 1},   // AM[2]
    {1, -1, 1, -1, 1, -1, 1, -1, 1, -1}, // AM[3]
    {1, -1, 1, 1, -1, 1, -1, -1, 1, -1}   // AM[4]
};

#endif // STATIC_DATA_H
