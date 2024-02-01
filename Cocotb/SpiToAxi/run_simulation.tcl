set sig_list [list spi_sck spi_miso spi_mosi spi_ss_n axi_aclk axi_aresetn s_axi_awaddr s_axi_awprot s_axi_awvalid s_axi_awready s_axi_wdata s_axi_wstrb s_axi_wvalid s_axi_wready spi_sck_re spi_rx_shreg spi_rx_addr spi_rx_bit_idx spi_rx_byte_idx spi_state spi_rx_cmd s_axi_bresp s_axi_bvalid s_axi_bready] 
gtkwave::addSignalsFromList $sig_list
gtkwave::/Time/Zoom/Zoom_Best_Fit
gtkwave::/View/Fullscreen 1