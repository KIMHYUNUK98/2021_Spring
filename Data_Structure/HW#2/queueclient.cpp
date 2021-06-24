#include "element_class.h"
#include "queue.cpp"

int main()
{
    Queue* queue = new Queue(5);
    Element *item;  

    queue->AddQ(new Element(1, "Hello"));
    queue->AddQ(new Element(2, "World"));
    queue->AddQ(new Element(10, "Handong"));
    queue->AddQ(new Element(11, "Global"));
    queue->AddQ(new Element(12, "University")); 
    queue->Print(); 
    
    item = queue->DeleteQ();
    cout << "Delete: " << item->key << ", " << item->data << endl;

    item = queue->DeleteQ();
    cout << "Delete: " << item->key << ", " << item->data << endl;

    queue->AddQ(new Element(30, "Data"));
    queue->AddQ(new Element(31, "Structure"));
    queue->AddQ(new Element(32, "Fun!!!!!"));

    queue->Print();
}