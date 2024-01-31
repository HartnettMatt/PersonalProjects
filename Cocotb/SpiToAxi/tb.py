import cocotb
from monitor import *
import random
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge

class SpiToAxiTester:
    def __init__(self, SpiToAxi):
        self.dut =SpiToAxi
        spi_mon_datas = {"MOSI": self.dut.spi_mosi, "MISO": self.dut.spi_miso}
        self.spi_mon = monitor(self.dut.spi_sck, spi_mon_datas, 1 )


    async def spi_write(self, byte):
        for i in range (8):
            await RisingEdge(self.dut.spi_sck)
            self.dut.spi_mosi.value = (byte & 2**i) >> i



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
    write_address = random.randbytes(4)
    dut.spi_ss_n.value = 0
    tester = SpiToAxiTester(dut)
    await tester.spi_write(0)
    for i in range(4):
        await tester.spi_write(write_address[i])

    await Timer(2000, "ns")

