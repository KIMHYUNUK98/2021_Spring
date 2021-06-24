#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char type[5];
    int price;
} Dinner;

int selectMenu() {
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
    printf("%d %s %s\n", d->price, d->type, d->name);
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

int listMenu(Dinner *d, int count) {
    printf("***************************\n");
    for(int i = 0 ; i < count ; i++) {
        if(d[i].price == -1) continue;
        printf("%d\t", i+1);
        readMenu(&d[i]);
    }
}

int selectDataNo(Dinner *d, int count) {
    int no ;
    listMenu(d, count);
    printf("번호는(취소 0:)?");
    scanf("%d", &no);
    return no;
}

int main() {

    Dinner dlist[20];
    int count = 0, index = 0, menu;

    while(1) {
        menu = selectMenu();
        if(menu == 0) {
            printf("종료됨!");
            break;
        }
        if(menu == 1 || menu == 3 || menu == 4)
            if(count == 0) continue;
        if(menu == 1) {
            if(count > 0) listMenu(dlist, index);
        }
        else if(menu == 2) {
            count += addMenu(&dlist[index++]);
            printf("=> 추가됨!\n");
        }
        else if(menu == 3) {
            int no = selectDataNo(dlist, index);
            if(no == 0) {
                printf("취소됨!!\n");
                continue;
            }
            updateMenu(&dlist[no-1]);
        }
        else if(menu == 4) {
            int no = selectDataNo(dlist, index);
            if(no == 0) {
                printf("취소됨!!\n");
                continue;
            }
            int delok;
            printf("정말로 삭제하시겠습니까(1:삭제)");
            scanf("%d", &delok);  
            if(delok == 1) 
                if(deleteMenu(&dlist[no-1])) count--;
                printf("=> 삭제됨!!\n");
        }
    }
    return 0;
}