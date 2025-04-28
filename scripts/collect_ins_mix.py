import os
import re
import matplotlib.pyplot as plt
from collections import defaultdict, Counter

# Directory containing the trace files
directory_path = './trace'

# Regular expression patterns for different types of instructions
branches = re.compile(r'\b(beq|bne|blt|bge|bltu|bgeu|bnez|beqz|bltz|bgez)\b')
jumps = re.compile(r'jal|j|jr|ret')
loads = re.compile(r'\b(lb|lh|lw|ld|lbu|lhu|lwu)\b')
stores = re.compile(r'\b(sb|sh|sw|sd|sc.w|sc.d)\b')
i_types = re.compile(r'addi|xori|andi|ori|auipc|li|lui|not')
r_types = re.compile(r'add|sub|xor|and|or|mv|csrr')
shifts_slts = re.compile(r'srai|slli|srli|sra|sll|srl|slt|sltu|slti|sltiu|snez')

name_dir = {
            "SDG_02": "02. Food Spoilage Detection\n(Decision Tree)",
            "SDG_03_arrythmia": "06. Arrhythmia Detection\n(Bloom Filter)",
            "SDG_03_cardiotocography": "08. Cardiotocography\n(Classification MLP)",
            "SDG_06": "04. Water Quality Monitoring\n(Threshold)",
            "SDG_09": "05. Smart HVAC Monitoring\n(Random Forest)",
            "SDG_10": "01. Gesture Recognition\n(Binary Cosine Similarity)",
            "SDG_11": "09. Air Pollution Monitoring\n(Regression MLP)",
            "SDG_12": "03. Odor Detection\n(Decision Tree)",
            "SDG_13": "07. Smart Irrigation\n(KNN)",
            "SDG_15": "10. Animal Tracking\n(Discrete Fourier Transform)"
        }

# Define cycles per instruction type
cycles_per_instruction = {
    'Others': 4+3+4+3,
    'I-types': 4+3,
    'Loads': 4+3+4+3+70,  # Assuming 70 cycle latency for mem read
    'R-types': 4+3,
    'Stores': 4+3+4+3+35,  # Assuming 35 cycle latency for mem write
    'Branches': 4+3+4+3,
    'Shifts and SLTs': 4+3+4+3,
    'Jumps': 4+3
}

# Function to classify instructions
def classify_instruction(instruction):
    if branches.match(instruction):
        return 'Branches'
    elif loads.match(instruction):
        return 'Loads'
    elif stores.match(instruction):
        return 'Stores'
    elif i_types.match(instruction):
    	return 'I-types'
    elif r_types.match(instruction):
    	return 'R-types'
    elif shifts_slts.match(instruction):
    	return 'Shifts and SLTs'
    elif jumps.match(instruction):
        return 'Jumps'
    else:
        return 'Others'

# Parse the spike output file
def parse_spike_output(file_path):
    instruction_counts = defaultdict(int)
    other_instructions = Counter()
    skip = 1
    
    with open(file_path, 'r') as file:
        for line in file:
            if skip: # Skip error message from spike
                skip = 0
                continue
            # Match the instruction mnemonic part of the trace line
            match = re.search(r'\)\s(c\.)?(\S+)', line)
            if match:
                instruction = match.group(2)
                category = classify_instruction(instruction)
                instruction_counts[category] += 1
                if category == 'Others':
                    other_instructions[instruction] += 1
    
    total_instructions = sum(instruction_counts.values())
    
    return instruction_counts, total_instructions, other_instructions

