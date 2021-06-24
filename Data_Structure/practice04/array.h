#include <iostream>	    // DO NOT CHANGE THIS LINE
#include <cstring>      // DO NOT CHANGE THIS LINE
#include <ctime>        // DO NOT CHANGE THIS LINE
using namespace std;    // DO NOT CHANGE THIS LINE

class Array {		// in Array.h
    private:
        int *array; 
        int length; 
    public: 
        Array (int len); 		    
        Array (int intarray[], int len);    

        int get_length ( ) 		     	    { return length; }
        int retrieve(int index) 		    { return array[index]; }
        void store(int index, int value)	{ array[index]=value; } 
        int index_at(int value); 	
        void sort(); 			    
        void print();
};
