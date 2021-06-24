#include "manager.h"
#include "product.h"

int loadProduct(Product *p) {
        int count = 0, i = 0;
        FILE *fp;
        fp = fopen("data.txt", "rt");

        if(fp == NULL) return 0;
        else {
                for(i = 0 ; i < 100 ; i++) {
                        fscanf(fp, "%s", p[i].name);
                        if(feof(fp)) break;
                        fscanf(fp, "%d", &p[i].price);
                        fscanf(fp, "%d", &p[i].weight);
                        fscanf(fp, "%d", &p[i].star_grade);
                        fscanf(fp, "%d", &p[i].count_star);
                }
                fclose(fp);
                return i;
        }
}

int selectDataNum(Product *p, int index){
        int no;
        listProduct(p, index);
        printf("Select Number :");
        scanf("%d", &no);
        return no;
}

int listProduct(Product *p, int index) {
        for(int i = 0 ; i < index ; i++) {
                if(p[i].price == -1) continue;
                printf("%d\t", i+1);
                readProduct(&p[i]);
        }
}

int saveProduct(Product *p, int index) {
        FILE *fp;
        fp = fopen("data.txt", "wt");

        for(int i = 0 ; i < index ; i++) {
                if(p[i].price == -1) continue;
                fprintf(fp, "%s %d %d %d %d\n", p[i].name, p[i].price, p[i].weight, p[i].star_grade, p[i].count_star);
        }
        fclose(fp);
        printf("=> Saved!!!\n");
}

void searchProduct(Product *p, int index) {
        int scnt = 0;
        char search[20];

        printf("Search the Fruit? :");
        scanf("%s", search);

        for(int i = 0 ; i < index ; i++) {
                if(p[i].price == -1) continue;
                if(strstr(p[i].name, search)) {
                        printf("%d\t", i+1);
                        readProduct(&p[i]);
                        scnt++;
                }
        }
        if(scnt == 0) printf("=> No Data!!\n");
}