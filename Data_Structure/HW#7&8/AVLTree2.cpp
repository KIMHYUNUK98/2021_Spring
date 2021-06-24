#include <iostream>
#include <iomanip>
using namespace std; 

typedef struct { 
    int key;
} element; 

typedef struct node {
   element data;
   short int bf;  
   struct node *left; 
   struct node *right; 

   short int level;         // For print
   short int parent_key;    // For print
} tree_node;

#include "Queue.cpp"

class AVLTree {
  private: 
    tree_node *root;          
    void avl_insert(tree_node **parent, element x, bool *unbalanced);
    void left_rotation(tree_node **parent, bool *unbalanced);
    void right_rotation(tree_node **parent, bool *unbalanced);

  public: 
    AVLTree();
    ~AVLTree();
    void delete_tree(tree_node* ptr);
    bool IsEmpty();
    void Insert(element x);
    void Print();
    void Delete(element x);
    void Delete(tree_node **parent, element x, bool *unbalanced);
    tree_node* Findleft(tree_node **parent);
    void Right_Balance(tree_node **parent, bool *unbalanced);
    void Left_Balance(tree_node **parent, bool *unbalanced);
}; 

AVLTree::AVLTree()
{
    root = NULL;
}

AVLTree::~AVLTree()
{
    delete_tree(root);
    root = NULL; 
}

void AVLTree::delete_tree(tree_node* ptr)
{
    if (ptr) {
        delete_tree(ptr->left);
        delete_tree(ptr->right);
        delete(ptr);
    }
}

bool AVLTree::IsEmpty()
{
    return (root == NULL);
}

void AVLTree::Delete(element x) {
    bool unbalanced;
    Delete(&root, x, &unbalanced);
}

void AVLTree::Delete(tree_node **parent, element x, bool *unbalanced)  
{
    if(!*parent) {
        cout << "Can't Delete the node!! " << endl;
        *unbalanced = false;
    }
    // x.key가 parent의 key보다 작은 경우 left child로 이동
    else if(x.key < (*parent)->data.key) 
    {
        Delete(&(*parent)->left, x, unbalanced);
        if(*unbalanced == false) Right_Balance(parent, unbalanced);
    }
    // x.key가 parent의 key보다 큰 경우 right child로 이동
    else if(x.key > (*parent)->data.key) 
    {
        Delete(&(*parent)->right, x, unbalanced);
        if(*unbalanced == false) Left_Balance(parent, unbalanced);
    }
    // x.key를 찾은 경우
    else 
    {
        // right child만 존재하는 경우 제거 알고리즘
        if((*parent)->left == NULL && (*parent)->right != NULL) 
        {
            (*parent) = (*parent)->right;
            (*parent)->right = NULL;
            *unbalanced = false;
        }
        // left child만 존재하는 경우 제거 알고리즘
        else if((*parent)->left != NULL && (*parent)->right == NULL) 
        {
            (*parent) = (*parent)->left;
            (*parent)->left = NULL;
            *unbalanced = false;
        }
        // left & right child가 둘다 없는 경우 해당 node를 제거하는 알고리즘 && unbalanced된다
        else if((*parent)->left == NULL && (*parent)->right == NULL)
        {
            (*parent) = NULL;
            *unbalanced = false;
        }
        // left와 right에 트리가 존재하는 경우 해당 node를 제거하기 위해
        // Findleft 함수를 이용해 대체제를 찾고
        // 해당 대체제를 recursive하게 제거해서 x.key가 없어지도록 한다.
        else 
        {
            tree_node *temp = new tree_node;
            temp = Findleft(&(*parent)->left);
            (*parent)->data.key = temp->data.key;
            Delete(&(*parent)->left, temp->data, unbalanced);
            if(*unbalanced == false) Right_Balance(parent, unbalanced);
        }
    }
}


void AVLTree::Left_Balance(tree_node **parent, bool *unbalanced)
{
    if((*parent)->bf == 0) 
    {
        (*parent)->bf = 1;
        *unbalanced = true;
    }
    else if((*parent)->bf == -1) 
    {
        (*parent)->bf = 0;
        *unbalanced = false;
    }
    else left_rotation(parent, unbalanced);
}

void AVLTree::Right_Balance(tree_node **parent, bool *unbalanced)
{
    if((*parent)->bf == 0) 
    {
        (*parent)->bf = -1;
        *unbalanced = true;
    }
    else if((*parent)->bf == 1)
    {
        (*parent)->bf = 0;
        *unbalanced = true;
    }
    else
        right_rotation(parent, unbalanced);
}

tree_node* AVLTree::Findleft(tree_node **ptr)
{
    tree_node *current = *ptr;

    while(current->right != NULL) 
        current = current->right;

    return current;
}

