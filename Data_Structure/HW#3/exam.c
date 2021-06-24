#include <stdio.h>

int main() {
     int num;
    char array[5];
    char Input[5];

    printf("Num: ");
    scanf("%d", &num);

    printf("Number array: ");
    scanf("%s", Input);
    /*for(int i = 0 ; i < num ; i++) {
        scanf(" %c", &Input[i]);
    } */

    //scanf("%s", &Input);
    printf("Input = %c %c %c", Input[0], Input[1], Input[2]);
}