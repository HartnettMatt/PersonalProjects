// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vspi2axi__pch.h"

//============================================================
// Constructors

Vspi2axi::Vspi2axi(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vspi2axi__Syms(contextp(), _vcname__, this)}
    , axi_aclk{vlSymsp->TOP.axi_aclk}
    , spi_sck{vlSymsp->TOP.spi_sck}
    , spi_ss_n{vlSymsp->TOP.spi_ss_n}
    , spi_mosi{vlSymsp->TOP.spi_mosi}
    , spi_miso{vlSymsp->TOP.spi_miso}
    , axi_aresetn{vlSymsp->TOP.axi_aresetn}
    , s_axi_awprot{vlSymsp->TOP.s_axi_awprot}
    , s_axi_awvalid{vlSymsp->TOP.s_axi_awvalid}
    , s_axi_awready{vlSymsp->TOP.s_axi_awready}
    , s_axi_wstrb{vlSymsp->TOP.s_axi_wstrb}
    , s_axi_wvalid{vlSymsp->TOP.s_axi_wvalid}
    , s_axi_wready{vlSymsp->TOP.s_axi_wready}
    , s_axi_arprot{vlSymsp->TOP.s_axi_arprot}
    , s_axi_arvalid{vlSymsp->TOP.s_axi_arvalid}
    , s_axi_arready{vlSymsp->TOP.s_axi_arready}
    , s_axi_rresp{vlSymsp->TOP.s_axi_rresp}
    , s_axi_rvalid{vlSymsp->TOP.s_axi_rvalid}
    , s_axi_rready{vlSymsp->TOP.s_axi_rready}
    , s_axi_bresp{vlSymsp->TOP.s_axi_bresp}
    , s_axi_bvalid{vlSymsp->TOP.s_axi_bvalid}
    , s_axi_bready{vlSymsp->TOP.s_axi_bready}
    , s_axi_awaddr{vlSymsp->TOP.s_axi_awaddr}
    , s_axi_wdata{vlSymsp->TOP.s_axi_wdata}
    , s_axi_araddr{vlSymsp->TOP.s_axi_araddr}
    , s_axi_rdata{vlSymsp->TOP.s_axi_rdata}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vspi2axi::Vspi2axi(const char* _vcname__)
    : Vspi2axi(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vspi2axi::~Vspi2axi() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vspi2axi___024root___eval_debug_assertions(Vspi2axi___024root* vlSelf);
#endif  // VL_DEBUG
void Vspi2axi___024root___eval_static(Vspi2axi___024root* vlSelf);
void Vspi2axi___024root___eval_initial(Vspi2axi___024root* vlSelf);
void Vspi2axi___024root___eval_settle(Vspi2axi___024root* vlSelf);
void Vspi2axi___024root___eval(Vspi2axi___024root* vlSelf);

void Vspi2axi::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vspi2axi::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vspi2axi___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vspi2axi___024root___eval_static(&(vlSymsp->TOP));
        Vspi2axi___024root___eval_initial(&(vlSymsp->TOP));
        Vspi2axi___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vspi2axi___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vspi2axi::eventsPending() { return false; }

uint64_t Vspi2axi::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vspi2axi::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vspi2axi___024root___eval_final(Vspi2axi___024root* vlSelf);

VL_ATTR_COLD void Vspi2axi::final() {
    Vspi2axi___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vspi2axi::hierName() const { return vlSymsp->name(); }
const char* Vspi2axi::modelName() const { return "Vspi2axi"; }
unsigned Vspi2axi::threads() const { return 1; }
void Vspi2axi::prepareClone() const { contextp()->prepareClone(); }
void Vspi2axi::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vspi2axi::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vspi2axi::trace()' called on model that was Verilated without --trace option");
}
