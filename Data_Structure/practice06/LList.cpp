
#include <iostream>
#include <cstring>

using namespace std;

typedef struct t_list_node {
    char data[4];
    struct t_list_node *link;   
} list_node;


// TODO: Define LList 

// TODO: Implement member functions of LList: 
//       GetBytData(), GetByIndex(), Insert(), InsertAfterNode(), Delete(), Print(), IsEmpty()
//       GetLength(), Concat(), Copy() 
class LList {
    private:
        list_node *head;

    public:
        LList();
        ~LList();
        list_node *GetByData(const char *data);  //Complete
        list_node *GetByIndex(int n);  //Complete
        void Insert(const char *data);  //Complete
        void InsertAfterNode(const char *data, list_node *ptr); //Complete
        void Delete(const char *data);  //Complete
        void Print();   //Complete
        void Invert();  //Complete
        bool IsEmpty(); //Complete
        void delete_list(list_node *node_ptr);

        int GetLength();
        void Concat(LList *src_list);
        void Copy(LList *src_list);
};

LList::LList() {
    head = NULL;
}

LList::~LList() {
    delete_list(head);
}

list_node *LList::GetByData(const char *data) {
    list_node *cur = NULL;
    for(cur = head ; cur != NULL ; cur = cur->link) {
        if(strcmp(cur->data, data) == 0) 
            break;
    }
    return cur;
}

list_node *LList::GetByIndex(int n) {
    list_node *cur = NULL;
    int i;
    for(cur = head, i = 0  ; cur != NULL && i < n ; cur = cur->link, i++) {

    }
    return cur;
}

void LList::Delete(const char *data) {
    list_node* prev;
    list_node* cur = head;
    
    while(cur && strcmp(cur->data, data)!= 0) {
        prev = cur;
        cur = cur->link;
    }
    if(cur) {
        if(cur == head)
            head = cur->link;
        else 
            prev->link = cur->link;

        delete cur;
    }
}

void LList::Print() {
    list_node *cur = NULL;
    cout << "List: ";
    for(cur = head ; cur != NULL ; cur = cur->link) {
        cout << cur->data << " ";
    }
    cout << endl;
}

void LList::Invert() {
    if(IsEmpty()) 
        return;
    list_node *cur = head;
    list_node *next = head->link;
    while(cur) {
        if(cur == head)
            cur->link = NULL;
        else {
            cur->link = head;
            head = cur;
        }
        cur = next;
        if(cur) next = next->link;
    }
}

bool LList::IsEmpty() {
    return (head == NULL);
}

void LList::delete_list(list_node *node_ptr) {
    if(node_ptr != NULL) {
        delete_list(node_ptr->link);
        delete node_ptr;
    }
}

int LList::GetLength() {
    list_node *cur;
    int i = 0;
    for(cur = head ; cur != NULL ; cur = cur->link) {
        i++; 
    }
    return i;
}

void LList::Concat(LList *src_list) {
    list_node *cur;
    for(cur = head ; cur->link != NULL ; cur = cur->link);
    cur->link = src_list->head;
}

void LList::Insert(const char *data) {
    list_node *new_node = (list_node*)malloc(sizeof(list_node));
    strcpy(new_node->data, data);
    new_node->link = head;
    head = new_node;
}

void LList::InsertAfterNode(const char *data, list_node *ptr) {
    list_node *new_node = (list_node*)malloc(sizeof(list_node));
    strcpy(new_node->data, data);
    new_node->link = ptr->link;
    ptr->link = new_node;
}

void LList::Copy(LList* src_list) {
    list_node *cur1;
    for(cur1 = src_list->head ; cur1 != NULL ; cur1 = cur1->link) {
        list_node *cur2 = new list_node;
        strcpy(cur2->data, cur1->data);
        cur2->link = head;
        head = cur2;
    }
    Invert();
}