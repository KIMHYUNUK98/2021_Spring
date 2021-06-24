// Code your design here
module mod_m_counter
  (input wire clk, reset,
   output wire [3:0] count_1,
   output wire [1:0] count_10);
  
  reg [3:0] r_reg;
  reg [3:0] r_next;
  reg [1:0] l_reg;
  reg [1:0] l_next;
  
  always @(posedge clk, posedge reset)
    if(reset) begin
      r_reg <= 0;
  	  l_reg <= 0;
    end
      else begin
      r_reg <= r_next;
  	  l_reg <= l_next;
      end

  always @*begin
 	if(r_reg == 9) begin
    	r_next = 0;
    	l_next = l_reg+1;
  	end
  	else if(r_reg == 3 & l_reg == 2) begin
    	r_next = 0;
    	l_next = 0;
  	end
  	else begin
    	r_next = r_reg+1;
    	l_next = l_reg;
  	end
  end

  assign count_1 = r_reg;
  assign count_10 = l_reg;
  
endmodule