void AVLTree::Insert(element x)
{
    bool unbalanced; 
    avl_insert(&root, x, &unbalanced);
}


// TODO: Impelement avl_insert()
void AVLTree::avl_insert(tree_node **parent, element x, bool *unbalanced)
{
    if(!*parent) {
        *unbalanced = true;
        *parent = new tree_node;
        (*parent)->left = NULL;
        (*parent)->right = NULL;
        (*parent)->bf = 0;
        (*parent)->data = x;
    }
    else if(x.key < (*parent)->data.key) {
        avl_insert(&(*parent)->left, x, unbalanced);
        if(*unbalanced) {
            switch((*parent)->bf) {
                case -1: (*parent)->bf = 0;
                        *unbalanced = false;
                        break;
                case 0: (*parent)-> bf = 1;
                        break;
                case 1: left_rotation(parent, unbalanced);
                        break;
            }
        }
    }
    else if(x.key > (*parent)->data.key) {
        avl_insert(&(*parent)->right, x, unbalanced);
        if(*unbalanced) {
            switch((*parent)->bf) {
                case -1: right_rotation(parent, unbalanced);
                        break;
                case  0: (*parent)->bf = -1;
                        break;
                case  1: (*parent)->bf = 0;
                        *unbalanced = false;
                        break;
            }
        }
    }
    else {
        *unbalanced = false;
        cout << "The key is already in the tree" << endl;
    }
}

// TODO: Impelemnt a left_rotation()
void AVLTree::left_rotation(tree_node **parent, bool *unbalanced)
{
    tree_node *grand_child, *child;
    child = (*parent)->left;
    if(child->bf == -1) {
        grand_child = child->right;
        child->right = grand_child->left;
        grand_child->left = child;
        (*parent)->left = grand_child->right;
        grand_child->right = *parent;
        switch(grand_child->bf) {
            case  1:(*parent)->bf = -1;
                    child->bf = 0;
                    break;
            case  0:(*parent)->bf = child->bf = 0;
                    break;
            case -1:(*parent)->bf = 0;
                    child->bf = 1;
                    break;
        }
        *parent = grand_child;
        cout << "LR rotation!!!!!!" << endl;
    }
    else {
        (*parent)->left = child->right;
        child->right = *parent;
        (*parent)->bf = 0;
        (*parent) = child;
        cout << "LL rotation!!!!!!" << endl;
    }
    (*parent)->bf = 0;
    *unbalanced = false;
}


// TODO: Impelemnt a right_rotation()
void AVLTree::right_rotation(tree_node **parent, bool *unbalanced)
{
    
    tree_node *grand_child, *child;
    child = (*parent)->right;
    if(child->bf == 1) {
        grand_child = child->left;
        child->left = grand_child->right;
        grand_child->right = child;
        (*parent)->right = grand_child->left;
        grand_child->left = *parent;
        switch(grand_child->bf) {
            case  1:(*parent)->bf = 0;
                    child->bf = -1;
                    break;
            case  0:(*parent)->bf = child->bf = 0;
                    break;
            case -1:(*parent)->bf = 1;
                    child->bf = 0;
                    break;
        }
        *parent = grand_child;
        cout << "RL rotation!!!!!" <<endl;
    }
    else {
            (*parent)->right = child->left;
            child->left = *parent;
            (*parent)->bf = 0;
            (*parent) = child;
            cout << "RR Rotation!!!!" << endl;
        
    }
    (*parent)->bf = 0;
    *unbalanced = false;
}


void AVLTree::Print()
{
    Queue queue;
    tree_node *ptr;
    int cur_level = 1; 

    if (IsEmpty()) 
        return;

    root->level = cur_level;
    root->parent_key = -1;
    cout << "Level " << cur_level << ": ";

    queue.AddQ(root);
    while (!queue.IsEmpty()) 
    {
        ptr = queue.DeleteQ();

        if (ptr->level != cur_level)
        {
            cur_level = ptr->level;
            cout << endl << "Level " << cur_level << ": ";
        }
        
        cout << "[" << setw(2) << ptr->data.key;
        cout << "(" << setw(2) << ptr->parent_key << "," << setw(2) << ptr->bf <<")]";

        if (ptr->left) 
        {
            ptr->left->level = cur_level + 1;
            ptr->left->parent_key = ptr->data.key;
            queue.AddQ(ptr->left);
        }
        if(ptr->right) 
        {
            ptr->right->level = cur_level + 1;
            ptr->right->parent_key = ptr->data.key;
            queue.AddQ(ptr->right);    
        }
    }
    cout << endl;
}