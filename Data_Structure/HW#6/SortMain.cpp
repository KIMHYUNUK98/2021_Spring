#include "Sort.cpp"

int main() 
{
    Sort *sort = new Sort(); 
    Element element;
    int type; 

    element.key = 26; sort->InsertElement(element);
    element.key = 5;  sort->InsertElement(element);
    element.key = 77; sort->InsertElement(element);
    element.key = 1;  sort->InsertElement(element);
    element.key = 61; sort->InsertElement(element);
    element.key = 11; sort->InsertElement(element);
    element.key = 59; sort->InsertElement(element);
    element.key = 15; sort->InsertElement(element);
    element.key = 48; sort->InsertElement(element);
    element.key = 19; sort->InsertElement(element);

    sort->QuickSort(); 
    
    return 0; 
}