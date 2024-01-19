import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge
from cocotb.triggers import FallingEdge

class monitor:
    def __init__(self, clk, datas, valid):
        self._values = []
        self._clk = clk
        self._datas = datas # Dictionary of signal name : handler pairs
        self._valid = valid
        self._coro = None # Coroutine handler

    def start(self):
        if self._running is not None:
            raise RuntimeError("Monitor already started")
        self._coro = cocotb.start_soon(self._run())

    def stop(self):
        if self._running is None:
            raise RuntimeError("Monitor already stopped")
        self._coro.kill()
        self._coro = None


    async def _run(self):
        while True:
            await RisingEdge(self._clk) # Capture only on the rising edge
            if self._valid.value != 1:
                await RisingEdge(self._valid)
            else:
                self._values.append(self._sample())
    def _sample(self):
        sample_dict = {}
        for i in self._datas:
            sample_dict[i] = self._datas[i].value
        return sample_dict
