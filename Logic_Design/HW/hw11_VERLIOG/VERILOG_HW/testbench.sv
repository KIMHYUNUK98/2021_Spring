// Code your testbench here
// or browse Examples
module tb_counter;
  
  reg clk, reset;
  wire [3:0] count_1;
  wire [1:0] count_10;
  
  mod_m_counter mod12_counter(clk, reset, count_1, count_10);
  
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars(1, tb_counter);
    #150
    $finish;
  end
  
  initial begin
    clk = 0;
    reset = -1;
    #3 reset = 0;
  end
  
  always begin 
    #1 clk = ~clk;
  end
  
  always @(posedge clk)
    begin
      $strobe("time=%t, BCD_24_mod =%d%d", $time, count_10, count_1);
    end
  
endmodule