// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->spi2axi__DOT__spi_mosi = vlSelf->spi_mosi;
    vlSelf->spi2axi__DOT__axi_aresetn = vlSelf->axi_aresetn;
    vlSelf->spi2axi__DOT__s_axi_awready = vlSelf->s_axi_awready;
    vlSelf->spi2axi__DOT__s_axi_wready = vlSelf->s_axi_wready;
    vlSelf->spi2axi__DOT__s_axi_arready = vlSelf->s_axi_arready;
    vlSelf->spi2axi__DOT__s_axi_rdata = vlSelf->s_axi_rdata;
    vlSelf->spi2axi__DOT__s_axi_rresp = vlSelf->s_axi_rresp;
    vlSelf->spi2axi__DOT__s_axi_rvalid = vlSelf->s_axi_rvalid;
    vlSelf->spi2axi__DOT__s_axi_bresp = vlSelf->s_axi_bresp;
    vlSelf->spi2axi__DOT__s_axi_bvalid = vlSelf->s_axi_bvalid;
    vlSelf->spi2axi__DOT__spi_sck = vlSelf->spi_sck;
    vlSelf->spi2axi__DOT__spi_ss_n = vlSelf->spi_ss_n;
    vlSelf->spi_miso = (1U & ((IData)(vlSelf->spi2axi__DOT__spi_tx_shreg) 
                              >> 7U));
    vlSelf->s_axi_awaddr = vlSelf->spi2axi__DOT__s_axi_awaddr_int;
    vlSelf->s_axi_awprot = vlSelf->spi2axi__DOT__s_axi_awprot_int;
    vlSelf->s_axi_awvalid = vlSelf->spi2axi__DOT__s_axi_awvalid_int;
    vlSelf->s_axi_wdata = vlSelf->spi2axi__DOT__s_axi_wdata_int;
    vlSelf->s_axi_wstrb = vlSelf->spi2axi__DOT__s_axi_wstrb_int;
    vlSelf->s_axi_wvalid = vlSelf->spi2axi__DOT__s_axi_wvalid_int;
    vlSelf->s_axi_araddr = vlSelf->spi2axi__DOT__s_axi_araddr_int;
    vlSelf->s_axi_arprot = vlSelf->spi2axi__DOT__s_axi_arprot_int;
    vlSelf->s_axi_arvalid = vlSelf->spi2axi__DOT__s_axi_arvalid_int;
    vlSelf->s_axi_rready = vlSelf->spi2axi__DOT__s_axi_rready_int;
    vlSelf->s_axi_bready = vlSelf->spi2axi__DOT__s_axi_bready_int;
    vlSelf->spi2axi__DOT__spi_sck_sync = vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_guard_r;
    vlSelf->spi2axi__DOT__spi_ss_n_sync = vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_guard_r;
    vlSelf->spi2axi__DOT__axi_areset = (1U & (~ (IData)(vlSelf->axi_aresetn)));
    vlSelf->spi2axi__DOT__axi_aclk = vlSelf->axi_aclk;
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__i_data 
        = vlSelf->spi2axi__DOT__spi_sck;
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__i_data 
        = vlSelf->spi2axi__DOT__spi_ss_n;
    vlSelf->spi2axi__DOT__spi_miso = vlSelf->spi_miso;
    vlSelf->spi2axi__DOT__s_axi_awaddr = vlSelf->s_axi_awaddr;
    vlSelf->spi2axi__DOT__s_axi_awprot = vlSelf->s_axi_awprot;
    vlSelf->spi2axi__DOT__s_axi_awvalid = vlSelf->s_axi_awvalid;
    vlSelf->spi2axi__DOT__s_axi_wdata = vlSelf->s_axi_wdata;
    vlSelf->spi2axi__DOT__s_axi_wstrb = vlSelf->s_axi_wstrb;
    vlSelf->spi2axi__DOT__s_axi_wvalid = vlSelf->s_axi_wvalid;
    vlSelf->spi2axi__DOT__s_axi_araddr = vlSelf->s_axi_araddr;
    vlSelf->spi2axi__DOT__s_axi_arprot = vlSelf->s_axi_arprot;
    vlSelf->spi2axi__DOT__s_axi_arvalid = vlSelf->s_axi_arvalid;
    vlSelf->spi2axi__DOT__s_axi_rready = vlSelf->s_axi_rready;
    vlSelf->spi2axi__DOT__s_axi_bready = vlSelf->s_axi_bready;
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__o_data 
        = vlSelf->spi2axi__DOT__spi_sck_sync;
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__o_data 
        = vlSelf->spi2axi__DOT__spi_ss_n_sync;
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__i_reset 
        = vlSelf->spi2axi__DOT__axi_areset;
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__i_reset 
        = vlSelf->spi2axi__DOT__axi_areset;
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__i_clk 
        = vlSelf->spi2axi__DOT__axi_aclk;
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__i_clk 
        = vlSelf->spi2axi__DOT__axi_aclk;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__spi2axi__DOT__spi_rx_valid;
    __Vdly__spi2axi__DOT__spi_rx_valid = 0;
    CData/*0:0*/ __Vdly__spi2axi__DOT__axi_fsm_reset;
    __Vdly__spi2axi__DOT__axi_fsm_reset = 0;
    CData/*7:0*/ __Vdly__spi2axi__DOT__spi_rx_shreg;
    __Vdly__spi2axi__DOT__spi_rx_shreg = 0;
    IData/*31:0*/ __Vdly__spi2axi__DOT__spi_state;
    __Vdly__spi2axi__DOT__spi_state = 0;
    CData/*7:0*/ __Vdly__spi2axi__DOT__spi_rx_cmd;
    __Vdly__spi2axi__DOT__spi_rx_cmd = 0;
    IData/*31:0*/ __Vdly__spi2axi__DOT__spi_rx_addr;
    __Vdly__spi2axi__DOT__spi_rx_addr = 0;
    IData/*31:0*/ __Vdly__spi2axi__DOT__spi_rx_wdata;
    __Vdly__spi2axi__DOT__spi_rx_wdata = 0;
    CData/*0:0*/ __Vdly__spi2axi__DOT__s_axi_awvalid_int;
    __Vdly__spi2axi__DOT__s_axi_awvalid_int = 0;
    CData/*0:0*/ __Vdly__spi2axi__DOT__s_axi_wvalid_int;
    __Vdly__spi2axi__DOT__s_axi_wvalid_int = 0;
    IData/*31:0*/ __Vdly__spi2axi__DOT__axi_state;
    __Vdly__spi2axi__DOT__axi_state = 0;
    // Body
    __Vdly__spi2axi__DOT__axi_state = vlSelf->spi2axi__DOT__axi_state;
    __Vdly__spi2axi__DOT__s_axi_wvalid_int = vlSelf->spi2axi__DOT__s_axi_wvalid_int;
    __Vdly__spi2axi__DOT__s_axi_awvalid_int = vlSelf->spi2axi__DOT__s_axi_awvalid_int;
    __Vdly__spi2axi__DOT__spi_rx_wdata = vlSelf->spi2axi__DOT__spi_rx_wdata;
    __Vdly__spi2axi__DOT__spi_rx_addr = vlSelf->spi2axi__DOT__spi_rx_addr;
    __Vdly__spi2axi__DOT__spi_rx_cmd = vlSelf->spi2axi__DOT__spi_rx_cmd;
    __Vdly__spi2axi__DOT__spi_state = vlSelf->spi2axi__DOT__spi_state;
    __Vdly__spi2axi__DOT__spi_rx_shreg = vlSelf->spi2axi__DOT__spi_rx_shreg;
    __Vdly__spi2axi__DOT__axi_fsm_reset = vlSelf->spi2axi__DOT__axi_fsm_reset;
    __Vdly__spi2axi__DOT__spi_rx_valid = vlSelf->spi2axi__DOT__spi_rx_valid;
    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx = 0U;
    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx = 0U;
    if (vlSelf->axi_aresetn) {
        __Vdly__spi2axi__DOT__spi_rx_valid = 0U;
        if ((0U == vlSelf->spi2axi__DOT__spi_state)) {
            if (vlSelf->spi2axi__DOT__spi_ss_n_sync) {
                vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_bit_idx = 0U;
                vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx = 0U;
                vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx = 0U;
                vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx = 0U;
                vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte = 0U;
                __Vdly__spi2axi__DOT__axi_fsm_reset = 1U;
            } else {
                vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_sck_re 
                    = ((IData)(vlSelf->spi2axi__DOT__spi_sck_sync) 
                       & (~ (IData)(vlSelf->spi2axi__DOT__spi_sck_sync_old)));
                vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_sck_fe 
                    = ((~ (IData)(vlSelf->spi2axi__DOT__spi_sck_sync)) 
                       & (IData)(vlSelf->spi2axi__DOT__spi_sck_sync_old));
                __Vdly__spi2axi__DOT__axi_fsm_reset = 0U;
                if (vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_sck_re) {
                    __Vdly__spi2axi__DOT__spi_rx_shreg 
                        = ((0xfeU & ((IData)(vlSelf->spi2axi__DOT__spi_rx_shreg) 
                                     << 1U)) | (IData)(vlSelf->spi_mosi));
                    if ((7U == (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_bit_idx))) {
                        vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_bit_idx = 0U;
                        if ((0xbU > (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx))) {
                            __Vdly__spi2axi__DOT__spi_state = 1U;
                        }
                    } else {
                        vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_bit_idx 
                            = (7U & ((IData)(1U) + (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_bit_idx)));
                    }
                } else if (vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_sck_fe) {
                    vlSelf->spi2axi__DOT__spi_tx_shreg 
                        = (0xfeU & ((IData)(vlSelf->spi2axi__DOT__spi_tx_shreg) 
                                    << 1U));
                    if ((7U == (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx))) {
                        vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx = 0U;
                        if ((0xaU > (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx))) {
                            vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx 
                                = (0x1fU & ((IData)(1U) 
                                            + (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx)));
                            __Vdly__spi2axi__DOT__spi_state = 2U;
                        }
                    } else {
                        vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx 
                            = (7U & ((IData)(1U) + (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx)));
                    }
                }
            }
        } else if ((1U == vlSelf->spi2axi__DOT__spi_state)) {
            if ((0U == (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx))) {
                __Vdly__spi2axi__DOT__spi_rx_cmd = vlSelf->spi2axi__DOT__spi_rx_shreg;
            } else if ((0U == (IData)(vlSelf->spi2axi__DOT__spi_rx_cmd))) {
                if ((4U >= (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx))) {
                    __Vdly__spi2axi__DOT__spi_rx_addr 
                        = ((vlSelf->spi2axi__DOT__spi_rx_addr 
                            << 8U) | (IData)(vlSelf->spi2axi__DOT__spi_rx_shreg));
                } else if ((8U >= (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx))) {
                    __Vdly__spi2axi__DOT__spi_rx_wdata 
                        = ((vlSelf->spi2axi__DOT__spi_rx_wdata 
                            << 8U) | (IData)(vlSelf->spi2axi__DOT__spi_rx_shreg));
                    if ((8U == (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx))) {
                        __Vdly__spi2axi__DOT__spi_rx_valid = 1U;
                    }
                }
            } else if ((4U >= (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx))) {
                __Vdly__spi2axi__DOT__spi_rx_addr = 
                    ((vlSelf->spi2axi__DOT__spi_rx_addr 
                      << 8U) | (IData)(vlSelf->spi2axi__DOT__spi_rx_shreg));
                if ((4U == (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx))) {
                    __Vdly__spi2axi__DOT__spi_rx_valid = 1U;
                }
            }
            __Vdly__spi2axi__DOT__spi_state = 0U;
            vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx)));
        } else if ((2U == vlSelf->spi2axi__DOT__spi_state)) {
            vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte = 0U;
            if ((0U == (IData)(vlSelf->spi2axi__DOT__spi_rx_cmd))) {
                if ((0xaU == (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx))) {
                    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte = 0U;
                    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte 
                        = ((4U & ((~ (IData)(vlSelf->spi2axi__DOT__axi_bresp_valid)) 
                                  << 2U)) | (IData)(vlSelf->spi2axi__DOT__axi_bresp));
                }
            } else if ((5U < (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx))) {
                if ((6U == (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx))) {
                    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte 
                        = (7U & (vlSelf->spi2axi__DOT__axi_rdata 
                                 >> 0x18U));
                } else if ((7U == (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx))) {
                    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte 
                        = (7U & (vlSelf->spi2axi__DOT__axi_rdata 
                                 >> 0x10U));
                } else if ((8U == (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx))) {
                    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte 
                        = (7U & (vlSelf->spi2axi__DOT__axi_rdata 
                                 >> 8U));
                } else if ((9U == (IData)(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx))) {
                    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte 
                        = (7U & vlSelf->spi2axi__DOT__axi_rdata);
                } else {
                    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte = 0U;
                    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte 
                        = ((4U & ((~ (IData)(vlSelf->spi2axi__DOT__axi_rdata_valid)) 
                                  << 2U)) | (IData)(vlSelf->spi2axi__DOT__axi_rresp));
                }
            }
            __Vdly__spi2axi__DOT__spi_state = 0U;
            vlSelf->spi2axi__DOT__spi_tx_shreg = vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte;
        }
    } else {
        vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_bit_idx = 0U;
        vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx = 0U;
        vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx = 0U;
        vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx = 0U;
        vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte = 0U;
        __Vdly__spi2axi__DOT__spi_rx_wdata = 0U;
        __Vdly__spi2axi__DOT__spi_rx_shreg = 0U;
        vlSelf->spi2axi__DOT__spi_tx_shreg = 0U;
        __Vdly__spi2axi__DOT__spi_rx_valid = 0U;
        __Vdly__spi2axi__DOT__spi_rx_cmd = 0U;
        __Vdly__spi2axi__DOT__spi_rx_addr = 0U;
        __Vdly__spi2axi__DOT__axi_fsm_reset = 1U;
        __Vdly__spi2axi__DOT__spi_state = 0U;
    }
    vlSelf->spi2axi__DOT__spi_rx_shreg = __Vdly__spi2axi__DOT__spi_rx_shreg;
    vlSelf->spi2axi__DOT__spi_state = __Vdly__spi2axi__DOT__spi_state;
    vlSelf->spi_miso = (1U & ((IData)(vlSelf->spi2axi__DOT__spi_tx_shreg) 
                              >> 7U));
    vlSelf->spi2axi__DOT__spi_sck_sync_old = ((IData)(vlSelf->axi_aresetn) 
                                              && (IData)(vlSelf->spi2axi__DOT__spi_sck_sync));
    if ((1U & ((~ (IData)(vlSelf->axi_aresetn)) | (IData)(vlSelf->spi2axi__DOT__axi_fsm_reset)))) {
        __Vdly__spi2axi__DOT__s_axi_awvalid_int = 0U;
        vlSelf->spi2axi__DOT__s_axi_awprot_int = 0U;
        vlSelf->spi2axi__DOT__s_axi_awaddr_int = 0U;
        vlSelf->spi2axi__DOT__s_axi_arvalid_int = 0U;
        vlSelf->spi2axi__DOT__s_axi_arprot_int = 0U;
        vlSelf->spi2axi__DOT__s_axi_araddr_int = 0U;
        __Vdly__spi2axi__DOT__s_axi_wvalid_int = 0U;
        vlSelf->spi2axi__DOT__s_axi_wstrb_int = 0U;
        vlSelf->spi2axi__DOT__s_axi_wdata_int = 0U;
        vlSelf->spi2axi__DOT__s_axi_bready_int = 0U;
        vlSelf->spi2axi__DOT__s_axi_rready_int = 0U;
        vlSelf->spi2axi__DOT__axi_bresp_valid = 0U;
        vlSelf->spi2axi__DOT__axi_bresp = 0U;
        vlSelf->spi2axi__DOT__axi_rresp = 0U;
        vlSelf->spi2axi__DOT__axi_rdata_valid = 0U;
        vlSelf->spi2axi__DOT__axi_rdata = 0U;
        __Vdly__spi2axi__DOT__axi_state = 0U;
    } else if ((0U == vlSelf->spi2axi__DOT__axi_state)) {
        if (vlSelf->spi2axi__DOT__spi_rx_valid) {
            vlSelf->spi2axi__DOT__axi_bresp_valid = 0U;
            vlSelf->spi2axi__DOT__axi_rdata_valid = 0U;
            if ((0U == (IData)(vlSelf->spi2axi__DOT__spi_rx_cmd))) {
                __Vdly__spi2axi__DOT__s_axi_awvalid_int = 1U;
                vlSelf->spi2axi__DOT__s_axi_awaddr_int = 0U;
                vlSelf->spi2axi__DOT__s_axi_awprot_int = 0U;
                __Vdly__spi2axi__DOT__s_axi_wvalid_int = 1U;
                vlSelf->spi2axi__DOT__s_axi_wdata_int 
                    = vlSelf->spi2axi__DOT__spi_rx_wdata;
                vlSelf->spi2axi__DOT__s_axi_wstrb_int = 0xfU;
                __Vdly__spi2axi__DOT__axi_state = 1U;
                vlSelf->spi2axi__DOT__s_axi_awaddr_int 
                    = vlSelf->spi2axi__DOT__spi_rx_addr;
            } else {
                vlSelf->spi2axi__DOT__s_axi_arvalid_int = 1U;
                vlSelf->spi2axi__DOT__s_axi_araddr_int = 0U;
                vlSelf->spi2axi__DOT__s_axi_arprot_int = 0U;
                __Vdly__spi2axi__DOT__axi_state = 3U;
                vlSelf->spi2axi__DOT__s_axi_araddr_int 
                    = vlSelf->spi2axi__DOT__spi_rx_addr;
            }
        }
    } else if ((1U == vlSelf->spi2axi__DOT__axi_state)) {
        if (vlSelf->s_axi_awready) {
            __Vdly__spi2axi__DOT__s_axi_awvalid_int = 0U;
            if ((1U & (~ (IData)(vlSelf->spi2axi__DOT__s_axi_wvalid_int)))) {
                vlSelf->spi2axi__DOT__s_axi_bready_int = 1U;
                __Vdly__spi2axi__DOT__axi_state = 2U;
            }
        }
        if (vlSelf->s_axi_wready) {
            __Vdly__spi2axi__DOT__s_axi_wvalid_int = 0U;
            vlSelf->spi2axi__DOT__s_axi_wstrb_int = 0U;
            if ((1U & (~ (IData)(vlSelf->spi2axi__DOT__s_axi_awvalid_int)))) {
                vlSelf->spi2axi__DOT__s_axi_bready_int = 1U;
                __Vdly__spi2axi__DOT__axi_state = 2U;
            }
        }
    } else if ((2U == vlSelf->spi2axi__DOT__axi_state)) {
        if (vlSelf->s_axi_bvalid) {
            vlSelf->spi2axi__DOT__s_axi_bready_int = 0U;
            vlSelf->spi2axi__DOT__axi_bresp_valid = 1U;
            vlSelf->spi2axi__DOT__axi_bresp = vlSelf->s_axi_bresp;
            __Vdly__spi2axi__DOT__axi_state = 0U;
        }
    } else if ((3U == vlSelf->spi2axi__DOT__axi_state)) {
        if (vlSelf->s_axi_arready) {
            vlSelf->spi2axi__DOT__s_axi_arvalid_int = 0U;
            vlSelf->spi2axi__DOT__s_axi_rready_int = 1U;
            __Vdly__spi2axi__DOT__axi_state = 4U;
        }
    } else if ((4U == vlSelf->spi2axi__DOT__axi_state)) {
        if (vlSelf->s_axi_rvalid) {
            vlSelf->spi2axi__DOT__s_axi_rready_int = 0U;
            vlSelf->spi2axi__DOT__axi_rdata_valid = 1U;
            vlSelf->spi2axi__DOT__axi_rdata = vlSelf->s_axi_rdata;
            vlSelf->spi2axi__DOT__axi_rresp = vlSelf->s_axi_rresp;
            __Vdly__spi2axi__DOT__axi_state = 0U;
        }
    }
    vlSelf->spi2axi__DOT__spi_miso = vlSelf->spi_miso;
    vlSelf->spi2axi__DOT__axi_fsm_reset = __Vdly__spi2axi__DOT__axi_fsm_reset;
    vlSelf->spi2axi__DOT__spi_rx_valid = __Vdly__spi2axi__DOT__spi_rx_valid;
    vlSelf->spi2axi__DOT__axi_state = __Vdly__spi2axi__DOT__axi_state;
    vlSelf->spi2axi__DOT__spi_rx_cmd = __Vdly__spi2axi__DOT__spi_rx_cmd;
    vlSelf->spi2axi__DOT__spi_rx_wdata = __Vdly__spi2axi__DOT__spi_rx_wdata;
    vlSelf->spi2axi__DOT__spi_rx_addr = __Vdly__spi2axi__DOT__spi_rx_addr;
    vlSelf->spi2axi__DOT__s_axi_awvalid_int = __Vdly__spi2axi__DOT__s_axi_awvalid_int;
    vlSelf->spi2axi__DOT__s_axi_wvalid_int = __Vdly__spi2axi__DOT__s_axi_wvalid_int;
    vlSelf->s_axi_awvalid = vlSelf->spi2axi__DOT__s_axi_awvalid_int;
    vlSelf->s_axi_awprot = vlSelf->spi2axi__DOT__s_axi_awprot_int;
    vlSelf->s_axi_awaddr = vlSelf->spi2axi__DOT__s_axi_awaddr_int;
    vlSelf->s_axi_arvalid = vlSelf->spi2axi__DOT__s_axi_arvalid_int;
    vlSelf->s_axi_arprot = vlSelf->spi2axi__DOT__s_axi_arprot_int;
    vlSelf->s_axi_araddr = vlSelf->spi2axi__DOT__s_axi_araddr_int;
    vlSelf->s_axi_wvalid = vlSelf->spi2axi__DOT__s_axi_wvalid_int;
    vlSelf->s_axi_wstrb = vlSelf->spi2axi__DOT__s_axi_wstrb_int;
    vlSelf->s_axi_wdata = vlSelf->spi2axi__DOT__s_axi_wdata_int;
    vlSelf->s_axi_bready = vlSelf->spi2axi__DOT__s_axi_bready_int;
    vlSelf->s_axi_rready = vlSelf->spi2axi__DOT__s_axi_rready_int;
    vlSelf->spi2axi__DOT__s_axi_awvalid = vlSelf->s_axi_awvalid;
    vlSelf->spi2axi__DOT__s_axi_awprot = vlSelf->s_axi_awprot;
    vlSelf->spi2axi__DOT__s_axi_awaddr = vlSelf->s_axi_awaddr;
    vlSelf->spi2axi__DOT__s_axi_arvalid = vlSelf->s_axi_arvalid;
    vlSelf->spi2axi__DOT__s_axi_arprot = vlSelf->s_axi_arprot;
    vlSelf->spi2axi__DOT__s_axi_araddr = vlSelf->s_axi_araddr;
    vlSelf->spi2axi__DOT__s_axi_wvalid = vlSelf->s_axi_wvalid;
    vlSelf->spi2axi__DOT__s_axi_wstrb = vlSelf->s_axi_wstrb;
    vlSelf->spi2axi__DOT__s_axi_wdata = vlSelf->s_axi_wdata;
    vlSelf->spi2axi__DOT__s_axi_bready = vlSelf->s_axi_bready;
    vlSelf->spi2axi__DOT__s_axi_rready = vlSelf->s_axi_rready;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_guard_r 
        = ((1U & (~ (IData)(vlSelf->spi2axi__DOT__axi_areset))) 
           && (IData)(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_sync_r));
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_guard_r 
        = ((1U & (~ (IData)(vlSelf->spi2axi__DOT__axi_areset))) 
           && (IData)(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_sync_r));
    vlSelf->spi2axi__DOT__spi_ss_n_sync = vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_guard_r;
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_sync_r 
        = ((1U & (~ (IData)(vlSelf->spi2axi__DOT__axi_areset))) 
           && (IData)(vlSelf->spi_ss_n));
    vlSelf->spi2axi__DOT__spi_sck_sync = vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_guard_r;
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_sync_r 
        = ((1U & (~ (IData)(vlSelf->spi2axi__DOT__axi_areset))) 
           && (IData)(vlSelf->spi_sck));
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__o_data 
        = vlSelf->spi2axi__DOT__spi_ss_n_sync;
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__o_data 
        = vlSelf->spi2axi__DOT__spi_sck_sync;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/matt/Documents/Personal/PersonalProjects/Cocotb/SpiToAxi/spi2axi.sv", 34, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/matt/Documents/Personal/PersonalProjects/Cocotb/SpiToAxi/spi2axi.sv", 34, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/matt/Documents/Personal/PersonalProjects/Cocotb/SpiToAxi/spi2axi.sv", 34, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->spi_sck & 0xfeU))) {
        Verilated::overWidthError("spi_sck");}
    if (VL_UNLIKELY((vlSelf->spi_ss_n & 0xfeU))) {
        Verilated::overWidthError("spi_ss_n");}
    if (VL_UNLIKELY((vlSelf->spi_mosi & 0xfeU))) {
        Verilated::overWidthError("spi_mosi");}
    if (VL_UNLIKELY((vlSelf->axi_aclk & 0xfeU))) {
        Verilated::overWidthError("axi_aclk");}
    if (VL_UNLIKELY((vlSelf->axi_aresetn & 0xfeU))) {
        Verilated::overWidthError("axi_aresetn");}
    if (VL_UNLIKELY((vlSelf->s_axi_awready & 0xfeU))) {
        Verilated::overWidthError("s_axi_awready");}
    if (VL_UNLIKELY((vlSelf->s_axi_wready & 0xfeU))) {
        Verilated::overWidthError("s_axi_wready");}
    if (VL_UNLIKELY((vlSelf->s_axi_arready & 0xfeU))) {
        Verilated::overWidthError("s_axi_arready");}
    if (VL_UNLIKELY((vlSelf->s_axi_rresp & 0xfcU))) {
        Verilated::overWidthError("s_axi_rresp");}
    if (VL_UNLIKELY((vlSelf->s_axi_rvalid & 0xfeU))) {
        Verilated::overWidthError("s_axi_rvalid");}
    if (VL_UNLIKELY((vlSelf->s_axi_bresp & 0xfcU))) {
        Verilated::overWidthError("s_axi_bresp");}
    if (VL_UNLIKELY((vlSelf->s_axi_bvalid & 0xfeU))) {
        Verilated::overWidthError("s_axi_bvalid");}
}
#endif  // VL_DEBUG
