#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int kor;
    int eng;
    int math;
} Score;

int addScore(Score *s1) {
    printf("이름은? ");
    scanf("%s", s1->name);
    printf("국어는? ");
    scanf("%d", &s1->kor);
    printf("영어는? ");
    scanf("%d", &s1->eng);
    printf("수학는? ");
    scanf("%d", &s1->math);
    return 1;
}

int updateScore(Score *s1) {
    printf("이름은? ");
    scanf("%s", s1->name);
    printf("국어는? ");
    scanf("%d", &s1->kor);
    printf("영어는? ");
    scanf("%d", &s1->eng);
    printf("수학는? ");
    scanf("%d", &s1->math);
    printf("=>수정성공 !\n");
    return 1;
}

void readScore(Score *s) {
    int sum = 0;
    double avg;

    sum = s->kor + s->eng + s->math;
    avg = sum / 3.0;
    printf("%s\t %d\t %d\t %d\t %d\t %.1f\n", s->name, s->kor, s->eng, s->math, sum, avg);
}

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

void listScore(Score *s[], int count) {
    printf("no\t name\t kor\t eng\t math\t sum\t avg\t\n");
    printf("=======================================================\n");
    for(int i = 0 ; i < count ; i++) {
        if(s[i] == NULL) continue; //삭제된 것은 표시 되지 않는다.
        printf("%d\t", i+1);
        readScore(s[i]);
    }
}

int selectDataNo(Score **s, int count) {
    int no ;
    listScore(s, count);
    printf("번호는(취소 0:)?");
    scanf("%d", &no);
    return no;
}

int main() {

    Score *sp[100];
    int index = 0;
    int count = 0, menu;

    while (1){
        menu = selectMenu();
        if (menu == 0) {
            printf("종료됨!");
            break;
        }
        if(menu == 1 || menu == 3 || menu == 4)
            if(count == 0) continue;

        if (menu == 2) { 
            sp[index] = (Score*) malloc(sizeof(Score));
            count += addScore(sp[index++]); // 주소값이 넘어가는 중
            printf("=> 추가됨!\n");
        }
        
        else if (menu == 1){
            if(count >= 1) listScore(&sp[0], index); 
        }
        
        else if (menu == 3){ 
            int no = selectDataNo(sp, index);
            if(no > 0)
            updateScore(sp[no-1]); 
        }
        
        else if (menu == 4){ 
            int no = selectDataNo(sp, index);
            if(no > 0) {
            printf("정말로 삭제하시겠습니까?(1:삭제)");
            int delok;
            scanf("%d", &delok);  
                if(delok == 1) {
                    free(sp[no-1]);
                    sp[no-1] = NULL;
                    count--;
                }
            }
        }
    }
    return 0;
}