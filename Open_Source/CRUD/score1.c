#include <stdio.h>

typedef struct {
    char name[20];
    int kor;
    int eng;
    int math;
} Score;

int addScore(Score *s1) {
    printf("�̸���? ");
    scanf("%s", s1->name);
    printf("�����? ");
    scanf("%d", &s1->kor);
    printf("�����? ");
    scanf("%d", &s1->eng);
    printf("���д�? ");
    scanf("%d", &s1->math);
    return 1;
}

int updateScore(Score *s1) {
    printf("�̸���? ");
    scanf("%s", s1->name);
    printf("�����? ");
    scanf("%d", &s1->kor);
    printf("�����? ");
    scanf("%d", &s1->eng);
    printf("���д�? ");
    scanf("%d", &s1->math);
    printf("=>�������� !\n");
    return 1;
}

void readScore(Score *s) {
    int sum = 0;
    double avg;

    sum = s->kor + s->eng + s->math;
    avg = sum / 3.0;
    printf("nane\t kor\t eng\t math\t sum\t avg\t\n");
    printf("%s\t %d\t %d\t %d\t %d\t %.1f\n", s->name, s->kor, s->eng, s->math, sum, avg);
}

int deleteScore(Score *s) {
    s->kor = -1;
    s->eng = -1;
    s->math = -1;
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** �������� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}


int main() {

    Score s;
    int count = 0, menu;

    while (1){
        menu = selectMenu();
        if (menu == 0) {
            printf("�����!");
            break;
        }
        if (menu == 1){ readScore(&s); }
        else if (menu == 2){ addScore(&s); }
        else if (menu == 3){ updateScore(&s); }
        else if (menu == 4){ 
            deleteScore(&s); 
            printf("=> ������!\n");
        }
    }
    return 0;

}