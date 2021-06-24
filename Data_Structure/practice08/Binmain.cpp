#include <iostream>

#include "BinTree.cpp"
#include "BinTree.h"

using namespace std;

int main() {
    BinTree* tree1 = new BinTree();
    BinTree* tree2 = new BinTree();
    BinTree* tree3 = new BinTree();
    BinTree* tree4 = new BinTree();

    tree1->insert_node_left(3);
    tree1->insert_node_left(1);
    tree1->insert_node_right(5);
    tree1->Print();

    tree2->insert_node_right(3);
    tree2->insert_node_right(1);
    tree2->Print();
    if (tree1->equal(tree2)) cout << "1-2 Equal!" << endl;
    else cout << "1-2 Not equal" << endl;

    tree3->copy(tree1);
    tree3->Print();
    if (tree1->equal(tree3)) cout << "1-3 Equal!" << endl;
    else cout << "1-3 Not equal" << endl;

    tree4->MakeBT(tree1, 11, tree2);
    tree4->Print();

    delete tree1;
}
