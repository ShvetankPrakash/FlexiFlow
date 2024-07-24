# Flexibench / Sustainabench

The United Nations’ (UN) 2030 Agenda for Sustainable Development established a shared framework aiming toward peace and prosperity for people and the planet. At its core are 17 Sustainable Development Goals (SDGs)[1], a call to action for all countries to work toward a more environmentally, economically, and socially sustainable future.

Much of the work in ICT today, looks at sustainable computing (i.e., reducing the footprint of computing) [2,3,4]; however there exists a unique opportunity to levarge *computing for sustainability*. In fact, the digital transformation is supposed to enable 20% of the savings outlined in the Paris Accord [5]. But there is currently no systematic framework and benchmark to outline how researchers in computing can work on these goals. This benchmark aims to capture workloads from the SDGs that computing can help address, serving as a call to action and roadmap for computer architects to systematically research. 

Traditional CMOS sillicon design can not be used for these applications due to the high-cost (raw dollars and environmental footprint) and scale at which these item-level applications will exist. For this reason, research on emerging technologies such as flexible electronics that have a ~1000x reduced footprint[6] and ~100x reduced dollar cost[7] is critical to enable these sustainability applications. 

# Installation

### RISC-V GNU Toolchain
TODO: Point them to Multilib install

### RISC-V Instruction Set Simulator (Spike)
TODO: Point them to install Spike without PK 

# Compiling Benchmarks
TODO: Write about how to use Makefile for build
- Update path to local RISCV toolchain
- Explain `make [SDG_NUM] INFERENCE=multi` vs `make [SDG_NUM] INFERENCE=single DATA_SAMPLE_NUM=0 QUANTIZATION=8`
- Explain `/build` dirs: `bin/`, `obj/`, `src/`

# Running Benchmarks

### Using Spike
After compiling the workload(s) you can use spike to simulate:
```bash
spike -l --isa=rv32e build/bin/[SDG_benchmark_executable]
```
To debug and verify the output result of the program, find the memory address of `correct_result` using objdump:
```bash
riscv64-unknown-elf-objdump -t build/bin/[SDG_benchmark_executable] | grep correct_result
```
You will see an output similar to this with the location of `correct_result` in memory:
```bash
80000344 g     O .data  00000001 correct_result
```
Then run the simulator in debug mode:
```bash
spike -d --isa=rv32e build/bin/[SDG_benchmark_executable]
```
and check the value of `correct_result` before and after running the program to verify correct execution (`correct_result` will always start as 0xff and end as 0x01 if run correctly):
```bash
(spike) mem 80000344
(spike) r
(spike) mem 80000344
```

# Profiling Benchmarks
TODO

### Instruction Mix
TODO

### Latency
TODO

# References
[1] SDGs

[2] Sustainable Computing Ref.

[3] Sustainable Computing Ref.

[4] Sustainable Computing Ref.

[5] World Economic Forum 

[6] Pragmatic Sustainability White Paper

[7] Pragmatic Ref.
