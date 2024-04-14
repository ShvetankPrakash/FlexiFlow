#define INPUT_SIZE 21
#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 3

const int hidden_bias[HIDDEN_SIZE] = {
    1,
    2,
    1
};

const int output_bias[OUTPUT_SIZE] = {
    2,
    0,
    -1
};

const int output_weights[OUTPUT_SIZE*HIDDEN_SIZE] = {
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    -1,
    -1
};

const int hidden_weights[INPUT_SIZE*HIDDEN_SIZE] = {
    -1,
    1,
    1,
    1,
    -1,
    1,
    -1,
    -1,
    1,
    1,
    1,
    1,
    1,
    2,
    1,
    1,
    1,
    1,
    1,
    1,
    -1,
    1,
    1,
    1,
    1,
    0,
    1,
    1,
    2,
    1,
    1,
    0,
    1,
    1,
    1,
    -1,
    1,
    1,
    1,
    1,
    2,
    -1,
    1,
    1,
    1,
    1,
    -1,
    1,
    1,
    -1,
    1,
    0,
    0,
    1,
    1,
    1,
    0,
    1,
    1,
    1,
    1,
    0,
    1,
};