#include <stdio.h>
#include <string.h>
#include "score.h"

int main() {

    Score slist[100];
    int index = 0;
    int count = 0, menu;

    count = loadData(slist);
    index = count;
    if(count == 0) 
        printf("=> 파일 없음\n");
    else 
        printf("=> 로딩 성공!\n");

    while (1){
        menu = selectMenu();
        if (menu == 0) {
            printf("종료됨!");
            break;
        }
        if(menu == 1 || menu == 3 || menu == 4)
            if(count == 0) continue;
        if (menu == 1){
            printf("No\t Name\t Kor\t Eng\t Math\t Sum\t Avg\t\n");
            printf("======================================================\n");
            if(count > 0) listScore(slist, index); 
        }
        else if (menu == 2) {
            count += addScore(&slist[index++]);
            printf("=> 추가됨!!\n");
        }
        else if (menu == 3){
            int no = selectDataNo(slist, index);
            if(no == 0) {
                printf("취소됨!!\n");
                continue;
            }
            updateScore(&slist[no-1]); 
        }
        else if (menu == 4){ 
            int no = selectDataNo(slist, index);
            if(no == 0) {
                printf("취소됨!!\n");
                continue;
            }
            int delok;
            printf("정말로 삭제하시겠습니까(1:삭제)");
            scanf("%d", &delok);  
            if(delok == 1) 
                if(deleteScore(&slist[no-1])) count--;
                printf("=> 삭제됨!!\n");
            }
        else if(menu == 5) {
            saveData(slist, index);
        }
        else if(menu == 6) {
            searchName(slist, index);
        }
        }
    return 0;
}