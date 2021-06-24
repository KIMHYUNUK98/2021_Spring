#include "AVLTree2.cpp"

int main() 
{
    AVLTree *avl = new AVLTree();
    element x;
       
    x.key = 8; avl->Insert(x);      
    x.key = 9; avl->Insert(x);     
    x.key = 10; avl->Insert(x);  
    cout << "AVL Tree #1" << endl;
    avl->Print();
    cout << endl;

    x.key = 2; avl->Insert(x);
    x.key = 1; avl->Insert(x);
    x.key = 5; avl->Insert(x);
    x.key = 3; avl->Insert(x);
    cout << "AVL Tree #2" << endl;
    avl->Print();
    cout << endl;

    x.key = 6; avl->Insert(x); 
    x.key = 4; avl->Insert(x);  
    x.key = 7; avl->Insert(x);
    cout << "AVL Tree #3" << endl;
    avl->Print();
    cout << endl;

    x.key = 11; avl->Insert(x);
    x.key = 12; avl->Insert(x);
    cout << "AVL Tree #4" << endl;
    avl->Print();
    cout << endl;

    cout << "----------------------------------" << endl;

    x.key = 6;  avl->Delete(x);
    cout << "AVL Tree #5" << endl;
    avl->Print();
    cout << endl;

    x.key = 10;  avl->Delete(x);
    cout << "AVL Tree #6" << endl;
    avl->Print();
    cout << endl;

    x.key = 4;  avl->Delete(x);
    cout << "AVL Tree #7" << endl;
    avl->Print();
    cout << endl;

    x.key = 2;  avl->Delete(x);
    cout << "AVL Tree #8" << endl;
    avl->Print();
    cout << endl;

    x.key = 3;  avl->Delete(x);
    cout << "AVL Tree #9" << endl;
    avl->Print();
    cout << endl;

    x.key = 11;  avl->Delete(x);
    cout << "AVL Tree #10" << endl;
    avl->Print();
    cout << endl;
    
    return 0; 
}