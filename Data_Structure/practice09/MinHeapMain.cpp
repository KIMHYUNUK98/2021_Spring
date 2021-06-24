#include <iostream>

using namespace std;

#include "MinHeap.h"
#include "MinHeap.cpp"

int main()
{
    // Min Heap
    MinHeap* minheap = new MinHeap();
    Element e1, e2;

    cout << "Min Heap Insert" << endl << endl;
    e1.key = 30; e1.data = "HHH";
    minheap->insert(e1);
    e1.key = 2; e1.data = "AAA";
    minheap->insert(e1);
    e1.key = 12; e1.data = "GGG";
    minheap->insert(e1);
    e1.key = 14; e1.data = "BBB";
    minheap->insert(e1);
    e1.key = 20; e1.data = "EEE";
    minheap->insert(e1);
    e1.key = 25; e1.data = "FFF";
    minheap->insert(e1);
    e1.key = 10; e1.data = "CCC";
    minheap->insert(e1);
    e1.key = 15; e1.data = "DDD";
    minheap->insert(e1);

    cout << "Min Heap Print: " << endl;
    minheap->Print();
    cout << endl;

    cout << "Delete: " << endl;
    e2 = minheap->deletion();
    cout << "[" << e2.key << " ";
    cout << e2.data << "]";
    e2 = minheap->deletion();
    cout << "[" << e2.key << " ";
    cout << e2.data << "]";
    e2 = minheap->deletion();
    cout << "[" << e2.key << " ";
    cout << e2.data << "]";
    cout << endl << endl;

    cout << "Min Heap Print: " << endl;
    minheap->Print();
    cout << endl; 
}
