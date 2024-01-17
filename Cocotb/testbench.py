import cocotb
from cocotb.triggers import Timer

async def reset_dut(reset_n, duration_ns):
    reset_n.value = 0
    await Timer(duration_ns, units="ns")
    reset_n.value = 1
    reset_n._log.info("Reset complete")

async def generate_clock(clk, period):
    for cycle in range(1000):
        clk.value = 0
        await Timer(period/2, units="ns")
        clk.value = 1
        await Timer(period/2, units="ns")
        
@cocotb.test()
async def testbench(dut):
    period = 10 # ns
    # Establish initial values for the input signals
    dut.CP.value = 1
    dut.P.value = 13
    dut.CEP.value = 1
    dut.CET.value = 1
    dut.PE.value = 1
    
    # Tie the SR signal to the reset_n variable then run the blocking subroutine that executes a reset
    reset_n = dut.SR
    await reset_dut(reset_n, 100)
    
    # Run the clock generate thread concurrently to the rest of the program
    clk = dut.CP
    clk_thread = cocotb.start_soon(generate_clock(clk, period))
    
    for control in range(4):
        match control:
            case 0:
                dut.CEP.value = 0
                dut.CET.value = 0
                dut.PE.value = 1
            case 1:
                dut.CEP.value = 1
                dut.CET.value = 1
                dut.PE.value = 1
            case 2:
                dut.CEP.value = 0
                dut.CET.value = 0
                dut.PE.value = 0
            case 3:
                dut.CEP.value = 1
                dut.CET.value = 1
                dut.PE.value = 0

        # Print the internal control signal to check for validity
        dut._log.info("Control is %s", control)
        # Check the output every clock period
        for cycle in range(32):
            match control:
                case 0:
                    assert dut.Q.value == 0
                case 1:
                    assert dut.Q.value == cycle % 16
                case 2:
                    assert dut.Q.value == dut.P.value
                # case 3:
            await Timer(period, units="ns")
