#include <stdio.h>
#include "calculator.h"

int main(){
  int n1,n2, result;


  char op;
  printf("두 수를 입력 :");
  scanf("%d %d", &n1, &n2);
  getchar();
  printf("연산자 입력(+, -, *, /) :");
  scanf("%c", &op);
  if(op == '+') result = add(n1, n2);
  else if(op == '-') result = subtract(n1, n2);
  else if(op == '*') result = multiply(n1, n2);
  else if(op == '/') result = divide(n1, n2);
  else{
    printf("=> 잘못 입력!\n");
    return 0;
}
  printResult(n1,n2,result,op);
  return 0;
}
