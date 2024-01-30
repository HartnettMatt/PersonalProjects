// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSPI2AXI__SYMS_H_
#define VERILATED_VSPI2AXI__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vspi2axi.h"

// INCLUDE MODULE CLASSES
#include "Vspi2axi___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vspi2axi__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vspi2axi* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vspi2axi___024root             TOP;

    // CONSTRUCTORS
    Vspi2axi__Syms(VerilatedContext* contextp, const char* namep, Vspi2axi* modelp);
    ~Vspi2axi__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
