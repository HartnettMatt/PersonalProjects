// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi2axi.h for the primary calling header

#include "Vspi2axi__pch.h"
#include "Vspi2axi__Syms.h"
#include "Vspi2axi___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi2axi___024root___dump_triggers__ico(Vspi2axi___024root* vlSelf);
#endif  // VL_DEBUG

void Vspi2axi___024root___eval_triggers__ico(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vspi2axi___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi2axi___024root___dump_triggers__act(Vspi2axi___024root* vlSelf);
#endif  // VL_DEBUG

void Vspi2axi___024root___eval_triggers__act(Vspi2axi___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vspi2axi__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi2axi___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->axi_aclk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_aclk__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->axi_aclk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_aclk__0))) 
                                     | ((IData)(vlSelf->spi2axi__DOT__axi_areset) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__spi2axi__DOT__axi_areset__0)))));
    vlSelf->__Vtrigprevexpr___TOP__axi_aclk__0 = vlSelf->axi_aclk;
    vlSelf->__Vtrigprevexpr___TOP__spi2axi__DOT__axi_areset__0 
        = vlSelf->spi2axi__DOT__axi_areset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vspi2axi___024root___dump_triggers__act(vlSelf);
    }
#endif
}
