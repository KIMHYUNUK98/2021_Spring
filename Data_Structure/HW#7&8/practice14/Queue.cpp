typedef tree_node Element;

// Definition of queue node
typedef struct t_queue_node {
    Element *data;
    struct t_queue_node *link;   
} queue_node;


// Definition of Queue class
class Queue {
  private:
    queue_node *front;
    queue_node *rear;

  public:
    Queue();            
    ~Queue();           
    void delete_queue(queue_node *node_ptr); 
    void AddQ(Element *e);
    Element *DeleteQ();
    Element *GetFront();
    bool IsEmpty();
};

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()    // recursive approach
{	
    delete_queue(front);
}

void Queue::delete_queue(queue_node* node_ptr) 
{
    if (node_ptr != NULL) 
    {
        delete_queue(node_ptr->link);
        delete node_ptr; 
    }
}

void Queue::AddQ(Element *e)
{
    queue_node *new_node = new queue_node;

    if (new_node == NULL)
        return;

    new_node->data = e;
    new_node->link = NULL;
    if (front) 
        rear->link = new_node;       
    else 
        front = new_node; // queue is empty
    
    rear = new_node; 
}

Element *Queue::DeleteQ()
{
    Element *e;
    queue_node *del = NULL;
    if (front == NULL)
        return NULL;

    e = front->data;
    del = front;
    front = front->link;
    
    if (front == NULL) 
        rear = NULL; // the only one is deleted
   
    delete del;
    
    return e;
}

Element *Queue::GetFront() 
{
    if (front != NULL)
        return front->data;
    else
        return NULL;
}

bool Queue::IsEmpty() 
{
    return (front == NULL);
}

