#include <stdio.h>
#include <stdlib.h>

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
    printf("=>������!\n");
    return 1;
}

void readScore(Score *s) {
    int sum = 0;
    double avg;

    sum = s->kor + s->eng + s->math;
    avg = sum / 3.0;
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
    printf("=========================\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

void listScore(Score s[], int count) {
  for(int i = 0 ; i < count ; i++) {
    if(s[i].kor == -1) continue; //������ ���� ǥ�� ���� �ʴ´�.
    printf("%d\t", i+1);
    readScore(&s[i]);
  }

}

int selectDataNo(Score *s, int count) {
  int no ;
  listScore(s, count);
  printf("��ȣ��(��� 0:)?");
  scanf("%d", &no);
  return no;
}

int main() {

    Score slist[100];
    int index = 0;
    int count = 0, menu;

    while (1){
        menu = selectMenu();
        if (menu == 0) {
            printf("�����!");
            break;
        }
        if(menu == 1 || menu == 3 || menu == 4)
            if(count == 0) continue;
        if (menu == 1){
            printf("�̸�\t �й�\t \t Math\t Sum\t Avg\t\n"); 
            if(count > 0) listScore(slist, index); 
        }
        else if (menu == 2) {
            count += addScore(&slist[index++]);
            printf("=> �߰���!!\n");
        }
        else if (menu == 3){
            int no = selectDataNo(slist, index);
            if(no == 0) {
                printf("��ҵ�!!\n");
                continue;
            }
            updateScore(&slist[no-1]); 
        }
        else if (menu == 4){ 
            int no = selectDataNo(slist, index);
            if(no == 0) {
                printf("��ҵ�!!\n");
                continue;
            }
            int delok;
            printf("������ �����Ͻðڽ��ϱ�(1:����)");
            scanf("%d", &delok);  
            if(delok == 1) 
                if(deleteScore(&slist[no-1])) count--;
                printf("=> ������!!\n");
            }
        }
    return 0;
}