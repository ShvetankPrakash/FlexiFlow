#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INPUT_SIZE 21
#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 3

#define DATA_SIZE 2126

typedef struct {
    int num_neurons;
    double weights[HIDDEN_SIZE][INPUT_SIZE];
    double biases[HIDDEN_SIZE];
} Layer;

double relu(double x) {
    if (x > 0.0) {
        return x;
    }
    return 0;
}

void forward_pass(double input[INPUT_SIZE], Layer hidden_layer, Layer output_layer, double output[OUTPUT_SIZE]) {
    double hidden_outputs[HIDDEN_SIZE] = {0};
    double output_logits[OUTPUT_SIZE] = {0};

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double neuron_output = hidden_layer.biases[i];
        for (int j = 0; j < INPUT_SIZE; j++) { // each neuron is connected to all inputs
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
    double exp_sum = 0;
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        exp_sum += exp(output_logits[i]-max_logit);
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output[i] = exp(output_logits[i]-max_logit) / exp_sum;
    }
}

double const sample_input[INPUT_SIZE] = {120,0,0,0,0,0,0,73,0.5,43,2.4,64,62,126,2,0,120,137,121,73,1};

double const hidden_bias[HIDDEN_SIZE] = {
    0.39832570839026904,
    0.1605624598440905,
    0.5324232692249139
};

double const output_bias[OUTPUT_SIZE] = {
    0.5144837505841111,
    -0.3180327795072319,
    -0.6209962969859462
};

// double const output_weights[OUTPUT_SIZE*HIDDEN_SIZE] = {
//     1.0746923135666613, -1.2391205226915465, -0.8319610838504377,
//     -0.6929492209624085, 0.6002867725408909, -0.7236438702563148,
//     -1.9729783350880774, 0.7706447052098919, 1.1440765214577697
//     };

double const output_weights[OUTPUT_SIZE*HIDDEN_SIZE] = {
    1.07469231, -0.69294922, -1.97297834,
    -1.23912052,  0.60028677,  0.77064471,
    -0.83196108, -0.72364387,  1.14407652
};

double const hidden_weights[INPUT_SIZE*HIDDEN_SIZE] = {
    -0.08219146251432813,
    1.0769869899550182,
    -0.05088947388031397,
    1.0838718688582196,
    0.5272659668921466,
    -0.5349238637105227,
    -1.0834734204121776,
    -0.6017219014009797,
    0.5216861251894986,
    -0.6741930879101631,
    0.9152377780366632,
    0.5886397066221515,
    0.10708381772582445,
    0.3147058046098541,
    0.29884590979940096,
    0.016291178258063505,
    0.23429462019017616,
    0.5104256389243933,
    0.09239322657281344,
    -0.9812369623268216,
    0.10999815201364166,
    0.8027429526780707,
    -0.7921318589195606,
    0.8371510099004212,
    -0.6183282738795719,
    0.3487511916635191,
    0.25150937081857155,
    1.0274093183319433,
    0.8132923682022977,
    -0.5992628440763731,
    0.9577413934716823,
    -0.18011044574951157,
    0.3209169689723827,
    -0.19267576991299679,
    0.3174535977422898,
    -0.10416776650601459,
    -0.041309297190460975,
    0.010300899079043345,
    0.1122592126115418,
    0.14573809143276886,
    0.5407678588376489,
    -0.27642028816634534,
    -0.12775482320950654,
    -0.12759887747994492,
    0.1468133032108444,
    0.45414289555057813,
    0.5621396764875509,
    0.6115691228364932,
    1.4400805739795852,
    0.46980675660006654,
    0.8190592756131252,
    -0.5711084282109582,
    0.0239393155610773,
    0.11033082691679866,
    -0.36580802269805723,
    0.28947305469558654,
    0.33379747152674477,
    0.5746025349068148,
    -0.37575993201621477,
    -0.33231561802949594,
    -0.8173585986320281,
    1.0930021904972145,
    -0.43452711714798936
    };


int read_csv(double (*inputs_list)[INPUT_SIZE], double *outputs_list) {
    FILE *file = fopen("cardio_data.csv", "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    int num_lines = 0;
    while (fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
                  &inputs_list[num_lines][0], &inputs_list[num_lines][1], &inputs_list[num_lines][2], &inputs_list[num_lines][3],
                  &inputs_list[num_lines][4], &inputs_list[num_lines][5], &inputs_list[num_lines][6], &inputs_list[num_lines][7],
                  &inputs_list[num_lines][8], &inputs_list[num_lines][9], &inputs_list[num_lines][10], &inputs_list[num_lines][11],
                  &inputs_list[num_lines][12], &inputs_list[num_lines][13], &inputs_list[num_lines][14], &inputs_list[num_lines][15],
                  &inputs_list[num_lines][16], &inputs_list[num_lines][17], &inputs_list[num_lines][18], &inputs_list[num_lines][19],
                  &inputs_list[num_lines][20], &outputs_list[num_lines]) == INPUT_SIZE + 1) {
        num_lines++;
    }

    fclose(file);

    // printf("Loaded data:\n");
    // for (int i = 0; i < 5; i++) {
    //     printf("Input:");
    //     for (int j = 0; j < INPUT_SIZE; j++) {
    //         printf(" %.4f", inputs_list[i][j]);
    //     }
    //     printf(", Output: %.4f\n", outputs_list[i]);
    // }

    return 0;
};

int main() {
    double inputs[DATA_SIZE][INPUT_SIZE];
    double outputs[DATA_SIZE];
    read_csv(inputs, outputs);

    // double input[INPUT_SIZE] = {132,0.006,0,0.006,0.003,0,0,17,2.1,0,10.4,130,68,198,6,1,141,136,140,12,0};

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
        hidden_layer.biases[i] = hidden_bias[ind];
        for (int j=0; j < INPUT_SIZE; j++) {
            hidden_layer.weights[i][j] = hidden_weights[ind];
            ind++;
        }
    }

    // set the output layer params
    ind = 0;
    for (int i=0; i < OUTPUT_SIZE; i++) {
        output_layer.biases[i] = output_bias[ind];
        for (int j=0; j < HIDDEN_SIZE; j++) {
            output_layer.weights[i][j] = output_weights[ind];
            ind++;
        }
    }

    double output_pred[OUTPUT_SIZE];
    int num_correct = 0;

    for (int i=0; i < DATA_SIZE; i++) {
        forward_pass(inputs[i], hidden_layer, output_layer, output_pred);
        int argmax = 0;
        double max_val = output_pred[0];
        for (int m=1; m < OUTPUT_SIZE; m++) {
            if (output_pred[m] > max_val) {
                argmax = m;
            };
        };
        // printf("predicted: %d \n", argmax+1);
        // printf("correct: %d \n", (int) outputs[i]);
        // printf("______");
        // check if correct prediction
        if ((argmax+1) == (int) outputs[i]) {
            num_correct += 1;
        }
    }

    double accuracy = (double) num_correct / (double) DATA_SIZE;
    printf("%f \n", accuracy);

    return 0;
}