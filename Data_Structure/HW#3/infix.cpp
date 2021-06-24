#include <iostream>
#include <cstring>
using namespace std;

#define MAX_EXPR_SIZE 100
typedef enum { lparen, rparen, Plus, Minus, times, divide, mod, EndOfString, operand} precedence;

char expr[MAX_EXPR_SIZE];
char post_expr[MAX_EXPR_SIZE];
precedence stack[MAX_EXPR_SIZE];

static int isp[] = { 0 ,19, 12, 12, 13, 13, 13, 0 };
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

class Stack {
    private:
        int top;
        int max_size;

    public:
        Stack();
        ~Stack();
        bool IsFullS();
        bool IsEmptyS();
        void Push(precedence item);
        precedence Pop();
};

Stack::Stack() {
    top = -1;
}

Stack::~Stack() {}

bool Stack::IsEmptyS() {
    return (top == -1);
}

bool Stack::IsFullS() {
    return (top == max_size -1);
}

void Stack::Push(precedence item) {
    if(IsFullS()) 
        cout << "Stack is full...!" << endl;
    else 
        stack[++top] = item;
}

precedence Stack::Pop() {
    if(IsEmptyS()) {
        cout << "Stack is empty...!" << endl;
        return (precedence)0;
    }
    else 
        return stack[top--];
}
