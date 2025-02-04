import csv
import argparse

def generate_header(csv_filename, header_filename, quant):
    # Default quantization value
    if quant == 0:
        quant = 16

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        # Check quantization
        if quant != 16:
            print(f"Error: cannot quantize to {quant}")
            return

        var_names = rows[0]  # Column names

        # Open header file for writing
        with open(header_filename, 'w') as header_file:
            header_file.write(f"#define QUANTIZATION {quant}\n\n")
            header_file.write(f"#define Num_Data_Samples {len(rows)-1}\n")
            header_file.write(f"#define Num_Features {len(var_names)-1}\n")
            header_file.write("\n")

            header_file.write("const volatile unsigned short Features_Vector[Num_Data_Samples][Num_Features] = {\n")
            for i in range(1, len(rows)):
                header_file.write("  {")
                for var in range(len(var_names)-1): # Don't include golden reference
                    x = rows[i][var]
                    header_file.write(f"{x},")
                header_file.write("},\n")
            header_file.write("};\n\n")

            ref_idx = len(var_names) - 1
            header_file.write("const char Golden_Reference_Occupancy_Vector[Num_Data_Samples] = {\n")
            for i in range(1,len(rows)):
                header_file.write(f"  {rows[i][ref_idx]},\n")
            header_file.write("};\n\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Generate a C header file from a CSV row.')
    parser.add_argument('data', help='Data CSV')
    parser.add_argument('output_header', help='Output filepath')
    parser.add_argument('quant', type=int, help='Quantization bits')

    args = parser.parse_args()

    data = args.data
    header_filename = f"{args.output_header}/sample_data.h"
    quant = args.quant

    generate_header(data, header_filename, quant)
