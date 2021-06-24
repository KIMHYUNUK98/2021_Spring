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


void AVLTree::Insert(element x)
{
    bool unbalanced; 
    avl_insert(&root, x, &unbalanced);
}


// TODO: Impelement avl_insert()
void AVLTree::avl_insert(tree_node **parent, element x, bool *unbalanced)
{
    
}


// TODO: Impelemnt a left_rotation()
void AVLTree::left_rotation(tree_node **parent, bool *unbalanced)
{
   
}


// TODO: Impelemnt a right_rotation()
void AVLTree::right_rotation(tree_node **parent, bool *unbalanced)
{
    
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