// My code is correctly working.
module clock24
  (input wire clk, reset,
   output wire [3:0] min1,
   output wire [2:0] min10,
   output wire [3:0] hour1,
   output wire [1:0] hour10);
  
  reg [3:0] m1_reg;
  reg [3:0] m1_next;
  reg [2:0] m10_reg;
  reg [2:0] m10_next;
  reg [3:0] h1_reg;
  reg [3:0] h1_next;
  reg [1:0] h10_reg;
  reg [1:0] h10_next;
  
  always @(posedge clk, posedge reset)
    if(reset) begin
      m1_reg <= 0;
  	  m10_reg <= 0;
      h1_reg <= 0;
      h10_reg <= 0;
    end
      else begin
      m1_reg <= m1_next;
  	  m10_reg <= m10_next;
      h1_reg <= h1_next;
      h10_reg <= h10_next;
      end

  always @*begin
    if(m1_reg == 9) begin
    	m1_next = 0;
    	m10_next = m10_reg+1;
      if(m10_reg == 5) begin
        m1_next = 0;
        m10_next = 0;
        if(h1_reg == 9) begin
          h1_next = 0;
          h10_next = h10_reg + 1;
        end
        else 
        	h1_next = h1_reg + 1;
        if(h10_reg == 2 & h1_reg == 3) begin
          m1_next = 0;
          m10_next = 0;
          h1_next = 0;
          h10_next = 0;
        end
      end
  	end
    
  	else begin
    	m1_next = m1_reg+1;
      	m10_next = m10_reg;
      	h1_next = h1_reg;
      	h10_next = h10_reg;
  	end
  end

  assign min1 = m1_reg;
  assign min10 = m10_reg;
  assign hour1 = h1_reg;
  assign hour10 = h10_reg;
  
endmodule