#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

char** solution(const char*s);

int main() {
    char s[MAXLEN] = {};
    char **answer;

    printf("Input the senctance: ");
    scanf("%s", s);

    answer = solution(s);

    printf("%s", *answer);

    return 0;
}

char** solution(const char* s) {
    char** answer = (char**)malloc(1);
    *answer = (char*)malloc(sizeof(char) * MAXLEN);

    int j = 0, count = 0, max_j = 0, k = 0;
    int save[MAXLEN]= {};

    printf("%s\n", s);


    for(int i = 0 ; i < strlen(s)+1 ; i++) {
        if(s[i] == s[i+1]) {
            save[j++] = i;
        }
    }

    /*
    for(int i = 0 ; i < strlen(s)+1 ; i++) {
        printf("%c", s[i]);
        if(s[i] == '\0') printf("NULL");
    }
    */
    //printf("\n");

    //max_j = j; // max_j는 save에 저장된 숫자의 개수(분할점의 개수)

    while(s[k] != '\0') {
        if(k == save[j-1]) {
            k = k + 2;
            continue;
        }
        else {
            printf("%c\n", s[k]);
            *answer[count++] = s[k++];
            printf("111\n");
            printf("%c\n", *answer[count-1]);
        }
    }

        printf("WHen Break????\n");
    printf("%c", *answer[0]);
    printf("%c", *answer[1]);
    printf("%c", *answer[2]);

    return answer;
}