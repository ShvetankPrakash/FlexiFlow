import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import r2_score
import numpy as np

# Load the CSV data
data = pd.read_csv('data.csv')

# Multiply the last three columns by 10 to convert them to integers
data['TEMP'] = (data['TEMP'] * 10).astype(int)
data['PRES'] = (data['PRES'] * 10).astype(int)
data['DEWP'] = (data['DEWP'] * 10).astype(int)

# Select features and target variable
features = ['SO2', 'NO2', 'CO', 'O3', 'TEMP', 'PRES', 'DEWP']
target = 'PM2.5'

X = data[features]
y = data[target]

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Initialize the Random Forest Regressor
rf = RandomForestRegressor(n_estimators=100, random_state=42)

# Train the model
rf.fit(X_train, y_train)

# Get feature importances
feature_importances = rf.feature_importances_
print("Feature Importances:")
for feature, importance in zip(features, feature_importances):
    print(f"{feature}: {importance}")

# Function to handle 'inf' values
def handle_inf(value):
    if np.isinf(value):
        return 1e6  # Replace 'inf' with a large number
    return value

# Write feature importances and input data to a .h file
with open('random_forest_data.h', 'w') as file:
    file.write('#define Num_Data_Samples 20\n')
    file.write('const int16_t inference_data[Num_Data_Samples][7] = {\n')
    inference_data = [
        [21, 115, 1600, 14, 52, 10037, -2],
        [22, 122, 1700, 6, 48, 10044, 0],
        [19, 128, 1899, 2, 47, 10055, 1],
        [18, 122, 1899, 2, 41, 10068, 1],
        [18, 115, 1700, 2, 34, 10076, -1],
        [18, 101, 1600, 3, 17, 10087, -1],
        [20, 95, 1399, 2, 11, 10095, -4],
        [30, 87, 1200, 2, 24, 10101, -53],
        [24, 95, 1200, 14, 44, 10107, -113],
        [24, 51, 900, 32, 40, 10116, -116],
        [12, 43, 500, 36, 27, 10129, -84],
        [18, 68, 700, 14, 58, 10139, -78],
        [24, 66, 600, 19, 76, 10148, -93],
        [28, 94, 600, 38, 86, 10148, -99],
        [27, 93, 600, 43, 81, 10144, -41],
        [27, 91, 700, 48, 87, 10137, -56],
        [51, 57, 1200, 39, 92, 10125, -37],
        [41, 48, 1000, 48, 98, 10119, -13],
        [31, 52, 1200, 56, 100, 10111, -20],
        [31, 47, 1100, 64, 96, 10106, -21]
    ]
    for i, row in enumerate(inference_data):
        row_str = ','.join(map(str, row))
        file.write(f'    {{{row_str}}}')
        if i < len(inference_data) - 1:
            file.write(',\n')
        else:
            file.write('\n')
    file.write('};\n')

    # Write feature importances
    file.write('\nconst float feature_importances[7] = {\n')
    importance_str = ', '.join(map(str, feature_importances))
    file.write(f'    {importance_str}\n')
    file.write('};\n')

    # Extract and write the model's tree information
    for i, tree in enumerate(rf.estimators_):
        file.write(f'\n// Tree {i+1} structure\n')
        tree_ = tree.tree_
        file.write(f'const int tree_{i+1}_feature[{tree_.node_count}] = {{\n')
        features_str = ', '.join(map(str, tree_.feature))
        file.write(features_str)
        file.write('\n};\n')
        
        file.write(f'const float tree_{i+1}_threshold[{tree_.node_count}] = {{\n')
        thresholds_str = ', '.join(map(lambda x: str(handle_inf(x)), tree_.threshold))
        file.write(thresholds_str)
        file.write('\n};\n')
        
        file.write(f'const int tree_{i+1}_children_left[{tree_.node_count}] = {{\n')
        children_left_str = ', '.join(map(str, tree_.children_left))
        file.write(children_left_str)
        file.write('\n};\n')
        
        file.write(f'const int tree_{i+1}_children_right[{tree_.node_count}] = {{\n')
        children_right_str = ', '.join(map(str, tree_.children_right))
        file.write(children_right_str)
        file.write('\n};\n')
        
        file.write(f'const float tree_{i+1}_value[{tree_.node_count}] = {{\n')
        values = [handle_inf(v[0][0]) for v in tree_.value]
        values_str = ', '.join(map(str, values))
        file.write(values_str)
        file.write('\n};\n')

# Provided data for inference
inference_df = pd.DataFrame(inference_data, columns=features)
predicted_pm25_inference = rf.predict(inference_df)
predicted_pm25_inference = np.round(predicted_pm25_inference).astype(int)

for i, pred in enumerate(predicted_pm25_inference):
    print(f'Inference {i + 1} - Predicted PM2.5: {pred}')

# Calculate and print the accuracy metric
y_test_pred = rf.predict(X_test)
r2 = r2_score(y_test, y_test_pred)
print(f'R² (Accuracy): {r2 * 100:.2f}%')