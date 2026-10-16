// Create an AVL tree by doing one insertion at a time and display the tree level by level with the level number.


#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} BST;

BST *makeNode(int data)
{
    BST *t = new BST;

    t->data = data;
    t->height = 1;
    t->left = NULL;
    t->right = NULL;

    return t;
}

int height(BST *t)
{
    if(!t)
        return 0;

    return t->height;
}

int getBalance(BST *t)
{
    if(!t)
        return 0;

    return height(t->left) - height(t->right);
}

BST *rightRotate(BST *y)
{
    BST *x = y->left;
    BST *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

BST *leftRotate(BST *x)
{
    BST *y = x->right;
    BST *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

BST *insert(BST *t, int data)
{
    if(!t)
        return makeNode(data);

    if(data < t->data)
        t->left = insert(t->left, data);
    else if(data > t->data)
        t->right = insert(t->right, data);
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

void displayLevelOrder(BST *root)
{
    if(!root)
        return;

    BST *q[MAX];

    int front = 0;
    int rear = 0;
    int level = 0;

    q[rear++] = root;

    while(front < rear)
    {
        int size = rear - front;

        cout << "Level " << level << ": ";

        for(int i = 0; i < size; i++)
        {
            BST *temp = q[front++];

            cout << temp->data << " ";

            if(temp->left)
                q[rear++] = temp->left;

            if(temp->right)
                q[rear++] = temp->right;
        }

        cout << endl;
        level++;
    }
}

int main()
{
    BST *root = NULL;

    int n, data;

    cout << "Enter number of elements: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;

        root = insert(root, data);

        cout << "\nAVL tree after insertion of "
             << data << ":\n";

        displayLevelOrder(root);

        cout << endl;
    }

    return 0;
}

/*

Sample Input
Enter number of elements: 6
Enter element 1: 10
Enter element 2: 20
Enter element 3: 30
Enter element 4: 40
Enter element 5: 50
Enter element 6: 25


Sample Output
The program displays the AVL tree after each insertion. For example, after all six insertions:
AVL tree after insertion of 25:
Level 0: 30
Level 1: 20 40
Level 2: 10 25 50


Important points
- height() returns the height of a node.
- getBalance() calculates the balance factor: height of the left subtree minus height of the right subtree.
- insert() performs ordinary BST insertion followed by AVL balancing.
- The four cases — LL, RR, LR and RL — are handled using rotations.
- displayLevelOrder() uses a queue. The variable size records the number of nodes at the current level, allowing the program to print each level separately.
- The first level is numbered 0.

*/