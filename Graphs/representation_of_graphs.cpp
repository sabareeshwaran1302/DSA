/*

Graph can be represented in 2 ways :
1.Adjacency Matrix
2.Adjacency List



1.Adjacency Matrix:
A 2D array of size V x V where V is the number of vertices in the graph. 
The value at index (i, j) represents the weight of the edge between vertex i and vertex j.
If there is no edge between the vertices, the value is typically 0 or infinity.


*/

/*
UNDIRECTED GRAPH WITHOUT WEIGHTS
*/
#include <iostream>
using namespace std;

#define MAX 100

void addEdge(int graph[][MAX], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void displayMatrix(int graph[][MAX], int vertices)
{
    cout << "\nAdjacency Matrix:\n\n";

    for(int i = 0; i < vertices; i++) // we are using an array of size vertices x vertices to represent the graph.
    {
        for(int j = 0; j < vertices; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }
}

void displayGraph(int graph[][MAX], int vertices)
{
    cout << "\nGraph Representation:\n\n";

    for(int i = 0; i < vertices; i++)
    {
        cout << i << " -> ";

        for(int j = 0; j < vertices; j++)
        {
            if(graph[i][j] == 1)
            {
                cout << j << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    int graph[MAX][MAX] = {0}; // Initialise the adjacency matrix with 0s

    int vertices;
    int edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    for(int i = 0; i < edges; i++)
    {
        int u, v;

        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v; // u and v are the vertices connected by the edge i.

        addEdge(graph, u, v);
    }

    displayMatrix(graph, vertices); // display the adjacency matrix

    displayGraph(graph, vertices); // display the graph representation

    return 0;
}

/*
Enter number of vertices: 5
Enter number of edges: 5
Enter edge 1: 0 1
Enter edge 2: 0 2
Enter edge 3: 1 2
Enter edge 4: 1 3
Enter edge 5: 3 4


       0
      / \
     1---2
     |
     3
     |
     4

Adjacency Matrix:

0 1 1 0 0
1 0 1 1 0
1 1 0 0 0
0 1 0 0 1
0 0 0 1 0

Graph Representation:

0 -> 1 2        // 0 is connected to 1 and 2
1 -> 0 2 3      // 1 is connected to 0, 2 and 3
2 -> 0 1        // 2 is connected to 0 and 1
3 -> 1 4        // 3 is connected to 1 and 4
4 -> 3          // 4 is connected to 3


*/



/*
DIRECTED GRAPH WITHOUT WEIGHTS

*/
#include <iostream>
using namespace std;

#define MAX 100

void addEdge(int graph[][MAX], int u, int v)
{
    graph[u][v] = 1; //     graph[v][u] does not need exist because it is a directed graph, so we only need to add the edge from u to v.
}

void displayMatrix(int graph[][MAX], int vertices)
{
    cout << "\nAdjacency Matrix:\n\n";

    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }
}

void displayGraph(int graph[][MAX], int vertices)
{
    cout << "\nGraph Representation:\n\n";

    for(int i = 0; i < vertices; i++)
    {
        cout << i << " -> ";

        for(int j = 0; j < vertices; j++)
        {
            if(graph[i][j] == 1)
            {
                cout << j << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    int graph[MAX][MAX] = {0};

    int vertices;
    int edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    for(int i = 0; i < edges; i++)
    {
        int u, v;

        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v;

        addEdge(graph, u, v);
    }

    displayMatrix(graph, vertices);
    displayGraph(graph, vertices);

    return 0;
}


/*

WEIGHTED UNDIRECTED GRAPH :
In an unweighted graph, we store 1 to indicate an edge.
In a weighted graph, we store the weight of the edge.

*/
void addEdge(int graph[][MAX], int u, int v, int weight)
{
    graph[u][v] = weight; // Instead of storing 1, we store the weight of the edge between vertex u and vertex v.
    graph[v][u] = weight;
}

/*
WEIGHTED DIRECTED GRAPH :
In a directed graph, we only store the weight of the edge from vertex u to vertex v
*/

void addEdge(int graph[][MAX], int u, int v, int weight)
{
    graph[u][v] = weight;
}


/*
2. Adjacency List:
An array of lists is used. The size of the array is equal to the number of vertices


UNDIRECTED GRAPH WITHOUT WEIGHTS

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

int main()
{
    NODE *adj[MAX];
    NODE *newNode;
    NODE *temp;

    int n, e;
    int i, j;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    /* Initialize adjacency list */

    for(i = 1; i <= n; i++)
    {
        adj[i] = NULL;
    }

    /* Read edges */

    for(i = 1; i <= e; i++)
    {
        printf("Enter edge %d: ", i);
        scanf("%d %d", &u, &v);

        /* u -> v */

        newNode = makeNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        /* v -> u */

        newNode = makeNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;

    }

    /* Display adjacency list */

    printf("\nAdjacency List:\n");

    for(i = 1; i <= n; i++)
    {
        printf("V%d -> ", i);

        temp = adj[i];

        while(temp != NULL)
        {
            printf("V%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }

    return 0;
}

/* 
Input :
Enter number of vertices: 5
Enter number of edges: 5

Enter edge 1: 1 2
Enter edge 2: 1 3
Enter edge 3: 2 4
Enter edge 4: 3 4
Enter edge 5: 4 5

Output :
Adjacency List:

V1 -> V3 -> V2 -> NULL

V2 -> V4 -> V1 -> NULL

V3 -> V4 -> V1 -> NULL

V4 -> V5 -> V3 -> V2 -> NULL

V5 -> V4 -> NULL




V1 connected to V3 and V2
V2 connected to V4 and V1
V3 connected to V4 and V1
V4 connected to V5, V3 and V2
V5 connected to V4



             V2
            /  \
           /    \
         V1      V4 -------- V5
           \    /
            \  /
             V3

*/

/*

DIRECTED GRAPH WITHOUT WEIGHTS

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

int main()
{
    NODE *adj[MAX];
    NODE *newNode;
    NODE *temp;

    int n, e;
    int i;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    /* Initialize adjacency list */

    for(i = 1; i <= n; i++)
    {
        adj[i] = NULL;
    }

    /* Read edges */

    for(i = 1; i <= e; i++)
    {
        printf("Enter edge %d: ", i);
        scanf("%d %d", &u, &v);

        /* u -> v */

        newNode = makeNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    /* Display adjacency list */

    printf("\nAdjacency List:\n");

    for(i = 1; i <= n; i++)
    {
        printf("V%d -> ", i);

        temp = adj[i];

        while(temp != NULL)
        {
            printf("V%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }

    return 0;
}


/*

UNDIRECTED WEIGHTED GRAPH

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct node
{
    int vertex;
    int weight; // STORING THE WEIGHT OF THE EDGE
    struct node *next;
} NODE;

NODE *makeNode(int vertex, int weight)
{
    NODE *newNode;

    newNode = (NODE *)malloc(sizeof(NODE));

    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
}

int main()
{
    NODE *adj[MAX];
    NODE *newNode;
    NODE *temp;

    int n, e;
    int i;
    int u, v, weight;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    /* Initialize adjacency list */

    for(i = 1; i <= n; i++)
    {
        adj[i] = NULL;
    }

    /* Read edges */

    for(i = 1; i <= e; i++)
    {
        printf("Enter edge %d: ", i);
        scanf("%d %d %d", &u, &v, &weight);

        /* u -> v */

        newNode = makeNode(v, weight);
        newNode->next = adj[u];
        adj[u] = newNode;

        /* v -> u */

        newNode = makeNode(u, weight);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    /* Display adjacency list */

    printf("\nWeighted Adjacency List:\n");

    for(i = 1; i <= n; i++)
    {
        printf("V%d -> ", i);

        temp = adj[i];

        while(temp != NULL)
        {
            printf("V%d(%d) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }

        printf("NULL\n");
    }

    return 0;
}

/*

Weighted Adjacency List:

V1 → V3(20) → V2(10) → NULL
V2 → V4(5) → V1(10) → NULL
V3 → V4(15) → V1(20) → NULL
V4 → V2(5) → V3(15) → NULL

*/