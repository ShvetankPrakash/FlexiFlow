import csv
import argparse

def generate_header(csv_filename, header_filename, quant):
    # Default quantization value
    if quant == 0:
        quant = 8

    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        if quant != 8:
            print(f"Error: cannot quantize to {quant}")
            return

        var_names = rows[0]

        with open(header_filename, 'w') as header_file:
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write(f"#define Num_Data_Samples {len(rows)-1}\n")

            header_file.write("\n")

            # List of quantization functions to be used on the columns
            quant_functions = [None,None,None,None,None,None,None,None,None,None,None,None,None,None,None]
            quant_types = ["char","char","short","char","char","char","char","char","char","char","char","char","char","char","char"]

            # Iterate through all variables, quantize if needed, and write out
            for var in range(len(var_names)):
                header_file.write(f"const volatile {quant_types[var]} {var_names[var]}_Vector[Num_Data_Samples] = {{\n")
                for i in range(1, len(rows)):
                    x = rows[i][var]
                    if quant_functions[var] != None:
                        x = quant_functions[var](x,quant)
                    header_file.write(f"  {x},\n")
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

