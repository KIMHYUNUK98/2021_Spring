#include <stdio.h>

typedef struct student {
    int score[3];
    char name[20];
    char grade[10];
} Student;

int InputScore(int i, Student *s) {
    int sum = 0;
    printf("%d�� �л�: ", i+1);

        for(int j = 0 ; j < 3 ; j++) {
            scanf("%d", &s->score[j]);
            sum += s->score[j];
        }
    return sum;
}

void OutputScore(int *sum, double *avg, Student *s) {
    for(int i = 0 ; i < 5 ; i++) {

        if(avg[i] >= 90) {
            s->grade[i] = 'A';
        } else if(avg[i] >= 80) {
            s->grade[i] = 'B';
        } else if(avg[i] >= 70) {
            s->grade[i] = 'C';
        } else if(avg[i] >= 60) {
            s->grade[i] = 'D';
        } else if(avg[i] < 60) {
            s->grade[i] = 'F';
        }

        printf("%d �л��� ������ %d, ����� %.1f(��� %c)\n", i+1, sum[i], avg[i], s->grade[i]);
    }
}

int main() {
    Student s1;
    int seperate_sum[5];
    double seperate_avg[5];

    for(int i = 0 ; i < 5 ; i++) {
        seperate_sum[i] = InputScore(i,&s1);
        seperate_avg[i] = seperate_sum[i] / 3.0;
    }
    printf("\n");
    OutputScore(seperate_sum, seperate_avg, &s1);
    
    return 0;
}