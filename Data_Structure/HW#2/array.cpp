#include "array.h"	// DO NOT CHANGE THIS LINE

Array::Array(int len) 
{
    array = (int *) malloc(sizeof(int) * len); 
    length = len;  
}

// TODO: Implement constructor that initializes the array using paraemter(i.e.,intarray).
Array::Array(int intarray[], int len)
{
    array = intarray;
    length = len;
}

// TODO: Implement index_at() that returns the index of 'value' in array (return -1 if not found)
int Array::index_at(int value) 
{
    for(int i = 0 ; i < length ; i++) {
        if(array[i] == value) {
            return i;
        }
    }
    return -1;
}

// TODO: Implement sort() that sorts the array by ascending order 
void Array::sort() 
{
    int conv;

    for(int i = 0 ; i < length ; i++) {
        for(int j = i+1 ; j < length ; j++) {
            if(array[i]>array[j]) {
                conv = array[i];
                array[i] = array[j];
                array[j] = conv;
            }
        }
    }
}

// TODO: Implement print() that prints out all values in array 
void Array::print()
{   
    for(int j  = 0 ; j < length ; j++) {
        if( j != length - 1) {
            cout << array[j] << ", ";
        } else if (j == length - 1) {
            cout << array[j];
        }
    } 
    cout << "\n";
}

