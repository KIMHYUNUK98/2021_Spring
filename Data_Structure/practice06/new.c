#include <stdio.h>

int main(void) {
        int size, scnt, bcnt;
        printf("size? ");
        scanf("%d", &size);
        scnt = 1;
        bcnt = (size - 1) * 2;
        for(int i = 0 ; i < size*2-1 ; i++) {
                for(int j = 0 ; j < scnt ; j++) printf("*");
                for(int j = 0 ; j < bcnt ; j++) printf(" ");
                for(int j = 0 ; j < scnt ; j++) printf("*");
                if(i < size - 1) {
                        scnt++; bcnt -=2;
                } else {
                        scnt--; bcnt +=2;
                } printf("\n");
        }
        return 0;
}