#include "BinTree.h"

BinTree::BinTree() {
    root = NULL;
}

BinTree::~BinTree() {
    delete_tree(root);
    root = NULL; 
}

void BinTree::delete_tree(tree_node* ptr) {
    if (ptr) {
    delete_tree(ptr->left_child);
    delete_tree(ptr->right_child);
    
    cout << "delete " << ptr->data << endl;
    delete(ptr);
    }
}

bool BinTree::IsEmpty() {
    return (root == NULL);
}

void BinTree::insert_node_left(int num) {
    tree_node *ptr = new tree_node;
    ptr->data = num;
    ptr->left_child = ptr->right_child = NULL;
    if(IsEmpty()) root = ptr;
    else{
        tree_node *cur = root;
        for(;cur->left_child;cur=cur->left_child);
        cur->left_child = ptr;
    }
}
void BinTree::insert_node_right(int num) {
    tree_node *ptr = new tree_node;
    ptr->data = num;
    ptr->left_child = ptr->right_child = NULL;
    
    if(IsEmpty()) root = ptr;
    else{
        tree_node *cur = root;
        for(;cur->right_child;cur=cur->right_child);
        cur->right_child = ptr;
    }
}

void BinTree::inorder(tree_node* ptr)   {
    if (ptr) {
        inorder(ptr->left_child);
        cout << "[" << ptr->data << "]";
        inorder(ptr->right_child);
    }
}

void BinTree::Print() {
    inorder(root);
    cout << endl;
}

bool BinTree::equal(tree_node* first, tree_node* second) {
    return ((!first && !second)||(first && second && (first->data == second->data) &&
            equal(first->left_child, second->left_child) &&
            equal(first->right_child, second->right_child)));
}

bool BinTree::equal(BinTree* second) {
    return equal(root, second->root);
}

tree_node* BinTree::copy(tree_node* original) {
    if(original){
    tree_node* temp = new tree_node;
    temp->left_child = copy(original->left_child);
    temp->right_child = copy(original->right_child);
    temp->data = original->data;
    return temp;
    }
    return NULL;
}

void BinTree::copy(BinTree *source) {
    root = copy(source->root);
}

void BinTree::MakeBT(BinTree *b1, int num, BinTree *b2) {
    root = new tree_node;
    root->left_child = copy(b1->root);
    root->right_child = copy(b2->root);
    root->data = num;
}
