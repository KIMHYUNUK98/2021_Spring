#include <stdio.h>
#include <stdlib.h>

void read_data(char* filename, int **data, int *num);
void print_data(int *data, int num);

int binsearch(int *list, int x, int left, int right);
int compare(int x, int y); 

int main()
{
    int *data;
    int num; 
    int target, idx;
    
    read_data("output.dat", &data, &num);   // output.data has sorted data 

    printf("After read: ");
    print_data(data, num);

    while (1)
    {
        printf("Search number: ");
        scanf("%d", &target);
        if (target < 0)
            break;

        // TODO: call binsearch() 
        idx = binsearch(data, target, 0, num-1);

        if (idx < 0)
            printf("There is no search number\n");
        else
            printf("The search number is at %d\n", idx);
    }
}


// Read data 
void read_data(char* filename, int **data, int *num)
{
    int i, line; 
    char c;
    FILE *fp; 

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not Found!\n");
        exit(1);
    }

    // TODO: Get the number of integers stored in file --> num
    else {
        while(fscanf(fp, "%c",&c) != EOF) {
            if(c == '\n') {
                line++;
            }
        } 
        rewind(fp);
        *num = line;

    // TODO: Create data array for num integers 
        int *array_data = malloc(sizeof(int) * line);

    // TODO: Read integers from file and store into data array 
        for(i = 0 ; i < line ; i ++) {
            fscanf(fp, "%d", &array_data[i]);
        }
        *data = array_data;
    }

    fclose(fp);
}

// Print data 
void print_data(int *data, int num)
{
    int i; 
    printf("num=%d \n", num);
    for (i = 0; i < num; i++)
        printf("%d ", data[i]);
    printf("\n\n");
}

// Binary search - list is sorted by descending order 
int binsearch(int *list, int x, int left, int right)
{ 
    // TODO: Find an index of x using recursive binary search algorithm 
    while(left <= right) {
        int middle = (left + right) / 2;
        switch(compare(list[middle], x)) {
            case -1 :  return binsearch(list, x, left, middle - 1);
            case 0 : return middle;
            case 1 : return binsearch(list, x, middle + 1, right);
        }
    }
    return -1;
}

// Compare x and y 
int compare(int x, int y)
{
    // TODO: Compare x and y for binary search   
    if(x < y) 
        return -1;
    else if(x == y)
        return 0;
    else
        return 1;
}
