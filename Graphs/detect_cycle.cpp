/*
A cycle means we can start from a vertex and come back to 
that same vertex by following edges.

Detect cycle in Undirected Graph : 

Graph 1 — Cycle exists
    0
   / \
  1---2

We can travel:
0 → 1 → 2 → 0
So this graph has a cycle.

Graph 2 — No cycle
0 --- 1 --- 2
There is no way to return to 0.
So:

Cycle → 0 → 1 → 2 → 0
No cycle → 0 → 1 → 2


For every unvisited vertex:
    DFS(vertex, parent)
Inside DFS:
    Mark vertex as visited
Look at every adjacent vertex
    If adjacent vertex is not visited:
        DFS(adjacent vertex, current vertex)
    Else if adjacent vertex is NOT parent:
        Cycle found

In simple form:
if(visited[temp->vertex] == 0)
{
    DFS(temp->vertex, v);
}
else if(temp->vertex != parent)
{
    cycle found
}

Remember this condition :
visited neighbor
        +
neighbor != parent
        ↓
      CYCLE

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct node
{
    int vertex;
    struct node *next;
} NODE;

NODE *makeNode(int vertex)
{
    NODE *newNode;

    newNode = (NODE *)malloc(sizeof(NODE));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

void init(NODE *adj[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        adj[i] = NULL;
    }
}

void insertEdge(NODE *adj[], int u, int v)
{
    NODE *newNode;

    /* u -> v */
    newNode = makeNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    /* v -> u */
    newNode = makeNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void createGraph(NODE *adj[], int e)
{
    int i;
    int u, v;

    for(i = 0; i < e; i++)
    {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        insertEdge(adj, u, v);
    }
}

int DFS(NODE *adj[], int visited[], int v, int parent)
{
    NODE *temp;

    visited[v] = 1;

    temp = adj[v];

    while(temp != NULL)
    {
        if(visited[temp->vertex] == 0)
        {
            if(DFS(adj, visited, temp->vertex, v)) // temp->vertx is child of parent v
                return 1;
        }
        else if(temp->vertex != parent)
        {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

/*
SECOND return 1
       ↓
Actually discovers the cycle


FIRST return 1
       ↓
Receives that discovery from child
and passes it back to its parent

*/

int hasCycle(NODE *adj[], int visited[], int n)
{
    int i;

    for(i = 0; i < n; i++) // to check every vertex bcoz the graph might be disconnected
    {
        if(visited[i] == 0)
        {
            if(DFS(adj, visited, i, -1)) // starting vertex has no parent
                return 1; // return 1 if atleast a single cycle is found in the entire graph
        }
    }

    return 0; // return 0 is no cycle is found at the entire graph
}

int main()
{
    NODE *adj[MAX];
    int visited[MAX] = {0};
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    init(adj, n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    createGraph(adj, e);

    if(hasCycle(adj, visited, n))
        printf("Cycle exists\n");
    else
        printf("Cycle does not exist\n");

    return 0;
}

/*
Detect cycle in Directed Graph :

For directed graphs:
Already visited
        +
Still in current DFS path
        ↓
      CYCLE


if(path[temp->vertex] == 1)
{
    return 1;
}

visited[] → Have I ever visited this vertex?
path[]    → Is this vertex currently in my DFS recursion path?

The important difference from undirected cycle detection
In undirected cycle detection, we used: parent
because when we see the vertex we came from, that's just the reverse side of the same edge.
For example:
0 --- 1
At 1, seeing 0 again is normal.
In a directed graph:
0 → 1
there is no automatic reverse edge.
So we don't need the same parent logic.
Instead, we need to know:
Is this vertex already present in my current DFS path?

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct node
{
    int vertex;
    struct node *next;
} NODE;

NODE *makeNode(int vertex)
{
    NODE *newNode;

    newNode = (NODE *)malloc(sizeof(NODE));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

int hasCycle(NODE *adj[], int visited[], int pathVisited[], int vertex)
{
    NODE *temp;

    visited[vertex] = 1;
    pathVisited[vertex] = 1;

    temp = adj[vertex];

    while(temp != NULL)
    {
        if(visited[temp->vertex] == 0)
        {
            if(hasCycle(adj, visited, pathVisited, temp->vertex))
                return 1;
        }
        else if(pathVisited[temp->vertex] == 1)
        {
            return 1;
        }

        temp = temp->next;
    }

    pathVisited[vertex] = 0; // making it as 0 after completing the current DFS path.

    return 0;
}

int main()
{
    NODE *adj[MAX];

    int visited[MAX] = {0};
    int pathVisited[MAX] = {0};

    int v, e;
    int src, dest;
    int i;
    int cycle = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    for(i = 0; i < v; i++)
    {
        adj[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination):\n");

    for(i = 0; i < e; i++)
    {
        scanf("%d %d", &src, &dest);

        NODE *newNode = makeNode(dest);

        newNode->next = adj[src];
        adj[src] = newNode;
    }

    for(i = 0; i < v; i++)
    {
        if(visited[i] == 0)
        {
            if(hasCycle(adj, visited, pathVisited, i))
            {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle == 1)
        printf("Cycle exists\n");
    else
        printf("No cycle\n");

    return 0;
}