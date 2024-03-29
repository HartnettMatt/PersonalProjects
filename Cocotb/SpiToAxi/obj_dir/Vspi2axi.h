// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VSPI2AXI_H_
#define VERILATED_VSPI2AXI_H_  // guard

#include "verilated.h"

class Vspi2axi__Syms;
class Vspi2axi___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vspi2axi VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vspi2axi__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&axi_aclk,0,0);
    VL_IN8(&spi_sck,0,0);
    VL_IN8(&spi_ss_n,0,0);
    VL_IN8(&spi_mosi,0,0);
    VL_OUT8(&spi_miso,0,0);
    VL_IN8(&axi_aresetn,0,0);
    VL_OUT8(&s_axi_awprot,2,0);
    VL_OUT8(&s_axi_awvalid,0,0);
    VL_IN8(&s_axi_awready,0,0);
    VL_OUT8(&s_axi_wstrb,3,0);
    VL_OUT8(&s_axi_wvalid,0,0);
    VL_IN8(&s_axi_wready,0,0);
    VL_OUT8(&s_axi_arprot,2,0);
    VL_OUT8(&s_axi_arvalid,0,0);
    VL_IN8(&s_axi_arready,0,0);
    VL_IN8(&s_axi_rresp,1,0);
    VL_IN8(&s_axi_rvalid,0,0);
    VL_OUT8(&s_axi_rready,0,0);
    VL_IN8(&s_axi_bresp,1,0);
    VL_IN8(&s_axi_bvalid,0,0);
    VL_OUT8(&s_axi_bready,0,0);
    VL_OUT(&s_axi_awaddr,31,0);
    VL_OUT(&s_axi_wdata,31,0);
    VL_OUT(&s_axi_araddr,31,0);
    VL_IN(&s_axi_rdata,31,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vspi2axi___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vspi2axi(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vspi2axi(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vspi2axi();
  private:
    VL_UNCOPYABLE(Vspi2axi);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
};

#endif  // guard
