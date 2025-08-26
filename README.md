# Flexibench / Sustainabench

The United Nations’ (UN) 2030 Agenda for Sustainable Development established a shared framework aiming toward peace and prosperity for people and the planet. At its core are 17 Sustainable Development Goals (SDGs)[1], a call to action for all countries to work toward a more environmentally, economically, and socially sustainable future.

Much of the work in ICT today, looks at sustainable computing (i.e., reducing the footprint of computing) [2,3,4]; however there exists a unique opportunity to levarge *computing for sustainability*. In fact, the digital transformation is supposed to enable 20% of the savings outlined in the Paris Accord [5]. But there is currently no systematic framework and benchmark to outline how researchers in computing can work on these goals. This benchmark aims to capture workloads from the SDGs that computing can help address, serving as a call to action and roadmap for computer architects to systematically research. 

Traditional CMOS sillicon design can not be used for these applications due to the high-cost (raw dollars and environmental footprint) and scale at which these item-level applications will exist. For this reason, research on emerging technologies such as flexible electronics that have a ~1000x reduced footprint[6] and ~100x reduced dollar cost[7] is critical to enable these sustainability applications. 

# Installation

### RISC-V GNU Toolchain
This project requires a RISC-V GNU toolchain with multilib support. You can build it from source by following these steps:
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

### RISC-V Instruction Set Simulator (Spike)
This project uses Spike for simulating the compiled benchmarks. To install Spike without the proxy kernel (pk), follow these steps:
1. Install the device-tree-compiler. On Debian/Ubuntu:
   ```bash
   sudo apt-get install device-tree-compiler libboost-regex-dev libboost-system-dev
   ```
2. Clone the Spike repository:
   ```bash
   git clone https://github.com/riscv-software-src/riscv-isa-sim.git
   ```
3. Build and install Spike:
   ```bash
   cd riscv-isa-sim
   mkdir build
   cd build
   ../configure
   make
   sudo make install
   ```

# Compiling Benchmarks
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

| Option            | Values            | Description                                                                  |
| ----------------- | ----------------- | ---------------------------------------------------------------------------- |
| `INFERENCE`       | `multi`, `single` | `multi` compiles for multi-inference, `single` for single-inference (default). |
| `DATA_SAMPLE_NUM` | `0-N`             | Specifies the data sample to use (default: 0).                               |
| `QUANTIZATION`    | `8`, `16`, `32`   | Specifies the quantization level (default: 0, no quantization).              |

For example, to compile the SDG 2 benchmark for multi-inference with 8-bit quantization, run:
```bash
make SDG_02 INFERENCE=multi QUANTIZATION=8
```

The compiled binaries will be placed in the `build/bin/` directory. The `build/obj/` directory contains the object files, and the `build/src/` directory contains the preprocessed source files.

# Running Benchmarks

### Using Spike
After compiling the workload(s) you can use spike to simulate:
```bash
spike -l --isa=rv32e build/bin/[SDG_benchmark_executable]
```
To debug and verify the output result of the program, find the memory address of `result` using objdump:
```bash
riscv64-unknown-elf-objdump -t build/bin/[SDG_benchmark_executable] | grep result
```
You will see an output similar to this with the location of `result` in memory:
```bash
80000344 g     O .data  00000001 result
```
Then run the simulator in debug mode:
```bash
spike -d --isa=rv32e build/bin/[SDG_benchmark_executable]
```
and check the value of `result` before and after running the program to verify correct execution:
```bash
(spike) mem 80000344
(spike) r
(spike) mem 80000344
```
`result` will always start as 0xff (i.e., -1) and end as the workload's prediction listed in `build/src/sample_data.h` if run correctly.

# Profiling Benchmarks

### Instruction Mix
To get the instruction mix of the benchmarks, you first need to generate trace files. You can do this by running:
```bash
make trace
```
This will create a `trace/` directory containing the trace files for each compiled benchmark.

Then, you can use the `scripts/collect_ins_mix.py` script to analyze the trace files and generate plots of the instruction mix:
```bash
python3 scripts/collect_ins_mix.py
```
The plots will be saved in the `plots/` directory.

### Latency on Bit-Serial Cores (Serv, Qerv, Herv, Nerv)
1. Install iverilog and vvp for cycle accurate RTL simulation
2. Clone [Serv Repository](https://github.com/olofk/serv)
3. `cd serv/`
4. Compile testbench using this command:
   ```
   iverilog -o servant_sim.out -y rtl/ -y  servant/ -y serving/ -y servile/ -y bench/ ./bench/servant_tb.v
   ```
5. Run Hello World Simulation using this command:
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

# Benchmark Overview

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

# FlexiFlow Modeling

The `model/` directory contains Jupyter notebooks for analyzing and modeling the FlexiBench workloads. These notebooks provide a framework for exploring the trade-offs between accuracy, energy consumption, and carbon footprint of different system configurations.

- **`FlexiBenchAnalysis.ipynb`**: This notebook provides a general analysis of the FlexiBench workloads, including instruction mix, memory usage, and execution time.
- **`KernelAblation.ipynb`**: This notebook performs a kernel ablation study, analyzing the impact of different kernels on the overall performance and energy consumption of the workloads.
- **`LifetimeModel.ipynb`**: This notebook presents a lifetime model for flexible electronic devices, considering the trade-offs between device lifetime, task frequency, and carbon footprint.

# References
[1] SDGs

[2] Sustainable Computing Ref.

[3] Sustainable Computing Ref.

[4] Sustainable Computing Ref.

[5] World Economic Forum 

[6] Pragmatic Sustainability White Paper

[7] Pragmatic Ref.
