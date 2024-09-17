// Custom square root function using the Newton-Raphson method
double custom_sqrt(double num) {
    double guess = num / 2.0;
    double epsilon = 0.00001;
    
    while ((guess * guess - num) > epsilon || (num - guess * guess) > epsilon) {
        guess = (guess + num / guess) / 2.0;
    }
    
    return guess;
}

// Function to calculate Euclidean distance between two points
double euclidean_distance(double *point1, double *point2, int num_features) {
    double sum = 0.0;
    int i;
    for (i = 0; i < num_features; i++) {
        double diff = point1[i] - point2[i];
        sum += diff * diff; // No need for a separate power function
    }
    return custom_sqrt(sum);
}

// Find the majority class among k neighbors
int majority_vote(int *labels, int k) {
    int count[2] = {0, 0}; // Assuming binary classification (0 or 1)
    int i;
    for (i = 0; i < k; i++) {
        count[labels[i]]++;
    }
    return (count[0] > count[1]) ? 0 : 1;
}

// Custom implementation of KNN without standard library functions
int predict_classification(double train_data[][3], int train_size, double *test_point, int k, int num_features) {
    // Static arrays to hold distances and labels
    double distances[1000]; // Adjust the size based on your data
    int labels[1000];
    
    // Calculate distances to each training point
    int i, j;
    for (i = 0; i < train_size; i++) {
        distances[i] = euclidean_distance(train_data[i], test_point, num_features);
        labels[i] = (int)train_data[i][num_features]; // Last column as label
    }
    
    // Simple selection sort to find k nearest neighbors
    for (i = 0; i < train_size - 1; i++) {
        for (j = i + 1; j < train_size; j++) {
            if (distances[i] > distances[j]) {
                // Swap distances
                double temp_dist = distances[i];
                distances[i] = distances[j];
                distances[j] = temp_dist;
                
                // Swap labels accordingly
                int temp_label = labels[i];
                labels[i] = labels[j];
                labels[j] = temp_label;
            }
        }
    }

    // Majority vote to decide the class
    return majority_vote(labels, k);
}

void main() {
    // Example dataset: Columns are [moisture, temp, label]
    double data[5][3] = {
        {40815, 11235, 1},
        {33347, 14979, 1},
        {47445, 22469, 1},
        {51115, 41193, 1},
        {44162, 33704, 1}
    };

    int train_size = 3; // First 3 as training data
    int test_size = 2;  // Remaining 2 as test data
    int k = 3;          // Number of neighbors
    int num_features = 2; // Number of features (moisture, temp)

    // Test data
    double test_data[2][3] = {
        {51115, 41193, 1},
        {44162, 33704, 1}
    };

    // Variables to calculate accuracy
    int correct_predictions = 0;
    int i;
    
    // Make predictions
    for (i = 0; i < test_size; i++) {
        int predicted_class = predict_classification(data, train_size, test_data[i], k, num_features);
        if (predicted_class == (int)test_data[i][num_features]) {
            correct_predictions++;
        }
    }

}
