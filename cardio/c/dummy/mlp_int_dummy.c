#include "dummy_data.h"
#include "dummy_weights.h"

int predictions[DATA_SIZE] = {0};

typedef struct {
    int num_neurons;
    int weights[HIDDEN_SIZE][INPUT_SIZE];
    int biases[HIDDEN_SIZE];
} Layer;

int relu(int x) {
    if (x > 0.0) {
        return x;
    }
    return 0;
}

// calculating the exp with the taylor series
int baremetal_exp(int x) {
    int result = 1;
    int term = 1;
    int i;

    for (i = 1; i < 26; ++i) { // 26 terms is the minimum to get max accuracy
        term *= x / i;
        result += term;
    }

    return result;
}

void forward_pass(const int input[INPUT_SIZE], Layer hidden_layer, Layer output_layer, int output[OUTPUT_SIZE]) {
    int hidden_outputs[HIDDEN_SIZE] = {0};
    int output_logits[OUTPUT_SIZE] = {0};

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        int neuron_output = hidden_layer.biases[i];
        for (int j = 0; j < INPUT_SIZE; j++) { // each neuron is connected to all inputs
            neuron_output += hidden_layer.weights[i][j] * input[j];
        }
        hidden_outputs[i] = relu(neuron_output);
    }


    for (int i = 0; i < OUTPUT_SIZE; i++) {
        int neuron_output = output_layer.biases[i];
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            neuron_output += output_layer.weights[i][j] * hidden_outputs[j];
        }
        output_logits[i] = neuron_output;
    }

    // softmax
    int max_logit = output_logits[0];
    for (int i = 1; i < OUTPUT_SIZE; i++) {
        if (output_logits[i] > max_logit) {
            max_logit = output_logits[i];
        }
    }
    int exp_sum = 0.0;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        exp_sum += baremetal_exp(output_logits[i]-max_logit);
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output[i] = baremetal_exp(output_logits[i]-max_logit) / exp_sum;
    }
}

int* read_inputs_run_mlp() {
    // using input_array from static_data.h
    Layer hidden_layer = {
        .num_neurons = HIDDEN_SIZE,
        .weights = {{0}},
        .biases = {0}
    };

    Layer output_layer = {
        .num_neurons = OUTPUT_SIZE,
        .weights = {{0}},
        .biases = {0}
    };

    // set the hidden layer params
    int ind = 0;
    for (int i=0; i < HIDDEN_SIZE; i++) {
        hidden_layer.biases[i] = hidden_bias[i];
        for (int j=0; j < INPUT_SIZE; j++) {
            hidden_layer.weights[i][j] = hidden_weights[ind];
            ind++;
        }
    }

    // set the output layer params
    ind = 0;
    for (int i=0; i < OUTPUT_SIZE; i++) {
        output_layer.biases[i] = output_bias[i];
        for (int j=0; j < HIDDEN_SIZE; j++) {
            output_layer.weights[i][j] = output_weights[ind];
            ind++;
        }
    }

    int output_pred[OUTPUT_SIZE];

    for (int i=0; i < DATA_SIZE; i++) {
        forward_pass(input_array[i], hidden_layer, output_layer, output_pred);
        int argmax = 0;
        int max_val = output_pred[0];
        for (int m=1; m < OUTPUT_SIZE; m++) {
            if (output_pred[m] > max_val) {
                argmax = m;
                max_val = output_pred[m];
            };
        };
        predictions[i] = argmax+1;
    }

    return predictions;
}

int main() {
    read_inputs_run_mlp();
    return 0;
}