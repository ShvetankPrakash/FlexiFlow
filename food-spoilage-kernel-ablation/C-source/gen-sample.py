import csv
import argparse

def generate_header(csv_filename, header_filename, sample, quant):
    # Default quantization value
    if quant == 0:
        quant = 8

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        if quant != 8:
            print(f"Error: cannot quantize to {quant}")
            return

        data_rows = len(rows) -1

        if sample >= data_rows:
            print(f"Error: sample {sample} out of range")
            return

        var_names = rows[0]
        row = rows[sample+1]

        num_features = len(var_names) - 1
        label_idx = 11

        with open(header_filename, 'w') as header_file:
            header_file.write(f"// Sample {sample}\n")
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write("\n")

            # List of quantization functions to be used on the columns
            names = ["MQ135", "MQ136", "MQ137", "MQ138", "MQ2", "MQ3", "MQ4", "MQ5", "MQ6", "MQ8", "MQ9"]
            
            header_file.write(f"const volatile char Golden_Reference = {row[label_idx]};\n");
            
            for idx, name in enumerate(names):
                header_file.write(f"const volatile unsigned char Testing_{name} = {row[idx]};\n")
            header_file.write("\n")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Generate a C header file from a CSV row.')
    parser.add_argument('data', help='Data CSV')
    parser.add_argument('output_header', help='Output filepath')
    parser.add_argument('sample', type=int, help='Sample index')
    parser.add_argument('quant', type=int, help='Quantization bits')

    args = parser.parse_args()

    data = args.data
    header_filename = f"{args.output_header}/sample_data.h"
    sample = args.sample
    quant = args.quant

    generate_header(data, header_filename, sample, quant)

