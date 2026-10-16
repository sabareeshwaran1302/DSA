/*

Prim’s Algorithm
Question: Implement Prim’s algorithm to find the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph.

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

Example input
4 5
0 1 10
0 2 4
1 3 3
2 3 7
0 3 2


Output:
0 - 3 : 2
3 - 1 : 3
0 - 2 : 4
Minimum cost = 9


Understand these three things
1. visited[0] = 1; — Start the MST from vertex 0.
2. cost[i][j] < min — Find the cheapest edge connecting a visited vertex to an unvisited vertex.
3. visited[b] = 1; — Include the newly reached vertex in the MST.
Why 9999? It is a large placeholder representing an edge that does not exist. Any actual edge with a smaller weight can replace it during the search.

*/