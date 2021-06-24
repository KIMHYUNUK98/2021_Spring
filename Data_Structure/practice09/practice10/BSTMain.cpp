#include <iostream>

using namespace std;

#include "BST.h"
#include "Queue.cpp"
#include "BST.cpp"


int main()
{
    bool found;
    BST* bst = new BST();
    
    bst->insert_node(40);
    bst->insert_node(20);
    bst->insert_node(60);
    bst->insert_node(10);
    bst->insert_node(30);
    bst->insert_node(50);
    bst->insert_node(45);
    bst->insert_node(55);
    bst->insert_node(52);
    bst->insert_node(70);

    cout << "BST Print after Insert Node:" << endl;
    bst->print();
    cout << endl;

    found = bst->search(20);
    cout << "BST Search 20: " << (found?"Found":"Not Found") << endl;
    found = bst->search(80);
    cout << "BST Search 80: " << (found?"Found":"Not Found") << endl;
    cout << endl;

    bst->delete_node(60);    
    cout << "BST Print after Delete Node 60:" << endl;
    bst->print();
    cout << endl;

    bst->delete_node(52);    
    cout << "BST Print after Delete Node 52" << endl;
    bst->print();
    cout << endl;

    bst->delete_node(50);    
    cout << "BST Print after Delete Node 50" << endl;
    bst->print();
    cout << endl;
}
