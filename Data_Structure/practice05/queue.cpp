// Definition of Queue class
class  Queue {
  private:
    int front, rear;
    int max_size;
    Element **queue;  

  public:       
    Queue(int num);     
    ~Queue();           
    bool IsFullQ();
    bool IsEmptyQ();
    void AddQ (Element* item);
    Element* DeleteQ();
    void Print();
};


Queue::Queue(int num)
{
    front = rear = 0;
    max_size = num + 1;

     // TODO: Create Element array of 'max_size' elements
    queue = new Element*[max_size];
}

Queue::~Queue()
{
    delete queue; 
}


bool Queue::IsFullQ() 
{
    // TODO: Implement IsFullQ() 
    if((rear+1) % max_size == front)
        return true;
    else
        return false;
}

bool Queue::IsEmptyQ() 
{
    // TODO: Implement IsEmptyQ()
    if(front == rear) 
        return true;
    else    
        return false;
}


void Queue::AddQ(Element* item) 
{
    // TODO: Implement AddQ()
    if(IsFullQ()) {
        cout << "The queue is full" << endl;
    }
    else {
        rear = (rear+1)%max_size;
        queue[rear] = item;
    }
}

Element* Queue::DeleteQ() 
{
    // TODO: Implement DeleteQ()
    if(IsEmptyQ()) {
        cout << "The queue is empty" << endl;
        return (Element*)0;
    }
    else {
        front = (front + 1) % max_size;
        return queue[front];
    }
}


void Queue::Print ()  
{
    // TODO: Print all of elements in queue (from front to rear)
    if(!IsEmptyQ()) {
        cout << endl << "Queue data: " << endl;
        int i = (front + 1) % max_size;
        while(i != (rear + 1)%max_size) {
            cout << "[" << i << "]: " << queue[i]->key << ", " << queue[i]->data << endl;
            i = (i + 1) % max_size;
        }
    }    
}

