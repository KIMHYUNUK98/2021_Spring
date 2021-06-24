#include "product.h"
#include "manager.h"

int main() {
        Product plist[100];
        int index = 0;
        int count = 0 , menu;

        count = loadProduct(plist);
        index = count;
        if(count == 0)
                printf("=> NO FILE!!");
        else
                printf("=> LOAD SUCCESS!!");


        while(1) {
                menu = selectProduct(&plist);
                if(menu == 0) break;
                if(menu == 1 || menu == 3 || menu == 4)
                        if(count == 0) continue;
                if(menu == 1) {
                        printf("\n=============================================\n");
                        printf("No\t Fruit\t Price\t Weight\t Grade\t Stars\n");
                        if(count > 0) listProduct(plist, index);
                }
                else if(menu == 2) {
                        count += addProduct(&plist[index++]);
                }
                else if(menu == 3) {
                        int no = selectDataNum(plist, index);
                        if( no == 0 ) {
                                printf("=> Canceled!!");
                                continue;
                        }
                        updateProduct(&plist[no-1]);
                }
                else if(menu == 4) {
                       int no = selectDataNum(plist, index);
                       if(no == 0) {
                               printf("=> Canceld!!!");
                                continue;
                       }
                       int delok;
                       printf("=> READY TO DELETE? (1) ");
                       scanf("%d", &delok);
                                if(delok == 1) {
                                        if(deleteProduct(&plist[no-1])) count--;
                                        printf("=> DELETED!!");
                                }
                }
                else if(menu == 5) {
                        saveProduct(plist, index);
                }
                else if(menu == 6) {
                        searchProduct(plist, index);
                }
    }
    return 0;
}