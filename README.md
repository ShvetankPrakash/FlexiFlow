# Flexibench / Sustainabench

The United Nations’ (UN) 2030 Agenda for Sustainable Development established a shared framework aiming toward peace and prosperity for people and the planet. At its core are 17 Sustainable Development Goals (SDGs)[1], a call to action for all countries to work toward a more environmentally, economically, and socially sustainable future.

Much of the work in ICT today, looks at sustainable computing (i.e., reducing the footprint of computing) [2,3,4]; however there exists a unique opportunity to levarge *computing for sustainability*. In fact, the digital transformation is supposed to enable 20% of the savings outlined in the Paris Accord [5]. But there is currently no systematic framework and benchmark to outline how researchers in computing can work on these goals. This benchmark aims to capture workloads from the SDGs that computing can help address, serving as a call to action and roadmap for computer architects to systematically research. 

Traditional CMOS sillicon design can not be used for these applications due to the high-cost (raw dollars and environmental footprint) and scale at which these item-level applications will exist. For this reason, research on emerging technologies such as flexible electronics that have a ~1000x reduced footprint[6] and ~100x reduced dollar cost[7] is critical to enable these sustainability applications. 

## Table of Contents
- [`FlexiBench` Overview](#flexibench-overview)
- [Installation](#installation)
  - [RISC-V GNU Toolchain](#risc-v-gnu-toolchain)
  - [RISC-V Instruction Set Simulator (`spike`)](#risc-v-instruction-set-simulator-spike)
  - [RTL-level Simulation (Icarus Verilog)](#rtl-level-simulation-icarus-verilog)
  - [`FlexiBits` Implementations](#flexibits-implementations)
- [Instruction-level Simulation](#instruction-level-simulation)
  - [Compiling Benchmarks](#compiling-benchmarks)
  - [`spike` simulation](#spike-simulation)
- [RTL-Level Simulation](#rtl-level-simulation)
  - [Compilation](#compilation)
  - [`vvp` Simulation](#vvp-simulation)
- [`FlexiFlow` Modeling](#flexiflow-modeling)
- [Kernel Ablation Study](#kernel-ablation-study)
- [References](#references)

## `FlexiBench` Overview

The following table provides an overview of the SDG-based benchmarks implemented in this repository:

| Benchmark                                                                          | SDG                                            | Core Computational Kernel   | Example Lifetime (years) | Program Execution Frequency (execs/year) |
|------------------------------------------------------------------------------------|------------------------------------------------|-----------------------------|--------------------------|------------------------------------------|
| [Water Quality Monitoring](src/SDG_06_Clean_Water_and_Sanitation)                  | #6: Clean Water and Sanitation                 | Thresholds                  | single-use               | hours-day                                |
| [Food Spoilage Detection](src/SDG_02_Zero_Hunger)                                  | #2: Zero Hunger                                | Logistic Regression         | 1 week                   | hours-days                               |
| [Arrhythmia Detection](src/SDG_03_Good_Health_and_Well_Being_Arrhythmia_Detection) | #3: Good Health and Well-Being                 | Bloom Filter                | 2 weeks                  | seconds-minutes                          |
| [Package Tracking](src/SDG_09_Industry_Innovation_and_Infrastructure)              | #9: Industry, Innovation and Infrastructure    | MLP                         | 3 weeks                  | minutes-hours                            |
| [Smart Irrigation Control](src/SDG_13_Climate_Action)                              | #13: Climate Action                            | K-Nearest Neighbors         | 6 months                 | days                                     |
| [Cardiotocography](src/SDG_03_Good_Health_and_Well_Being_Cardiotocography)         | #3: Good Health and Well-Being                 | MLP                         | 9 months                 | minutes-hours                            |
| [Gesture Recognition](src/SDG_10_Reduced_Inequality)                               | #10: Reduced Inequality                        | Cosine Similarity           | 2 years                  | sub-second                               |
| [Malodor Classification](src/SDG_12_Responsible_Consumption_and_Production)        | #12: Responsible Consumption and Production    | Decision Tree               | 4 years                  | days                                     |
| [Air Pollution Monitoring](src/SDG_11_Sustainable_Communities_and_Cities)          | #11: Sustainable Communities and Cities        | XGBoost                     | 4 years                  | hours-day                                |
| [Tree Tracking](src/SDG_15_Life_on_Land)                                           | #15: Life on Land                              | Discrete Fourier Transform  | 10 years                 | seconds                                  |
| [HVAC Control](src/SDG_07_Affordable_and_Clean_Energy)                             | #7: Affordable and Clean Energy                | Random Forest               | 20 years                 | minutes-hours                            |

## Installation

### RISC-V GNU Toolchain
1. Install the necessary prerequisites for your operating system. For example, on Debian/Ubuntu:
   ```bash
   sudo apt-get install autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev
   ```
2. Clone the toolchain repository:
   ```bash
   git clone --recursive https://github.com/riscv/riscv-gnu-toolchain
   cd riscv-gnu-toolchain
   ```
3. Configure, build, and install the toolchain:
   ```bash
   ./configure --prefix=/opt/riscv --enable-multilib
   make
   ```
4. Finally, add the toolchain to your `PATH`:
   ```bash
   export PATH="/opt/riscv/bin:$PATH"
   ```

### RISC-V Instruction Set Simulator (`spike`)
1. Install the device-tree-compiler. On Debian/Ubuntu:
   ```bash
   sudo apt-get install device-tree-compiler libboost-regex-dev libboost-system-dev
   ```
2. Clone the `spike` repository:
   ```bash
   git clone https://github.com/riscv-software-src/riscv-isa-sim.git
   ```
3. Build and install `spike`:
   ```bash
   cd riscv-isa-sim
   mkdir build
   cd build
   ../configure
   make
   sudo make install
   ```

### RTL-level Simulation (Icarus Verilog)
1.  Install `iverilog` and `vvp` for cycle-accurate RTL simulation:
    ```bash
    sudo apt-get install iverilog
    ```

### `FlexiBits` Implementations
1. Pull the submodule implementations for SERV, QERV, and HERV:
    ```bash
    git submodule update --init --recursive
    ```

## Instruction-level Simulation

### Compiling Benchmarks
To compile the benchmarks, you can use the provided `Makefile`. First, update the `RV_PREFIX` variable in the `Makefile` to point to your local RISC-V toolchain installation.

You can compile a specific SDG benchmark by running:
```bash
make [SDG_TARGET]
```
For example, to compile the SDG 2 benchmark, run:
```bash
make SDG_02
```

You can also specify the inference mode and data sample number:

| Option            | Values            | Description                                                                              |
| ----------------- | ----------------- | ---------------------------------------------------------------------------------------- |
| `INFERENCE`       | `single`, `multi` | `single` (default) for single-sample executable, `multi` for multi-sample verification,. |
| `DATA_SAMPLE_NUM` | `0-N`             | Specifies the data sample to use for single-inference (default: 0).                      |
| `QUANTIZATION`    | `0-32`            | Specifies the quantization level (limited support, 0 = default quantization).            |

For example, to compile the SDG 2 benchmark for multi-inference with 8-bit quantization, run:
```bash
make SDG_02 INFERENCE=multi QUANTIZATION=8
```

The compiled binaries will be placed in the `build/bin/` directory. The `build/obj/` directory contains the object files, and the `build/src/` directory contains the preprocessed source files.

### `spike` simulation

Instruction-level simulation is performed using `spike`, the RISC-V ISA simulator.

**Running a Benchmark:**

After compiling a workload, you can simulate it with `spike`:
```bash
`spike` -l --isa=rv32e build/bin/[SDG_benchmark_executable]
```
To debug and verify the output, you can find the memory address of the `result` variable using `objdump`:
```bash
riscv32-unknown-elf-objdump -t build/bin/[SDG_benchmark_executable] | grep result
```
This will show the memory location of `result`, for example:
```bash
80000344 g     O .data  00000001 result
```
You can then run `spike` in debug mode to inspect the memory and verify the result:
```bash
spike -d --isa=rv32e build/bin/[SDG_benchmark_executable]
(spike) mem 80000344
(spike) r
(spike) mem 80000344
```
The `result` variable will start as `0xff` (-1) and should match the workload's prediction in `build/src/sample_data.h` after execution.

**Generating Instruction Traces:**

To get the instruction mix of the benchmarks, generate trace files by running:
```bash
make trace
```
This creates a `trace/` directory with trace files for each compiled benchmark. You can then use the provided script to analyze these traces:
```bash
python3 scripts/collect_ins_mix.py
```
The resulting plots will be saved in the `plots/` directory.

## RTL-Level Simulation

### Compilation

To compile a benchmark for RTL simulation, use the `_serv` make targets. This will generate a `.hex` file in the `build/hex` directory. For example:
```bash
make SDG_02_serv DATA_SAMPLE_NUM=0
```

### `vvp` Simulation

In each `FlexiBits` processor directory, compile the `servant_tb.v` benchmark:
```bash
iverilog -o servant_sim.out -y rtl/ -y  servant/ -y serving/ -y servile/ -y bench/ ./bench/servant_tb.v
```

Test the compiled `servant_sim.out` file. Run Hello World Simulation using this command:
```
vvp servant_sim.out  +uart_baudrate=115200 +firmware=sw/hello_uart.hex
```
You will see the following output:
```
Preloading servant_tb.dut.dut.ram from hello_uart.hex
Loading RAM from sw/hello_uart.hex
Hi, I'm Servant!
Test complete
```

Finally, run simulation with generated `FlexiBench` hex files:
```bash
vvp servant_sim.out +firmware=path/to/Flexibench/build/hex/[benchmark].hex
```

## `FlexiFlow` Modeling

The `model/` directory contains Jupyter notebooks for analyzing and modeling the FlexiBench workloads. These notebooks provide a framework for exploring the trade-offs between accuracy, energy consumption, and carbon footprint of different system configurations.

- **`FlexiBenchAnalysis.ipynb`**: Instruction-level and cycle-accurate
  simulation results and analysis of the FlexiBench workloads running on SERV,
  QERV, and HERV.
- **`LifetimeModel.ipynb`**: `FlexiFlow` lifetime-aware modeling for
  carbon-optimal architecture choices across all `FlexiBench` workloads.

## Kernel Ablation Study

The `src/kernel-ablation/` directory provides a case study on the Food Spoilage Detection benchmark, exploring different software kernel implementations and their impact on accuracy and performance. This study demonstrates how `FlexiBench` can be used to evaluate different software and hardware configurations for a given SDG application.

- **Implementations**: The C-code for each kernel implementation can be found in [`src/kernel-ablation/`](src/kernel-ablation/README.md).
- **Building**: The `scripts/gen-hexes-ablation.sh` script can be used to compile the different kernel implementations.
- **Analysis**: The `model/KernelAblation.ipynb` notebook provides a detailed analysis of the trade-offs between the different kernel implementations.

## References
[1] SDGs

[2] Sustainable Computing Ref.

[3] Sustainable Computing Ref.

[4] Sustainable Computing Ref.

[5] World Economic Forum 

[6] Pragmatic Sustainability White Paper

[7] Pragmatic Ref.
