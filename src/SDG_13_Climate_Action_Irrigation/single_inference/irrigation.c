#include "sample_data.h"

// Define the number of neighbors (k) for KNN
#define K 5

// Global volatile variable to verify result is not optimized out
volatile char correct_result = -1;

// Function to calculate Euclidean distance between two points
double Euclidean_Distance(double *a, double *b, int num_features) {
    double distance = 0.0;
    for (int i = 0; i < num_features; i++) {
        double diff = a[i] - b[i];
        distance += diff * diff;
    }
    return distance; // Returning squared distance for comparison
}

// Function to find the majority class among the k-nearest neighbors
char Find_Majority_Class(int *neighbor_classes, int k) {
    int count_0 = 0, count_1 = 0;
    for (int i = 0; i < k; i++) {
        if (neighbor_classes[i] == 0)
            count_0++;
        else
            count_1++;
    }
    return (count_0 > count_1) ? 0 : 1;
}

// Function to classify a single test point using KNN
char KNN_Classifier(double *test_features, double training_data[][NUM_FEATURES], int training_labels[], int num_training_samples) {
    double distances[TRAIN_SIZE];
    int neighbor_classes[K];

    // Calculate distances from the test point to all training points
    for (int i = 0; i < num_training_samples; i++) {
        distances[i] = Euclidean_Distance(training_data[i], test_features, NUM_FEATURES);
    }

    // Find the K nearest neighbors (simple selection sort for K smallest)
    for (int i = 0; i < K; i++) {
        int min_index = i;
        for (int j = i + 1; j < num_training_samples; j++) {
            if (distances[j] < distances[min_index]) {
                min_index = j;
            }
        }
        // Swap to bring the closest neighbor to the front
        double temp_dist = distances[i];
        distances[i] = distances[min_index];
        distances[min_index] = temp_dist;

        neighbor_classes[i] = training_labels[min_index];
    }

    // Return the majority class
    return Find_Majority_Class(neighbor_classes, K);
}

// Read the sensor values from the data samples and run the KNN to make predictions
// Compare the predicted class made by this model to the predicted class made by the Python model for equivalence check
char Read_Sensor_Values_Run_KNN() {
    unsigned short data_sample;
    char python_predicted_class, c_predicted_class, GPIO;
    double test_features[NUM_FEATURES];

    // Read sensor values from the static data array
    // Process single data sample
        // Load test data features
        for (int i = 0; i < NUM_FEATURES; i++) {
            test_features[i] = Test_Feature_Vector[0][i];
        }

        // Python-predicted class
        python_predicted_class = Golden_Reference_Class_Prediction_Vector[data_sample];

        // Run KNN classifier
        c_predicted_class = KNN_Classifier(test_features, Training_Data, Training_Labels, TRAIN_SIZE);

        if (python_predicted_class != c_predicted_class) {
            GPIO = 0;
            return GPIO;
        } else {
            GPIO = 1;
        }
    }

    return GPIO;
}

int main() {
    correct_result = Read_Sensor_Values_Run_KNN();
    return 0;
}
