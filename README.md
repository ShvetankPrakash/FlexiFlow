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
TODO

### Instruction Mix
TODO

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

# References
[1] SDGs

[2] Sustainable Computing Ref.

[3] Sustainable Computing Ref.

[4] Sustainable Computing Ref.

[5] World Economic Forum 

[6] Pragmatic Sustainability White Paper

[7] Pragmatic Ref.
