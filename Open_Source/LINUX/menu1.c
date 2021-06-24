#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char type[5];
    int price;
} Dinner;

int selectMenu(Dinner *d) {
    int menu;
    printf("\n***PizzaYaho***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int addMenu(Dinner *d) {
    printf("메뉴명은 ?");
    scanf(" %[^\n]", d->name);
    printf("메뉴종류는(P/S/R)? ");
    scanf("%s", d->type);
    printf("가격은? ");
    scanf("%d", &d->price);
    return 1;
}

void readMenu(Dinner *d) {
    printf("***************************\n");
    printf("1\t %d %s %s\n", d->price, d->type, d->name);
}

int updateMenu(Dinner *d) {
    printf("메뉴명은 ?");
    scanf(" %[^\n]", d->name);
    printf("메뉴종류는(P/S/R)? ");
    scanf("%s", d->type);
    printf("가격은? ");
    scanf("%d", &d->price);
    printf("=> 수정성공!\n");
    return 1;
}

int deleteMenu(Dinner *d) {

    strcpy(d->name, "NULL");
    strcpy(d->type, "NULL");
    d->price = -1;
    
    return 1;
}

int main() {

    Dinner d;
    int count = 0, menu;

    while(1) {
        menu = selectMenu(&d);
        if(menu == 0) {
            printf("종료됨!");
            break;
        }
        if(menu == 1) readMenu(&d);
        else if(menu == 2) addMenu(&d);
        else if(menu == 3) updateMenu(&d);
        else if(menu == 4) {
            deleteMenu(&d);
            printf("=> 삭제됨!\n");
        }
    }
    return 0;
}