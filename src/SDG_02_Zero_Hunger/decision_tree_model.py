
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, export_text
from sklearn.metrics import accuracy_score, classification_report

# Load the dataset
file_path = '用这个Dataset.csv'  # Ensure the dataset is in the same directory as this script
df = pd.read_csv(file_path)

# Convert the 'Fruit' column into separate binary columns using one-hot encoding
df_encoded = pd.get_dummies(df, columns=['Fruit'], prefix='Fruit')

# Convert 'Spoiled' column from Yes/No to 1/0
df_encoded['Spoiled'] = df_encoded['Spoiled'].map({'Yes': 1, 'No': 0})

# Normalize the columns Temp, Humidity, CO2, and Days to the range [0, 2^8 - 1] which is [0, 255]
columns_to_normalize = ['Temp', 'Humidity', 'CO2', 'Days']
max_value = 2**8 - 1  # 255

# Normalize each column
for column in columns_to_normalize:
    min_col = df_encoded[column].min()
    max_col = df_encoded[column].max()
    df_encoded[column] = ((df_encoded[column] - min_col) / (max_col - min_col)) * max_value
    df_encoded[column] = df_encoded[column].round().astype(int)  # Round and convert to integer

# Prepare the dataset for training
X = df_encoded.drop(columns=['Unnamed: 0', 'Spoiled'])  # Features
y = df_encoded['Spoiled']  # Target

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Initialize the Decision Tree Classifier
clf = DecisionTreeClassifier(random_state=42)

# Train the model
clf.fit(X_train, y_train)

# Make predictions on the test set
y_pred = clf.predict(X_test)

# Calculate accuracy and display classification report
accuracy = accuracy_score(y_test, y_pred)
report = classification_report(y_test, y_pred)

# Display the decision tree structure
tree_structure = export_text(clf, feature_names=list(X.columns))
print("Accuracy:", accuracy)
print("\nClassification Report:\n", report)
print("\nDecision Tree Structure:\n", tree_structure)
