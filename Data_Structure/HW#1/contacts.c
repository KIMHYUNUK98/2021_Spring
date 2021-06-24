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

int main() 
{
    struct contact *contacts; 
    int num;

    read_data("data.dat", &contacts, &num); 

    print_data(contacts, num);

    return 0;
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


void print_data(struct contact *contacts, int num)
{
    int i; 
    printf("%-20s   %-20s   %-30s   %-20s \n", "Name", "Birthday", "E-mail", "Phone Number");
    printf("----------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < num; i++)
    {
        printf("%-20s / %-20s / %-30s / %-20s \n", contacts[i].name, contacts[i].birthday, contacts[i].email, contacts[i].phone_number);
    }
}