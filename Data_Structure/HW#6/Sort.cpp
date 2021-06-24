#include <iostream>
#include <iomanip>
using namespace std; 
#include "stack.cpp"

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
    
  public: 
    Sort();
    void InsertElement(Element e);
    void QuickSort();
    void QuickSort(int front, int rear);
    void Print(int i);
    int partition(int low, int high);
    void threeSort(int front, int mid, int rear);
    void median_swap(int a, int b);  // median swap function
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

void Sort::median_swap(int a, int b) 
{
    Element temp;

    temp = list[a];
    list[a] = list[b];
    list[b] = temp;
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

// Quick Sort (completed)
void Sort::QuickSort()
{
    cout << "Quick Sort" << endl;
    Print(-1);
    cur = 0; 

    QuickSort(0, num-1);
}

void Sort::QuickSort(int front, int rear) 
{
    Stack *stack = new Stack(num);
    int high, low;

    stack->Push(front);
    stack->Push(rear);

    // ���ÿ� �ε��� ������ ������� ������ while���� Ż���Ѵ�.
    while(!stack->IsEmptyS()) {
        // ���� high�� low�� �������� �迭�� ���� ó���� index�� �Ҵ��Ѵ�.
        high = stack->Pop();
        low = stack->Pop();

        // �ǹ��� �ε��� ���� ��ȯ���ش�.
        int p = partition(low, high);
        Print(cur++);
        //printf("==> low = %d, high = %d\n", low, high);
        // �ǹ��� ���� �迭�� �����Ѵٸ� ���� �迭�� ���۰� �� index�� ���ÿ� �ִ´�.
        if(p-1 > low) 
        {
            stack->Push(low);
            stack->Push(p - 1);
        }
        // �ǹ��� ������ �迭�� �����Ѵٸ� ������ �迭�� ���۰� �� index�� ���ÿ� �ִ´�.
        if(p+1 < high)
        {
            stack->Push(p+1);
            stack->Push(high);
        }
    }
}

// �迭 �˰��� (median�� ���� pivot�� ����)
int Sort::partition(int front, int rear) 
{
    int mid = front + (rear-front)/2;
    int pivot, i, j;

    // �� ó�� median�� �����ؼ� ���Ľ�Ų��.
    // �� ���� ���ص� �Ǵ� ���� swap�� || 3�� �̻��� median �˰��� ��� 
    if(front == mid) 
    {
        if(list[front].key > list[rear].key) median_swap(front, rear);
        i = front;
    }
    else 
    {
        threeSort(front, mid, rear);
        i = mid;
    }

    // �迭�� ���� 3���� ũ�� Quicksort ������ ��Ų��
    if(rear - front + 1 > 3) {
        pivot = list[mid].key;
        // pivot�� rear-1 �ε����� ��ġ��Ű�� �˰���
        median_swap(mid, rear - 1);
        i = front;
        j = rear - 1;

        // pivot���� ���� ���� ū ���� ���� swap ���ִ� �˰���
        while(true) {
            while(list[++i].key < pivot && i < rear);
            while(list[--j].key > pivot && front < j);
            if(i >= j) break;
            median_swap(i, j);
        }
        median_swap(i, rear - 1);
    }
    return i;
}

// front, mid, rear�� ���� ũ�� ������ �������ִ� �Լ�
void Sort::threeSort(int front, int mid, int rear)
{
    if(list[front].key > list[mid].key) median_swap(front, mid);
    if(list[mid].key > list[rear].key) median_swap(mid, rear);
    if(list[front].key > list[mid].key) median_swap(front, mid);
}