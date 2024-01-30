// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_spi2axi);
    __Vhier.remove(&__Vscope_spi2axi, &__Vscope_spi2axi__spi_sck_sync_inst);
    __Vhier.remove(&__Vscope_spi2axi, &__Vscope_spi2axi__spi_ss_sync_inst);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_spi2axi.configure(this, name(), "spi2axi", "spi2axi", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_spi2axi__spi_fsm.configure(this, name(), "spi2axi.spi_fsm", "spi_fsm", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_spi2axi__spi_sck_sync_inst.configure(this, name(), "spi2axi.spi_sck_sync_inst", "spi_sck_sync_inst", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_spi2axi__spi_ss_sync_inst.configure(this, name(), "spi2axi.spi_ss_sync_inst", "spi_ss_sync_inst", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_spi2axi);
    __Vhier.add(&__Vscope_spi2axi, &__Vscope_spi2axi__spi_sck_sync_inst);
    __Vhier.add(&__Vscope_spi2axi, &__Vscope_spi2axi__spi_ss_sync_inst);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"axi_aclk", &(TOP.axi_aclk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"axi_aresetn", &(TOP.axi_aresetn), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_araddr", &(TOP.s_axi_araddr), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_arprot", &(TOP.s_axi_arprot), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,2,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_arready", &(TOP.s_axi_arready), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_arvalid", &(TOP.s_axi_arvalid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_awaddr", &(TOP.s_axi_awaddr), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_awprot", &(TOP.s_axi_awprot), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,2,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_awready", &(TOP.s_axi_awready), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_awvalid", &(TOP.s_axi_awvalid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_bready", &(TOP.s_axi_bready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_bresp", &(TOP.s_axi_bresp), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_bvalid", &(TOP.s_axi_bvalid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_rdata", &(TOP.s_axi_rdata), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_rready", &(TOP.s_axi_rready), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_rresp", &(TOP.s_axi_rresp), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_rvalid", &(TOP.s_axi_rvalid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_wdata", &(TOP.s_axi_wdata), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_wready", &(TOP.s_axi_wready), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_wstrb", &(TOP.s_axi_wstrb), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"s_axi_wvalid", &(TOP.s_axi_wvalid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"spi_miso", &(TOP.spi_miso), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"spi_mosi", &(TOP.spi_mosi), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"spi_sck", &(TOP.spi_sck), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"spi_ss_n", &(TOP.spi_ss_n), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"AXI_ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.spi2axi__DOT__AXI_ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"CMD_READ", const_cast<void*>(static_cast<const void*>(&(TOP.spi2axi__DOT__CMD_READ))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"CMD_WRITE", const_cast<void*>(static_cast<const void*>(&(TOP.spi2axi__DOT__CMD_WRITE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"SPI_CPHA", const_cast<void*>(static_cast<const void*>(&(TOP.spi2axi__DOT__SPI_CPHA))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"SPI_CPOL", const_cast<void*>(static_cast<const void*>(&(TOP.spi2axi__DOT__SPI_CPOL))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"SPI_FRAME_LENGTH_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.spi2axi__DOT__SPI_FRAME_LENGTH_BYTES))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"axi_aclk", &(TOP.spi2axi__DOT__axi_aclk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"axi_areset", &(TOP.spi2axi__DOT__axi_areset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"axi_aresetn", &(TOP.spi2axi__DOT__axi_aresetn), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"axi_bresp", &(TOP.spi2axi__DOT__axi_bresp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"axi_bresp_valid", &(TOP.spi2axi__DOT__axi_bresp_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"axi_fsm_reset", &(TOP.spi2axi__DOT__axi_fsm_reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"axi_rdata", &(TOP.spi2axi__DOT__axi_rdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"axi_rdata_valid", &(TOP.spi2axi__DOT__axi_rdata_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"axi_rresp", &(TOP.spi2axi__DOT__axi_rresp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"axi_state", &(TOP.spi2axi__DOT__axi_state), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_araddr", &(TOP.spi2axi__DOT__s_axi_araddr), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_araddr_int", &(TOP.spi2axi__DOT__s_axi_araddr_int), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_arprot", &(TOP.spi2axi__DOT__s_axi_arprot), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_arprot_int", &(TOP.spi2axi__DOT__s_axi_arprot_int), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_arready", &(TOP.spi2axi__DOT__s_axi_arready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_arvalid", &(TOP.spi2axi__DOT__s_axi_arvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_arvalid_int", &(TOP.spi2axi__DOT__s_axi_arvalid_int), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_awaddr", &(TOP.spi2axi__DOT__s_axi_awaddr), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_awaddr_int", &(TOP.spi2axi__DOT__s_axi_awaddr_int), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_awprot", &(TOP.spi2axi__DOT__s_axi_awprot), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_awprot_int", &(TOP.spi2axi__DOT__s_axi_awprot_int), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_awready", &(TOP.spi2axi__DOT__s_axi_awready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_awvalid", &(TOP.spi2axi__DOT__s_axi_awvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_awvalid_int", &(TOP.spi2axi__DOT__s_axi_awvalid_int), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_bready", &(TOP.spi2axi__DOT__s_axi_bready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_bready_int", &(TOP.spi2axi__DOT__s_axi_bready_int), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_bresp", &(TOP.spi2axi__DOT__s_axi_bresp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_bvalid", &(TOP.spi2axi__DOT__s_axi_bvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_rdata", &(TOP.spi2axi__DOT__s_axi_rdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_rready", &(TOP.spi2axi__DOT__s_axi_rready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_rready_int", &(TOP.spi2axi__DOT__s_axi_rready_int), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_rresp", &(TOP.spi2axi__DOT__s_axi_rresp), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_rvalid", &(TOP.spi2axi__DOT__s_axi_rvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_wdata", &(TOP.spi2axi__DOT__s_axi_wdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_wdata_int", &(TOP.spi2axi__DOT__s_axi_wdata_int), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_wready", &(TOP.spi2axi__DOT__s_axi_wready), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_wstrb", &(TOP.spi2axi__DOT__s_axi_wstrb), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_wstrb_int", &(TOP.spi2axi__DOT__s_axi_wstrb_int), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_wvalid", &(TOP.spi2axi__DOT__s_axi_wvalid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"s_axi_wvalid_int", &(TOP.spi2axi__DOT__s_axi_wvalid_int), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_miso", &(TOP.spi2axi__DOT__spi_miso), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_mosi", &(TOP.spi2axi__DOT__spi_mosi), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_rx_addr", &(TOP.spi2axi__DOT__spi_rx_addr), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_rx_cmd", &(TOP.spi2axi__DOT__spi_rx_cmd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_rx_shreg", &(TOP.spi2axi__DOT__spi_rx_shreg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_rx_valid", &(TOP.spi2axi__DOT__spi_rx_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_rx_wdata", &(TOP.spi2axi__DOT__spi_rx_wdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_sck", &(TOP.spi2axi__DOT__spi_sck), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_sck_sync", &(TOP.spi2axi__DOT__spi_sck_sync), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_sck_sync_old", &(TOP.spi2axi__DOT__spi_sck_sync_old), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_ss_n", &(TOP.spi2axi__DOT__spi_ss_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_ss_n_sync", &(TOP.spi2axi__DOT__spi_ss_n_sync), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_state", &(TOP.spi2axi__DOT__spi_state), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_spi2axi.varInsert(__Vfinal,"spi_tx_shreg", &(TOP.spi2axi__DOT__spi_tx_shreg), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_spi2axi__spi_fsm.varInsert(__Vfinal,"spi_rx_bit_idx", &(TOP.spi2axi__DOT__spi_fsm__DOT__spi_rx_bit_idx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_spi2axi__spi_fsm.varInsert(__Vfinal,"spi_rx_byte_idx", &(TOP.spi2axi__DOT__spi_fsm__DOT__spi_rx_byte_idx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,4,0);
        __Vscope_spi2axi__spi_fsm.varInsert(__Vfinal,"spi_sck_fe", &(TOP.spi2axi__DOT__spi_fsm__DOT__spi_sck_fe), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_fsm.varInsert(__Vfinal,"spi_sck_re", &(TOP.spi2axi__DOT__spi_fsm__DOT__spi_sck_re), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_fsm.varInsert(__Vfinal,"spi_tx_bit_idx", &(TOP.spi2axi__DOT__spi_fsm__DOT__spi_tx_bit_idx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_spi2axi__spi_fsm.varInsert(__Vfinal,"spi_tx_byte", &(TOP.spi2axi__DOT__spi_fsm__DOT__spi_tx_byte), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
        __Vscope_spi2axi__spi_fsm.varInsert(__Vfinal,"spi_tx_byte_idx", &(TOP.spi2axi__DOT__spi_fsm__DOT__spi_tx_byte_idx), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,4,0);
        __Vscope_spi2axi__spi_sck_sync_inst.varInsert(__Vfinal,"G_INIT_VALUE", const_cast<void*>(static_cast<const void*>(&(TOP.spi2axi__DOT__spi_sck_sync_inst__DOT__G_INIT_VALUE))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi__spi_sck_sync_inst.varInsert(__Vfinal,"G_NUM_GUARD_FFS", const_cast<void*>(static_cast<const void*>(&(TOP.spi2axi__DOT__spi_sck_sync_inst__DOT__G_NUM_GUARD_FFS))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi__spi_sck_sync_inst.varInsert(__Vfinal,"i_clk", &(TOP.spi2axi__DOT__spi_sck_sync_inst__DOT__i_clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_sck_sync_inst.varInsert(__Vfinal,"i_data", &(TOP.spi2axi__DOT__spi_sck_sync_inst__DOT__i_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_sck_sync_inst.varInsert(__Vfinal,"i_reset", &(TOP.spi2axi__DOT__spi_sck_sync_inst__DOT__i_reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_sck_sync_inst.varInsert(__Vfinal,"o_data", &(TOP.spi2axi__DOT__spi_sck_sync_inst__DOT__o_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_sck_sync_inst.varInsert(__Vfinal,"s_data_guard_r", &(TOP.spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_guard_r), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,0,0);
        __Vscope_spi2axi__spi_sck_sync_inst.varInsert(__Vfinal,"s_data_sync_r", &(TOP.spi2axi__DOT__spi_sck_sync_inst__DOT__s_data_sync_r), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_ss_sync_inst.varInsert(__Vfinal,"G_INIT_VALUE", const_cast<void*>(static_cast<const void*>(&(TOP.spi2axi__DOT__spi_ss_sync_inst__DOT__G_INIT_VALUE))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi__spi_ss_sync_inst.varInsert(__Vfinal,"G_NUM_GUARD_FFS", const_cast<void*>(static_cast<const void*>(&(TOP.spi2axi__DOT__spi_ss_sync_inst__DOT__G_NUM_GUARD_FFS))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_spi2axi__spi_ss_sync_inst.varInsert(__Vfinal,"i_clk", &(TOP.spi2axi__DOT__spi_ss_sync_inst__DOT__i_clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_ss_sync_inst.varInsert(__Vfinal,"i_data", &(TOP.spi2axi__DOT__spi_ss_sync_inst__DOT__i_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_ss_sync_inst.varInsert(__Vfinal,"i_reset", &(TOP.spi2axi__DOT__spi_ss_sync_inst__DOT__i_reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_ss_sync_inst.varInsert(__Vfinal,"o_data", &(TOP.spi2axi__DOT__spi_ss_sync_inst__DOT__o_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_spi2axi__spi_ss_sync_inst.varInsert(__Vfinal,"s_data_guard_r", &(TOP.spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_guard_r), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,0,0);
        __Vscope_spi2axi__spi_ss_sync_inst.varInsert(__Vfinal,"s_data_sync_r", &(TOP.spi2axi__DOT__spi_ss_sync_inst__DOT__s_data_sync_r), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
    }
}
