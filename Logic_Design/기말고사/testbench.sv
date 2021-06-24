// Code your testbench here
// or browse Examples
module tb_counter;
  
  reg clk, reset;
  wire [3:0] min1;
  wire [2:0] min10;
  wire [3:0] hour1;
  wire [1:0] hour10;
  
  clock24 clock24_counter(clk, reset, min1, min10, hour1, hour10);
  
  initial begin
    $dumpfile("dump.vcd");
    $dumpvars(1, tb_counter);
    #3000
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
      $strobe("hour10 = %d hour1 = %d : min10 = %d min1 = %d", hour10, hour1, min10, min1);
    end
  
endmodule