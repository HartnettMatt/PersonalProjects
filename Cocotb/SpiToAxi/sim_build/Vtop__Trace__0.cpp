// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->spi_sck));
    bufp->chgBit(oldp+1,(vlSelf->spi_ss_n));
    bufp->chgBit(oldp+2,(vlSelf->spi_mosi));
    bufp->chgBit(oldp+3,(vlSelf->spi_miso));
    bufp->chgBit(oldp+4,(vlSelf->axi_aclk));
    bufp->chgBit(oldp+5,(vlSelf->axi_aresetn));
    bufp->chgIData(oldp+6,(vlSelf->s_axi_awaddr),32);
    bufp->chgCData(oldp+7,(vlSelf->s_axi_awprot),3);
    bufp->chgBit(oldp+8,(vlSelf->s_axi_awvalid));
    bufp->chgBit(oldp+9,(vlSelf->s_axi_awready));
    bufp->chgIData(oldp+10,(vlSelf->s_axi_wdata),32);
    bufp->chgCData(oldp+11,(vlSelf->s_axi_wstrb),4);
    bufp->chgBit(oldp+12,(vlSelf->s_axi_wvalid));
    bufp->chgBit(oldp+13,(vlSelf->s_axi_wready));
    bufp->chgIData(oldp+14,(vlSelf->s_axi_araddr),32);
    bufp->chgCData(oldp+15,(vlSelf->s_axi_arprot),3);
    bufp->chgBit(oldp+16,(vlSelf->s_axi_arvalid));
    bufp->chgBit(oldp+17,(vlSelf->s_axi_arready));
    bufp->chgIData(oldp+18,(vlSelf->s_axi_rdata),32);
    bufp->chgCData(oldp+19,(vlSelf->s_axi_rresp),2);
    bufp->chgBit(oldp+20,(vlSelf->s_axi_rvalid));
    bufp->chgBit(oldp+21,(vlSelf->s_axi_rready));
    bufp->chgCData(oldp+22,(vlSelf->s_axi_bresp),2);
    bufp->chgBit(oldp+23,(vlSelf->s_axi_bvalid));
    bufp->chgBit(oldp+24,(vlSelf->s_axi_bready));
    bufp->chgBit(oldp+25,(vlSelf->spi2axi__DOT__spi_sck));
    bufp->chgBit(oldp+26,(vlSelf->spi2axi__DOT__spi_ss_n));
    bufp->chgBit(oldp+27,(vlSelf->spi2axi__DOT__spi_mosi));
    bufp->chgBit(oldp+28,(vlSelf->spi2axi__DOT__spi_miso));
    bufp->chgBit(oldp+29,(vlSelf->spi2axi__DOT__axi_aclk));
    bufp->chgBit(oldp+30,(vlSelf->spi2axi__DOT__axi_aresetn));
    bufp->chgIData(oldp+31,(vlSelf->spi2axi__DOT__s_axi_awaddr),32);
    bufp->chgCData(oldp+32,(vlSelf->spi2axi__DOT__s_axi_awprot),3);
    bufp->chgBit(oldp+33,(vlSelf->spi2axi__DOT__s_axi_awvalid));
    bufp->chgBit(oldp+34,(vlSelf->spi2axi__DOT__s_axi_awready));
    bufp->chgIData(oldp+35,(vlSelf->spi2axi__DOT__s_axi_wdata),32);
    bufp->chgCData(oldp+36,(vlSelf->spi2axi__DOT__s_axi_wstrb),4);
    bufp->chgBit(oldp+37,(vlSelf->spi2axi__DOT__s_axi_wvalid));
    bufp->chgBit(oldp+38,(vlSelf->spi2axi__DOT__s_axi_wready));
    bufp->chgIData(oldp+39,(vlSelf->spi2axi__DOT__s_axi_araddr),32);
    bufp->chgCData(oldp+40,(vlSelf->spi2axi__DOT__s_axi_arprot),3);
    bufp->chgBit(oldp+41,(vlSelf->spi2axi__DOT__s_axi_arvalid));
    bufp->chgBit(oldp+42,(vlSelf->spi2axi__DOT__s_axi_arready));
    bufp->chgIData(oldp+43,(vlSelf->spi2axi__DOT__s_axi_rdata),32);
    bufp->chgCData(oldp+44,(vlSelf->spi2axi__DOT__s_axi_rresp),2);
    bufp->chgBit(oldp+45,(vlSelf->spi2axi__DOT__s_axi_rvalid));
    bufp->chgBit(oldp+46,(vlSelf->spi2axi__DOT__s_axi_rready));
    bufp->chgCData(oldp+47,(vlSelf->spi2axi__DOT__s_axi_bresp),2);
    bufp->chgBit(oldp+48,(vlSelf->spi2axi__DOT__s_axi_bvalid));
    bufp->chgBit(oldp+49,(vlSelf->spi2axi__DOT__s_axi_bready));
    bufp->chgIData(oldp+50,(vlSelf->spi2axi__DOT__spi_state),32);
    bufp->chgIData(oldp+51,(vlSelf->spi2axi__DOT__axi_state),32);
    bufp->chgBit(oldp+52,(vlSelf->spi2axi__DOT__spi_sck_sync_old));
    bufp->chgCData(oldp+53,(vlSelf->spi2axi__DOT__spi_rx_shreg),8);
    bufp->chgCData(oldp+54,(vlSelf->spi2axi__DOT__spi_tx_shreg),8);
    bufp->chgBit(oldp+55,(vlSelf->spi2axi__DOT__axi_bresp_valid));
    bufp->chgCData(oldp+56,(vlSelf->spi2axi__DOT__axi_bresp),2);
    bufp->chgCData(oldp+57,(vlSelf->spi2axi__DOT__axi_rresp),2);
    bufp->chgBit(oldp+58,(vlSelf->spi2axi__DOT__axi_rdata_valid));
    bufp->chgIData(oldp+59,(vlSelf->spi2axi__DOT__axi_rdata),32);
    bufp->chgCData(oldp+60,(vlSelf->spi2axi__DOT__spi_rx_cmd),8);
    bufp->chgIData(oldp+61,(vlSelf->spi2axi__DOT__spi_rx_addr),32);
    bufp->chgIData(oldp+62,(vlSelf->spi2axi__DOT__spi_rx_wdata),32);
    bufp->chgBit(oldp+63,(vlSelf->spi2axi__DOT__spi_rx_valid));
    bufp->chgBit(oldp+64,(vlSelf->spi2axi__DOT__s_axi_awvalid_int));
    bufp->chgBit(oldp+65,(vlSelf->spi2axi__DOT__s_axi_wvalid_int));
    bufp->chgBit(oldp+66,(vlSelf->spi2axi__DOT__axi_fsm_reset));
    bufp->chgIData(oldp+67,(vlSelf->spi2axi__DOT__s_axi_awaddr_int),32);
    bufp->chgCData(oldp+68,(vlSelf->spi2axi__DOT__s_axi_awprot_int),3);
    bufp->chgIData(oldp+69,(vlSelf->spi2axi__DOT__s_axi_wdata_int),32);
    bufp->chgCData(oldp+70,(vlSelf->spi2axi__DOT__s_axi_wstrb_int),4);
    bufp->chgIData(oldp+71,(vlSelf->spi2axi__DOT__s_axi_araddr_int),32);
    bufp->chgCData(oldp+72,(vlSelf->spi2axi__DOT__s_axi_arprot_int),3);
    bufp->chgBit(oldp+73,(vlSelf->spi2axi__DOT__s_axi_arvalid_int));
    bufp->chgBit(oldp+74,(vlSelf->spi2axi__DOT__s_axi_rready_int));
    bufp->chgBit(oldp+75,(vlSelf->spi2axi__DOT__s_axi_bready_int));
    bufp->chgBit(oldp+76,(vlSelf->spi2axi__DOT__spi_sck_sync));
    bufp->chgBit(oldp+77,(vlSelf->spi2axi__DOT__spi_ss_n_sync));
    bufp->chgBit(oldp+78,(vlSelf->spi2axi__DOT__axi_areset));
    bufp->chgCData(oldp+79,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_bit_idx),3);
    bufp->chgCData(oldp+80,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx),5);
    bufp->chgCData(oldp+81,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx),3);
    bufp->chgCData(oldp+82,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx),5);
    bufp->chgBit(oldp+83,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_sck_re));
    bufp->chgBit(oldp+84,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_sck_fe));
    bufp->chgCData(oldp+85,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte),3);
    bufp->chgBit(oldp+86,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__i_reset));
    bufp->chgBit(oldp+87,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__i_clk));
    bufp->chgBit(oldp+88,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__i_data));
    bufp->chgBit(oldp+89,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__o_data));
    bufp->chgBit(oldp+90,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_sync_r));
    bufp->chgBit(oldp+91,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_guard_r));
    bufp->chgBit(oldp+92,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__i_reset));
    bufp->chgBit(oldp+93,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__i_clk));
    bufp->chgBit(oldp+94,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__i_data));
    bufp->chgBit(oldp+95,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__o_data));
    bufp->chgBit(oldp+96,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_sync_r));
    bufp->chgBit(oldp+97,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_guard_r));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
