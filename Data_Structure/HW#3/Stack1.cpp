#include <stdio.h>
#include <iostream>
using namespace std;

typedef int Element;

class Stack {
    private:
        int top;
        int max_size;
        int *Array;
        int *Input;
        Element *stack;

    public:
        Stack(int num);
        ~Stack();
        bool IsFullS();
        bool IsEmptyS();
        void Push(Element item);
        void Input_Array();
        void Expected_Order();
        void Print_Output();
        int Detect();
        Element Pop();      
};

Stack::Stack(int num) { // Constructor
    top = -1;
    max_size = num;

    Array = new int[max_size];
    Input = new int[max_size];
    stack = new Element[max_size];
}

Stack::~Stack() { // Destructor
    delete(stack);
    delete(Array);
    delete(Input);
}

bool Stack::IsEmptyS() {
    return (top == -1);
}

bool Stack::IsFullS() {
    return (top == max_size -1);
}

void Stack::Push(Element item) {
    if(IsFullS()) 
        cout << "Stack is full...!" << endl;
    else 
        stack[++top] = item;
}

Element Stack::Pop() {
    if(IsEmptyS()) {
        cout << "Stack is empty...!" << endl;
        return (Element)0;
    }
    else 
        return stack[top--];
}

void Stack::Input_Array() { // 스택에 들어가는 숫자를 Input 배열에 집어넣는 함수
    char Input[max_size];

    printf("Input: ");
    scanf("%s", Input);
}

void Stack::Expected_Order() { // 꺼내고 싶은 순서를 입력하고 Array 배열에 집어넣는 함수
    cout << "Enter the expected order(1~" << max_size << "): " ;
    for(int i = 0 ; i < max_size; i++) {
        cin >> Array[i];
    }
}

void Stack::Print_Output() { // Array 배열에 넣은 값을 출력해주는 함수
    printf("Output: ");
    for(int i = 0 ; i < max_size ; i++) {
        cout << Array[i];
    }
    printf("\n");
}

int Stack::Detect() { // Array 배열의 입력한 순서대로 스택에서 꺼낼 수 있는지 판단해주는 함수
    int index = 0;

    for(int i = 1 ; i <= max_size ; i++) {
        Push(i);
        for(int j = 0 ; j < max_size ; j++) {
            if(stack[top] == Array[index]) {
                
                index++;
                Pop();
            }
            else break;
        }
    }

    if(top == -1) return 1;
    else return 0;
}
