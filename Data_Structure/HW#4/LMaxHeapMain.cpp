#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#include "LMaxHeap.h"
#include "LMaxHeap.cpp"

int main()
{
    LMaxHeap* maxheap = new LMaxHeap();
    Element e1, e2;
    
    // Max Heap
    cout << "Max Heap Insert" << endl << endl;
    e1.key = 3; e1.data = "?";
    maxheap->insert(e1);
    e1.key = 1; e1.data = "The";
    maxheap->insert(e1);
    e1.key = 7; e1.data = "Why";
    maxheap->insert(e1);
    e1.key = 4; e1.data = "Not";
    maxheap->insert(e1);
    e1.key = 2; e1.data = "World";
    maxheap->insert(e1);
    e1.key = 5; e1.data = "Change";
    maxheap->insert(e1);

    e1.key = 6; e1.data = "KIM";
    maxheap->insert(e1);
    e1.key = 9; e1.data = "HYUN";
    maxheap->insert(e1);
    e1.key = 8; e1.data = "UK";
    maxheap->insert(e1);
    e1.key = 11; e1.data = "THANK";
    maxheap->insert(e1);
    e1.key = 10; e1.data = "YOU";
    maxheap->insert(e1);

    cout << "Max Heap Print: " << endl;
    maxheap->Print();
    cout << endl << endl;

    cout << "Max Heap Delete: " << endl;
    e2 = maxheap->deletion();
    cout << "[" << e2.key << " ";
    cout << e2.data << "]";
    e2 = maxheap->deletion();
    cout << "[" << e2.key << " ";
    cout << e2.data << "]";
    e2 = maxheap->deletion();
    cout << "[" << e2.key << " ";
    cout << e2.data << "]";
    cout << endl << endl;

    cout << "Max Heap Print: " << endl;
    maxheap->Print();
    cout << endl;

}