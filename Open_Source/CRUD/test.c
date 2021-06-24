#include<stdio.h>

typedef struct{
    char name[20];
    int kor;
    int eng;
    int math;
} Score;

int selectMenu(Score *s) {
    int menu = 0;

    printf("***Calculator Score***\n");
    printf("1. Show\n");
    printf("2. Add\n");
    printf("3. Change\n");
    printf("4. Delete\n");
    printf("5. Save\n");
    printf("0. ByeBye\n\n");
    printf("=> Select Menu? ");
    scanf("%d", menu);

    return menu;
}

void readScore(Score *s) {
    int sum = 0;
    double avg;

    sum = s->kor + s->eng + s->math;
    avg = sum / 3.0;
    printf("%s\t %d\t %d\t %d\t %d\t %.1f\n", s->name, s->kor, s->eng, s->math, sum, avg);
}

int loadData(Score *s) {

    int fp, i;
    FILE *fp;
    fp = fopen("score.txt", "rt");

    if(fp == NULL) return 0;
    else 
        for( i = 0 ; i < 100 ; i++) {
            fscanf(fp, "%s", s[i].name);
            if(feof(fp)) continue;
            fscanf(fp, "%d", &s[i].kor);
            fscanf(fp, "%d", &s[i].eng);
            fscanf(fp, "%d", &s[i].math);
        }
    fclose(fp);

    return i;
}

void listScore(Score *s, int count) {
    for(int i = 0 ; i < count ; i++) {
        if(s[i].kor == -1) continue;
        printf("%d\t", i+1);
        readScore(&s[i]);
    }
}

int addScore(Score *s) {
    
}

int main() {

    Score slist[100];
    int count, index, menu;

    count = loadData(slist);
    index = count;

    if(count == 0) printf("=>No loading!!");
    else printf("loading Success!!!");

    while(1) {
        menu = selectmenu(slist);

        if(menu == 0) 
            printf("ByeBye!!!!\n");
            break;
        if(menu == 1 || menu == 3 || menu == 4)
            if(count == 0) continue;
        if(menu == 1) {
            printf("No\t Name\t Kor\t Eng\t Math\t Sum\t Avg\t\n");
            printf("======================================================\n");
            if(count > 0) listScore(slist, count);
        }
        else if(menu == 2) {
            count += addScore(&slist[index++]);
            printf("=> ADDED!!");
        }
    }


    return 0;
}