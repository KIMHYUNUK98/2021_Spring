// TODO: implement the member functions of MaxHeap class
void MinHeap::swap(Element *a, Element *b) {
    Element temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void MinHeap::insert(Element item) {
    if(IsFull()) {
        cout << "The heap is full"<< endl;
        return;
    }
    int i = ++index;    
    while((i != 1) && (item.key < heap[i/2].key)) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

Element MinHeap::deletion() {
    int parent, larger;
    Element item = heap[1];
    heap[1] = heap[index--];
    parent = 1;
    while(parent*2 <= index) {
        if(parent*2+1 <= index) {
            if(heap[parent*2].key <= heap[parent*2+1].key)
                larger = parent*2;
            else
                larger = parent*2+1;
        }
        else 
            larger = parent*2;

        if(heap[parent].key <= heap[larger].key)
            break;
        swap(&heap[parent], &heap[larger]);
            parent = larger;
    }
    return item;
}

void MinHeap::Print() {
    Element show;
    show = heap[1];
    cout << show.key << " ";
}