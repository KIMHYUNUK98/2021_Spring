// 헤더파일에 선언한 클래스를 include 하기
#include "search_class.h"

void Search::sort_data(Search *element, int column, int num)
{
    // Search 클래스를 타입으로 하는 temp 변수를 선언
    Search temp;
    // column 번호에 따라 해당 변수를 오름차순으로 정렬시킴
    if(column == 0) {
        for(int i = 0 ; i < num - 1 ; i++) {
            for(int j = i + 1 ; j < num ; j++) {
                int check = strcmp(element[i].name, element[j].name);
                if(check > 0) {
                    temp = element[i];
                    element[i] = element[j];
                    element[j] = temp;
                }
            }
        }
    }
    else if(column == 1) {
        for(int i = 0 ; i < num - 1 ; i++) {
            for(int j = i + 1 ; j < num ; j++) {
                int check = strcmp(element[i].birthday, element[j].birthday);
                if(check > 0) {
                    temp = element[i];
                    element[i] = element[j];
                    element[j] = temp;
                }
            }
        }
    }
    else if(column == 2) {
        for(int i = 0 ; i < num - 1 ; i++) {
            for(int j = i + 1 ; j < num ; j++) {
                int check = strcmp(element[i].email, element[j].email);
                if(check > 0) {
                    temp = element[i];
                    element[i] = element[j];
                    element[j] = temp;
                }
            }
        }
    }
    else if(column == 3) {
        for(int i = 0 ; i < num - 1 ; i++) {
            for(int j = i + 1 ; j < num ; j++) {
                int check = strcmp(element[i].phone_number, element[j].phone_number);
                if(check > 0) {
                    temp = element[i];
                    element[i] = element[j];
                    element[j] = temp;
                }
            }
        }
    }
}

int Search::binsearch(Search *element, char *search_data, int left, int right, int column)
{
    // column 번호에 따라 해당 search_data와 일치하는 index 반환 
    if(column == 0) {
        int middle = (left + right) / 2;
        while(left <= right) {
        if(strcmp(element[middle].name, search_data) > 0)
            return binsearch(element, search_data, left, middle-1, column);
        else if(strcmp(element[middle].name, search_data) < 0)
            return binsearch(element, search_data, middle+1, right, column);
        else 
            return middle;
        }
        return -1;
    }
    else if(column == 1) {
        int middle = (left + right) / 2;
        while(left <= right) {
        if(strcmp(element[middle].birthday, search_data) > 0) 
            return binsearch(element, search_data, left, middle-1, column);
        else if(strcmp(element[middle].birthday, search_data) < 0)
            return binsearch(element, search_data, middle+1, right, column);
        else
            return middle;
        }
        return -1;
    }
    else if(column == 2) {
        int middle = (left + right) / 2;
        while(left <= right) {
        if(strcmp(element[middle].email, search_data) > 0) 
            return binsearch(element, search_data, left, middle-1, column);
        else if(strcmp(element[middle].email, search_data) < 0)
            return binsearch(element, search_data, middle+1, right, column);
        else 
            return middle;
        }
        return -1;
    }
    else if(column == 3) {
        int middle = (left + right) / 2;
        while(left <= right) {
        if(strcmp(element[middle].phone_number, search_data) > 0) 
            return binsearch(element, search_data, left, middle-1, column);
        else if(strcmp(element[middle].phone_number, search_data) < 0)
            return binsearch(element, search_data, middle+1, right, column);
        else 
            return middle;
        }
        return -1;
    }
    return 1;
}

void Search::read_data(char* filename, Search **element, int *num)
{
    int line = 0; 
    char str[BUFSIZE];
    char *ptr;
    FILE *fp; 

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not Found!\n");
        exit(1);
    }

    // data.dat의 파일을 라인별로 읽고 num 변수에 저장
    while (fgets(str, BUFSIZE, fp) != NULL)
    {
        line++; 
    }
    *num = line;

    // Element 클래스의 배열 동적할당 
    *element = new Search[*num];

    line = 0;
    fseek(fp, SEEK_SET, 0);

    // 모든 data를 읽고 element의 변수에 각각 저장
    while (fgets(str, BUFSIZE, fp) != NULL) 
    {
        ptr = strtok(str, ";");

        strcpy((*element)[line].name, ptr);
        ptr = strtok(NULL, ";");

        strcpy((*element)[line].birthday, ptr);
        ptr = strtok(NULL, ";");

        strcpy((*element)[line].email, ptr);
        ptr = strtok(NULL, ";");

        strcpy((*element)[line].phone_number, ptr);
        ptr = strtok(NULL, ";");
        line++;

    }
    fclose(fp); 
}

// 해당 idx에 해당하는 이름, 생일, 메일, 번호 출력
void Search::print_data(Search *element, int idx)
{   
    int i = idx;
    printf("%-20s   %-20s   %-30s   %-20s \n", "Name", "Birthday", "E-mail", "Phone Number");
    printf("----------------------------------------------------------------------------------------------------");
    printf("\n%-20s / %-20s / %-30s / %-20s \n", element[i].name, element[i].birthday, element[i].email, element[i].phone_number);
    printf("\n");
}