import cocotb
from cocotb.triggers import RisingEdge


class monitor:
    def __init__(self, clk, datas, valid, active_valid=1):
        self._values = []
        self._clk = clk
        self._datas = datas  # Dictionary of signal name : handler pairs
        self._valid = valid
        self._coro = None  # Coroutine handler
        self.active_valid = active_valid

    def start(self):
        if self._coro is not None:
            raise RuntimeError("Monitor already started")
        self._coro = cocotb.start_soon(self._run())

    def stop(self):
        if self._coro is None:
            raise RuntimeError("Monitor already stopped")
        self._coro.kill()
        self._coro = None

    async def _run(self):
        while True:
            await RisingEdge(self._clk)  # Capture only on the rising edge
            if self._valid.value != self.active_valid:
                await RisingEdge(self._valid)
            else:
                self._values.append(self._sample())

    def _sample(self):
        sample_dict = {}
        for i in self._datas:
            sample_dict[i] = self._datas[i].value
        return sample_dict
