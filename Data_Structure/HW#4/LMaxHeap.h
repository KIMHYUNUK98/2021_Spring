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
        Element deletion(tree_node *node);  // ������ node �Ҵ����� & root node ��ȯ
        tree_node* Search(tree_node *node); // ������ node ã���ִ� �Լ�
        void Switch(tree_node *node);   // delete�ϰ� ũ�� ������� swap���ִ� �Լ�
        void compare(tree_node *node);  // insert�ϰ� ũ�� ������� swap���ִ� �Լ�
        void Print();   // preorder print �Լ� call
        void print_preorder(tree_node *node); // preorder�� print ���ִ� �Լ�
};