#include "Sort.cpp"

void print_usage(const char *argv);

int main(int argc, char *argv[]) 
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

    if (argc != 2) 
    {
        print_usage(argv[0]); 
        return 0; 
    }

    type = atoi(argv[1]);
    if (type >= 0 && type <= 5)
    {
        switch (atoi(argv[1]))
        {
            case 0:  sort->SelectionSort(); break;
            case 1:  sort->BubbleSort();    break;
            case 2:  sort->InsertionSort(); break;
            case 3:  sort->QuickSort();     break;
            case 4:  sort->MergeSort();     break;
            case 5:  sort->HeapSort();      break;
            default: sort->SelectionSort(); break;
        }
    }
    else 
    {
        print_usage(argv[0]);
    }
    
    return 0; 
}


void print_usage(const char *argv)
{
    cout << "Usage: " << argv << " <Sorting Alg=0~5>" << endl; 
    cout << "\t (Sorting Alg: 0=Selection, 1:Bubble, 2:Insertion, 3:Quick, 4:Merge, 5:Heap)" << endl;
}