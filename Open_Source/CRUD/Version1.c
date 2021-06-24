#include <stdio.h>

int main() {
    
    int i, j,num1, num2, num3;
    int sum[5];
    double aver[5];
    char grade[5];

    for(i = 0 ; i < 5 ; i++) {
        printf("%d번 학생 : ", i+1);
        scanf("%d %d %d", &num1, &num2, &num3);
        sum[i] = num1 + num2 + num3;
        aver[i] = sum[i] / 3.0;

        if(aver[i] >= 90) {
            grade[i] = 'A';
        } else if(aver[i] >= 80) {
            grade[i] = 'B';
        } else if(aver[i] >= 70) {
            grade[i] = 'C';
        } else if(aver[i] >= 60) {
            grade[i] = 'D';
        } else if(aver[i] < 60) {
            grade[i] = 'F';
        }
    }
    printf("\n");

    for(j = 0; j < 5; j++) {
        printf("%d번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", j, sum[j], aver[j], grade[j]);
    }

    return 0;
}