/* Find whether the given binary tree is a min-heap or not.
A Min-Heap is a binary tree that satisfies two conditions:
1. Complete Binary Tree: Every level is completely filled except possibly the last level, 
    and the last level is filled from left to right.
2. Min-Heap Property: Every parent node must be less than or equal to its children.

2. Approach
We need to check both properties.
- Completeness: Use a queue to traverse the tree level by level. Once a missing child position is encountered, no later child position should contain a node.
- Min-heap property: For every node, check that its left and right children, if present, are not smaller than the parent


Initially, no missing child position has been found.
Suppose we encounter a node whose left child is NULL. We set:
missing = 1;


From that point onward, no child node may appear in any later position. If we find another non-NULL child, the tree is not complete, so we return 0.

If the parent is greater than its child, the min-heap property is violated.



*/


#include <iostream>
using namespace std;

#define MAX 100

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} BT;

BT *makeNode(int data)
{
    BT *t = new BT;

    t->data = data;
    t->left = NULL;
    t->right = NULL;

    return t;
}

typedef struct
{
    BT *arr[MAX];
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

void insert(Q *q, BT *t)
{
    if(q->rear < MAX)
        q->arr[q->rear++] = t;
}

BT *pop(Q *q)
{
    if(isempty(*q))
        return NULL;

    return q->arr[q->front++];
}

int isMinHeap(BT *root)
{
    if(root == NULL)
        return 1;

    Q q;
    init(&q);

    insert(&q, root);

    int missing = 0;

    while(!isempty(q))
    {
        BT *temp = pop(&q);

        // Check left child
        if(temp->left != NULL)
        {
            if(missing == 1)
                return 0;

            if(temp->data > temp->left->data)
                return 0;

            insert(&q, temp->left);
        }
        else
            missing = 1;

        // Check right child
        if(temp->right != NULL)
        {
            if(missing == 1)
                return 0;

            if(temp->data > temp->right->data)
                return 0;

            insert(&q, temp->right);
        }
        else
            missing = 1;
    }

    return 1;
}

int main()
{
    BT *root = makeNode(10);

    root->left = makeNode(20);
    root->right = makeNode(30);

    root->left->left = makeNode(40);
    root->left->right = makeNode(50);

    root->right->left = makeNode(60);
    root->right->right = makeNode(70);

    if(isMinHeap(root))
        cout << "The binary tree is a Min-Heap";
    else
        cout << "The binary tree is not a Min-Heap";

    return 0;
}
