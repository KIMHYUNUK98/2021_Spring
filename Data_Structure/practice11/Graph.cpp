#include <iostream>
using namespace std; 
#include "Stack.cpp"
#include "Queue.cpp"

#define MAX_VERTICES    50

typedef struct t_node {
    int vertex;
    struct t_node *link;
} node; 

class Graph {
  private: 
    node *graph[MAX_VERTICES];      // Adjacency list
    bool visited[MAX_VERTICES];     // Visited vertex
    int num_valid_vertex;           // Number of vertices currently in use  
    
  public: 
    Graph();
    bool IsEmpty();
    void InsertEdge(int src, int dest);
    void DFS_recur(int v);          // Recursive DFS
    void DFS_iter(int v);           // Iterative DFS
    void BFS_iter(int v);           // Iterative BFS 
    void PrintAdjList();            // Print all adjacency list
    int  GetNumVertices() { return num_valid_vertex; };
    void InsertNode(int src, int dest);
    void InsertNodeAfter(int src, int dest);
}; 


Graph::Graph() 
{
    num_valid_vertex = 0;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph[i] = NULL;
        visited[i] = false;
    }
}

bool Graph::IsEmpty()
{
    return (num_valid_vertex == 0);
}

// TODO: Insert an edge between vertex src and vertex dest
void Graph::InsertEdge(int src, int dest) 
{
    InsertNode(src, dest);
    InsertNode(dest, src);
}


void Graph::InsertNode(int src, int dest)
{
    node* src_node = new node;

    if(graph[src] == NULL)
        num_valid_vertex++;

    src_node->vertex = dest;
    src_node->link = graph[src]; // NULL 값 이동시키는 과정
    graph[src] = src_node; 
}

// TODO: recursive DFS algorithm 
void Graph::DFS_recur(int v)
{
    node* w;
    if(visited[v])
        return;

    visited[v] = true;
    cout << v;
    for(w = graph[v] ; w; w = w->link) {
        if(visited[w->vertex] != true)
            DFS_recur(w->vertex);
    }
}

// TODO: iterative DFS algorithm
void Graph::DFS_iter(int v)
{
    node* w;
    Stack graphS;

    for (int i = 0; i < MAX_VERTICES; i++)  visited[i] = false;

    graphS.Push(v);
    while(!graphS.IsEmpty()) {
        v = graphS.Pop();
        if(visited[v]) continue;
        visited[v] = true;
        cout << v;
        for(w = graph[v] ; w ; w = w->link) 
            if(!visited[w->vertex]) 
                graphS.Push(w->vertex);
    }
}

// TODO: iterative BFS algorithm
void Graph::BFS_iter(int v) 
{
    node* w;
    Queue graphQ;

    for (int i = 0; i < MAX_VERTICES; i++)  visited[i] = false;

    cout << v;
    visited[v] = true;
    graphQ.AddQ(v); 
    while(!graphQ.IsEmpty()) {
        v = graphQ.DeleteQ();
        for(w = graph[v] ; w ; w = w->link)
            if(!visited[w->vertex]) {
                cout << w->vertex;
                visited[w->vertex] = true;
                graphQ.AddQ(w->vertex);
            }
    }
}

// TODO: Print all adjacency lists linked by graph[]
void Graph::PrintAdjList()
{
    node* w;
    int i = 0;
    w = graph[0];
    
    for (i = 0; i < num_valid_vertex; i++) 
    {
        cout << "graph[" << i << "]: ";

        w = graph[i];
        while(w) {
            cout << w->vertex << " ";
            if(w->link != NULL) cout << "->" << " ";
            else cout << endl;
            w = w ->link;
        }
    }
}