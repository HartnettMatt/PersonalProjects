//--------------------------------------------------------------------------------
//--                                                                            --
//--               				4 Bit Counter Module                   			--
//--                                                                            --
//--------------------------------------------------------------------------------
//--
//-- [Replace [items in brackets] with your content]
//-- @file 4BitCounter.v
//-- @brief 4 bit counter
//-- @version: 1.0 
//-- Date of current revision:  @date 2023-09-20  
//-- Target FPGA: [Intel Altera Cyclone IV] 
//-- Tools used: [Quartus Prime 16.1] for editing and synthesis 
//--             [Modeltech ModelSIM 10.4a Student Edition] for simulation 
//--             [Quartus Prime 16.1]  for place and route if applied
//--             
//--  Functional Description:  This file contains the verilog which describes the 
//--               FPGA implementation of a 4 bit counter. 
// 
//--  Hierarchy:  There is only one level in this simple design.
//--  
//--                
//--  Designed by:  @author Matt Hartnett
//--                University of Colorado Boulder
//--                maha7943@colorado.edu
//-- 
//--      Copyright (c) 2023 by Matt Hartnett
//--
//-- Redistribution, modification or use of this software in source or binary
//-- forms is permitted as long as the files maintain this copyright. Users are
//-- permitted to modify this and use it to learn about the field of HDl code.
//-- Matt Hartnett is not liable for any misuse of this material.
//------------------------------------------------------------------------------


module FourBitCounter (P, CP, SR, PE, CEP, CET, Q, TC);
	// Define input and output
	input [3:0] P; // Parallel Input
	input CP; // Clock
	input SR; // Active Low Synchronous Reset
	input PE; // Count Enable Parallel Input
	input CEP; // Count Enable Parallel
	input CET; // Count Enable Trickle
	output [3:0]Q; // Parallel Output
	output TC; // Terminal Count
	
	reg [3:0] count;
	wire [1:0] control;
	
	assign Q = count;
	assign control[0] = CEP & CET; 	// Count enables
	assign control[1] = ~PE;		// Parallel input enable
	assign TC = &Q & CET;
	
	
	always @(posedge CP)
	begin
		if( SR == 1'b0) begin // Active low synchronous reset
			count <= 4'b0000;
		end else begin
			case (control)
				3'b00 	:	count <= count;		// If both bits are 0, then counting is disabled
				3'b01 	:	count <= count + 1;	// If the enables are high and the parallel input is low, count up
				3'b10 	:	count <= P;				// If parallel input is high, force in the input
				3'b11 	:	count <= P;				// If parallel input is high, force in the input
				default	:	count <= count;		// Disable counting is default behavior
			endcase
		end
	end
	
endmodule