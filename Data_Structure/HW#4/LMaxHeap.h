typedef struct node {
    int key;
    string data;
    struct node *parent, *left_child, *right_child;
} tree_node;

typedef struct {
    int key;
    string data;
} Element;

#define MAX_SIZE 30

class LMaxHeap{
  // TODO: Define the MaxHeap class
    private:
        tree_node *root;

    public:
        LMaxHeap() {root = NULL;};
        ~LMaxHeap() {root = NULL;};
        void insert(Element item);
        void insert(Element item, tree_node *tree);
        Element deletion();
        Element deletion(tree_node *node);  // 마지막 node 할당해제 & root node 반환
        tree_node* Search(tree_node *node); // 마지막 node 찾아주는 함수
        void Switch(tree_node *node);   // delete하고 크기 순서대로 swap해주는 함수
        void compare(tree_node *node);  // insert하고 크기 순서대로 swap해주는 함수
        void Print();   // preorder print 함수 call
        void print_preorder(tree_node *node); // preorder로 print 해주는 함수
};