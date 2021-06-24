#include "AVLTree.cpp"

int main() 
{
    AVLTree *avl = new AVLTree();
    element x;

    x.key = 8; avl->Insert(x);      
    x.key = 9; avl->Insert(x);     
    x.key = 10; avl->Insert(x);  
    cout << "AVL Tree: Step #1" << endl;
    avl->Print();
    cout << endl;

    x.key = 2; avl->Insert(x);
    x.key = 1; avl->Insert(x);
    x.key = 5; avl->Insert(x);
    x.key = 3; avl->Insert(x);
    cout << "AVL Tree: Step #2" << endl;
    avl->Print();
    cout << endl;

    x.key = 6; avl->Insert(x); 
    x.key = 4; avl->Insert(x);  
    x.key = 7; avl->Insert(x);
    cout << "AVL Tree: Step #3" << endl;
    avl->Print();
    cout << endl;

    x.key = 11; avl->Insert(x);
    x.key = 12; avl->Insert(x);
    cout << "AVL Tree: Step #4" << endl;
    avl->Print();
    cout << endl;
    
    return 0; 
}