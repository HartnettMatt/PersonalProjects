# Makefile

# defaults
SIM ?= verilator
TOPLEVEL_LANG ?= systemverilog

VERILOG_SOURCES += $(PWD)/spi2axi.sv
# use VHDL_SOURCES for VHDL files

# TOPLEVEL is the name of the toplevel module in your Verilog or VHDL file
TOPLEVEL = spi2axi

# MODULE is the basename of the Python test file
MODULE = tb

# include cocotb's make rules to take care of the simulator setup
include $(shell cocotb-config --makefiles)/Makefile.sim