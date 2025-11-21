open_project C:/Users/maha7943/Documents/Libera/SSIM-GSE/FPGA/SSIM_PPS_1/SSIM_PPS_1.xpr
reset_run synth_1
launch_runs synth_1
wait_on_run synth_1
launch_runs impl_1 -to_step write_bitstream -jobs 8
wait_on_run impl_1
puts "Bitstream Generated!"
close_project