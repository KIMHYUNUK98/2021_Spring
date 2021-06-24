// Definition of stack node
typedef struct t_stack_node {
    int data;
    struct t_stack_node *link;   
} stack_node;

// Definition of Stack class
class Stack {
  private:
    stack_node *top;

  public:
    Stack();            
    ~Stack();           
    void delete_stack(stack_node *node_ptr); 
    void Push(int data);
    int  Pop();
    void Print();
    bool IsEmpty();
};

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()    // recursive approach
{	
    delete_stack(top);
}

void Stack::delete_stack(stack_node* node_ptr) 
{
    if (node_ptr != NULL) 
    {
        delete_stack(node_ptr->link);
        delete node_ptr; 
    }
}

void Stack::Push(int data)
{
    stack_node *new_node = new stack_node;

    if (new_node == NULL) 
        return; 
    
    new_node->data = data;
    new_node->link = top;
    top = new_node;
}

int Stack::Pop()
{
    int data;
    stack_node *del;

    if (top == NULL)
        return -99999;

    data = top->data;
    del = top;
    top = top->link;
    delete del;
    
    return data;
}

void Stack::Print() 
{
    stack_node *cur;
    cout << "Stack: ";
    for (cur = top; cur != NULL; cur = cur->link)
    {
        cout << cur->data << "  ";
    }
    cout << endl;
}

bool Stack::IsEmpty() 
{
    return (top == NULL);
}

