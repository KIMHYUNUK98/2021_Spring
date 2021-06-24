#include <stdio.h>
#include "calculator.h"

int add(int n1, int n2){return n1 + n2;}
int subtract(int n1, int n2){return n1 - n2;}
int multiply(int n1, int n2){return n1 * n2;}
int divide(int n1, int n2){return n1 / n2;}
void printResult(int n1, int n2, int r, char op){
    printf("=> %d %c %d = %d\n",n1,op,n2,r);
}