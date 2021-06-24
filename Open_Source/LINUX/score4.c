#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char gender[20];
    int number;
} Score;

int loadScore(Score *s) { // 6줄을 읽으면 i는 6가 return 된다.

    int i = 0;
    FILE *fp;
    fp = fopen("data2.txt", "rt");

    if(fp == NULL) return 0;
    else {
        for(i = 0 ; i < 100 ; i++) {
            fscanf(fp, "%s", s[i].name);
            if(feof(fp)) break;
            fscanf(fp, "%s", s[i].gender);
            fscanf(fp, "%d", &s[i].number);
        }
        fclose(fp);
        return i;
    }
}

int showMenu() {
    int menu;
    printf("***** MENU ******\n");
    printf("1. Load Data\n");
    printf("2. Add Date\n");
    printf("3. Update Data\n");
    printf("4. Save Data\n");
    printf("5. Remove Data\n");
    printf("6. Search Data\n\n");
    printf("Enter the Menu_numeber: ");
    scanf("%d", &menu);
    return menu;
}

int readScore(Score *s) {
    printf("%s\t %s\t %d\n", s->name, s->gender, s->number);
}

void listScore(Score *s, int count) {
    for(int i = 0 ; i < count ; i++) {
        printf("%d  ", i+1);
        readScore(&s[i]);
    }
}

int addScore(Score *s) {
    printf("Enter The name: ");
    scanf("%s", s->name);
    printf("Enter the gender: ");
    scanf("%s", s->gender);
    printf("Enter the people: ");
    scanf("%d", &s->number);
    printf("\n");
    return -1;
}

int selectNo(Score *s) {
    int no;
    printf("Select the Menu to Update(Cancel = 0): ");
    scanf("%d", &no);
    return no;
}

int updateScore(Score *s) {
    printf("Enter The name: ");
    scanf("%s", s->name);
    printf("Enter the gender: ");
    scanf("%s", s->gender);
    printf("Enter the people: ");
    scanf("%d", &s->number);
    printf("\n");
    return -1;
}

void saveScore(Score *s, int count) {
    int i = 0;
    FILE *fp;
    fp = fopen("data2.txt", "wt");

    for(i = 0 ; i < count ; i++) {
        if(s[i].number == -1) continue;
        fprintf(fp, "%s", s[i].name);
        fprintf(fp, "%s", s[i].gender);
        fprintf(fp, "%d", s[i].number);
    }
    fclose(fp);
    printf("Saved\n\n");

}

int deleteScore(Score *s) {
    strcpy(s->name, NULL);
    strcpy(s->gender, NULL);
    s->number = -1;
}

int main() {
    Score slist[100];        // Score *slist 와 Score slist[100]의 차이점은..?

    int menu = 0;
    int count = loadScore(slist);        // 몇줄인지가 count로 들어간다
    int index = count;                   // index 와 count 를 구분할 것

    if(count == 0) printf("No Data!!!\n");
    else {
        printf("Load Data!!!\n\n");
    }

    while(1) {
        menu = showMenu();
        if(menu == 0) {
            printf("Exit the Program\n\n"); 
            break;
        }
        if(menu == 1) {
            if(count > 0) listScore(slist, index);
            printf("\n");
        } 
        else if(menu == 2) {
            count += addScore(&slist[index++]);
        }
        else if(menu == 3) {
            int no = selectNo(slist);
            if(no == 0) {
                printf("Cancel the Update!!!\n\n");
                continue;
            }
            updateScore(&slist[no-1]);
        }
        else if(menu == 4) {
            saveScore(slist, index);
        }
        else if(menu == 5) {
            int no = selectNo(slist);
            if(no == 0) {
                printf("Cancel the Remove!!!\n");
                continue;
            }
            int delok;
            printf("Do you really want to remove?? (Enter 1): ");
            scanf("%d", delok);
            if(delok == 1) {
                if(deleteScore(&slist[delok--])) count--;
                printf("Deleted!!!\n");
            }
        }
        else if(menu == 6) {
            
        }
    }
}