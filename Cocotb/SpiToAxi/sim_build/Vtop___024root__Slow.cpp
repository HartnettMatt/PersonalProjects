// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

// Parameter definitions for Vtop___024root
constexpr CData/*7:0*/ Vtop___024root::spi2axi__DOT__CMD_WRITE;
constexpr CData/*7:0*/ Vtop___024root::spi2axi__DOT__CMD_READ;
constexpr IData/*31:0*/ Vtop___024root::spi2axi__DOT__SPI_CPOL;
constexpr IData/*31:0*/ Vtop___024root::spi2axi__DOT__SPI_CPHA;
constexpr IData/*31:0*/ Vtop___024root::spi2axi__DOT__AXI_ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::spi2axi__DOT__SPI_FRAME_LENGTH_BYTES;
constexpr IData/*31:0*/ Vtop___024root::spi2axi__DOT__spi_sck_sync_inst__DOT__G_INIT_VALUE;
constexpr IData/*31:0*/ Vtop___024root::spi2axi__DOT__spi_sck_sync_inst__DOT__G_NUM_GUARD_FFS;
constexpr IData/*31:0*/ Vtop___024root::spi2axi__DOT__spi_ss_sync_inst__DOT__G_INIT_VALUE;
constexpr IData/*31:0*/ Vtop___024root::spi2axi__DOT__spi_ss_sync_inst__DOT__G_NUM_GUARD_FFS;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop___024root::~Vtop___024root() {
}
