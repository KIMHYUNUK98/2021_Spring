// Definition of Stack class
class  Stack {
  private:
    int top;
    int max_size; 
    Element **stack;    // Strucutre pointer

  public:         
    Stack(int num);     
    ~Stack();           
    bool IsFullS();
    bool IsEmptyS(); 
    void Push(Element* item);
    Element* Pop();
    int Length() { return top; };
};


Stack::Stack(int num) 
{
    top = -1;
    max_size = num;

    // TODO: Create Element array of 'max_size' elements
    stack = new Element*[max_size];
}


Stack::~Stack()
{
    delete stack; 
}


bool Stack::IsFullS()
{
    // TODO: Implement IsFulls()
    return (top == max_size-1);
}


bool Stack::IsEmptyS()
{
    // TODO: Implement IsEmpty() 
    return (top == -1);
}


void Stack::Push(Element* item) 
{
    // TODO: Implement Push()
    if(IsFullS()) {
        cout << "The stack is full" << endl;
    }
    else 
        stack[++top] = item;
}


Element* Stack::Pop() 
{
    // TODO: Implement Pop()
    if(IsEmptyS()) {
        cout << "The stack is empty" << endl;
        return NULL;
    }
    else 
        return stack[top--];
}




