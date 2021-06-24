#include "Digraph.cpp"

int main() 
{
    Digraph *digraph = new Digraph(); 

    digraph->InsertEdge(0, 1, 50);
    digraph->InsertEdge(0, 2, 10);
    digraph->InsertEdge(0, 4, 45);
    digraph->InsertEdge(1, 2, 15);
    digraph->InsertEdge(1, 4, 10);
    digraph->InsertEdge(2, 0, 20);
    digraph->InsertEdge(2, 3, 15);
    digraph->InsertEdge(3, 1, 20);
    digraph->InsertEdge(3, 4, 30);
    digraph->InsertEdge(4, 3, 35);
    digraph->InsertEdge(5, 3, 3);

    cout << "Print Adj Matrix: ";
    cout << digraph->GetNumVertices();
    cout << " vertices are in use currently" << endl;
    digraph->PrintAdjMatrix();
    cout << endl;

    cout << "Single Source Shortest Path from " << 0 << endl; 
    digraph->ShortestPath(0);
    cout << endl;

    cout << "Single Source Shortest Path from " << 1 << endl; 
    digraph->ShortestPath(1);
    cout << endl;
    
    return 0; 
}