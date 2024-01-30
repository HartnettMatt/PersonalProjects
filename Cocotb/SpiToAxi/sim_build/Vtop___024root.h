// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
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
        CData/*0:0*/ spi2axi__DOT__spi_sck;
        CData/*0:0*/ spi2axi__DOT__spi_ss_n;
        CData/*0:0*/ spi2axi__DOT__spi_mosi;
        CData/*0:0*/ spi2axi__DOT__spi_miso;
        CData/*0:0*/ spi2axi__DOT__axi_aclk;
        CData/*0:0*/ spi2axi__DOT__axi_aresetn;
        CData/*2:0*/ spi2axi__DOT__s_axi_awprot;
        CData/*0:0*/ spi2axi__DOT__s_axi_awvalid;
        CData/*0:0*/ spi2axi__DOT__s_axi_awready;
        CData/*3:0*/ spi2axi__DOT__s_axi_wstrb;
        CData/*0:0*/ spi2axi__DOT__s_axi_wvalid;
        CData/*0:0*/ spi2axi__DOT__s_axi_wready;
        CData/*2:0*/ spi2axi__DOT__s_axi_arprot;
        CData/*0:0*/ spi2axi__DOT__s_axi_arvalid;
        CData/*0:0*/ spi2axi__DOT__s_axi_arready;
        CData/*1:0*/ spi2axi__DOT__s_axi_rresp;
        CData/*0:0*/ spi2axi__DOT__s_axi_rvalid;
        CData/*0:0*/ spi2axi__DOT__s_axi_rready;
        CData/*1:0*/ spi2axi__DOT__s_axi_bresp;
        CData/*0:0*/ spi2axi__DOT__s_axi_bvalid;
        CData/*0:0*/ spi2axi__DOT__s_axi_bready;
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
        CData/*0:0*/ spi2axi__DOT__spi_sck_sync;
        CData/*0:0*/ spi2axi__DOT__spi_ss_n_sync;
        CData/*2:0*/ spi2axi__DOT__spi_fsm__DOT__spi_rx_bit_idx;
    };
    struct {
        CData/*4:0*/ spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx;
        CData/*2:0*/ spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx;
        CData/*4:0*/ spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx;
        CData/*0:0*/ spi2axi__DOT__spi_fsm__DOT__spi_sck_re;
        CData/*0:0*/ spi2axi__DOT__spi_fsm__DOT__spi_sck_fe;
        CData/*2:0*/ spi2axi__DOT__spi_fsm__DOT__spi_tx_byte;
        CData/*0:0*/ spi2axi__DOT__spi_sck_sync_inst__DOT__i_reset;
        CData/*0:0*/ spi2axi__DOT__spi_sck_sync_inst__DOT__i_clk;
        CData/*0:0*/ spi2axi__DOT__spi_sck_sync_inst__DOT__i_data;
        CData/*0:0*/ spi2axi__DOT__spi_sck_sync_inst__DOT__o_data;
        CData/*0:0*/ spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_sync_r;
        CData/*0:0*/ spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_guard_r;
        CData/*0:0*/ spi2axi__DOT__spi_ss_sync_inst__DOT__i_reset;
        CData/*0:0*/ spi2axi__DOT__spi_ss_sync_inst__DOT__i_clk;
        CData/*0:0*/ spi2axi__DOT__spi_ss_sync_inst__DOT__i_data;
        CData/*0:0*/ spi2axi__DOT__spi_ss_sync_inst__DOT__o_data;
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
        IData/*31:0*/ spi2axi__DOT__s_axi_awaddr;
        IData/*31:0*/ spi2axi__DOT__s_axi_wdata;
        IData/*31:0*/ spi2axi__DOT__s_axi_araddr;
        IData/*31:0*/ spi2axi__DOT__s_axi_rdata;
        IData/*31:0*/ spi2axi__DOT__spi_state;
        IData/*31:0*/ spi2axi__DOT__axi_state;
        IData/*31:0*/ spi2axi__DOT__axi_rdata;
        IData/*31:0*/ spi2axi__DOT__spi_rx_addr;
        IData/*31:0*/ spi2axi__DOT__spi_rx_wdata;
        IData/*31:0*/ spi2axi__DOT__s_axi_awaddr_int;
        IData/*31:0*/ spi2axi__DOT__s_axi_wdata_int;
        IData/*31:0*/ spi2axi__DOT__s_axi_araddr_int;
        IData/*31:0*/ __VactIterCount;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*7:0*/ spi2axi__DOT__CMD_WRITE = 0U;
    static constexpr CData/*7:0*/ spi2axi__DOT__CMD_READ = 1U;
    static constexpr IData/*31:0*/ spi2axi__DOT__SPI_CPOL = 0U;
    static constexpr IData/*31:0*/ spi2axi__DOT__SPI_CPHA = 0U;
    static constexpr IData/*31:0*/ spi2axi__DOT__AXI_ADDR_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ spi2axi__DOT__SPI_FRAME_LENGTH_BYTES = 0x0000000bU;
    static constexpr IData/*31:0*/ spi2axi__DOT__spi_sck_sync_inst__DOT__G_INIT_VALUE = 0U;
    static constexpr IData/*31:0*/ spi2axi__DOT__spi_sck_sync_inst__DOT__G_NUM_GUARD_FFS = 1U;
    static constexpr IData/*31:0*/ spi2axi__DOT__spi_ss_sync_inst__DOT__G_INIT_VALUE = 0U;
    static constexpr IData/*31:0*/ spi2axi__DOT__spi_ss_sync_inst__DOT__G_NUM_GUARD_FFS = 1U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