# Plotting function for instruction mix
def plot_instruction_mix(instruction_data, total_instructions_data):
    # Sort workloads by their name
    sorted_workloads = sorted(instruction_data.keys())

    # Define pastel colors
    colors = ['#92c6ff', '#97f0aa', '#f4b400', '#d291bc', '#ff4500', '#764428', '#ff55a3']  # Light blue, green, yellow, pink

    # Create the stacked bar chart
    fig, ax = plt.subplots(figsize=(16, 9))  


    # Initialize the bottom for the stacking
    bottom = [0] * len(sorted_workloads)
    
    for category, color in zip(['Branches', 'Loads', 'Stores', 'I-types', 'R-types', 'Shifts and SLTs', 'Jumps'], colors):
        values = [(instruction_data[workload][category] / total_instructions_data[workload]) * 100 for workload in sorted_workloads]
        bars = ax.bar(sorted_workloads, values, label=category, color=color, bottom=bottom)
        for bar, value in zip(bars, values):
            if value > 0:
                height = bar.get_height()
                ax.text(
                    bar.get_x() + bar.get_width() / 2, 
                    bar.get_y() + height / 2, 
                    f'{value:.1f}%', 
                    ha='center', 
                    va='center',
                    fontsize=12,
                    fontweight='bold'
                )
        bottom = [l + v for l, v in zip(bottom, values)]

    ax.set_ylabel('Percentage')
    ax.set_title('Instruction Mix of Workloads')
    ax.legend(loc='upper right', bbox_to_anchor=(1.15, 1))  # Moves legend outside the plot

    plt.xticks(rotation=45, ha='right')  # Rotates x-axis labels and aligns them to the right
    plt.tight_layout()
    plt.savefig("plots/instruction_mix.png", dpi=300, bbox_inches='tight')  # High resolution and better layout
    plt.show()


# Plotting function for total instructions
def plot_total_instructions(total_instructions_data):
    # Sort workloads by their name
    sorted_workloads = sorted(total_instructions_data.keys())

    # Prepare data for the bar chart
    total_instructions = [total_instructions_data[workload] for workload in sorted_workloads]

    # Plot
    plt.figure(figsize=(14, 7))
    plt.bar(sorted_workloads, total_instructions, color='#add8e6')  # Light blue color
    plt.xlabel('Workload')
    plt.ylabel('Total Instructions (in billions)')
    plt.title('Total Instruction Count of Workloads')
    plt.xticks(rotation=45, ha='right')  # Rotates x-axis labels and aligns them to the right
    plt.tight_layout()
    plt.savefig("plots/total_instructions.png", dpi=300, bbox_inches='tight')  # High resolution and better layout
    plt.show()


# Plotting function to plot the number of cycles per instruction based on the instruction mix counts
# Ins	Cycles
# Others:	50
# I-types:	35
# Loads:	70
# R-types:	35
# Stores:	70
# Branches:	70
# Shifts and SLTs	70
# Plot a stacked bar for each workload where each bar's height is equal to total number of cycles and each segment of the bar should be colored for the cycles attributed each instruction type
def plot_total_cycles_per_instruction(instruction_data, total_instructions_data, log_scale=True, clock_freq=50000):
    # Sort workloads by their name
    sorted_workloads = sorted(instruction_data.keys())

    # Define pastel colors
    colors = ['orange', 'orange', 'orange', 'orange', 'orange', 'orange', 'orange']  # Light blue, green, yellow, pink

    # Create the stacked bar chart
    fig, ax = plt.subplots(figsize=(14, 7))

    # Initialize the bottom for the stacking
    bottom = [0] * len(sorted_workloads)
    
    total_cycles_per_workload = {workload: sum(instruction_data[workload][cat] * cycles_per_instruction[cat] for cat in cycles_per_instruction) for workload in sorted_workloads}

    for category, color in zip(['Branches', 'Loads', 'Stores', 'I-types', 'R-types', 'Shifts and SLTs', 'Jumps'], colors):
        values = [(instruction_data[workload][category] * cycles_per_instruction[category]) for workload in sorted_workloads]
        bars = ax.bar(sorted_workloads, values, label=category, color=color, bottom=bottom)
        bottom = [l + v for l, v in zip(bottom, values)]

    # Label the top of each bar with the total cycles and runtime in seconds
    for i, workload in enumerate(sorted_workloads):
        total_cycles = total_cycles_per_workload[workload]
        runtime_seconds = total_cycles / clock_freq
        ax.text(i, total_cycles + 0.05 * total_cycles, f'{total_cycles:.0f} cycles\n{runtime_seconds:.2f} s', ha='center', va='bottom', fontsize=12, fontweight='bold')

    # Set y-axis to log scale if log_scale is True
    if log_scale:
        ax.set_yscale('log')

    ax.set_ylabel('Total Cycles')
    ax.set_title('Total Cycles Per Instruction of Workloads')
    ax.legend(loc='upper right', bbox_to_anchor=(1.15, 1))  # Moves legend outside the plot

    plt.xticks(rotation=45, ha='right')  # Rotates x-axis labels and aligns them to the right
    plt.tight_layout()
    plt.savefig("plots/total_cycles_per_instruction.png", dpi=300, bbox_inches='tight')  # High resolution and better layout
    plt.show()



