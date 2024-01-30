// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vspi2axi.h for the primary calling header

#ifndef VERILATED_VSPI2AXI___024ROOT_H_
#define VERILATED_VSPI2AXI___024ROOT_H_  // guard

#include "verilated.h"


class Vspi2axi__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vspi2axi___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(axi_aclk,0,0);
        CData/*0:0*/ spi2axi__DOT__axi_areset;
        VL_IN8(spi_sck,0,0);
        VL_IN8(spi_ss_n,0,0);
        VL_IN8(spi_mosi,0,0);
        VL_OUT8(spi_miso,0,0);
        VL_IN8(axi_aresetn,0,0);
        VL_OUT8(s_axi_awprot,2,0);
        VL_OUT8(s_axi_awvalid,0,0);
        VL_IN8(s_axi_awready,0,0);
        VL_OUT8(s_axi_wstrb,3,0);
        VL_OUT8(s_axi_wvalid,0,0);
        VL_IN8(s_axi_wready,0,0);
        VL_OUT8(s_axi_arprot,2,0);
        VL_OUT8(s_axi_arvalid,0,0);
        VL_IN8(s_axi_arready,0,0);
        VL_IN8(s_axi_rresp,1,0);
        VL_IN8(s_axi_rvalid,0,0);
        VL_OUT8(s_axi_rready,0,0);
        VL_IN8(s_axi_bresp,1,0);
        VL_IN8(s_axi_bvalid,0,0);
        VL_OUT8(s_axi_bready,0,0);
        CData/*0:0*/ spi2axi__DOT__spi_sck_sync_old;
        CData/*7:0*/ spi2axi__DOT__spi_rx_shreg;
        CData/*7:0*/ spi2axi__DOT__spi_tx_shreg;
        CData/*0:0*/ spi2axi__DOT__axi_bresp_valid;
        CData/*1:0*/ spi2axi__DOT__axi_bresp;
        CData/*1:0*/ spi2axi__DOT__axi_rresp;
        CData/*0:0*/ spi2axi__DOT__axi_rdata_valid;
        CData/*7:0*/ spi2axi__DOT__spi_rx_cmd;
        CData/*0:0*/ spi2axi__DOT__spi_rx_valid;
        CData/*0:0*/ spi2axi__DOT__s_axi_awvalid_int;
        CData/*0:0*/ spi2axi__DOT__s_axi_wvalid_int;
        CData/*0:0*/ spi2axi__DOT__axi_fsm_reset;
        CData/*2:0*/ spi2axi__DOT__s_axi_awprot_int;
        CData/*3:0*/ spi2axi__DOT__s_axi_wstrb_int;
        CData/*2:0*/ spi2axi__DOT__s_axi_arprot_int;
        CData/*0:0*/ spi2axi__DOT__s_axi_arvalid_int;
        CData/*0:0*/ spi2axi__DOT__s_axi_rready_int;
        CData/*0:0*/ spi2axi__DOT__s_axi_bready_int;
        CData/*0:0*/ spi2axi__DOT__spi_fsm__DOT__spi_sck_re;
        CData/*0:0*/ spi2axi__DOT__spi_fsm__DOT__spi_sck_fe;
        CData/*2:0*/ spi2axi__DOT__spi_fsm__DOT__spi_tx_byte;
        CData/*0:0*/ spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_sync_r;
        CData/*0:0*/ spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_guard_r;
        CData/*0:0*/ spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_sync_r;
        CData/*0:0*/ spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_guard_r;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__axi_aclk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__spi2axi__DOT__axi_areset__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT(s_axi_awaddr,31,0);
        VL_OUT(s_axi_wdata,31,0);
        VL_OUT(s_axi_araddr,31,0);
        VL_IN(s_axi_rdata,31,0);
        IData/*31:0*/ spi2axi__DOT__spi_state;
        IData/*31:0*/ spi2axi__DOT__axi_state;
        IData/*31:0*/ spi2axi__DOT__axi_rdata;
        IData/*31:0*/ spi2axi__DOT__spi_rx_addr;
        IData/*31:0*/ spi2axi__DOT__spi_rx_wdata;
        IData/*31:0*/ spi2axi__DOT__s_axi_awaddr_int;
        IData/*31:0*/ spi2axi__DOT__s_axi_wdata_int;
        IData/*31:0*/ spi2axi__DOT__s_axi_araddr_int;
    };
    struct {
        IData/*31:0*/ __VactIterCount;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vspi2axi__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vspi2axi___024root(Vspi2axi__Syms* symsp, const char* v__name);
    ~Vspi2axi___024root();
    VL_UNCOPYABLE(Vspi2axi___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
