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

    printf("%-20s   %-20s   %-30s   %-20s \n", "Name", "Birthday", "E-mail", "Phone Number");
    printf("----------------------------------------------------------------------------------------------------");
    read_data(argv[1], &contacts, &num);
    sort_data(contacts, column, num);
    int idx = binsearch(contacts, argv[3], 0, num-1, column);
    printf("\n\n%d\n\n", idx);
    print_data(contacts, idx);

    return 0; 
}

int binsearch(struct contact *contacts, char *search_data, int left, int right, int column) {

    if(column == 0) {
        while(left < right) {
        int middle = (left + right) / 2;
        if(strcmp(contacts[middle].name, search_data) > 0)
            return binsearch(contacts, search_data, left, middle, column);
        else if(strcmp(contacts[middle].name, search_data) < 0)
            return binsearch(contacts, search_data, middle, right, column);
        else if(strcmp(contacts[middle].name, search_data) == 0)
            return middle;
        else return -1;
        }
    }
    else if(column == 1) {
        while(left <= right) {
        int middle = (left + right) / 2;
        if(strcmp(contacts[middle].birthday, search_data) > 0) 
            return binsearch(contacts, search_data, left, middle, column);
        else if(strcmp(contacts[middle].birthday, search_data) < 0)
            return binsearch(contacts, search_data, middle, right, column);
        else
            return middle;
        }
    }
    else if(column == 2) {
        while(left <= right) {
        int middle = (left + right) / 2;
        if(strcmp(contacts[middle].email, search_data) > 0) 
            return binsearch(contacts, search_data, left, middle, column);
        else if(strcmp(contacts[middle].email, search_data) < 0)
            return binsearch(contacts, search_data, middle, right, column);
        else
            return middle;
        }
    }
    else if(column == 3) {
        while(left <= right) {
        int middle = (left + right) / 2;
        if(strcmp(contacts[middle].phone_number, search_data) > 0) 
            return binsearch(contacts, search_data, left, middle, column);
        else if(strcmp(contacts[middle].phone_number, search_data) < 0)
            return binsearch(contacts, search_data, middle, right, column);
        else
            return middle;
        }
    }
    return -1;
}


void sort_data(struct contact *contacts, int column, int num) {
    struct contact temp;

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

// Read data 
void read_data(char* filename, struct contact **contacts, int *num)
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

    // Count lines 
    while (fgets(str, BUFSIZE, fp) != NULL)
    {
        line++; 
    }
    *num = line;    // *num stores the number of lines in file

    // TODO: Create struct array using double pointer
    *contacts = malloc(sizeof(struct contact));

    line = 0;
    fseek(fp, SEEK_SET, 0);     // Set the file pointer to begin of file 

    // TODO: Read line from file using fgets()
    while (fgets(str, BUFSIZE, fp) != NULL) 
    {
        // TODO: Do tokenization using strtok() by ";" 
        // TODO: Stores the tokenized value into structure (e.g., token pointer -> (*contacts)[line].name)
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
    printf("\n%-20s / %-20s / %-30s / %-20s \n", contacts[i].name, contacts[i].birthday, contacts[i].email, contacts[i].phone_number);
}