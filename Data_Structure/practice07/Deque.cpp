#include <iostream>
#include <cstring> 

using namespace std;

typedef struct t_list_node {
    char data[10];
    struct t_list_node *llink, *rlink;   
} list_node;


// Definition of Deque
class Deque
{
  private:
    list_node *front, *rear;
    int length;
 
  public:
    Deque();            
    ~Deque();   
    void delete_deque(list_node *node_ptr); // for ~Deque()
    void InsertFront(const char *data);
    void InsertRear(const char *data);
    void DeleteFront();
    void DeleteRear();
    int  GetLength();
    bool IsEmpty();
    void PrintFromFront();
    void PrintFromRear();
};

Deque::Deque()
{
    front = rear = NULL;
    length = 0;
}
 
Deque::~Deque()    // recursive approach
{	
    delete_deque(front);
}

// Delete Deque 
void Deque::delete_deque(list_node* node_ptr) 
{
    if (node_ptr != NULL) 
    {
        delete_deque(node_ptr->rlink);
        delete node_ptr; 
    }
}

// TODO: InsertFront() - Insert a new node at front end
void Deque::InsertFront(const char *data) {
    list_node *new_data = new list_node;
    if(front == NULL) {
        strcpy(new_data->data, data);
        new_data->llink = NULL;
        front = new_data;
        new_data->rlink = NULL;
        rear = new_data;
    }
    else 
    {
        strcpy(new_data->data, data);
        new_data->llink = NULL;
        new_data->rlink = front;
        front->llink = new_data;
        front = new_data;
    }
}

// TODO: InsertRear() - Insert a new node at rear end
void Deque::InsertRear(const char *data) {
    list_node *new_data = new list_node;
    if(rear == NULL) {
        strcpy(new_data->data, data);
        new_data->llink = NULL;
        front = new_data;
        new_data->rlink = NULL;
        rear = new_data;
    }
    else 
    {
        strcpy(new_data->data, data);   
        new_data->rlink = NULL;         
        new_data->llink = rear;        
        rear->rlink = new_data;         
        rear = new_data;
    }
}

// TODO: DeleteFront() - Delete a node at front end
void Deque::DeleteFront() {
    if(front != NULL) {
        list_node *Link = front;
        front = front->rlink;
        free(Link);
        if(front != NULL) {
            front->llink = NULL;
        }
    }
}

// TODO: DeleteRear() - Delete a node at rear end
void Deque::DeleteRear() {
    if(rear != NULL) {
        list_node *Link = rear;
        rear = rear->llink;
        free(Link);
        if(rear != NULL) {
            rear->rlink = NULL;
        }
    }
}

// TODO: GetLength() - Return the number of nodes in deque
int Deque::GetLength() {
    int size = 0;
    list_node *Dlink;
    Dlink = front;

    while(Dlink != NULL) {
        Dlink = Dlink->rlink;
        size++;
    }
    return size;
}
// TODO: IsEmpty() - Return true if deque is empty. Otherwise return false.
bool Deque::IsEmpty() {
    list_node *Dlist;
    return ( Dlist->rlink == NULL && Dlist->llink == NULL);
}

// TOOD: PrintFromFront() - Print all data start from front end
void Deque::PrintFromFront() {
    list_node *Dlist = front;
    int count = GetLength();
    for(int i = 0 ; i < count ; i++) {
        cout << Dlist->data << " ";
        Dlist = Dlist->rlink;
    }
}

// TODO: PrintFromRear() - Print all data start from rear end
void Deque::PrintFromRear() {
    list_node *Dlist = rear;
    int count = GetLength();
    for(int i = 0 ; i < count ; i++) {
        cout << Dlist->data << " ";
        Dlist = Dlist->llink;
    }
}