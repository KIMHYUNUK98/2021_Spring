#include <stdio.h>
#include "calculator.h"

int main(){
  int n1,n2, result;


  char op;
  printf("�� ���� �Է� :");
  scanf("%d %d", &n1, &n2);
  getchar();
  printf("������ �Է�(+, -, *, /) :");
  scanf("%c", &op);
  if(op == '+') result = add(n1, n2);
  else if(op == '-') result = subtract(n1, n2);
  else if(op == '*') result = multiply(n1, n2);
  else if(op == '/') result = divide(n1, n2);
  else{
    printf("=> �߸� �Է�!\n");
    return 0;
}
  printResult(n1,n2,result,op);
  return 0;
}
