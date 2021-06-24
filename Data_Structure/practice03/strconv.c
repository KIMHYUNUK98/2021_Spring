#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 1024
char* convert_case(char*);
int main()
{
    char aLine[MAX_LEN];
    char *p;

    fgets(aLine, MAX_LEN, stdin);

    p = convert_case(aLine);
    printf("%s\n", p);

    free(p);
    return 0;
}

char* convert_case(char* src)
{
    int i = 0;
    char *ptr = malloc(sizeof(char) * (strlen(src))* MAX_LEN);

    for(i = 0 ; i<strlen(src) ; i++) {
        if(isupper(src[i])) {
            ptr[i] = tolower(src[i]);
        } else if(islower(src[i])) {
            ptr[i] = toupper(src[i]);
        } else ptr[i] = src[i];
    }
    ptr[i] = '\0';
    
    return ptr;
}
