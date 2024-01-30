import cocotb
import monitor
import random
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge


async def reset_dut(reset_n, duration_ns):
    reset_n.value = 0
    await Timer(duration_ns, units="ns")
    reset_n.value = 1
    reset_n._log.info("Reset complete")


async def generate_clock(clk, period):
    for cycle in range(1000):
        clk.value = 0
        await Timer(period / 2, units="ns")
        clk.value = 1
        await Timer(period / 2, units="ns")


async def reset(dut):
    spi_period = 40  # 25 Mhz
    axi_period = 10  # 100 Mhz

    # Establish initial values for the input signals
    dut.spi_sck.value = 0
    dut.spi_ss_n.value = 1
    dut.spi_mosi.value = 0

    dut.axi_aclk.value = 0
    dut.axi_aresetn.value = 0

    dut.s_axi_awready.value = 0
    dut.s_axi_wready.value = 0
    dut.s_axi_arready.value = 0

    dut.s_axi_rdata.value = 0
    dut.s_axi_rresp.value = 0
    dut.s_axi_rvalid.value = 0

    dut.s_axi_bready.value = 0

    # Run the clock generate threads concurrently to the rest of the program
    axi_clk_thread = cocotb.start_soon(generate_clock(dut.spi_sck, spi_period))
    spi_clk_thread = cocotb.start_soon(generate_clock(dut.axi_aclk, axi_period))

    # Reset the axi bus for 100 ns
    axi_resetn = dut.axi_aresetn
    await reset_dut(axi_resetn, 100)
    await Timer(10, "ns")

@cocotb.test()
async def write(dut):
    await reset(dut)
    await Timer(20, "ns")
    write_address = random.getrandbits(32)
    for cycle in range(32):
        await RisingEdge(dut.spi_sck)
        dut.spi_mosi.value = (write_address & 2**cycle) >> cycle

    await Timer(2000, "ns")

