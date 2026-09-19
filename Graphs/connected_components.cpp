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

    newNode = makeNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = makeNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void createGraph(NODE *adj[], int n, int e)
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

void DFS(NODE *adj[], int visited[], int v)
{
    NODE *temp;

    printf("%d ", v);
    visited[v] = 1;

    temp = adj[v];

    while(temp != NULL)
    {
        if(visited[temp->vertex] == 0)
        {
            DFS(adj, visited, temp->vertex);
        }

        temp = temp->next;
    }
}

int connectedComponents(NODE *adj[], int visited[], int n)
{
    int i;
    int count = 0;

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            count++;

            printf("Component %d: ", count);

            DFS(adj, visited, i);

            printf("\n");
        }
    }

    return count;
}

int main()
{
    NODE *adj[MAX];
    int visited[MAX] = {0};
    int n, e, count;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    init(adj, n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    createGraph(adj, n, e);

    count = connectedComponents(adj, visited, n);

    printf("Number of connected components = %d\n", count);

    return 0;
}

/*
Example input
Enter number of vertices: 6
Enter number of edges: 4

Enter edge 1: 0 1
Enter edge 2: 1 2
Enter edge 3: 3 4
Enter edge 4: 0 2


The graph is:
    0
   / \
  1---2

  3---4

  5

  
Output
Component 1: 0 2 1
Component 2: 3 4
Component 3: 5

Number of connected components = 3

*/