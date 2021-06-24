#include <stdio.h>

typedef struct {
    char name[20];
    int kor;
    int eng;
    int math;
} Score;

int addScore(Score *s1);
int updateScore(Score *s1);
void readScore(Score *s);
int deleteScore(Score *s);
int selectMenu();
void listScore(Score *s, int count);
int selectDataNo(Score *s, int count);
void saveData(Score *s, int count);
int loadData(Score *s);
void searchName(Score *s, int count);