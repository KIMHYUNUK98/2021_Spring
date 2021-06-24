#ifndef _NONO_
#define _NONO_
#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *left_child, *right_child;
} tree_node;

class BinTree{
    private:
        tree_node* root;
    
    public:
    BinTree();
    ~BinTree();
    bool IsEmpty();
    void MakeBT(BinTree *b1, int item, BinTree *b2);
    tree_node* Lchild(tree_node *bt){return bt->left_child;};
    tree_node* Rchild(tree_node *bt){return bt->right_child;};
    void insert_node_left(int data);
    void insert_node_right(int data);
    // tree_node* modified_search(int data); 
    // void insert_node(int data);
    void delete_tree(tree_node* tree);
    void inorder(tree_node* ptr);
    void Print();
    bool equal(tree_node *first, tree_node *second);
    bool equal(BinTree* second);
    tree_node* copy(tree_node* original);
    void copy(BinTree* source);
};
#endif