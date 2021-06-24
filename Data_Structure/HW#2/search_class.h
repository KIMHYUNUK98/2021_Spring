#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define BUFSIZE 128
#define MAX_LEN 7

class Search {
    private:
        char name[30]; 
        char birthday[10]; 
        char email[30];
        char phone_number[20];
    
    public:
        Search() {}; // Constructor 생성
        void read_data(char* filename, Search **element, int *num);
        void print_data(Search *element, int idx); 
        void sort_data(Search *element, int column, int num);
        int binsearch(Search *element, char *search_data, int left, int right, int column);
};