/*


Generate an array of 4000 random integers using rand() % 1000. Store these elements in a sorted array, linked list, Binary Search Tree (BST), and AVL tree. 
Perform 50,000 searches for random integers and calculate the average number of comparisons for unsuccessful searches in each data structure.

*/



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

#define N 4000
#define SEARCH 50000

/* Linked List */

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *makeListNode(int data)
{
    NODE *t = new NODE;

    t->data = data;
    t->next = NULL;

    return t;
}

NODE *insertHead(NODE *l, int data)
{
    NODE *t = makeListNode(data);

    t->next = l;
    l = t;

    return l;
}

/* BST and AVL Tree */

typedef struct tree
{
    int data;
    int height;
    struct tree *left;
    struct tree *right;
} TREE;

TREE *makeNode(int data)
{
    TREE *t = new TREE;

    t->data = data;
    t->height = 1;
    t->left = NULL;
    t->right = NULL;

    return t;
}

int height(TREE *t)
{
    if(!t)
        return 0;

    return t->height;
}

int getBalance(TREE *t)
{
    if(!t)
        return 0;

    return height(t->left) - height(t->right);
}

TREE *rightRotate(TREE *y)
{
    TREE *x = y->left;
    TREE *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

TREE *leftRotate(TREE *x)
{
    TREE *y = x->right;
    TREE *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

/* BST Insertion */

TREE *insertBST(TREE *t, int data)
{
    if(!t)
        return makeNode(data);

    if(data < t->data)
        t->left = insertBST(t->left, data);

    else if(data > t->data)
        t->right = insertBST(t->right, data);

    return t;
}

/* AVL Insertion */

TREE *insertAVL(TREE *t, int data)
{
    if(!t)
        return makeNode(data);

    if(data < t->data)
        t->left = insertAVL(t->left, data);

    else if(data > t->data)
        t->right = insertAVL(t->right, data);

    else
        return t;

    t->height = 1 + max(height(t->left), height(t->right));

    int balance = getBalance(t);

    /* LL Case */
    if(balance > 1 && data < t->left->data)
        return rightRotate(t);

    /* RR Case */
    if(balance < -1 && data > t->right->data)
        return leftRotate(t);

    /* LR Case */
    if(balance > 1 && data > t->left->data)
    {
        t->left = leftRotate(t->left);
        return rightRotate(t);
    }

    /* RL Case */
    if(balance < -1 && data < t->right->data)
    {
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }

    return t;
}

/* Search in Sorted Array */

int searchArray(int arr[], int key, int *found)
{
    int low = 0;
    int high = N - 1;
    int mid;
    int comparisons = 0;

    *found = 0;

    while(low <= high)
    {
        mid = low + (high - low) / 2;
        comparisons++;

        if(arr[mid] == key)
        {
            *found = 1;
            return comparisons;
        }

        if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return comparisons;
}

/* Search in Linked List */

int searchList(NODE *l, int key, int *found)
{
    int comparisons = 0;

    *found = 0;

    while(l != NULL)
    {
        comparisons++;

        if(l->data == key)
        {
            *found = 1;
            return comparisons;
        }

        l = l->next;
    }

    return comparisons;
}

/* Search in BST */

int searchBST(TREE *t, int key, int *found)
{
    int comparisons = 0;

    *found = 0;

    while(t != NULL)
    {
        comparisons++;

        if(key == t->data)
        {
            *found = 1;
            return comparisons;
        }

        if(key < t->data)
            t = t->left;
        else
            t = t->right;
    }

    return comparisons;
}

/* Search in AVL */

int searchAVL(TREE *t, int key, int *found)
{
    int comparisons = 0;

    *found = 0;

    while(t != NULL)
    {
        comparisons++;

        if(key == t->data)
        {
            *found = 1;
            return comparisons;
        }

        if(key < t->data)
            t = t->left;
        else
            t = t->right;
    }

    return comparisons;
}

int main()
{
    int arr[N];
    int key;
    int found;

    int unsuccessful = 0;

    long long totalArray = 0;
    long long totalList = 0;
    long long totalBST = 0;
    long long totalAVL = 0;

    NODE *list = NULL;

    TREE *bst = NULL;
    TREE *avl = NULL;

    srand(time(NULL));

    /* Generate data and build all structures */

    for(int i = 0; i < N; i++)
    {
        arr[i] = rand() % 1000;

        list = insertHead(list, arr[i]);

        bst = insertBST(bst, arr[i]);
        avl = insertAVL(avl, arr[i]);
    }

    /* Sort the array */

    sort(arr, arr + N);

    /* Perform random searches */

    for(int i = 0; i < SEARCH; i++)
    {
        key = rand() % 2000;

        int cArray = searchArray(arr, key, &found);

        if(found)
            continue;

        int cList = searchList(list, key, &found);

        int cBST = searchBST(bst, key, &found);

        int cAVL = searchAVL(avl, key, &found);

        totalArray += cArray;
        totalList += cList;
        totalBST += cBST;
        totalAVL += cAVL;

        unsuccessful++;
    }

    /* Display results */

    cout << "Total elements: " << N << endl;
    cout << "Total search attempts: " << SEARCH << endl;
    cout << "Unsuccessful searches: " << unsuccessful << endl;

    if(unsuccessful > 0)
    {
        cout << "\nAverage comparisons for unsuccessful searches\n";

        cout << "Sorted Array : "
             << (double)totalArray / unsuccessful << endl;

        cout << "Linked List  : "
             << (double)totalList / unsuccessful << endl;

        cout << "BST          : "
             << (double)totalBST / unsuccessful << endl;

        cout << "AVL Tree     : "
             << (double)totalAVL / unsuccessful << endl;
    }

    return 0;
}
