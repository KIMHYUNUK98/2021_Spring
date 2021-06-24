#include<stdio.h>

int main() {
        
    int i, j,num1, num2, num3;
    int sum1, sum2, sum3, sum4, sum5;
    double avg1, avg2, avg3, avg4, avg5;
    char grade1, grade2, grade3, grade4, grade5;

    printf("1번 학생 : ");
    scanf("%d %d %d", &num1, &num2, &num3);
    sum1 = num1 + num2 + num3;
    avg1 = sum1 / 3.0;

    printf("2번 학생 : ");
    scanf("%d %d %d", &num1, &num2, &num3);
    sum2 = num1 + num2 + num3;
    avg2 = sum2 / 3.0;
    
    printf("3번 학생 : ");
    scanf("%d %d %d", &num1, &num2, &num3);
    sum3 = num1 + num2 + num3;
    avg3 = sum3 / 3.0;

    printf("4번 학생 : ");
    scanf("%d %d %d", &num1, &num2, &num3);
    sum4 = num1 + num2 + num3;
    avg4 = sum4 / 3.0;

    printf("5번 학생 : ");
    scanf("%d %d %d", &num1, &num2, &num3);
    sum5 = num1 + num2 + num3;
    avg5 = sum5 / 3.0;

    if(avg1 >= 90) {
        grade1 = 'A';
    } else if(avg1 >= 80) {
        grade1 = 'B';
    } else if(avg1 >= 70) {
        grade1 = 'C';
    } else if(avg1 >= 60) {
        grade1 = 'D';
    } else if(avg1 < 60) {
        grade1 = 'F';
    }

    if(avg2 >= 90) {
        grade2 = 'A';
    } else if(avg2 >= 80) {
        grade2 = 'B';
    } else if(avg2 >= 70) {
        grade2 = 'C';
    } else if(avg2 >= 60) {
        grade2 = 'D';
    } else if(avg2 < 60) {
        grade2 = 'F';
    }

    if(avg3 >= 90) {
        grade3 = 'A';
    } else if(avg3 >= 80) {
        grade3 = 'B';
    } else if(avg3 >= 70) {
        grade3 = 'C';
    } else if(avg3 >= 60) {
        grade3 = 'D';
    } else if(avg3 < 60) {
        grade3 = 'F';
    }

    if(avg4 >= 90) {
        grade4 = 'A';
    } else if(avg4 >= 80) {
        grade4 = 'B';
    } else if(avg4 >= 70) {
        grade4 = 'C';
    } else if(avg4 >= 60) {
        grade4 = 'D';
    } else if(avg4 < 60) {
        grade4 = 'F';
    }

    if(avg5 >= 90) {
        grade5 = 'A';
    } else if(avg5 >= 80) {
        grade5 = 'B';
    } else if(avg5 >= 70) {
        grade5 = 'C';
    } else if(avg5 >= 60) {
        grade5 = 'D';
    } else if(avg5 < 60) {
        grade5 = 'F';
        }
    
    printf("\n");

    printf("%d번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", j, sum1, avg1, grade1);
    printf("%d번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", j, sum2, avg2, grade2);
    printf("%d번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", j, sum3, avg3, grade3);
    printf("%d번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", j, sum4, avg4, grade4);
    printf("%d번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", j, sum5, avg5, grade5);
    
    return 0;
}