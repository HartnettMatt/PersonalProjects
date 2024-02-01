import cocotb
from monitor import *
import random
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge


class SpiToAxiTester:
    # Create monitors, define clock speeds,
    def __init__(self, SpiToAxi):
        self.dut = SpiToAxi
        self.spi_mon_datas = {"MOSI": self.dut.spi_mosi,
                              "MISO": self.dut.spi_miso,
                              "CS_n": self.dut.spi_ss_n
                              }
        self.spi_mon = monitor(self.dut.spi_sck, self.spi_mon_datas, self.dut.spi_ss_n, 0)
        self.axi_aw_mon_datas = {"Reset_n": self.dut.axi_aresetn,
                                 "Address": self.dut.s_axi_awaddr,
                                 "Address Valid": self.dut.s_axi_awvalid,
                                 "Address Ready": self.dut.s_axi_awready
                                 }
        self.axi_aw_mon = monitor(self.dut.axi_aclk, self.axi_aw_mon_datas, self.dut.s_axi_awvalid)
        self.axi_wr_mon_datas = {"Reset_n": self.dut.axi_aresetn,
                                 "Data": self.dut.s_axi_wdata,
                                 "Strobe": self.dut.s_axi_wstrb,
                                 "Data Valid": self.dut.s_axi_wvalid,
                                 "Data Ready": self.dut.s_axi_wready
                                 }
        self.axi_wr_mon = monitor(self.dut.axi_aclk, self.axi_wr_mon_datas, self.dut.s_axi_wvalid)
        self.spi_period = 400  # 25 Mhz
        self.axi_period = 10  # 100 Mhz
        self.axi_clk_thread = None  # Empty clock coroutine handler

    # Establish initial values for the input signals
    def _init_values(self):
        self.dut.spi_sck.value = 0
        self.dut.spi_ss_n.value = 1
        self.dut.spi_mosi.value = 0

        self.dut.axi_aclk.value = 0
        self.dut.axi_aresetn.value = 0

        self.dut.s_axi_awready.value = 0
        self.dut.s_axi_wready.value = 0
        self.dut.s_axi_arready.value = 0

        self.dut.s_axi_rdata.value = 0
        self.dut.s_axi_rresp.value = 0
        self.dut.s_axi_rvalid.value = 0

        self.dut.s_axi_bready.value = 0

    # Start Monitors, initialize values to safe state, start AXI clock
    def start(self):
        # Starts monitors
        self.spi_mon.start()
        self.axi_aw_mon.start()
        self.axi_wr_mon.start()
        self._init_values()
        self.axi_clk_thread = cocotb.start_soon(generate_clock(self.dut.axi_aclk, self.axi_period))

    # Write a single byte onto the SPI bus
    async def spi_write(self, byte):
        self.dut.spi_ss_n.value = 0
        spi_clk_thread = cocotb.start_soon(generate_clock(self.dut.spi_sck, self.spi_period))
        for i in range(7, -1, -1):
            await RisingEdge(self.dut.spi_sck)
            self.dut.spi_mosi.value = (byte & 2 ** i) >> i
        await RisingEdge(self.dut.spi_sck)
        spi_clk_thread.cancel()
        self.dut.spi_ss_n.value = 1
        self.dut.spi_sck.value = 0
        self.dut.spi_mosi.value = 0

    # Reset the axi bus for a given duration
    async def axi_reset(self, duration):
        # Reset the axi bus for 100 ns
        axi_resetn = self.dut.axi_aresetn
        await reset_signal(axi_resetn, duration)

    # AXI respond
    async def axi_respond(self, response="OKAY"):
        while True:
            await RisingEdge(self.dut.axi_aclk)
            if (self.dut.s_axi_bready.value == 1):
                match response:
                    case "OKAY":
                        self.dut.s_axi_bresp.value = 0
                    case "EXOKAY":
                        self.dut.s_axi_bresp.value = 1
                    case "SLVERR":
                        self.dut.s_axi_bresp.value = 2
                    case "DECERR":
                        self.dut.s_axi_bresp.value = 3
                self.dut.s_axi_bvalid.value = 1
                await RisingEdge(self.dut.axi_aclk)
                self.dut.s_axi_bvalid = 0
                self.dut.s_axi_bresp.value = 0
            else:
                await RisingEdge(self.dut.s_axi_bready)


async def reset_signal(reset_n, duration_ns):
    reset_n.value = 0
    await Timer(duration_ns, units="ns")
    reset_n.value = 1
    reset_n._log.info("Reset complete")


async def generate_clock(clk, period):
    while 1:
        clk.value = 0
        await Timer(period / 2, units="ns")
        clk.value = 1
        await Timer(period / 2, units="ns")


@cocotb.test()
async def write(dut):
    tester = SpiToAxiTester(dut)
    tester.start()
    await tester.axi_reset(100)
    await Timer(100, "ns")
    write_address = random.randbytes(4)
    write_data = random.randbytes(4)
    # cocotb.log.info("Address: " + ' '.join(format(byte, '02x') for byte in write_address))
    # cocotb.log.info("Data: " + ' '.join(format(byte, '02x') for byte in write_data))
    dut.s_axi_awready.value = 1
    dut.s_axi_wready.value = 1
    await tester.spi_write(0)
    for i in range(4):
        await tester.spi_write(write_address[i])
    for i in range(4):
        await tester.spi_write(write_data[i])
    cocotb.start_soon(tester.axi_respond())
    await tester.spi_write(0)  # don't care
    await tester.spi_write(0)  # don't care
    assert tester.axi_aw_mon._values[0]['Address'].integer == int.from_bytes(write_address, byteorder='big')
    assert tester.axi_wr_mon._values[0]['Data'].integer == int.from_bytes(write_data, byteorder='big')


@cocotb.test()
async def read(dut):
    # Init and wait to create clear line in waveform
    tester = SpiToAxiTester(dut)
    await Timer(2000, "ns")
    tester.start()
    await tester.axi_reset(100)
    await Timer(100, "ns")
