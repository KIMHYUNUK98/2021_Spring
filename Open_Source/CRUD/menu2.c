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
    printf("%d %s %s\n", d->price, d->type, d->name);
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
    printf("��ȣ��(��� 0:)?");
    scanf("%d", &no);
    return no;
}

int main() {

    Dinner dlist[20];
    int count = 0, index = 0, menu;

    while(1) {
        menu = selectMenu();
        if(menu == 0) {
            printf("�����!");
            break;
        }
        if(menu == 1 || menu == 3 || menu == 4)
            if(count == 0) continue;
        if(menu == 1) {
            if(count > 0) listMenu(dlist, index);
        }
        else if(menu == 2) {
            count += addMenu(&dlist[index++]);
            printf("=> �߰���!\n");
        }
        else if(menu == 3) {
            int no = selectDataNo(dlist, index);
            if(no == 0) {
                printf("��ҵ�!!\n");
                continue;
            }
            updateMenu(&dlist[no-1]);
        }
        else if(menu == 4) {
            int no = selectDataNo(dlist, index);
            if(no == 0) {
                printf("��ҵ�!!\n");
                continue;
            }
            int delok;
            printf("������ �����Ͻðڽ��ϱ�(1:����)");
            scanf("%d", &delok);  
            if(delok == 1) 
                if(deleteMenu(&dlist[no-1])) count--;
                printf("=> ������!!\n");
        }
    }
    return 0;
}