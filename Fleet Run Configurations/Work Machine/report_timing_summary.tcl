open_project C:/Users/maha7943/Documents/Libera/SSIM-GSE/FPGA/SSIM_PPS_1/SSIM_PPS_1.xpr
reset_run synth_1
launch_runs synth_1
wait_on_run synth_1
launch_runs impl_1 -jobs 8
wait_on_run impl_1
puts "Implementation completed"
puts "Running timing analysis:"
open_run impl_1
report_timing_summary -delay_type min_max -report_unconstrained -check_timing_verbose -max_paths 10 -input_pins -routable_nets -warn_on_violation
puts "Timing analysis completed"
close_project