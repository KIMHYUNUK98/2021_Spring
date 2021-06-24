#define MAX_SIZE 30

typedef struct {
    int key;
    int src;
    int dest;
    bool visited[MAX_SIZE];
} Element;

class MinHeap{
  // TODO: Define the MinHeap class
    private:
      Element heap[MAX_SIZE];
      int index; 

    public:
      MinHeap() {index = 0;};
      ~MinHeap() {index = 0;};
      bool IsEmpty() {return (index == 0);};
      bool IsFull() {return (index == MAX_SIZE -1);};
      void swap(Element *a, Element *b);
      void insert(Element item);
      Element deletion();
      void Print();
};
