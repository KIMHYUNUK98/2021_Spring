#include <iostream>
using namespace std; 

#include "Stack.cpp"
#include "Queue.cpp"
#include "MinHeap.h"
#include "MinHeap.cpp"

#define MAX_VERTICES    50

typedef struct t_node {
    int vertex;
    int cost;
    struct t_node *link;
} node;

class Graph {
  private: 
    node *graph[MAX_VERTICES];      // Adjacency list
    node *cycle[MAX_VERTICES];

    int sum_vertex[MAX_VERTICES];
    bool visited[MAX_VERTICES];     // Visited vertex
    bool cycle_visited[MAX_VERTICES];
    int detect[MAX_VERTICES];
    Element item[MAX_VERTICES];
    Element cost;

    int num_valid_vertex;           // Number of vertices currently in use
    int num_valid_edge;
    int vertex_count;
    int count;
    int sum;
    int detect_cycle;  
    int num_select_edge; 
    int num;
    int dfs_edge_count;
    
  public: 
    Graph();
    bool IsEmpty() {return (num_valid_vertex == 0);};
    void InsertEdge(int src, int dest, int cost);
    void Insert();                  // Insert MinHeap
    void DFS_recur(int v);          // Recursive DFS
    void DFS_iter(int v);           // Iterative DFS
    void BFS_iter(int v);           // Iterative BFS 
    void PrintAdjList();            // Print all adjacency list
    int  GetNumVertices() { return num_valid_vertex; };
    void InsertNode(int src, int dest, int cost);
    void InsertCycle(int src, int dest);    // Cycle array
    void InsertNodeAfter(int src, int dest, int cost);
    void KruskalAlg();
    int FindCycle(int src, int dest);
    void Print_Krus();
    void DFS_cycle_detect_recur(int v);
}; 


Graph::Graph() 
{
    num_valid_vertex = 0;
    num_valid_edge = 0;
    vertex_count = 0;
    count = 0;
    sum = 0;
    detect_cycle = 0;  
    num_select_edge = 0; 
    num = 0;
    dfs_edge_count = 0;

    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph[i] = NULL;
        visited[i] = NULL;
        cycle_visited[i] = NULL;
        cycle[i] = NULL;
    }
}

// TODO: Insert an edge between vertex src and vertex dest
void Graph::InsertEdge(int src, int dest, int cost) 
{
    InsertNode(src, dest, cost);
    InsertNode(dest, src, cost);

    item[count].key = cost;
    item[count].src = src;
    item[count++].dest = dest;
}

void Graph::InsertNode(int src, int dest, int cost)
{
    node* src_node = new node;

    num_valid_edge++;
    if(graph[src] == NULL)
        num_valid_vertex++;
    

    src_node->vertex = dest;
    src_node->cost = cost;
    src_node->link = graph[src];
    graph[src] = src_node; 
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

void Graph::Insert() {
    MinHeap *min = new MinHeap();
    Element view[num_valid_edge];

    for(int i = 0 ; i < num_valid_edge/2 ; i++) {
        min->insert(item[i]);
    }

    for(int i = 0 ; i < num_valid_vertex ; i++) {
        view[i] = min->deletion();
        cout << "[" << view[i].key << "]";
    }
}

void Graph::KruskalAlg() {
    MinHeap *min = new MinHeap();

    //cost�� ���� �������� minheap�� �����Ѵ�. (edge ����ŭ ����)
    for(int i = 0 ; i < num_valid_edge/2 ; i++) min->insert(item[i]);
    

    // ���õǴ� edge�� ���� node - 1 �϶� && minheap�� ������� �ƴҶ����� �ݺ��Ѵ�.
    while( num_select_edge <  (num_valid_vertex-1) && !min->IsEmpty()) {
        // �ּ� ��θ� �����ϰ� �����
        cost = min->deletion();

        // �ش� ������ ���� �ִ� src�� dest�� �̿��� �ּҺ��Ʈ���� �����.
        detect_cycle = FindCycle(cost.src, cost.dest);
        if(detect_cycle == 1)   // cycle�� ���� ��� Linkedlist�� ǥ��
        {
            InsertCycle(cost.src, cost.dest);
            InsertCycle(cost.dest, cost.src);
            sum_vertex[num++] = cost.key;
            num_select_edge++;
        }
        else if(detect_cycle == -1) continue;   // cycle�� �ִ� ��� continue
    }

    cout << "- DFS from 0: ";
    DFS_recur(0);
    cout << endl;

    cout << "- Total Cost: ";
    for(int i = 0 ; i < num_valid_vertex ; i++) sum+= sum_vertex[i];
    cout << sum;
}

// �ּ� ������ indirected graph�� Linked List�� ǥ��
void Graph::InsertCycle(int src, int dest) {
    node* cycle_node = new node;

    cycle_node->vertex = dest;
    cycle_node->link = cycle[src];
    cycle[src] = cycle_node;
}

// InsertCycle�� ���� Linked List�� Cycle ���� ������ �Ǵ��ϴ� �Լ� ����
int Graph::FindCycle(int src, int dest) {
    node* src_node;
    node* dest_node;
    int i = 1;

    // DFS_cycle_detect_recur �Լ��� �ݺ� �����ϱ� ���� �ʿ��� �ʱ�ȭ
    vertex_count = 0;
    for(int j = 0 ; j < num_valid_vertex ; j++) {
        detect[j] = 0;
        cycle_visited[j] = 0;
    }

    // DFS �˰������� cycle ���� ���� �ľ��� ���� �׷� ���� (�迭 detect�� �׷�ȭ)
    // src���� �����ϴ� dfs�� ����
    DFS_cycle_detect_recur(src);

    // src���� �����ϰ� ���� �׷쿡 ���� vertex �� dest�� ���� ���� ������ cycle�� �����ȴ�
    // dest�� ���� vertex�� ������ cycle�� �������� �ʴ´�.
    for(int m = 0 ; m < vertex_count ; m++) 
    {
        if(detect[m] == dest) {
            i = -1;
            break;
        }
        else if(detect[m] != dest) i = 1;
    }

    return i;
}

void Graph::DFS_cycle_detect_recur(int v)
{
    node* w;

    // �ش� v���� DFS recursive�� �����ϰ� ã�� vertex�� detect �迭�� �ִ´�. (�׷�ȭ)
    detect[vertex_count++] = v;

    if(cycle_visited[v])
        return;

    cycle_visited[v] = true;
    for(w = cycle[v] ; w ; w = w->link) {
        if(!cycle_visited[w->vertex])
            DFS_cycle_detect_recur(w->vertex);
    }
}

void Graph::DFS_recur(int v)
{
    node* w;
    int i = 0;

    if(visited[v])
        return;

    visited[v] = true;
    cout << v ;
    for(w = cycle[v] ; w; w = w->link) {
        if(!visited[w->vertex])
            DFS_recur(w->vertex);
    }
}

void Graph::Print_Krus()
{
    node* w;
    int i = 0;
    w = cycle[0];
    
    for (i = 0; i < num_valid_vertex; i++) 
    {
        cout << "cycle[" << i << "]: ";

        w = cycle[i];
        while(w) {
            cout << w->vertex << " ";
            if(w->link != NULL) cout << "->" << " ";
            else cout << endl;
            w = w ->link;
        }
    }
}