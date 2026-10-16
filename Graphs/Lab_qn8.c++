/*
Find all vertices that can be reached from a source vertex at distance k.

Concept: Graph traversal using BFS (Breadth-First Search).


*/

#include <iostream>
using namespace std;

#define MAX 20

int adj[MAX][MAX], visited[MAX], distance[MAX];
int queue[MAX];
int front = 0, rear = 0;
int v, e;

void readGraph()
{
    int u, w;
    cin >> v >> e;

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            adj[i][j] = 0;

    for(int i = 0; i < e; i++)
    {
        cin >> u >> w;
        adj[u][w] = 1;
        adj[w][u] = 1;
    }
}

void BFS(int source)
{
    for(int i = 0; i < v; i++)
    {
        visited[i] = 0;
        distance[i] = -1;
    }

    front = 0;
    rear = 0;

    queue[rear++] = source;
    visited[source] = 1;
    distance[source] = 0;

    while(front < rear)
    {
        int current = queue[front++];

        for(int i = 0; i < v; i++)
        {
            if(adj[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                distance[i] = distance[current] + 1;
                queue[rear++] = i;
            }
        }
    }
}

void printVertices(int k)
{
    int found = 0;

    for(int i = 0; i < v; i++)
    {
        if(distance[i] == k)
        {
            cout << i << " ";
            found = 1;
        }
    }

    if(!found)
        cout << "No vertices found";
}

int main()
{
    int source, k;

    readGraph();
    cin >> source >> k;

    BFS(source);
    printVertices(k);

    return 0;
}
