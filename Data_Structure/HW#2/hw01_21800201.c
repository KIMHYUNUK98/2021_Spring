#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 128

struct contact {
    char name[30]; 
    char birthday[10]; 
    char email[30];
    char phone_number[20];
};

void read_data(char* filename, struct contact **contacts, int *num);
void print_data(struct contact *data, int num); 
void sort_data(struct contact *data, int column, int num);
int binsearch(struct contact *contacts, char *search_data, int left, int right, int column);

int main(int argc, char *argv[])
{
    struct contact *contacts;
    int num;
    int column = atoi(argv[2]);

    // argc must be 4
    if(argc == 4) {
        // column number range 0 ~ 3
        if(column >= 0 && column <= 3) {

            read_data(argv[1], &contacts, &num);                        // read_data using argv[1] (filename)
            sort_data(contacts, column, num);                           // sort_data in ascending order
            int idx = binsearch(contacts, argv[3], 0, num-1, column);   // binsearch using strcmp and return idx or -1

            if(idx < 0) {                                               // if idx < 0 print "Not Found!!"
                printf("%s Not Found!!\n", argv[3]);
                printf("\n");
            } else {
                print_data(contacts, idx);                              // else print the search data 
            }
        }
        else {
            printf("Column range should be 0 ~ 3!\n\n");
        }
    }
    else {
        printf("Usage:  search.exe <Data File> <Column Number> <Search Data>\n\n");
    }
    return 0; 
}

int binsearch(struct contact *contacts, char *search_data, int left, int right, int column) {

    // using column number to select the name / birthday / E-mail / Phone number
    if(column == 0) {
        int middle = (left + right) / 2;
        while(left <= right) {
        if(strcmp(contacts[middle].name, search_data) > 0)
            return binsearch(contacts, search_data, left, middle-1, column);
        else if(strcmp(contacts[middle].name, search_data) < 0)
            return binsearch(contacts, search_data, middle+1, right, column);
        else 
            return middle;
        }
        return -1;
    }
    else if(column == 1) {
        int middle = (left + right) / 2;
        while(left <= right) {
        if(strcmp(contacts[middle].birthday, search_data) > 0) 
            return binsearch(contacts, search_data, left, middle-1, column);
        else if(strcmp(contacts[middle].birthday, search_data) < 0)
            return binsearch(contacts, search_data, middle+1, right, column);
        else
            return middle;
        }
        return -1;
    }
    else if(column == 2) {
        int middle = (left + right) / 2;
        while(left <= right) {
        if(strcmp(contacts[middle].email, search_data) > 0) 
            return binsearch(contacts, search_data, left, middle-1, column);
        else if(strcmp(contacts[middle].email, search_data) < 0)
            return binsearch(contacts, search_data, middle+1, right, column);
        else 
            return middle;
        }
        return -1;
    }
    else if(column == 3) {
        int middle = (left + right) / 2;
        while(left <= right) {
        if(strcmp(contacts[middle].phone_number, search_data) > 0) 
            return binsearch(contacts, search_data, left, middle-1, column);
        else if(strcmp(contacts[middle].phone_number, search_data) < 0)
            return binsearch(contacts, search_data, middle+1, right, column);
        else 
            return middle;
        }
        return -1;
    }
}


void sort_data(struct contact *contacts, int column, int num) {
    struct contact temp;

    //sort data regarding to the column number
    if(column == 0) {
        for(int i = 0 ; i < num - 1 ; i++) {
            for(int j = i + 1 ; j < num ; j++) {
                int check = strcmp(contacts[i].name, contacts[j].name);
                if(check > 0) {
                    temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }
    else if(column == 1) {
        for(int i = 0 ; i < num - 1 ; i++) {
            for(int j = i + 1 ; j < num ; j++) {
                int check = strcmp(contacts[i].birthday, contacts[j].birthday);
                if(check > 0) {
                    temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }
    else if(column == 2) {
        for(int i = 0 ; i < num - 1 ; i++) {
            for(int j = i + 1 ; j < num ; j++) {
                int check = strcmp(contacts[i].email, contacts[j].email);
                if(check > 0) {
                    temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }
    else if(column == 3) {
        for(int i = 0 ; i < num - 1 ; i++) {
            for(int j = i + 1 ; j < num ; j++) {
                int check = strcmp(contacts[i].phone_number, contacts[j].phone_number);
                if(check > 0) {
                    temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }
}

void read_data(char* filename, struct contact **contacts, int *num)
{
    int line = 0; 
    char str[BUFSIZE];
    char *ptr;
    FILE *fp; 

    // open filename with read condition
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not Found!\n");
        exit(1);
    }

    // read each lines and store to pointer num
    while (fgets(str, BUFSIZE, fp) != NULL)
    {
        line++; 
    }
    *num = line;

    // create structure array 
    *contacts = malloc(sizeof(struct contact) * (*num));

    // rewind
    line = 0;
    fseek(fp, SEEK_SET, 0);

    //copy all data using strtok and strcpy
    while (fgets(str, BUFSIZE, fp) != NULL) 
    {
        ptr = strtok(str, ";");
        strcpy((*contacts)[line].name, ptr);
        ptr = strtok(NULL, ";");
        strcpy((*contacts)[line].birthday, ptr);
        ptr = strtok(NULL, ";");
        strcpy((*contacts)[line].email, ptr);
        ptr = strtok(NULL, ";");
        strcpy((*contacts)[line].phone_number, ptr);
        ptr = strtok(NULL, ";");
        line++; 
    }
    fclose(fp); 
}


void print_data(struct contact *contacts, int idx)
{   
    int i = idx;
    printf("%-20s   %-20s   %-30s   %-20s \n", "Name", "Birthday", "E-mail", "Phone Number");
    printf("----------------------------------------------------------------------------------------------------");
    printf("\n%-20s / %-20s / %-30s / %-20s \n", contacts[i].name, contacts[i].birthday, contacts[i].email, contacts[i].phone_number);
    printf("\n");
}