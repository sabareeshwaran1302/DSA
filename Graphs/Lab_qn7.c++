/*

What is a spanning tree?
Suppose we want to connect all four cities using roads.
A spanning tree must satisfy two conditions:
1. Every vertex must be connected to the network.
2. There must be no cycles (closed loops).
For four vertices, a spanning tree has exactly \(V-1=4-1=3\) edges.
Example: A spanning tree
All four vertices are connected using three edges, without a cycle.

This is a spanning tree because every city is connected and no loop exists.
But is it the cheapest spanning tree? Not necessarily.



4. What is a Minimum Spanning Tree (MST)?
MST = Minimum Spanning Tree.
It is the spanning tree that connects all vertices with the smallest possible total edge weight.
Let's use the same graph.

We have these edge weights:
Edge	Weight
A–B	    10
A–C	    4
B–D	    3
C–D	    7
A–D	    2
One possible selection is A–B, A–C and B–D.


This connects all four vertices with three edges, without a cycle, and with a lower total cost.
The minimum spanning tree
Minimum total cost = 9
Edges selected: A–D (2), B–D (3), and A–C (4).

The MST problem is:
Connect every vertex, avoid cycles, and make the total edge weight as small as possible.

There may be more than one MST if some edge weights are equal.

5. Why do we need Prim’s and Kruskal’s algorithms?
Both algorithms solve the same MST problem. They just choose the edges in different ways.

Prim’s algorithm
Start with one vertex. Look at the edges leaving the vertices already in the tree. 
Choose the cheapest edge that connects to a new vertex. Repeat until all vertices are included.

Kruskal’s algorithm
Sort all edges from smallest weight to largest. Consider them in that order. Add an edge if it does not create a cycle. Stop after selecting \(V-1\) edges.



How does Prim's algorithm work?
Remember these three rules:
1. Start from any vertex. Here, we start from vertex 0.
2. Look at the edges connecting visited vertices to unvisited vertices.
3. Choose the cheapest such edge and visit its new vertex. Repeat until all vertices are visited.


*/

#include <iostream>
using namespace std;

#define MAX 20

int cost[MAX][MAX], visited[MAX];
int v, e;

void readGraph()
{
    int u, w, wt;

    cin >> v >> e;

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            cost[i][j] = 9999;

    for(int i = 0; i < e; i++)
    {
        cin >> u >> w >> wt;
        cost[u][w] = wt;
        cost[w][u] = wt;
    }
}

void prim()
{
    int minCost = 0;

    for(int i = 0; i < v; i++)
        visited[i] = 0;

    visited[0] = 1;

    for(int count = 0; count < v-1; count++)
    {
        int min = 9999, a = -1, b = -1;

        for(int i = 0; i < v; i++)
        {
            if(visited[i] == 1)
            {
                for(int j = 0; j < v; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if(a == -1)
        {
            cout << "MST not possible";
            return;
        }

        cout << a << " - " << b << " : " << min << endl;
        visited[b] = 1;
        minCost += min;
    }

    cout << "Minimum cost = " << minCost;
}


int main()
{
    readGraph();
    prim();
    return 0;
}




/*
Kruskal's Algorithm :
1. What is the difference between Prim's and Kruskal's?
- Prim's: Starts from a vertex and grows one connected MST by selecting the cheapest eligible edge.
- Kruskal's: Sorts all edges by weight and selects the cheapest edge that does not create a cycle.



*/


#include <iostream>
using namespace std;

#define MAX 20

int u[MAX], w[MAX], wt[MAX], parent[MAX];
int v, e;

void readGraph()
{
    cin >> v >> e;

    for(int i = 0; i < e; i++)
        cin >> u[i] >> w[i] >> wt[i];
}

void sortEdges()
{
    for(int i = 0; i < e-1; i++)
    {
        for(int j = 0; j < e-i-1; j++)
        {
            if(wt[j] > wt[j+1])
            {
                swap(wt[j], wt[j+1]);
                swap(u[j], u[j+1]);
                swap(w[j], w[j+1]);
            }
        }
    }
}


int findParent(int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}


void kruskal()
{
    int minCost = 0, count = 0;

    for(int i = 0; i < v; i++)
        parent[i] = i;

    sortEdges();

    for(int i = 0; i < e; i++)
    {
        int a = findParent(u[i]);
        int b = findParent(w[i]);

        if(a != b)
        {
            cout << u[i] << " - " << w[i]
                 << " : " << wt[i] << endl;

            parent[a] = b;
            minCost += wt[i];
            count++;

            if(count == v-1)
                break;
        }
    }

    if(count == v-1)
        cout << "Minimum cost = " << minCost;
    else
        cout << "MST not possible";
}

int main()
{
    readGraph();
    kruskal();
    return 0;
}
