#include <iostream>
#include <iomanip>
using namespace std; 

#define MAX_SIZE 100

typedef struct {
    int key;
    /* other fields */
} Element;

class Sort {
  private: 
    Element *list;
    int num;          // Number of elements currently in use  
    int cur;                        

    void swap(Element *e1, Element *e2);
    void QuickSort(int left, int right);
    void MergeSort(Element sorted[], int low, int high);
    void merge(Element sorted[], int i, int m, int n);
    void adjust(int root, int n);
    
  public: 
    Sort();
    void InsertElement(Element e);
    void SelectionSort();
    void BubbleSort();
    void InsertionSort();
    void QuickSort();
    void MergeSort();
    void HeapSort();
    void Print(int i);
}; 


Sort::Sort() 
{
    list = new Element[MAX_SIZE];
    num = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        list[i].key = -1;
    }
}


void Sort::InsertElement(Element e)
{
    list[num] = e;
    num++; 
}

void Sort::swap(Element *e1, Element *e2)
{
    Element temp; 

    temp = *e1; 
    *e1 = *e2;
    *e2 = temp;    
}

void Sort::Print(int i)
{
    if (i < 0)
        cout << "[Init]: ";
    else    
        cout << "[" << setw(4) << i << "]: ";

    for (int i = 0; i < num; i++)
        cout << setw(3) << list[i].key << "  ";
    cout << endl;
}


// Selection Sort
void Sort::SelectionSort()
{
    int i, j, min = 0, temp = 0;

    cout << "Selection Sort" << endl;
    Print(-1); 
    cur = 0;

    for (i = 0; i < num - 1; i++) 
    {
        // find the minimum of list[i] through list[n-1]
        min = i;
        for (j = i + 1; j < num; j++) 
        {
            if (list[j].key < list[min].key)
                min = j;
        }
        swap(&list[i], &list[min]);
        Print(cur++);
    }
}


// Bubble Sort
void Sort::BubbleSort() 
{
    int i, j; 

    cout << "Bubble Sort" << endl;
    Print(-1); 
    cur = 0;

    for (i = 0; i < num-1; i++)
    {
        for (j = 0; j < num-i-1; j++)
        {
            if (list[j].key > list[j+1].key)
                swap(&list[j], &list[j+1]);
        }
        Print(cur++);
    }
}


// TODO: Implement a insertion sort 
void Sort::InsertionSort() 
{
    int i, j;
    Element next;

    cout << "Insertion Sort" << endl;
    Print(-1); 
    cur = 0;

    // TODO
    for(int i = 1 ; i < num ; i++) {
        next = list[i];
        for(j = i-1 ; j >= 0 && next.key < list[j].key ; j--)
            list[j+1] = list[j];
        list[j+1] = next;
        Print(cur++);
    }
}


// Quick Sort (completed)
void Sort::QuickSort()

{
    cout << "Quick Sort" << endl;
    Print(-1);
    cur = 0; 

    QuickSort(0, num-1);
}

// TODO: Implement a quick sort 
void Sort::QuickSort(int left, int right) 
{
    int pivot, i, j;
    if(left < right) {
        i = left;
        j = right+1;
        pivot = list[left].key; // 가장 왼쪽에 있는 값을 pivot으로 설정
        do {
            do i++; while(i <= right && list[i].key < pivot);
            do j--; while(j > left && list[j].key > pivot);
            if(i<j)
                swap(&list[i], &list[j]);
        } while(i<j);
        swap(&list[left], &list[j]);
        Print(cur++);
        

    QuickSort(left, j-1);
    QuickSort(j+1, right);
    }
}


// Merge Sort (completed)
void Sort::MergeSort()
{
    cout << "Merge Sort" << endl;
    Print(-1);
    cur = 0; 

    Element sorted[MAX_SIZE];
    MergeSort(sorted, 0, num-1);
}

// TODO: Implement a merge sort 
void Sort::MergeSort(Element sorted[], int low, int high) 
{
    if(low < high) {
        int mid = (low+high)/2;
        MergeSort(sorted, low, mid);
        MergeSort(sorted, mid+1, high);
        merge(sorted, low, mid, high);
    }    
}

// TODO: Implement a merge sort 
void Sort::merge(Element sorted[], int i, int m, int n) 
{
    int j, k, t;
    j = m + 1; 	    // the first element of the second sorted list 
    k = i;
    int start = i;

    // TODO 
    while(i <= m && j <= n) {
        if(list[i].key < list[j].key)
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if(i > m)
        while(j<=n) sorted[k++] = list[j++];
    else
        while(i<=m) sorted[k++] = list[i++];
    
    // Copy sorted[] to list[]
    for (i = start; i < k; i++)
        list[i] = sorted[i];

    Print(cur++);
}


// TODO: implement a HeapSort() 
void Sort::HeapSort() 
{
    int i;

    cout << "Heap Sort" << endl;
    Print(-1);
    cur = 0; 

    printf("num = %d\n", num);

    // TODO
    for(i = (num-1)/2; i>=0 ; i--)
    {
        adjust(i, num);
    }
    //Print(cur++);

    for(i = num - 1 ; i >= 0; i--)
    {
        swap(&list[0], &list[i]);
        adjust(0, i);
        Print(cur++);
    }
}


// TODO: implement an adjust() 
void Sort::adjust(int root, int n) 
{
    int child, rootkey;
    Element temp = list[root];
    rootkey = list[root].key;
    child = 2 * root +1;
    while(child <= n-1)
    {
        if((child < n -1) && (list[child].key < list[child+1].key))
            child++;
        if(rootkey > list[child].key)
        {
            break;
        }
        else
        {
            list[(child-1)/2] = list[child];
            child = child * 2 + 1;
        }
    }
    list[(child-1)/2] = temp;
}
