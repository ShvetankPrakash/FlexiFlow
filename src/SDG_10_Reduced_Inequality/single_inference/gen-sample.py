import csv
import argparse

def generate_header(csv_filename, header_filename, sample):
    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        if sample >= len(rows):
            print(f"Error: sample {sample} out of range")
            return

        row = rows[sample]

        with open(header_filename, 'w') as header_file:
            header_file.write("#include \"static_data.h\"\n\n")
            header_file.write("const volatile int Ngram_Array[VECTOR_SIZE] = { ")

            # Write the row values, separated by commas
            header_file.write(", ".join(row))

            header_file.write(" };")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Generate a C header file from a CSV row.')
    parser.add_argument('data', help='Data CSV')
    parser.add_argument('output_header', help='Output filepath')
    parser.add_argument('sample', type=int, help='Sample index')

    args = parser.parse_args()

    data = args.data
    header_filename = f"{args.output_header}/sample_data.h"
    sample = args.sample

    generate_header(data, header_filename, sample)
