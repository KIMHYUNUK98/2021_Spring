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


// Definition of queue node
typedef struct t_queue_node {
    Element *data;
    struct t_queue_node *link;   
} queue_node;


// TODO: Define LQueue class 
// Definition of LQueue class
class LQueue {
    private:
        queue_node *front;
        queue_node *rear;

    public: 
        LQueue();
        ~LQueue();
        void AddQ(Element *e);
        Element *DeleteQ();
        void Print();
        bool IsEmpty();
        void delete_Queue(queue_node *node_ptr);
};

// TODO: Implement member functions of LQueue class: 
//       LQueue(), ~LQueue(), AddQ(), DeleteQ(), Print(), IsEmpty()
LQueue::LQueue() {
    front = NULL;
    rear = NULL;
}

LQueue::~LQueue() {
    delete_Queue(front);
}

void LQueue::delete_Queue(queue_node *node_ptr) {
    if(node_ptr != NULL) {
        delete_Queue(node_ptr->link);
        delete node_ptr;
    }
}

bool LQueue::IsEmpty() {
    return (front == NULL && rear == NULL);
}

void LQueue::Print() {
    queue_node *cur = NULL;
    cout << "List: ";
    for(cur = front ; cur != NULL ; cur = cur->link) {
        cout << cur->data->str << " ";
    }
    cout << endl;
}

Element *LQueue::DeleteQ() {
    Element *e;
    queue_node *del = NULL;
    if(front == NULL)
        return NULL;

    e = front->data;
    del = front;
    front = front->link;
    if(front == NULL)
        rear = NULL;
    delete del;
    return e;
}

void LQueue::AddQ(Element *e) {
    queue_node *new_node = new queue_node;

    if(new_node == NULL) 
        return;
    
    new_node->data = e;
    new_node->link = NULL;
    if(front)
        rear->link = new_node;
    else 
        front = new_node;

    rear = new_node;
}