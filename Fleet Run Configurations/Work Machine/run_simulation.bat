wsl.exe --shell-type login -- ./run_simulation.sh
@ECHO OFF
gtkwave --script ./run_simulation.tcl ./cocotb/tb.vcd >NUL 2>&1