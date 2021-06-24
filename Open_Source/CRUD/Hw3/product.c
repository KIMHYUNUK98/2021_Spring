#include "product.h"

int selectProduct(Product *p) {
        int menu;
        printf("\n****** Menu *********\n");
        printf("1. List Menu\n");
        printf("2. Add Menu\n");
        printf("3. Update Menu\n");
        printf("4. Delete Menu\n");
        printf("0. Exit the program\n");
        printf("Enter the Menu:  ");
        scanf("%d", &menu);
        printf("\n");

        return menu;
}

int readProduct(Product *p) {
        printf("%s\t %d\t %d\t %d\t %d\n\n", p->name, p->price, p->weight, p->star_grade, p->count_star);
        return 1;
}

int addProduct(Product *p) {
        printf("Fruit?: ");
        scanf("%s", p->name);
        printf("Price?: ");
        scanf("%d", &p->price);
        printf("Weight?: ");
        scanf("%d", &p->weight);
        printf("Grade?: ");
        scanf("%d", &p->star_grade);
        printf("Star?: ");
        scanf("%d", &p->count_star);
        return 1;
}

int updateProduct(Product *p) {
        printf("Fruit?: ");
        scanf("%s", p->name);
        printf("Price?: ");
        scanf("%d", &p->price);
        printf("Weight?: ");
        scanf("%d", &p->weight);
        printf("Grade?: ");
        scanf("%d", &p->star_grade);
        printf("Star?: ");
        scanf("%d", &p->count_star);
        printf("Update Success!!!\n\n");

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