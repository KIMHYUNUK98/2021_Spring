#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strnins(char *s, char *t, int i);

int main() 
{
    //char src[] = {"amobile"};
    //char dst[] = {"uto"};
    char src[] = {"Han University"};
    char dst[] = {"dong Global"};

    printf("Before strnins(): %s\n", src);

    strnins(src, dst, 3);

    printf("After strnins(): %s \n", src);

    return 0;
}


void strnins(char *s, char *t, int i)
{
    char *temp = (char *) malloc(strlen(s) + strlen(t) + 1);

    if (strlen(s) == 0)
    {
        // Move all of t to s 
        while (*t != 0)
            *s++ = *t++; 
        *s = 0;
    }
    else if (strlen(t)) 
    {
        int j;
        // TODO: Move 0~i-th characters in s to temp
        for(j = 0 ; j < i; j++) {
            temp[j] = s[j];
        }

        // TODO: Move all characters in t to temp 
        for(j = i ; j < strlen(t)+3; j++) {
            temp[j] = t[j-3];
        }

        // TODO: Move i-th  ~ last characters in s to temp 
        for(j = i ; j < strlen(s); j++) {
            temp[strlen(t)+j] = s[j];
        }

        // TODO: Move all characters in temp to s 
        for(j = 0 ; j < strlen(temp); j++) {
            s[j] = temp[j];
        }
        s[strlen(temp)] = 0;
    }

    free(temp);
}