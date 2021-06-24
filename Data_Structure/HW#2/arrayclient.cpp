#include "array.h"   // DO NOT CHANGE THIS LINE

int main ( ) 
{
    Array* a1;
    a1 = new Array(10); 

    srand((unsigned int)time(NULL));
    for (int i = 0; i < a1->get_length(); i++)
    {
        a1->store(i, rand()%100);
    }

    int temp[] = {50, 20, 30, 40, 10};
    Array a2(temp, 5);
        
    // TODO: Implement the program referring to expected results 
    cout << "a1: before sort(): ";
    a1->print();

    a1->sort();
    cout << "a1: after sort(): ";
    a1->print();

    cout << "a2: before sort(): ";
    a2.print();

    a2.sort();
    cout << "a1: after sort(): ";
    a2.print();
}