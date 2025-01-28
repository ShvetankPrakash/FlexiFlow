import re
import csv

# Define the file names
file_names = [f"data_{i}.h" for i in range(5)]
output_csv = "parsed_data.csv"

# Function to extract array data from the file
def parse_h_file(file_name):
    with open(file_name, "r") as file:
        content = file.read()
        # Match the array initialization inside curly braces
        match = re.search(r"\{([^}]*)\}", content)
        if match:
            array_data = match.group(1)
            # Split the values by comma and strip whitespace
            values = [value.strip() for value in array_data.split(",")]
            return values
        else:
            raise ValueError(f"No array data found in {file_name}")

# Parse all files and store the data in a list
parsed_data = []

for file_name in file_names:
    print(f"Parsing {file_name}...")
    parsed_data.append(parse_h_file(file_name))

# Ensure all rows have the same number of columns
for row in parsed_data:
    if len(row) != 10000:
        raise ValueError("Mismatch in VECTOR_SIZE. All rows must have 10000 values.")

# Write the parsed data into a CSV file
with open(output_csv, "w", newline="") as csv_file:
    writer = csv.writer(csv_file)
    writer.writerows(parsed_data)

print(f"Data has been successfully written to {output_csv}.")