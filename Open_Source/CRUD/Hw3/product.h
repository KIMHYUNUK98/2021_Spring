#ifndef _HYUN__
#define _HYUN__
#include <stdio.h>
#include <string.h>

typedef struct {
        char name[20];
        int weight;
        int price;
        int star_grade;
        int count_star;
} Product;

int selectProduct();
int readProduct(Product *p);
int addProduct(Product *p);
int updateProduct(Product *p);
int deleteProduct(Product *p);
#endif