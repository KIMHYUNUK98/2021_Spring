#include <stdio.h>
#include <stdlib.h>

void read_data(char* filename, int **data, int *num);
void sort_data(int *data, int num);
void exchange(int *value1, int *value2);
void save_data(char* filename, int *data, int num);
void print_data(int *data, int num);


int main()
{
    int num;
    int i;
    int arr[500];

    int *data = arr;
    
    FILE *fp;  
    
    read_data("data.dat", &data, &num);
    
    printf("After read: ");
    print_data(data, num);

    sort_data(data, num); // descending order

    printf("After sort: ");
    print_data(data, num);

    save_data("output.dat", data, num);
    
    return 0;
} 

// Read data 
void read_data(char* filename, int **data, int *num)
{
    int i = 0;
    int line = 0; 
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



// Selection sort - descending order 
void sort_data(int *data, int num)
{
    // TODO: Selection sort with descending order 
    int temp = 0;

    for(int i = 0 ; i < num - 1 ; i++) {
        for(int j = i + 1 ; j < num ; j++) {
            if(data[i] < data[j]) 
                exchange(&data[i], &data[j]);
        }
    }
}


// Exchange data 
void exchange(int *value1, int *value2)
{
    int temp = 0;

    // TODO: Exchange data 
    temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}


// Save data (Do not change)
void save_data(char* filename, int *data, int num)
{
    int i;
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("File not Found!\n");
        exit(1);
    }

    for (i = 0; i < num; i++)
    {
        fprintf(fp, "%d\n", data[i]);
    }

    fclose(fp);
}

// Print data (Do not change)
void print_data(int *data, int num)
{
    int i; 
    printf("num=%d \n", num);
    for (i = 0; i < num; i++)
        printf("%d ", data[i]);
    printf("\n\n");
}