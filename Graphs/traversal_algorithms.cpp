/*
There are two ways to traverse a graph:
1. Breadth First Search (BFS)
2. Depth First Search (DFS)





1.Breadth First Search (BFS):
In BFS, we start from a source vertex and explore all its neighbors before moving to the next level neighbors.
It uses a queue data structure to keep track of the vertices to be explored.
It is similar to level order traversal of a tree.

1. Initialize queue
2. Insert starting vertex
3. Mark starting vertex visited
4. Repeat:
      Pop vertex
      Visit its neighbours
      Insert unvisited neighbours
5. Stop when queue is empty

*/

#include <iostream>
using namespace std;

#define MAX 20


/* QUEUE IMPLEMENTATION */

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
} Q;


void init(Q *q)
{
    q->front = 0;
    q->rear = 0;
}


int isempty(Q q)
{
    return q.front == q.rear;
}


int isfull(Q q)
{
    return q.rear == MAX;
}


void insert(Q *q, int data)
{
    if(isfull(*q))
    {
        cout << "Queue is Full" << endl;
        return;
    }

    q->arr[q->rear] = data;
    q->rear++;
}


void pop(Q *q, int *val)
{
    if(isempty(*q))
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    *val = q->arr[q->front];
    q->front++;
}


void peek(Q *q, int *val)
{
    if(isempty(*q))
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    *val = q->arr[q->front];
}


/* GRAPH NODE */

typedef struct node
{
    int vertex;
    struct node *next;
} NODE;


NODE *makeNode(int vertex)
{
    NODE *newNode;

    newNode = new NODE;

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

void display(Q q)
{
    int i;

    cout << "Queue: ";

    for(i = q.front; i < q.rear; i++)
    {
        cout << q.arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    NODE *adj[MAX];
    NODE *newNode;
    NODE *temp;

    int visited[MAX];

    int n, e;
    int i;
    int u, v;
    int start;
    int val;

    Q q;


    /* GET GRAPH DETAILS */

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;


    /* INITIALIZE */

    for(i = 0; i < n; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }


    /* CREATE GRAPH */

    for(i = 1; i <= e; i++)
    {
        cout << "Enter edge " << i << ": ";
        cin >> u >> v;


        /* u -> v */

        newNode = makeNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;


        /* v -> u */

        newNode = makeNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }


    /* DISPLAY ADJACENCY LIST */

    cout << "\nAdjacency List:\n";

    for(i = 0; i < n; i++)
    {
        cout << "V" << i << " -> ";

        temp = adj[i];

        while(temp != NULL)
        {
            cout << "V" << temp->vertex << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }


    /* GET STARTING VERTEX */

    cout << "\nEnter starting vertex: ";
    cin >> start;


    /* BFS */

    init(&q);

    insert(&q, start);

    visited[start] = 1;


    cout << "\nBFS Traversal: ";


    while(!isempty(q))
    {
        pop(&q, &val);

        cout << "V" << val << " ";


        temp = adj[val];

        while(temp != NULL)
        {
            if(visited[temp->vertex] == 0)
            {
                visited[temp->vertex] = 1;

                insert(&q, temp->vertex);
            }

            temp = temp->next;
        }
    }
    display(q);


    return 0;
}


/*
2.Depth First Search (DFS):
In DFS, we start from a source vertex and explore as far as possible along each branch before backtracking.
It uses recursion.

DFS = Depth First Search
DFS visits a graph by going as deep as possible first, then coming back and taking the next path.
Think:
BFS → go level by level
DFS → go deep, then come back


1. Start at a vertex
2. Mark it visited
3. Print it
4. Go to an unvisited neighbour
5. Repeat
6. When no unvisited neighbour exists, return back

*/
#include <iostream>
using namespace std;

#define MAX 20


typedef struct node
{
    int vertex;
    struct node *next;
} NODE;


NODE *makeNode(int vertex)
{
    NODE *newNode;

    newNode = new NODE;

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}


void DFS(NODE *adj[], int visited[], int vertex)
{
    NODE *temp;

    visited[vertex] = 1;

    cout << "V" << vertex << " ";

    temp = adj[vertex];

    while(temp != NULL)
    {
        if(visited[temp->vertex] == 0)
        {
            DFS(adj, visited, temp->vertex); // it immediately goes into that neighbour's adjacency list.
        }

        temp = temp->next;
    }
}


int main()
{
    NODE *adj[MAX];
    NODE *newNode;
    NODE *temp;

    int visited[MAX];

    int n, e;
    int i;
    int u, v;
    int start;


    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;


    /* Initialize */

    for(i = 0; i < n; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }


    /* Create graph */

    for(i = 1; i <= e; i++)
    {
        cout << "Enter edge " << i << ": ";
        cin >> u >> v;


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

    cout << "\nAdjacency List:\n";

    for(i = 0; i < n; i++)
    {
        cout << "V" << i << " -> ";

        temp = adj[i];

        while(temp != NULL)
        {
            cout << "V" << temp->vertex << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }


    /* Starting vertex */

    cout << "\nEnter starting vertex: ";
    cin >> start;


    /* DFS */

    cout << "\nDFS Traversal: ";

    DFS(adj, visited, start);


    return 0;
}

/*

              V0
             /  \
           V1    V2
          /  \     \
        V3   V4     V5
             |
            V6


BFS Traversal: V0 V2 V1 V5 V4 V3 V6
DFS Traversal: V0 V2 V5 V1 V4 V6 V3

*/
