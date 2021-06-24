typedef struct {
    int key;
    string data;
} Element;

#define MAX_SIZE 30

class MaxHeap{
  // TODO: Define the MaxHeap class
    private:
      Element heap[MAX_SIZE];
      int index;

    public:
      MaxHeap() {index = 0;};
      ~MaxHeap() {index = 0;};
      bool IsEmpty() {return (index == 0);};
      bool IsFull() {return (index == MAX_SIZE -1);};
      void swap(Element *a, Element *b);
      void insert(Element item);
      Element deletion();
      void Print();
};
