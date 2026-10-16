// Find the kth smallest number from the given Binary Search Tree (BST).


#include <iostream>
using namespace std;

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

BT *insert(BT *t, int data)
{
    if(t == NULL)
        return makeNode(data);

    if(data < t->data)
        t->left = insert(t->left, data);
    else if(data > t->data)
        t->right = insert(t->right, data);

    return t;
}

void inOrder(BT *t, int k, int *count, int *result)
{
    if(t == NULL || *count >= k)
        return;

    inOrder(t->left, k, count, result);

    if(*count < k)
    {
        (*count)++;

        if(*count == k)
            *result = t->data;
    }

    inOrder(t->right, k, count, result);
}

int main()
{
    BT *root = NULL;
    int n, data, k;
    int count = 0;
    int result = 0;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";

    for(int i = 0; i < n; i++)
    {
        cin >> data;
        root = insert(root, data);
    }

    cout << "Enter k: ";
    cin >> k;

    if(k <= 0 || k > n)
    {
        cout << "Invalid k";
        return 0;
    }

    inOrder(root, k, &count, &result);

    cout << "Kth smallest element = " << result;

    return 0;
}


/*

Sample Input
Enter number of nodes: 7
Enter BST elements: 50 30 70 20 40 60 80
Enter k: 3


Output
Kth smallest element = 40


Important logic
In a BST, inorder traversal visits the elements in ascending order.
For the given tree:
        50
       /  \
     30    70
    / \    / \
   20 40  60 80


Inorder traversal produces:
20 30 40 50 60 70 80


Therefore, the 3rd smallest element is 40.
- count tracks how many nodes have been visited.
- answer stores the kth smallest element.
- count >= k stops unnecessary traversal once the answer is found.
Time complexity: \(O(n)\) in the worst case.

*/