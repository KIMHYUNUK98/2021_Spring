// Definition of Element class
class Element{
  public: 
    int key;
    char str[20];

    Element(int e_key, const char *e_str) {
        key = e_key;
        strcpy(str, e_str);
    }
};


// Definition of stack node
typedef struct t_stack_node {
    Element *data;
    struct t_stack_node *link;   
} stack_node;


// TODO: Define LStack class 
// Definition of LStack class
class LStack {
    private:
        stack_node *top;

    public: 
        LStack();
        ~LStack();
        Element* Pop();
        void Push(Element *e);
        void Print();
        bool IsEmpty();
        void delete_Stack(stack_node *node_ptr);
};      

// TODO: Implement member functions of LStack class: 
//       LStack(), ~LStack(), Push(), Pop(), Print(), IsEmpty()

LStack::LStack() {
    top = NULL;
}

LStack::~LStack() {
    delete_Stack(top);
}

void LStack::delete_Stack(stack_node  *node_ptr) {
    if(node_ptr != NULL) {
        delete_Stack(node_ptr->link);
        delete node_ptr;
    }
}

Element *LStack::Pop() {
    Element *e;
    stack_node *del;

    if(top == NULL)
        return NULL;

    e = top->data;
    del = top;
    top = top->link;
    delete del;
    return e;
}

void LStack::Push(Element *e) {
    stack_node *new_node = new stack_node;

    if(new_node == NULL)
        return;

    new_node->data = e;
    new_node->link = top;
    top = new_node;
}

void LStack::Print() {
    stack_node *cur = NULL;
    cout << "List: ";
    for(cur = top ; cur != NULL ; cur = cur->link) {
        cout << cur->data->str << " ";
    }
    cout << endl;
}

bool LStack::IsEmpty() {
    return (top == NULL);
}