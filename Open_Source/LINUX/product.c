#include <stdio.h>
#include <string.h>
#include "������_product.h"


int selectProduct(Product *p) {
    int menu;
    printf("\n****** �޴� *******\n");
    printf("1. ��ȸ�ϱ�\n");
    printf("2. �߰��ϱ�\n");
    printf("3. �����ϱ�\n");
    printf("4. �����ϱ�\n");
    printf("0. �����ϱ�\n\n");
    printf("Enter the Menu:  ");
    scanf("%d", &menu);

    return menu;
}

int readProduct(Product *p) {
    printf("%s\t %d\t %d\t %d\t %d\t\n", p->name, p->price, p->weight, p->star_grade, p->count_star);
    return 1;
}

int addProduct(Product *p) {
    printf("���� �̸���?: ");
    scanf("%s", p->name);
    printf("������? :");
    scanf("%d", &p->price);
    printf("���Դ�? :");
    scanf("%d", &p->weight);
    printf("������? :");
    scanf("%d", &p->star_grade);
    printf("���� ������? :");
    scanf("%d", &p->count_star);

    return 1;
}

int updateProduct(Product *p) {
    printf("���� �̸���?: ");
    scanf("%s", p->name);
    printf("������? :");
    scanf("%d", &p->price);
    printf("���Դ�? :");
    scanf("%d", &p->weight);
    printf("������? :");
    scanf("%d", &p->star_grade);
    printf("���� ������? :");
    scanf("%d", &p->count_star);
    printf("=> ��������!!\n");

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
            printf("����\t ����\t ����\t ����\t �� ����\n");
            readProduct(&p);
        }
        else if(menu == 2) {addProduct(&p); count++;}
        else if(menu == 3) updateProduct(&p);
        else if(menu == 4) deleteProduct(&p);
    }
    return 0;
}