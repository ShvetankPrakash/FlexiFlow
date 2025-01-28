##############################################
#   Flexibench / Sustainabench Makefile      #
##############################################
# RISC-V Toolchain and Compiler
RV_PREFIX = /opt/riscv/bin/riscv64-unknown-elf-
CC = $(RV_PREFIX)gcc

# Flags telling GCC to compile to rv32e, without libraries (e.g. baremetal), to use a different memory model so that we can put our code at 0x80000000, to use the specified linker script, and turn on full optimizations.
CCFLAGS = -march=rv32e_zicsr -mabi=ilp32e -nostdlib -mcmodel=medany -Tlink.ld -O3 -fno-builtin

# Python installation
PYTHON = python3

# Source directory
SRC_DIR = src

# Path to write compiled executables and object files
BUILD_DIR = build/
BUILD_BIN_DIR = $(BUILD_DIR)bin
BUILD_OBJ_DIR = $(BUILD_DIR)obj
BUILD_SRC_DIR = $(BUILD_DIR)src

# Default values for INFERENCE (multi or single), DATA_SAMPLE_NUM, and
# QUANTIZATION
INFERENCE ?= single
DATA_SAMPLE_NUM ?= 0
QUANTIZATION ?= 0

# Create the build directories if they don't exist
build_dirs:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_BIN_DIR)
	mkdir -p $(BUILD_OBJ_DIR)
	mkdir -p $(BUILD_SRC_DIR)

# Compile all benchmarks
all: SDG_02 SDG_03 SDG_06 SDG_10 SDG_11 SDG_12 SDG_13 # SDG_09 SDG_14

# Compile each benchmark with inference type and sample number
SDG_02:
	$(MAKE) compile_inference SDG_DIR=SDG_02_Zero_Hunger C_FILE=food_spoilage_detection BIN_FILE=SDG_02_food_spoilage_detection

SDG_03:
	$(MAKE) compile_inference SDG_DIR=SDG_03_Good_Health_and_Well_Being C_FILE=cardiotocography BIN_FILE=SDG_03_cardiotocography

SDG_06:
	$(MAKE) compile_inference SDG_DIR=SDG_06_Clean_Water_and_Sanitation C_FILE=water_quality_monitoring BIN_FILE=SDG_06_water_quality_monitoring

# SDG_09:
# 	$(MAKE) compile_inference SDG_DIR=SDG_09_Industry_Innovation_and_Infrastructure C_FILE=hvac BIN_FILE=SDG_09_hvac

SDG_10:
	$(MAKE) compile_inference SDG_DIR=SDG_10_Reduced_Inequality C_FILE=muscle BIN_FILE=SDG_10_muscle

SDG_11:
	$(MAKE) compile_inference SDG_DIR=SDG_11_Sustainable_Communities_and_Cities C_FILE=air_pollution_monitoring BIN_FILE=SDG_11_air_pollution_monitoring

SDG_12:
	$(MAKE) compile_inference SDG_DIR=SDG_12_Responsible_Consumption_and_Production C_FILE=odor_detection BIN_FILE=SDG_12_odor_detection

SDG_13:
	$(MAKE) compile_inference SDG_DIR=SDG_13_Climate_Action C_FILE=irrigation BIN_FILE=SDG_13_irrigation

# SDG_14:
# 	$(MAKE) compile_inference SDG_DIR=SDG_14_Life_Below_Water C_FILE=animal_tracking BIN_FILE=SDG_14_animal_tracking

# Rule to handle multi-inference and single-inference compilation
compile_inference: build_dirs
	cp $(SRC_DIR)/$(SDG_DIR)/$(INFERENCE)_inference/$(C_FILE).c $(BUILD_SRC_DIR)/
	@if find "$(SRC_DIR)/$(SDG_DIR)/$(INFERENCE)_inference/" -type f -name "*.h" | grep -q .; then \
		cp $(SRC_DIR)/$(SDG_DIR)/$(INFERENCE)_inference/*.h $(BUILD_SRC_DIR)/ ; \
		echo "cp $(SRC_DIR)/$(SDG_DIR)/$(INFERENCE)_inference/*.h $(BUILD_SRC_DIR)/"; \
	fi 
	cp $(SRC_DIR)/asm/init.s $(BUILD_SRC_DIR)/
	@if [ "$(INFERENCE)" = "multi" ]; then \
		if [ -e "$(SRC_DIR)/$(SDG_DIR)/samples.csv" ]; then \
			$(PYTHON) $(SRC_DIR)/$(SDG_DIR)/multi_inference/gen-multi-sample.py $(SRC_DIR)/$(SDG_DIR)/samples.csv $(BUILD_SRC_DIR)/ $(QUANTIZATION); \
		fi ; \
		$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/init.s -o $(BUILD_OBJ_DIR)/init.o; \
		$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/$(C_FILE).c -o $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o; \
		$(CC) $(CCFLAGS) -o $(BUILD_BIN_DIR)/$(BIN_FILE)_multi_inference $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o $(BUILD_OBJ_DIR)/init.o; \
	elif [ "$(INFERENCE)" = "single" ]; then \
		if [ -e "$(SRC_DIR)/$(SDG_DIR)/samples.csv" ]; then \
			$(PYTHON) $(SRC_DIR)/$(SDG_DIR)/single_inference/gen-sample.py $(SRC_DIR)/$(SDG_DIR)/samples.csv $(BUILD_SRC_DIR)/ $(DATA_SAMPLE_NUM) $(QUANTIZATION); \
		fi ; \
		$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/init.s -o $(BUILD_OBJ_DIR)/init.o; \
		$(CC) $(CCFLAGS) -c $(BUILD_SRC_DIR)/$(C_FILE).c -o $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o; \
		$(CC) $(CCFLAGS) -o $(BUILD_BIN_DIR)/$(BIN_FILE)_single_inference_sample_$(DATA_SAMPLE_NUM) $(BUILD_OBJ_DIR)/$(notdir $(C_FILE)).o $(BUILD_OBJ_DIR)/init.o; \
	fi
clean:
	rm -rf $(BUILD_DIR)
