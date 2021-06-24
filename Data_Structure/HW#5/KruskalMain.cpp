#include "Graph.cpp"

int main() 
{ 
    Graph *graph = new Graph(); 

    /*
    graph->InsertEdge(0, 1, 5); // src, dest, cost
    graph->InsertEdge(0, 2, 6);
    graph->InsertEdge(0, 3, 8);
    graph->InsertEdge(1, 2, 2);
    graph->InsertEdge(1, 4 ,3);
    graph->InsertEdge(1, 5, 10); 
    graph->InsertEdge(2, 3, 7);
    graph->InsertEdge(2, 4, 1);
    graph->InsertEdge(3, 4, 4);
    graph->InsertEdge(3, 6, 6);
    graph->InsertEdge(4, 6, 9);
    graph->InsertEdge(5, 6, 6);
    */
    graph->InsertEdge(0, 1, 1);
    graph->InsertEdge(0, 2, 2);
    graph->InsertEdge(0, 5, 3);
    graph->InsertEdge(1, 2, 4);
    graph->InsertEdge(1, 5, 5);
    graph->InsertEdge(1, 3, 7);
    graph->InsertEdge(2, 3, 6);
    graph->InsertEdge(3, 5, 8);
    graph->InsertEdge(3, 4, 9);
    graph->InsertEdge(4, 5, 10);

    cout << "Print All Lists: ";
    cout << graph->GetNumVertices();
    cout << " vertices are in use currently" << endl;
    graph->PrintAdjList();

    cout << endl;
    cout << "Kruskal Algorithm: " << endl;
    graph->KruskalAlg();
    
    return 0; 
}