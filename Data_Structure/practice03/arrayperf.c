#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define numRows 10000
#define numColumns 10000

int main() 
{
    int **matrix;
    int row, column;
    clock_t start = 0, stop = 0;
    double duration = 0.0;
        
    // TODO: Create 2D array 
    matrix = malloc(numRows * sizeof(* matrix));
    for(int i = 0 ; i < numRows; i++) {
        matrix[i] = malloc(numColumns * sizeof(** matrix));
    }

    // Row-major format
    // TODO: start clock()
    start = clock();
    // TODO: Access matrix by row-major format
    for (row = 0 ;row < numRows ; row++) 
    {
        for (column = 0 ; column < numColumns ; column++) 
        {
            matrix[row][column] = row * column;
        }
    }
    
    // TODO: stop clock()
    stop = clock();
    // TODO: calculate the elasped time 
    duration = ((double) (stop- start) / CLOCKS_PER_SEC);
    printf("Time for row-major format: %f\n", duration);

    // Column-major format
    // TODO: start clock()
    start = clock();
    // TODO: Access matrix by column-major format
    for (column = 0 ; column < numColumns ; column++) 
    {
        for (row = 0 ;row < numRows ; row++) 
        {
            matrix[row][column] = row * column;
        }
    }
    // TODO: stop clock()
    stop = clock();
    // TODO: calculate the elasped time 
    duration = ((double) (stop - start) / CLOCKS_PER_SEC);
    printf("Time for column-major format: %f\n", duration);

    return 0;
}