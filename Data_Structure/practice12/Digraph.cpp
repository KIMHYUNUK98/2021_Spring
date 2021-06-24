#include <iostream>
#include <iomanip>
using namespace std; 
#include "Stack.cpp"                        // We may need to print path

#define MAX_VERTICES    50
#define INFINITY        999999

class Digraph {
  private: 
    int  graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int  distance[MAX_VERTICES];            // Distance for shortest path
    int  parent[MAX_VERTICES];              // We may need to print path
    bool valid[MAX_VERTICES];               // To count the number of vertices
    bool found[MAX_VERTICES];               // Set for shortest path 
    int  num;                               // Number of vertices currently in use  
    
  public: 
    Digraph();
    void InsertEdge(int src, int dest, int cost);
    int  GetNumVertices() { return num; };
    void ShortestPath(int v);
    int  Choose();                          
    void PrintAdjMatrix();                  // Print adjacency matrix
    void PrintShortestPath(int v);          // Print length of shortest path
    void PrintPath(int src, int dest);      // Print path
}; 


Digraph::Digraph() 
{
    num = 0;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        parent[i] = -1;
        valid[i] = false;                      
        found[i] = false;
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            graph[i][j] = INFINITY;
        }
    }
}


// Insert an edge from vertex src to vertex dest
void Digraph::InsertEdge(int src, int dest, int cost) 
{
    graph[src][dest] = cost;

    if (!valid[src])
    {
        valid[src] = true;
        num++;
    }

    if (!valid[dest])
    {
        valid[dest] = true;
        num++;
    }
}


// TODO: Implement a Dijikstra Algorithm
void Digraph::ShortestPath(int v)
{
    // Initialization
    int i, u, w;
    for(i = 0 ; i < num ; i++) { 
        found[i] = false;
        distance[i] = graph[v][i]; // v vertex���� �� �� �ִ� �Ÿ��� distance �迭�� �־��ش�.

        if(distance[i] != INFINITY) // ��ΰ� �����Ѵٸ� �θ�-�ڳ� ���踦 �������ش�.
            parent[i] = v;
        else
            parent[i] = -1; // ������ -1 ���� �ִ´�.
    }

    found[v] = true; // �ش� vertex�� true�� �ٲ��ش�.
    distance[v] = 0; // �ڱ� �ڽ����� ���� distance�� 0�̹Ƿ� �������ش�.

    for(i = 0 ; i < num - 2 ; i++) {
        u = Choose();   // v vertex���� �� �� �ִ� ��� �� �ִ� ��θ� ã�´�.
        found[u] = true;    // �ִ� ����� vertex u �� �̵��� �Ѵ�.

        for(w = 0 ; w < num ; w++) {
            // �ִ� ��ο��� �� �� �� �ִ� w vertex������ �Ÿ��� v���� w�� �� �� �ִ� �Ÿ� �� ª�� ���� ã�´�.
            if(!found[w] && distance[u]+graph[u][w] < distance[w]) {
                //ã�� ��� �ش� w vertex�� �θ�� v�� �ִ� ����� u�� �ȴ�.
                parent[w] = u;
                // v���� w������ �Ÿ��� (v->u) + (u->w) �Ÿ��� ������ �Ҵ����ش�.
                distance[w] = distance[u]+graph[u][w];
            }
        }
    }
    // Determine shortest paths from vertext v 
    
    PrintShortestPath(v); 
}


// TODO: Find the smallest distance not yet checked and return the corresponding vertex
int Digraph::Choose()
{   
    int i, min, minpos;
    min = INFINITY;
    minpos = -1;
    for(i = 0 ; i < num ; i++) {
        if(found[i] != true && distance[i] < min) {
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}


void Digraph::PrintAdjMatrix()
{
    cout << "   "; 
    for (int i = 0; i < num; i++)
        cout << setw(3) << right << "[" << i << "]"; 

    cout << endl;
    for (int i = 0; i < num; i++)
    {
        cout << setw(1) << left << "[" << i << "]"; 
        for (int j = 0; j < num; j++)
        {
            if (graph[i][j] < INFINITY)
                cout << setw(5) << right << graph[i][j];
            else    
                cout << setw(5) << right << -1;
        }
        cout << endl;
    }
}


void Digraph::PrintShortestPath(int v)
{
    cout << "Dest\tCost\t Path" << endl;
    for (int i = 0; i < num; i++)
    {
        if (i != v)
        {
            cout << i << "\t";

            if (distance[i] < INFINITY) 
                cout << distance[i] << "\t ";
            else if (distance[i] == INFINITY)
                cout << -1 << "\t ";

            PrintPath(v, i);
            cout << endl;
        }
    }
}

// TODO: Print Path
void Digraph::PrintPath(int src, int dest)
{
    if(parent[dest] != -1) {
        Stack *stack = new Stack();
        int i = dest;

        while(parent[i] != -1) {
            stack->Push(i);;
            i = parent[i];
        }
        stack->Push(i);

        while(!stack->IsEmpty()) {
            cout << stack->Pop() << " ";
        }
    }
    else{
        cout << "No Path";
    }
}