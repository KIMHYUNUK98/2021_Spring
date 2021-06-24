#include <stdio.h>
#include <string.h>
#include "김현욱_product.h"


int selectProduct(Product *p) {
    int menu;
    printf("\n****** 메뉴 *******\n");
    printf("1. 조회하기\n");
    printf("2. 추가하기\n");
    printf("3. 수정하기\n");
    printf("4. 삭제하기\n");
    printf("0. 종료하기\n\n");
    printf("Enter the Menu:  ");
    scanf("%d", &menu);

    return menu;
}

int readProduct(Product *p) {
    printf("%s\t %d\t %d\t %d\t %d\t\n", p->name, p->price, p->weight, p->star_grade, p->count_star);
    return 1;
}

int addProduct(Product *p) {
    printf("과일 이름은?: ");
    scanf("%s", p->name);
    printf("가격은? :");
    scanf("%d", &p->price);
    printf("무게는? :");
    scanf("%d", &p->weight);
    printf("평점은? :");
    scanf("%d", &p->star_grade);
    printf("별의 개수는? :");
    scanf("%d", &p->count_star);

    return 1;
}

int updateProduct(Product *p) {
    printf("과일 이름은?: ");
    scanf("%s", p->name);
    printf("가격은? :");
    scanf("%d", &p->price);
    printf("무게는? :");
    scanf("%d", &p->weight);
    printf("평점은? :");
    scanf("%d", &p->star_grade);
    printf("별의 개수는? :");
    scanf("%d", &p->count_star);
    printf("=> 수정성공!!\n");

    return 1;
}

int deleteProduct(Product *p) {
    strcpy(p->name, "NULL");
    p->price = -1;
    p->weight = -1;
    p->star_grade = -1;
    p->count_star = -1;

    return 1;
}

int main() {

    Product p;
    int count = 0, menu;

    while(1) {
        menu = selectProduct(&p);
        if(menu == 0) break;
        if(menu == 1 || menu == 3 || menu ==4)
            if(count ==0) continue;
        if(menu == 1) {
            printf("\n========================================\n");
            printf("과일\t 가격\t 무게\t 평점\t 별 개수\n");
            readProduct(&p);
        }
        else if(menu == 2) {addProduct(&p); count++;}
        else if(menu == 3) updateProduct(&p);
        else if(menu == 4) deleteProduct(&p);
    }
    return 0;
}