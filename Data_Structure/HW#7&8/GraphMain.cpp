#include "Graph2.cpp"

int main() 
{
    Graph *graph = new Graph(); 

    graph->InsertEdge(0, 1);
    graph->InsertEdge(0, 2);
    graph->InsertEdge(1, 3);
    graph->InsertEdge(1, 4);
    graph->InsertEdge(2, 5);
    graph->InsertEdge(2, 6);
    graph->InsertEdge(3, 7);
    graph->InsertEdge(4, 7);
    graph->InsertEdge(5, 7);
    graph->InsertEdge(6, 7);

    cout << "DFS(Recursive): "; 
    graph->DFS_recur(0);
    cout << endl << endl;

    cout << "DFS(Iterative): "; 
    graph->DFS_iter(0);
    cout << endl << endl;

    cout << "BFS(Iterative): "; 
    graph->BFS_iter(0);
    cout << endl << endl;

    cout << "Print All Lists: ";
    cout << graph->GetNumVertices();
    cout << " vertices are in use currently" << endl;
    graph->PrintAdjList();

    return 0; 
}