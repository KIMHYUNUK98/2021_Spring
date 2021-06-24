#include <iostream>
#include <cstring>
using namespace std;

#define MAX_EXPR_SIZE 100

typedef enum { lparen, rparen, Plus, Minus, times, divide, mod, EndOfString, operand} precedence;
typedef precedence Element;

// 배열 선언 부분
char expr[MAX_EXPR_SIZE];
char post_expr[MAX_EXPR_SIZE];
precedence pstack[MAX_EXPR_SIZE];
int stack[MAX_EXPR_SIZE];

// 연산자 별 우선순위 할당
static int isp[ ] = { 0 ,19, 12, 12, 13, 13, 13, 0 };
static int icp[ ] = { 20, 19, 12, 12, 13, 13, 13, 0 };

// 함수 선언 부분
int eval(void);
void postfix(void);
bool IsEmptyS();
bool IsFullS();
void Push(int *top, int item);
void PPush(int *top, precedence item);
char print_token(precedence token);
precedence PPop(int *top);
int Pop(int *top);
precedence get_token(char *symbol, int *n);

int main(int argc, char *argv[]) {
    int len = strlen(argv[1]);
    int result;
    char whatever;
    
    cout << "Infix: ";
    cout << argv[1] << endl;
    strcpy(expr, argv[1]);

    postfix();
    cout << "Posfix: " << expr;
    cout << endl;
    cout << "Evaluation: " << eval();

    return 0;
}

// 계산해주는 Evaluation 함수
int eval(void) {
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;
    int top = -1;

    token = get_token(&symbol, &n);
    while(token != EndOfString) {
        if(token == operand) {
            Push(&top, symbol - '0');
        } else {
            op2 = Pop(&top); op1 = Pop(&top);
            switch(token) {
                case Plus : Push(&top, op1+op2); break;
                case Minus : Push(&top, op1-op2); break;
                case times : Push(&top, op1*op2); break;
                case divide : Push(&top, op1/op2); break;
                case mod : Push(&top, op1 % op2); break;
            }
        }
        token = get_token(&symbol, &n);
    }
    return Pop(&top);
}

// 후위 연산자로 바꿔주는 함수
void postfix(void) {
    char symbol;
    precedence token;
    int n = 0 , index = 0;
    int top = 0;
    int on = 0;
    int mcnt = 1;
    char CHOOSE;
    pstack[0] = EndOfString;
    
    for(token = get_token(&symbol, &n) ; token != EndOfString ; token = get_token(&symbol, &n)) {
        if(token == Minus) { // 연산자가 '-''인 경우 
            on = n;
            for(; expr[n] == '-'; n++)
                mcnt++;
            if(expr[n] == '(' && expr[n-2] != '-' && isdigit(expr[n-2]) == 0) {
                expr[n-4] = '(';
                expr[n-3] = '-';
                expr[n-2] = '1';
                expr[n-1] = '*';
                n-=3;
            } else if(expr[n] == '('&& expr[n-2] != '-' && isdigit(expr[n-2]) !=0) {
                expr[n-4] = '+';
                expr[n-3] = '-';
                expr[n-2] = '1';
                expr[n-1] = '*';
                n-=4;
            } else if(isdigit(expr[on-2]) ==0 && (mcnt%2==1) && expr[on-2] !=')') {
                post_expr[index++] = '-';
            } else if(mcnt % 2 == 0) { // 음수가 연속으로 나온 경우 +로 바꾸기
                if(isdigit(expr[on-2]) == 0);
                else {
                    token = Plus;
                    while(isp[stack[top]] >= icp[token])
                        print_token(PPop(&top));
                    PPush(&top, token);
                }
            } else if(mcnt % 2 == 1) { // 음수가 홀수번 나온 경우 -로 바꾸기
                token = Minus;
                while(isp[stack[top]] >= icp[token])
                    print_token(PPop(&top));
                PPush(&top, token);
            }
            mcnt = 1;
        }
        
        else if(token == operand) // token이 숫자인 경우 바로 post_expr에 집어넣기
            post_expr[index++] = symbol;

        else if(token == rparen) { // token이 ) 를 만나면 ( 만날때까지 post_expr에 집어넣기
            while(pstack[top] != lparen)
                post_expr[index++] = print_token(PPop(&top));   
            PPop(&top);                      
        }
        else { // 연산자를 넣을 때 기존의 연산자와 우선순위를 비교해서 넣는 것의 우선순위가 낮으면 기존의 것을 출력
            while(isp[pstack[top]] >= icp[token])
                print_token(PPop(&top));
            PPush(&top, token);
        }
    } // 배열이 끝날 때까지 스택의 있는 것들을 post_expr로 집어넣기
    while((token = PPop(&top)) != EndOfString)
        post_expr[index++] = print_token(token);
    strcpy(expr, post_expr);
}

// expr의 배열에 있는 하나하나를 토큰화시키는 함수
precedence get_token(char *symbol, int *n) {
    *symbol = expr[(*n)++];
    switch(*symbol) {
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return Plus;
        case '-' : return Minus;
        case '/' : return divide;
        case '*' : return times;
        case '%' : return mod;
        case '\0': return EndOfString;
        default  : return operand;
    }
}

//토큰화된 것을 문자로 다시 바꿔주는 함수
char print_token(precedence token) {

    switch(token) {
        case Plus : return '+';
        case Minus : return '-';
        case divide : return '/';
        case times : return '*';
        case mod : return '%';
        case EndOfString : return '\0';
        default : return token;
    }
}
// 계산을 위한 PUSH
void Push(int *top, int item) {
    if(*top == MAX_EXPR_SIZE - 1) 
        cout << "Stack is full...!" << endl;
    else 
        stack[++(*top)] = item;
}
// 토큰화된 것을 스택에 쌓기 위한 PUSH
void PPush(int *top, precedence item) {
    if(*top == MAX_EXPR_SIZE - 1) 
        cout << "Stack is full...!" << endl;
    else 
        pstack[++(*top)] = item;
}

// 계산을 위한 Pop
int Pop(int *top) {
    if(*top == -1) {
        cout << "Stack is empty...!" << endl;
        return 0;
    }
    else 
        return stack[(*top)--];
}
// 토큰화된 것을 꺼내기 위한 POP
precedence PPop(int *top) {
    if(*top == -1) {
        cout << "Stack is empty...!" << endl;
        return (precedence)0;
    }
    else 
        return pstack[(*top)--];
}