# Plotting function to plot the instruction mix based on cycles per instruction and instruction counts
def plot_instruction_mix_by_cycles(instruction_data, total_instructions_data):
    # Sort workloads by their name
    sorted_workloads = sorted(instruction_data.keys())

    # Define pastel colors
    colors = ['#92c6ff', '#97f0aa', '#f4b400', '#d291bc', '#ff4500', '#764428', '#ff55a3']  # Light blue, green, yellow, pink

    # Create the stacked bar chart
    fig, ax = plt.subplots(figsize=(14, 7))

    # Initialize the bottom for the stacking
    bottom = [0] * len(sorted_workloads)
    
    for category, color in zip(['Branches', 'Loads', 'Stores', 'I-types', 'R-types', 'Shifts and SLTs', 'Jumps'], colors):
        values = [(instruction_data[workload][category] * cycles_per_instruction[category]) for workload in sorted_workloads]
        total_cycles_per_workload = [sum(instruction_data[workload][cat] * cycles_per_instruction[cat] for cat in cycles_per_instruction) for workload in sorted_workloads]
        percentage_values = [value / total * 100 if total != 0 else 0 for value, total in zip(values, total_cycles_per_workload)]
        bars = ax.bar(sorted_workloads, percentage_values, label=category, color=color, bottom=bottom)
        for bar, value in zip(bars, percentage_values):
            if value > 0:
                height = bar.get_height()
                ax.text(
                    bar.get_x() + bar.get_width() / 2, 
                    bar.get_y() + height / 2, 
                    f'{value:.1f}%', 
                    ha='center', 
                    va='center',
                    fontsize=12,
                    fontweight='bold'
                )
        bottom = [l + v for l, v in zip(bottom, percentage_values)]

    ax.set_ylabel('Percentage of Cycles')
    ax.set_title('Instruction Mix by Cycles of Workloads')
    ax.legend(loc='upper right', bbox_to_anchor=(1.15, 1))  # Moves legend outside the plot

    plt.xticks(rotation=45, ha='right')  # Rotates x-axis labels and aligns them to the right
    plt.tight_layout()
    plt.savefig("plots/instruction_mix_by_cycles.png", dpi=300, bbox_inches='tight')  # High resolution and better layout
    plt.show()


# Main function to process all trace files and plot the instruction mix
def process_trace_files(directory_path):
    instruction_data = defaultdict(lambda: defaultdict(int))
    total_instructions_data = defaultdict(int)
    all_other_instructions = defaultdict(Counter)

    for filename in os.listdir(directory_path):
        if filename.endswith('.tr'):
            file_path = os.path.join(directory_path, filename)
            workload_name = filename.replace('.tr', '')
            friendly_name = next((v for k, v in name_dir.items() if k in workload_name), workload_name)

            instruction_counts, total_instructions, other_instructions = parse_spike_output(file_path)
            other_instructions_count = sum(other_instructions.values())

            total_instructions_data[friendly_name] = total_instructions
            for category, count in instruction_counts.items():
                instruction_data[friendly_name][category] = count
            all_other_instructions[friendly_name] = other_instructions

            if total_instructions > 0:
                # Print the instruction mix and total number of instructions
                print(f'Workload: {workload_name}')
                print(f'Total Number of Instructions: {total_instructions}')
                print('Instruction Mix:')
                for category, count in instruction_counts.items():
                    print(f'{category}: {100 * count / total_instructions:.2f}%;  count: {count}')
                print(f'Others: {100* other_instructions_count / total_instructions:.2f}%;  count : {other_instructions_count}')
                # print('Unique Instructions in "Others":')
                # for inst, count in other_instructions.items():
                #    print(f'{inst}: {count}')\
                print('______________________')
            else:
                print(f'No instructions found in file: {filename}')

    # Once all files are processed, plot the instruction mix and total instructions
    plot_instruction_mix(instruction_data, total_instructions_data)
    plot_total_instructions(total_instructions_data)
    plot_total_cycles_per_instruction(instruction_data, total_instructions_data)
    plot_instruction_mix_by_cycles(instruction_data, total_instructions_data)

# Run the processing function

os.makedirs("plots", exist_ok=True)
process_trace_files(directory_path)

