// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,0,"spi_sck",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"spi_ss_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"spi_mosi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"spi_miso",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"axi_aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"axi_aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"s_axi_awprot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+9,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"s_axi_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"s_axi_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+13,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"s_axi_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"s_axi_arprot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+17,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"s_axi_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+21,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"s_axi_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+24,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"s_axi_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("spi2axi", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+99,0,"SPI_CPOL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"SPI_CPHA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"AXI_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"spi_sck",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"spi_ss_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"spi_mosi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"spi_miso",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"axi_aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"axi_aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"s_axi_awprot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+34,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"s_axi_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"s_axi_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+38,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"s_axi_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"s_axi_arprot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+42,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"s_axi_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+46,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"s_axi_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+49,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"s_axi_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"CMD_WRITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+102,0,"CMD_READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+103,0,"SPI_FRAME_LENGTH_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+51,0,"spi_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+52,0,"axi_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+53,0,"spi_sck_sync_old",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"spi_rx_shreg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+55,0,"spi_tx_shreg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+56,0,"axi_bresp_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"axi_bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+58,0,"axi_rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+59,0,"axi_rdata_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"axi_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"spi_rx_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+62,0,"spi_rx_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"spi_rx_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+64,0,"spi_rx_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"s_axi_awvalid_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"s_axi_wvalid_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"axi_fsm_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"s_axi_awaddr_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"s_axi_awprot_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+70,0,"s_axi_wdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"s_axi_wstrb_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+72,0,"s_axi_araddr_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"s_axi_arprot_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+74,0,"s_axi_arvalid_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"s_axi_rready_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"s_axi_bready_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"spi_sck_sync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"spi_ss_n_sync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"axi_areset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("spi_fsm", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+80,0,"spi_rx_bit_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+81,0,"spi_rx_byte_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+82,0,"spi_tx_bit_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+83,0,"spi_tx_byte_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+84,0,"spi_sck_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"spi_sck_fe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+86,0,"spi_tx_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("spi_sck_sync_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+99,0,"G_INIT_VALUE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"G_NUM_GUARD_FFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+87,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"s_data_sync_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"s_data_guard_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("spi_ss_sync_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+99,0,"G_INIT_VALUE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"G_NUM_GUARD_FFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+93,0,"i_reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"s_data_sync_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"s_data_guard_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+99,(0U),32);
    bufp->fullIData(oldp+100,(0x20U),32);
    bufp->fullCData(oldp+101,(0U),8);
    bufp->fullCData(oldp+102,(1U),8);
    bufp->fullIData(oldp+103,(0xbU),32);
    bufp->fullIData(oldp+104,(1U),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->spi_sck));
    bufp->fullBit(oldp+2,(vlSelf->spi_ss_n));
    bufp->fullBit(oldp+3,(vlSelf->spi_mosi));
    bufp->fullBit(oldp+4,(vlSelf->spi_miso));
    bufp->fullBit(oldp+5,(vlSelf->axi_aclk));
    bufp->fullBit(oldp+6,(vlSelf->axi_aresetn));
    bufp->fullIData(oldp+7,(vlSelf->s_axi_awaddr),32);
    bufp->fullCData(oldp+8,(vlSelf->s_axi_awprot),3);
    bufp->fullBit(oldp+9,(vlSelf->s_axi_awvalid));
    bufp->fullBit(oldp+10,(vlSelf->s_axi_awready));
    bufp->fullIData(oldp+11,(vlSelf->s_axi_wdata),32);
    bufp->fullCData(oldp+12,(vlSelf->s_axi_wstrb),4);
    bufp->fullBit(oldp+13,(vlSelf->s_axi_wvalid));
    bufp->fullBit(oldp+14,(vlSelf->s_axi_wready));
    bufp->fullIData(oldp+15,(vlSelf->s_axi_araddr),32);
    bufp->fullCData(oldp+16,(vlSelf->s_axi_arprot),3);
    bufp->fullBit(oldp+17,(vlSelf->s_axi_arvalid));
    bufp->fullBit(oldp+18,(vlSelf->s_axi_arready));
    bufp->fullIData(oldp+19,(vlSelf->s_axi_rdata),32);
    bufp->fullCData(oldp+20,(vlSelf->s_axi_rresp),2);
    bufp->fullBit(oldp+21,(vlSelf->s_axi_rvalid));
    bufp->fullBit(oldp+22,(vlSelf->s_axi_rready));
    bufp->fullCData(oldp+23,(vlSelf->s_axi_bresp),2);
    bufp->fullBit(oldp+24,(vlSelf->s_axi_bvalid));
    bufp->fullBit(oldp+25,(vlSelf->s_axi_bready));
    bufp->fullBit(oldp+26,(vlSelf->spi2axi__DOT__spi_sck));
    bufp->fullBit(oldp+27,(vlSelf->spi2axi__DOT__spi_ss_n));
    bufp->fullBit(oldp+28,(vlSelf->spi2axi__DOT__spi_mosi));
    bufp->fullBit(oldp+29,(vlSelf->spi2axi__DOT__spi_miso));
    bufp->fullBit(oldp+30,(vlSelf->spi2axi__DOT__axi_aclk));
    bufp->fullBit(oldp+31,(vlSelf->spi2axi__DOT__axi_aresetn));
    bufp->fullIData(oldp+32,(vlSelf->spi2axi__DOT__s_axi_awaddr),32);
    bufp->fullCData(oldp+33,(vlSelf->spi2axi__DOT__s_axi_awprot),3);
    bufp->fullBit(oldp+34,(vlSelf->spi2axi__DOT__s_axi_awvalid));
    bufp->fullBit(oldp+35,(vlSelf->spi2axi__DOT__s_axi_awready));
    bufp->fullIData(oldp+36,(vlSelf->spi2axi__DOT__s_axi_wdata),32);
    bufp->fullCData(oldp+37,(vlSelf->spi2axi__DOT__s_axi_wstrb),4);
    bufp->fullBit(oldp+38,(vlSelf->spi2axi__DOT__s_axi_wvalid));
    bufp->fullBit(oldp+39,(vlSelf->spi2axi__DOT__s_axi_wready));
    bufp->fullIData(oldp+40,(vlSelf->spi2axi__DOT__s_axi_araddr),32);
    bufp->fullCData(oldp+41,(vlSelf->spi2axi__DOT__s_axi_arprot),3);
    bufp->fullBit(oldp+42,(vlSelf->spi2axi__DOT__s_axi_arvalid));
    bufp->fullBit(oldp+43,(vlSelf->spi2axi__DOT__s_axi_arready));
    bufp->fullIData(oldp+44,(vlSelf->spi2axi__DOT__s_axi_rdata),32);
    bufp->fullCData(oldp+45,(vlSelf->spi2axi__DOT__s_axi_rresp),2);
    bufp->fullBit(oldp+46,(vlSelf->spi2axi__DOT__s_axi_rvalid));
    bufp->fullBit(oldp+47,(vlSelf->spi2axi__DOT__s_axi_rready));
    bufp->fullCData(oldp+48,(vlSelf->spi2axi__DOT__s_axi_bresp),2);
    bufp->fullBit(oldp+49,(vlSelf->spi2axi__DOT__s_axi_bvalid));
    bufp->fullBit(oldp+50,(vlSelf->spi2axi__DOT__s_axi_bready));
    bufp->fullIData(oldp+51,(vlSelf->spi2axi__DOT__spi_state),32);
    bufp->fullIData(oldp+52,(vlSelf->spi2axi__DOT__axi_state),32);
    bufp->fullBit(oldp+53,(vlSelf->spi2axi__DOT__spi_sck_sync_old));
    bufp->fullCData(oldp+54,(vlSelf->spi2axi__DOT__spi_rx_shreg),8);
    bufp->fullCData(oldp+55,(vlSelf->spi2axi__DOT__spi_tx_shreg),8);
    bufp->fullBit(oldp+56,(vlSelf->spi2axi__DOT__axi_bresp_valid));
    bufp->fullCData(oldp+57,(vlSelf->spi2axi__DOT__axi_bresp),2);
    bufp->fullCData(oldp+58,(vlSelf->spi2axi__DOT__axi_rresp),2);
    bufp->fullBit(oldp+59,(vlSelf->spi2axi__DOT__axi_rdata_valid));
    bufp->fullIData(oldp+60,(vlSelf->spi2axi__DOT__axi_rdata),32);
    bufp->fullCData(oldp+61,(vlSelf->spi2axi__DOT__spi_rx_cmd),8);
    bufp->fullIData(oldp+62,(vlSelf->spi2axi__DOT__spi_rx_addr),32);
    bufp->fullIData(oldp+63,(vlSelf->spi2axi__DOT__spi_rx_wdata),32);
    bufp->fullBit(oldp+64,(vlSelf->spi2axi__DOT__spi_rx_valid));
    bufp->fullBit(oldp+65,(vlSelf->spi2axi__DOT__s_axi_awvalid_int));
    bufp->fullBit(oldp+66,(vlSelf->spi2axi__DOT__s_axi_wvalid_int));
    bufp->fullBit(oldp+67,(vlSelf->spi2axi__DOT__axi_fsm_reset));
    bufp->fullIData(oldp+68,(vlSelf->spi2axi__DOT__s_axi_awaddr_int),32);
    bufp->fullCData(oldp+69,(vlSelf->spi2axi__DOT__s_axi_awprot_int),3);
    bufp->fullIData(oldp+70,(vlSelf->spi2axi__DOT__s_axi_wdata_int),32);
    bufp->fullCData(oldp+71,(vlSelf->spi2axi__DOT__s_axi_wstrb_int),4);
    bufp->fullIData(oldp+72,(vlSelf->spi2axi__DOT__s_axi_araddr_int),32);
    bufp->fullCData(oldp+73,(vlSelf->spi2axi__DOT__s_axi_arprot_int),3);
    bufp->fullBit(oldp+74,(vlSelf->spi2axi__DOT__s_axi_arvalid_int));
    bufp->fullBit(oldp+75,(vlSelf->spi2axi__DOT__s_axi_rready_int));
    bufp->fullBit(oldp+76,(vlSelf->spi2axi__DOT__s_axi_bready_int));
    bufp->fullBit(oldp+77,(vlSelf->spi2axi__DOT__spi_sck_sync));
    bufp->fullBit(oldp+78,(vlSelf->spi2axi__DOT__spi_ss_n_sync));
    bufp->fullBit(oldp+79,(vlSelf->spi2axi__DOT__axi_areset));
    bufp->fullCData(oldp+80,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_bit_idx),3);
    bufp->fullCData(oldp+81,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx),5);
    bufp->fullCData(oldp+82,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx),3);
    bufp->fullCData(oldp+83,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx),5);
    bufp->fullBit(oldp+84,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_sck_re));
    bufp->fullBit(oldp+85,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_sck_fe));
    bufp->fullCData(oldp+86,(vlSelf->spi2axi__DOT__spi_fsm__DOT__spi_tx_byte),3);
    bufp->fullBit(oldp+87,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__i_reset));
    bufp->fullBit(oldp+88,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__i_clk));
    bufp->fullBit(oldp+89,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__i_data));
    bufp->fullBit(oldp+90,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__o_data));
    bufp->fullBit(oldp+91,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_sync_r));
    bufp->fullBit(oldp+92,(vlSelf->spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_guard_r));
    bufp->fullBit(oldp+93,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__i_reset));
    bufp->fullBit(oldp+94,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__i_clk));
    bufp->fullBit(oldp+95,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__i_data));
    bufp->fullBit(oldp+96,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__o_data));
    bufp->fullBit(oldp+97,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_sync_r));
    bufp->fullBit(oldp+98,(vlSelf->spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_guard_r));
}
