import csv
import argparse

#TODO: update these ranges
def quantize_O2(val, quant):
    return int(val / 14.5 * (2**quant - 1))

def quantize_pH(val, quant):
    return int((val) / 14 * (2**quant - 1))

def quantize_TDS(val, quant):
    return int(val / 55600 * (2**quant - 1))

def generate_header(csv_filename, header_filename, quant):
    with open(csv_filename, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        rows = list(csv_reader)

        # Determine quantization datatype
        if quant > 64 or quant < 1:
            print(f"Error: cannot quantize to {quant}")
            return

        var_names = rows[0]

        with open(header_filename, 'w') as header_file:
            header_file.write(f"#define QUANTIZATION {quant}\n")
            header_file.write(f"#define Num_Data_Samples {len(rows)-1}\n")

            min_o2 = quantize_O2(6, quant)
            header_file.write(f"#define O2_MIN {min_o2}\n")
            min_ph = quantize_pH(6.5, quant)
            header_file.write(f"#define PH_MIN {min_ph}\n")
            max_ph = quantize_pH(8.5, quant)
            header_file.write(f"#define PH_MAX {max_ph}\n")
            max_tds = quantize_TDS(600, quant)
            header_file.write(f"#define TDS_MAX {max_tds}\n")

            header_file.write("\n")

            # O2
            header_file.write(f"const volatile long {var_names[0]}_Vector[Num_Data_Samples] = {{\n")
            for i in range(1, len(rows)):
                o2 = quantize_O2(float(rows[i][0]), quant)
                header_file.write(f"  {o2},\n")
            header_file.write("};\n\n")

            # pH
            header_file.write(f"const volatile long {var_names[1]}_Vector[Num_Data_Samples] = {{\n")
            for i in range(1, len(rows)):
                ph = quantize_pH(float(rows[i][1]), quant)
                header_file.write(f"  {ph},\n")
            header_file.write("};\n\n")

            # TDS
            header_file.write(f"const volatile long {var_names[2]}_Vector[Num_Data_Samples] = {{\n")
            for i in range(1, len(rows)):
                tds = quantize_TDS(float(rows[i][2]), quant)
                header_file.write(f"  {tds},\n")
            header_file.write("};\n\n")

            # Reference
            header_file.write(f"const volatile char {var_names[3]}_Vector[Num_Data_Samples] = {{\n")
            for i in range(1, len(rows)):
                ref = rows[i][3]
                header_file.write(f"  {ref},\n")
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

