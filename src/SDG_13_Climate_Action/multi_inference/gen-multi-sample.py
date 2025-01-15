import csv
import argparse

def quantize_moisture(val, quant):
    return int((float(val) - 4) / 1018 * (2**quant - 1))

def quantize_temp(val, quant):
    return int((float(val) - 10) / 35 * (2**quant - 1))

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

        training_rows = int((len(rows) - 1) * 0.8)
        data_rows = len(rows) - 1 - training_rows

        with open(header_filename, 'w') as header_file:
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write(f"#define Num_Training_Samples {training_rows}\n")
            header_file.write(f"#define Num_Data_Samples {data_rows}\n")
            header_file.write("#define Num_Features 2")

            header_file.write("\n")

            # List of quantization functions to be used on the columns
            quant_functions = [quantize_moisture,quantize_temp,None]

            # Iterate through all variables, quantize if needed, and write out
            header_file.write("const volatile short Data_Vector[Num_Data_Samples][Num_Features+1] = {\n")
            for i in range(training_rows+1, len(rows)):
                header_file.write("  {")
                for var in range(len(var_names)):
                    x = rows[i][var]
                    if quant_functions[var] != None:
                        x = quant_functions[var](x,quant)
                    header_file.write(f"{x},")
                header_file.write("},\n")
            header_file.write("};\n\n")

            header_file.write("const volatile short Training_Vector[Num_Training_Samples][Num_Features+1] = {\n")
            for i in range(1, training_rows+1):
                header_file.write("  {")
                for var in range(len(var_names)):
                    x = rows[i][var]
                    if quant_functions[var] != None:
                        x = quant_functions[var](x,quant)
                    header_file.write(f"{x},")
                header_file.write("},\n")
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

