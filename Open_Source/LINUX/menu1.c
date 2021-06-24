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
    printf("1. �޴���ȸ\n");
    printf("2. �޴��߰�\n");
    printf("3. �޴�����\n");
    printf("4. �޴�����\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

int addMenu(Dinner *d) {
    printf("�޴����� ?");
    scanf(" %[^\n]", d->name);
    printf("�޴�������(P/S/R)? ");
    scanf("%s", d->type);
    printf("������? ");
    scanf("%d", &d->price);
    return 1;
}

void readMenu(Dinner *d) {
    printf("***************************\n");
    printf("1\t %d %s %s\n", d->price, d->type, d->name);
}

int updateMenu(Dinner *d) {
    printf("�޴����� ?");
    scanf(" %[^\n]", d->name);
    printf("�޴�������(P/S/R)? ");
    scanf("%s", d->type);
    printf("������? ");
    scanf("%d", &d->price);
    printf("=> ��������!\n");
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
            printf("�����!");
            break;
        }
        if(menu == 1) readMenu(&d);
        else if(menu == 2) addMenu(&d);
        else if(menu == 3) updateMenu(&d);
        else if(menu == 4) {
            deleteMenu(&d);
            printf("=> ������!\n");
        }
    }
    return 0;
}