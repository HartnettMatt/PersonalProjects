// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi2axi.h for the primary calling header

#include "Vspi2axi__pch.h"
#include "Vspi2axi___024root.h"

VL_ATTR_COLD void Vspi2axi___024root___eval_static__TOP(Vspi2axi___024root* vlSelf);

VL_ATTR_COLD void Vspi2axi___024root___eval_static(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___eval_static\n"); );
    // Body
    Vspi2axi___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vspi2axi___024root___eval_static__TOP(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->spi2axi__DOT__spi_state = 0U;
    vlSelf->spi2axi__DOT__axi_state = 0U;
    vlSelf->spi2axi__DOT__spi_sck_sync_old = 0U;
    vlSelf->spi2axi__DOT__spi_rx_shreg = 0U;
    vlSelf->spi2axi__DOT__spi_tx_shreg = 0U;
    vlSelf->spi2axi__DOT__axi_bresp_valid = 0U;
    vlSelf->spi2axi__DOT__axi_bresp = 0U;
    vlSelf->spi2axi__DOT__axi_rresp = 0U;
    vlSelf->spi2axi__DOT__axi_rdata_valid = 0U;
    vlSelf->spi2axi__DOT__axi_rdata = 0U;
    vlSelf->spi2axi__DOT__spi_rx_cmd = 0U;
    vlSelf->spi2axi__DOT__spi_rx_addr = 0U;
    vlSelf->spi2axi__DOT__spi_rx_wdata = 0U;
    vlSelf->spi2axi__DOT__spi_rx_valid = 0U;
    vlSelf->spi2axi__DOT__s_axi_awvalid_int = 0U;
    vlSelf->spi2axi__DOT__s_axi_wvalid_int = 0U;
    vlSelf->spi2axi__DOT__axi_fsm_reset = 1U;
    vlSelf->spi2axi__DOT__s_axi_awaddr_int = 0U;
    vlSelf->spi2axi__DOT__s_axi_awprot_int = 0U;
    vlSelf->spi2axi__DOT__s_axi_wdata_int = 0U;
    vlSelf->spi2axi__DOT__s_axi_wstrb_int = 0U;
    vlSelf->spi2axi__DOT__s_axi_araddr_int = 0U;
    vlSelf->spi2axi__DOT__s_axi_arprot_int = 0U;
    vlSelf->spi2axi__DOT__s_axi_arvalid_int = 0U;
    vlSelf->spi2axi__DOT__s_axi_rready_int = 0U;
    vlSelf->spi2axi__DOT__s_axi_bready_int = 0U;
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_sync_r = 0U;
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_guard_r = 0U;
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_sync_r = 0U;
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_guard_r = 0U;
}

VL_ATTR_COLD void Vspi2axi___024root___eval_initial(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__axi_aclk__0 = vlSelf->axi_aclk;
    vlSelf->__Vtrigprevexpr___TOP__spi2axi__DOT__axi_areset__0 
        = vlSelf->spi2axi__DOT__axi_areset;
}

VL_ATTR_COLD void Vspi2axi___024root___eval_final(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi2axi___024root___dump_triggers__stl(Vspi2axi___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vspi2axi___024root___eval_phase__stl(Vspi2axi___024root* vlSelf);

VL_ATTR_COLD void Vspi2axi___024root___eval_settle(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vspi2axi___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/mnt/c/Users/maha7943/Documents/PersonalProjects/Cocotb/SpiToAxi/spi2axi.sv", 33, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vspi2axi___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi2axi___024root___dump_triggers__stl(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vspi2axi___024root___stl_sequent__TOP__0(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->spi_miso = (1U & ((IData)(vlSelf->spi2axi__DOT__spi_tx_shreg) 
                              >> 7U));
    vlSelf->spi2axi__DOT__axi_areset = (1U & (~ (IData)(vlSelf->axi_aresetn)));
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
}

VL_ATTR_COLD void Vspi2axi___024root___eval_stl(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vspi2axi___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vspi2axi___024root___eval_triggers__stl(Vspi2axi___024root* vlSelf);

VL_ATTR_COLD bool Vspi2axi___024root___eval_phase__stl(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vspi2axi___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vspi2axi___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi2axi___024root___dump_triggers__ico(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi2axi___024root___dump_triggers__act(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge axi_aclk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge axi_aclk or posedge spi2axi.axi_areset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi2axi___024root___dump_triggers__nba(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge axi_aclk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge axi_aclk or posedge spi2axi.axi_areset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vspi2axi___024root___ctor_var_reset(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->spi_sck = VL_RAND_RESET_I(1);
    vlSelf->spi_ss_n = VL_RAND_RESET_I(1);
    vlSelf->spi_mosi = VL_RAND_RESET_I(1);
    vlSelf->spi_miso = VL_RAND_RESET_I(1);
    vlSelf->axi_aclk = VL_RAND_RESET_I(1);
    vlSelf->axi_aresetn = VL_RAND_RESET_I(1);
    vlSelf->s_axi_awaddr = VL_RAND_RESET_I(32);
    vlSelf->s_axi_awprot = VL_RAND_RESET_I(3);
    vlSelf->s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->s_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->s_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->s_axi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->s_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->s_axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->s_axi_arprot = VL_RAND_RESET_I(3);
    vlSelf->s_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->s_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->s_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->s_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->s_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->s_axi_rready = VL_RAND_RESET_I(1);
    vlSelf->s_axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->s_axi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->s_axi_bready = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__spi_state = 0;
    vlSelf->spi2axi__DOT__axi_state = 0;
    vlSelf->spi2axi__DOT__spi_sck_sync_old = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__spi_rx_shreg = VL_RAND_RESET_I(8);
    vlSelf->spi2axi__DOT__spi_tx_shreg = VL_RAND_RESET_I(8);
    vlSelf->spi2axi__DOT__axi_bresp_valid = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->spi2axi__DOT__axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->spi2axi__DOT__axi_rdata_valid = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->spi2axi__DOT__spi_rx_cmd = VL_RAND_RESET_I(8);
    vlSelf->spi2axi__DOT__spi_rx_addr = VL_RAND_RESET_I(32);
    vlSelf->spi2axi__DOT__spi_rx_wdata = VL_RAND_RESET_I(32);
    vlSelf->spi2axi__DOT__spi_rx_valid = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__s_axi_awvalid_int = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__s_axi_wvalid_int = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__axi_fsm_reset = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__s_axi_awaddr_int = VL_RAND_RESET_I(32);
    vlSelf->spi2axi__DOT__s_axi_awprot_int = VL_RAND_RESET_I(3);
    vlSelf->spi2axi__DOT__s_axi_wdata_int = VL_RAND_RESET_I(32);
    vlSelf->spi2axi__DOT__s_axi_wstrb_int = VL_RAND_RESET_I(4);
    vlSelf->spi2axi__DOT__s_axi_araddr_int = VL_RAND_RESET_I(32);
    vlSelf->spi2axi__DOT__s_axi_arprot_int = VL_RAND_RESET_I(3);
    vlSelf->spi2axi__DOT__s_axi_arvalid_int = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__s_axi_rready_int = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__s_axi_bready_int = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__axi_areset = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_sck_re = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_sck_fe = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte = VL_RAND_RESET_I(3);
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_sync_r = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_guard_r = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_sync_r = VL_RAND_RESET_I(1);
    vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_guard_r = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__axi_aclk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__spi2axi__DOT__axi_areset__0 = VL_RAND_RESET_I(1);
}
