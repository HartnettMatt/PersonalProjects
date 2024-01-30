set sig_list [list spi_sck spi_miso spi_mosi spi_ss_n axi_aclk axi_aresetn s_axi_araddr s_axi_awvalid s_axi_awready]
gtkwave::addSignalsFromList $sig_list
gtkwave::/Time/Zoom/Zoom_Best_Fit
gtkwave::/View/Fullscreen 1