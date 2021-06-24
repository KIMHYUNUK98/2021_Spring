#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 128

struct contact {
    char name[30]; 
    char birthday[10]; 
    char email[30];
    char phone[15];
};

void read_data(char* filename, struct contact **contacts, int *num);
void print_data(struct contact *contacts, int num);
void print_one_data(struct contact *contacts);
void sort_data(struct contact *contacts, int num, int column);
void exchange(struct contact *data1, struct contact *data2);
int search_data(struct contact *contacts, char *x, int left, int right, int column);
int compare(char *data1, char *data2);


int main(int argc, char *argv[]) 
{
    struct contact *contacts; 
    int num; 
    int column;
    int find_idx;
    
    if (argc != 3)
    {
        printf("Usage: %s <Data File> <Column Number> <Search Data> \n\n", argv[0]);
        exit(0);
    }

    column = atoi(argv[2]);
    if (column < 0 || column > 3) 
    {
        printf("Column range should be 0 ~ %d! \n\n", 3);
        exit(0);
    }

    // File read 
    read_data(argv[1], &contacts, &num);
    // print_data(contacts, num);

    // Sort by attribute 
    sort_data(contacts, num, atoi(argv[2])); 
    // print_data(contacts, num);

    // Search data - binay search 
    find_idx = search_data(contacts, argv[3], 0, num, column);
    if (find_idx >= 0)
        print_one_data(&contacts[find_idx]);
    else 
        printf("%s Not Found!! \n\n", argv[3]);
   
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
    *num = line;

    // Create struct array using double pointer
    *contacts = (struct contact *) malloc(sizeof(struct contact) * (*num));
   
    line = 0;
    fseek(fp, SEEK_SET, 0);     // Set the file pointer to begin of file 

    // Read line from file
    while (fgets(str, BUFSIZE, fp) != NULL)
    {
        // Parse the line by ';'
        ptr = strtok(str, ";");

        strcpy((*contacts)[line].name, ptr); 
        ptr = strtok(NULL, ";");

        strcpy((*contacts)[line].birthday, ptr);
        ptr = strtok(NULL, ";");

        strcpy((*contacts)[line].email, ptr);
        ptr = strtok(NULL, ";");

        strcpy((*contacts)[line].phone, ptr);
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
        // Print data 
        printf("%-20s / %-20s / %-30s / %-20s \n", contacts[i].name, contacts[i].birthday, contacts[i].email, contacts[i].phone);
    }
    printf("\n");
}


void print_one_data(struct contact *contacts)
{
    printf("%-20s   %-20s   %-30s   %-20s \n", "Name", "Birthday", "E-mail", "Phone Number");
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("%-20s / %-20s / %-30s / %-20s \n", contacts->name, contacts->birthday, contacts->email, contacts->phone);
    printf("\n");
}


void sort_data(struct contact *contacts, int num, int column)
{
    int i, j, min, cmp; 

    // Selection sort: ascending order 
    for (i = 0; i < num - 1; i++) 
    {
        // Find the minimum of contacts[i] through contact[num-1]
        min = i; 
        for (j = i + 1; j < num; j++) 
        {
            // Compare by column number 
            switch (column)
            {
                case 0:
                    cmp = strcmp(contacts[j].name, contacts[min].name); 
                    break;
                case 1: 
                    cmp = strcmp(contacts[j].birthday, contacts[min].birthday); 
                    break;
                case 2:
                    cmp = strcmp(contacts[j].email, contacts[min].email); 
                    break;
                case 3: 
                    cmp = strcmp(contacts[j].phone, contacts[min].phone); 
                    break;
            }
            
            if (cmp == -1)
                min = j;
        }

        if (min != i)
        {
        	exchange(&contacts[i], &contacts[min]);
        }
    }
}


// Exchange two values 
void exchange(struct contact *data1, struct contact *data2) 
{
    struct contact temp; 

    strcpy(temp.name, data1->name);
    strcpy(temp.birthday, data1->birthday);
    strcpy(temp.email, data1->email);
    strcpy(temp.phone, data1->phone);

    strcpy(data1->name, data2->name);
    strcpy(data1->birthday, data2->birthday);
    strcpy(data1->email, data2->email);
    strcpy(data1->phone, data2->phone);
    
    strcpy(data2->name, temp.name);
    strcpy(data2->birthday, temp.birthday);
    strcpy(data2->email, temp.email);
    strcpy(data2->phone, temp.phone);
}


// Binary search 
int search_data(struct contact *contacts, char *x, int left, int right, int column)
{
    int cmp;
    if (left <= right) {		   // termination condition 1
        int mid = (left + right) / 2;

        // Compare by column number 
        switch (column) {
            case 0: cmp = compare(contacts[mid].name, x); break;
            case 1: cmp = compare(contacts[mid].birthday, x); break;
            case 2: cmp = compare(contacts[mid].email, x); break;
            case 3: cmp = compare(contacts[mid].phone, x); break;
        }

	    switch (cmp) {
	        case -1: return search_data(contacts, x, mid+1, right, column);  // A[mid] < x
	        case 0: return mid;          // termination condition 2, A[mid] == x
	        case +1: return search_data(contacts, x, left, mid-1, column);    // A[mid] > x
	    }
    }
    return -1;
}
      
int compare(char *data1, char *data2)
{
    int ret = strcmp(data1, data2);

	if (ret == -1)
		return -1;
	else if (ret == 0)
		return 0;
	else
		return 1;
}