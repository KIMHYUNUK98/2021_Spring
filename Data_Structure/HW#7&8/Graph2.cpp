#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std; 

#define MAX_VERTICES 50

typedef struct t_node {
    int vertex;
    struct t_node *link;
} node; 

class Graph {
  private: 
    node *graph[MAX_VERTICES];      // Adjacency list
    bool visited[MAX_VERTICES];     // Visited vertex
    vector<int> adList[MAX_VERTICES];
    int num_valid_vertex;           // Number of vertices currently in use  
    
  public: 
    Graph();
    bool IsEmpty();
    void InsertEdge(int src, int dest);
    void InsertNode(int src, int dest);
    void DFS_recur(int v);          // Recursive DFS
    void DFS_iter(int v);           // Iterative DFS
    void BFS_iter(int v);           // Iterative BFS 
    void PrintAdjList();            // Print all adjacency list
    int  GetNumVertices() { return num_valid_vertex; };
}; 


Graph::Graph() 
{
    num_valid_vertex = 0;
    for(int i = 0 ; i < MAX_VERTICES ; i++)
    {
        visited[i] = false;
        graph[i] = NULL;
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
    
    // vertex를 세기 위한 graph 구성
    if(graph[src] == NULL) {
        num_valid_vertex++;
    }
    src_node->vertex = dest;
    graph[src] = src_node;

    // vector 를 이용한 Linked List 형성
    adList[src].push_back(dest);
    sort(adList[src].rbegin(), adList[src].rend());

}

// TODO: recursive DFS algorithm 
void Graph::DFS_recur(int v)
{
    vector<int>::iterator it;
    
    if(visited[v])
        return;
    
    visited[v] = true;
    cout << v;

    for(it = adList[v].begin() ; it < adList[v].end() ; it++) {
        if(!visited[*it])
            DFS_recur(*it);
    }
}

// TODO: iterative DFS algorithm
void Graph::DFS_iter(int v)
{
    stack<int> stacks; 
    vector<int>::iterator it;

    for (int i = 0; i < MAX_VERTICES; i++)  visited[i] = false;

    stacks.push(v);
    while(!stacks.empty()) {
        v = stacks.top();
        stacks.pop();
        if(visited[v]) continue;
        visited[v] = true;
        cout << v ;
        for(it = adList[v].begin() ; it < adList[v].end() ; it++) {
            if(!visited[*it]) {
                stacks.push(*it);
            }
        }
    }
}

// TODO: iterative BFS algorithm
void Graph::BFS_iter(int v) 
{
    queue<int> q;
    vector<int>::iterator it;

    for (int i = 0; i < MAX_VERTICES; i++)  visited[i] = false;

    cout << v;
    visited[v] = true;
    q.push(v);
    while(!q.empty()) {
        v = q.front();
        q.pop();
        for(it = adList[v].begin() ; it < adList[v].end() ; it++) {
            if(!visited[*it]) {
                cout << *it; 
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}

// TODO: Print all adjacency lists linked by graph[]
void Graph::PrintAdjList()
{
    vector<int>::iterator it;

    for(int i = 0 ; i < 8 ; i ++) 
    {
        cout << "graph[" << i << "]: ";
        for(it = adList[i].begin(); it < adList[i].end(); ++it)
        {
            cout << *it << " ";
            if(it+1 != adList[i].end()) cout << "->" << " ";
            else cout << endl;
        }
    }
}