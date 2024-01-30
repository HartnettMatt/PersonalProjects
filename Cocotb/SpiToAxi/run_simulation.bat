wsl.exe --shell-type login -- ./Cocotb/SpiToAxi/run_simulation.sh
gtkwave --script ./Cocotb/SpiToAxi/run_simulation.tcl ./Cocotb/SpiToAxi/dump.vcd >NUL 2>&1