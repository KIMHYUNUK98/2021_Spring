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

    // 스택에 인덱스 값들이 들어있지 않으면 while문을 탈출한다.
    while(!stack->IsEmptyS()) {
        // 각각 high와 low를 정렬해줄 배열의 끝과 처음의 index로 할당한다.
        high = stack->Pop();
        low = stack->Pop();

        // 피벗의 인덱스 값을 반환해준다.
        int p = partition(low, high);
        Print(cur++);
        //printf("==> low = %d, high = %d\n", low, high);
        // 피벗의 왼쪽 배열이 존재한다면 왼쪽 배열의 시작과 끝 index를 스택에 넣는다.
        if(p-1 > low) 
        {
            stack->Push(low);
            stack->Push(p - 1);
        }
        // 피벗의 오른쪽 배열이 존재한다면 오른쪽 배열의 시작과 끝 index를 스택에 넣는다.
        if(p+1 < high)
        {
            stack->Push(p+1);
            stack->Push(high);
        }
    }
}

// 배열 알고리즘 (median을 통해 pivot을 설정)
int Sort::partition(int front, int rear) 
{
    int mid = front + (rear-front)/2;
    int pivot, i, j;

    // 맨 처음 median을 선정해서 정렬시킨다.
    // 두 개만 비교해도 되는 경우는 swap만 || 3개 이상은 median 알고리즘 사용 
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

    // 배열의 수가 3보다 크면 Quicksort 정렬을 시킨다
    if(rear - front + 1 > 3) {
        pivot = list[mid].key;
        // pivot을 rear-1 인덱스에 위치시키는 알고리즘
        median_swap(mid, rear - 1);
        i = front;
        j = rear - 1;

        // pivot보다 작은 값과 큰 값을 서로 swap 해주는 알고리즘
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

// front, mid, rear를 먼저 크기 순으로 정렬해주는 함수
void Sort::threeSort(int front, int mid, int rear)
{
    if(list[front].key > list[mid].key) median_swap(front, mid);
    if(list[mid].key > list[rear].key) median_swap(mid, rear);
    if(list[front].key > list[mid].key) median_swap(front, mid);
}