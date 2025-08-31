# Flexibench / Sustainabench

The United Nations’ (UN) 2030 Agenda for Sustainable Development established a shared framework aiming toward peace and prosperity for people and the planet. At its core are 17 Sustainable Development Goals (SDGs)[1], a call to action for all countries to work toward a more environmentally, economically, and socially sustainable future.

Much of the work in ICT today, looks at sustainable computing (i.e., reducing the footprint of computing) [2,3,4]; however there exists a unique opportunity to levarge *computing for sustainability*. In fact, the digital transformation is supposed to enable 20% of the savings outlined in the Paris Accord [5]. But there is currently no systematic framework and benchmark to outline how researchers in computing can work on these goals. This benchmark aims to capture workloads from the SDGs that computing can help address, serving as a call to action and roadmap for computer architects to systematically research. 

Traditional CMOS sillicon design can not be used for these applications due to the high-cost (raw dollars and environmental footprint) and scale at which these item-level applications will exist. For this reason, research on emerging technologies such as flexible electronics that have a ~1000x reduced footprint[6] and ~100x reduced dollar cost[7] is critical to enable these sustainability applications. 

## Table of Contents
- [Installation](#installation)
  - [RISC-V GNU Toolchain](#risc-v-gnu-toolchain)
  - [RISC-V Instruction Set Simulator (`spike`)](#risc-v-instruction-set-simulator-spike)
  - [RTL-level Simulation (Icarus Verilog)](#rtl-level-simulation-icarus-verilog)
  - [`FlexiBits` Implementations](#flexibits-implementations)
- [Workflows](#workflows)
- [`FlexiBench` Benchmarks](#flexibench-benchmarks)
- [`FlexiFlow` Modeling](#flexiflow-modeling)
- [References](#references)

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

## Workflows

The core simulation and analysis workflows are located in the [`workflows/`](./workflows) directory. Please refer to the [`workflows/README.md`](./workflows/README.md) for detailed instructions on the following:

- **Instruction-level Workflow**: For compiling benchmarks and running them on the `spike` ISA simulator to generate instruction traces for analysis.
- **Cycle-level Workflow**: For running cycle-accurate RTL-level simulations using Icarus Verilog.
- **Kernel Ablation Workflow**: A case study on the Food Spoilage Detection benchmark to explore trade-offs between different software kernel implementations.

## `FlexiBench` Benchmarks

The FlexiBench benchmarks are described in detail in the
[`flexibench/README.md`](./flexibench/README.md) file.

## `FlexiFlow` Modeling

Our final `FlexiFlow` model is presented in
[`flexiflow/LifetimeModel.ipynb`](./flexiflow/LifetimeModel.ipynb). This
notebook provides the framework for exploring the trade-offs between embodied
and operational carbon footprint based on workload lifetime.

## References
[1] SDGs

[2] Sustainable Computing Ref.

[3] Sustainable Computing Ref.

[4] Sustainable Computing Ref.

[5] World Economic Forum 

[6] Pragmatic Sustainability White Paper

[7] Pragmatic Ref.
