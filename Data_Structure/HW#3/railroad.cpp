#include "Stack1.cpp"

int main() {
    int num = 0;
    int index = 0, x = 0;
    Element item[5];
    char Input[5];
    char Array[5];

    while(1) {
    cout << "Enter the number of cars: ";
    cin >> num;
    if(num == 0) break; // num에 0을 입력하면 프로그램 종료

    Stack *stack = new Stack(num); // num 크기의 각각의 배열을 선언해주는 함수

    stack->Expected_Order();  // 원하는 순서의 배열을 입력해주는 함수 
    stack->Input_Array();  // 스택에 넣는 숫자의 배열을 입력해주는 함수
    num = stack->Detect();  // 원하는 순서대로 꺼낼 수 있는지 리턴값을 주는 함수

    if(num == 1) {
        stack->Print_Output(); 
        printf("Possible\n"); }
    else printf("No Possible\n");


    }
}