#include <stdio.h>
#include "static_data.h"
#include "static_params.h"

#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 3

typedef struct {
    int num_neurons;
    double weights[HIDDEN_SIZE][NUM_INPUT_FEATURES];
    double biases[HIDDEN_SIZE];
} Layer;

double relu(double x) {
    if (x > 0.0) {
        return x;
    }
    return 0;
}

// calculating the exp with the taylor series
double baremetal_exp(double x) {
    double result = 1.0;
    double term = 1.0;
    int i;

    for (i = 1; i < 26; ++i) { // 26 terms is the minimum to get max accuracy
        term *= x / i;
        result += term;
    }

    return result;
}

void forward_pass(const double* input, Layer hidden_layer, Layer output_layer, double output[OUTPUT_SIZE]) {
    double hidden_outputs[HIDDEN_SIZE] = {0};
    double output_logits[OUTPUT_SIZE] = {0};

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double neuron_output = hidden_layer.biases[i];
        for (int j = 0; j < NUM_INPUT_FEATURES; j++) { // each neuron is connected to all inputs
            neuron_output += hidden_layer.weights[i][j] * input[j];
        }
        hidden_outputs[i] = relu(neuron_output);
    }


    for (int i = 0; i < OUTPUT_SIZE; i++) {
        double neuron_output = output_layer.biases[i];
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            neuron_output += output_layer.weights[i][j] * hidden_outputs[j];
        }
        output_logits[i] = neuron_output;
    }

    // softmax
    double max_logit = output_logits[0];
    for (int i = 1; i < OUTPUT_SIZE; i++) {
        if (output_logits[i] > max_logit) {
            max_logit = output_logits[i];
        }
    }
    double exp_sum = 0.0;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        exp_sum += baremetal_exp(output_logits[i]-max_logit);
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output[i] = baremetal_exp(output_logits[i]-max_logit) / exp_sum;
    }
}

// int read_csv(double (*inputs_list)[NUM_INPUT_FEATURES], double *outputs_list) {
//     FILE *file = fopen("test_data_fp20.csv", "r");
//     if (file == NULL) {
//         printf("Error: Unable to open file\n");
//         return 1;
//     }

//     int num_lines = 0;
//     while (fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
//                   &inputs_list[num_lines][0], &inputs_list[num_lines][1], &inputs_list[num_lines][2], &inputs_list[num_lines][3],
//                   &inputs_list[num_lines][4], &inputs_list[num_lines][5], &inputs_list[num_lines][6], &inputs_list[num_lines][7],
//                   &inputs_list[num_lines][8], &inputs_list[num_lines][9], &inputs_list[num_lines][10], &inputs_list[num_lines][11],
//                   &inputs_list[num_lines][12], &inputs_list[num_lines][13], &inputs_list[num_lines][14], &inputs_list[num_lines][15],
//                   &inputs_list[num_lines][16], &inputs_list[num_lines][17], &inputs_list[num_lines][18], &inputs_list[num_lines][19],
//                   &inputs_list[num_lines][20], &outputs_list[num_lines]) == NUM_INPUT_FEATURES + 1) {
//         num_lines++;
//     }

//     fclose(file);

//     // Open the file for writing
//     FILE *t_file = fopen("inputs.txt", "w");
//     if (t_file == NULL) {
//         printf("Error opening file.\n");
//         return 1;
//     }

//     // Write data to the file
//     for (int i = 0; i < SAMPLE_SIZE; i++) {
//         fprintf(t_file, "{");
//         for (int j = 0; j < NUM_INPUT_FEATURES; j++) {
//             fprintf(t_file, "%lf", inputs_list[i][j]);  // Adjust the precision as needed
//             if (j < NUM_INPUT_FEATURES - 1) {
//                 fprintf(t_file, ", ");
//             }
//         }
//         fprintf(t_file, "},\n");
//     }

//     // Close the file
//     fclose(t_file);

//     return 0;
// };

int predictions[SAMPLE_SIZE] = {0};

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
        for (int j=0; j < NUM_INPUT_FEATURES; j++) {
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

    double output_pred[OUTPUT_SIZE];

    for (int i=0; i < SAMPLE_SIZE; i++) {
        forward_pass(input_array[i], hidden_layer, output_layer, output_pred);
        int argmax = 0;
        double max_val = output_pred[0];
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


void calculate_accuracy() {    
    read_inputs_run_mlp();

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
        for (int j=0; j < NUM_INPUT_FEATURES; j++) {
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

    double output_pred[OUTPUT_SIZE];
    int num_correct = 0;

    for (int i=0; i < SAMPLE_SIZE; i++) {
        forward_pass(input_array[i], hidden_layer, output_layer, output_pred);
        int argmax = 0;
        double max_val = output_pred[0];
        for (int m=1; m < OUTPUT_SIZE; m++) {
            if (output_pred[m] > max_val) {
                argmax = m;
                max_val = output_pred[m];
            };
        };

        if ((argmax+1) == (int) output_array[i]) {
            num_correct += 1;
        }
    }

    double accuracy = (double) num_correct / (double) SAMPLE_SIZE;
    printf("%f \n", accuracy);
}

int main() {
    calculate_accuracy();
    return 0;
}