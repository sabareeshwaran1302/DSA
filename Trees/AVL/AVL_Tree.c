/*
AVL TREE IMPLEMENTATIONS : 

Same as BST.
The only major addition is AVL balancing: 
    height, getBalance, rightRotate, leftRotate.


What changed from your BST?

Your BST node was:
    typedef struct node
    {
        int data;
        struct node *left;
        struct node *right;
    } BT;

AVL needs one extra field:
    int height;

So:
typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} BT;

And these are the new AVL functions:
    height()
        ↓
    getBalance()
        ↓
    rightRotate()
        ↓
    leftRotate()

Then your existing insert() and deleteNode() get the balancing logic.

One important difference in height()
In your BST, you calculate height recursively:
    int height(BT *t)
    {
        if(!t)
            return 0;

        int l=height(t->left);
        int r=height(t->right);

        if(l>r)
            return l+1;

        return r+1;
    }

In AVL, each node stores its height, so:
    int height(BT *t)
    {
        if(!t)
            return 0;

        return t->height;
    }

That is intentional. Otherwise, repeatedly calculating the entire subtree height would make AVL operations unnecessarily expensive.
Also, I used max() in the height updates, so if your compiler complains about it, add:
    #include <algorithm>

or simply use the same if(l>r) style you already use.

*/


#include <iostream>
using namespace std;

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


void inOrder(BST *t)
{
    if(t)
    {
        inOrder(t->left);
        cout << t->data << " ";
        inOrder(t->right);
    }
}


void preOrder(BST *t)
{
    if(t)
    {
        cout << t->data << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}


void postOrder(BST *t)
{
    if(t)
    {
        postOrder(t->left);
        postOrder(t->right);
        cout << t->data << " ";
    }
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


/*
        t
       /
    temp

After right rotation:

      temp
        \
         t
*/

BST *rightRotate(BST *t)
{
    BST *temp = t->left;
    BST *temp2 = temp->right;

    temp->right = t;
    t->left = temp2;

    t->height = 1 + max(height(t->left), height(t->right));

    // Update the lower node first, then the new root.
    temp->height = 1 + max(height(temp->left), height(temp->right));

    // After rotation, temp becomes the root.
    return temp;
}


/*
        t
         \
         temp

After left rotation:

        temp
        /
       t
*/

BST *leftRotate(BST *t)
{
    BST *temp = t->right;
    BST *temp2 = temp->left;

    temp->left = t;
    t->right = temp2;

    t->height = 1 + max(height(t->left), height(t->right));

    temp->height = 1 + max(height(temp->left), height(temp->right));

    return temp;
}


BST *insert(BST *t, int data)
{
    if(!t)
        return makeNode(data);

    if(t->data > data)
    {
        t->left = insert(t->left, data);
    }
    else if(t->data < data)
    {
        t->right = insert(t->right, data);
    }
    else
    {
        return t;
    }


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


int search(BST *t, int data)
{
    if(!t)
        return 0;

    if(t->data == data)
        return 1;

    if(t->data > data)
        return search(t->left, data);

    return search(t->right, data);
}


int count(BST *t)
{
    if(!t)
        return 0;

    return 1 + count(t->left) + count(t->right);
}


int countLeaf(BST *t)
{
    if(!t)
        return 0;

    if(!t->left && !t->right)
        return 1;

    return countLeaf(t->left) + countLeaf(t->right);
}


int minimum(BST *t)
{
    if(!t)
        return -9999;

    while(t->left)
        t = t->left;

    return t->data;
}


int maximum(BST *t)
{
    if(!t)
        return -9999;

    while(t->right)
        t = t->right;

    return t->data;
}


BST *findMin(BST *t)
{
    while(t->left)
        t = t->left;

    return t;
}


BST *deleteNode(BST *t, int data)
{
    if(!t)
        return NULL;


    if(data < t->data)
    {
        t->left = deleteNode(t->left, data);
    }
    else if(data > t->data)
    {
        t->right = deleteNode(t->right, data);
    }
    else
    {
        /* No child */

        if(!t->left && !t->right)
        {
            delete t;

            return NULL;
        }


        /* Only right child */

        if(!t->left)
        {
            BST *temp = t->right;

            delete t;

            return temp;
        }


        /* Only left child */

        if(!t->right)
        {
            BST *temp = t->left;

            delete t;

            return temp;
        }


        /* Two children */

        BST *temp = findMin(t->right);

        t->data = temp->data;

        t->right = deleteNode(t->right, temp->data);
    }


    t->height = 1 + max(height(t->left), height(t->right));

    int balance = getBalance(t);


    /* LL Case */

    if(balance > 1 && getBalance(t->left) >= 0)
        return rightRotate(t);


    /* LR Case */

    if(balance > 1 && getBalance(t->left) < 0)
    {
        t->left = leftRotate(t->left);

        return rightRotate(t);
    }


    /* RR Case */

    if(balance < -1 && getBalance(t->right) <= 0)
        return leftRotate(t);


    /* RL Case */

    if(balance < -1 && getBalance(t->right) > 0)
    {
        t->right = rightRotate(t->right);

        return leftRotate(t);
    }


    return t;
}


int main()
{
    BST *t = NULL;

    int n, data;


    cout << "Enter Number of Elements : ";
    cin >> n;


    for(int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " Element : ";
        cin >> data;

        t = insert(t, data);
    }


    cout << "\nInorder : ";
    inOrder(t);


    cout << "\nPreorder : ";
    preOrder(t);


    cout << "\nPostorder : ";
    postOrder(t);


    cout << "\n\nNumber of Nodes : " << count(t);


    cout << "\nNumber of Leaf Nodes : " << countLeaf(t);


    cout << "\nHeight : " << height(t);


    cout << "\nMinimum : " << minimum(t);


    cout << "\nMaximum : " << maximum(t);


    cout << "\n\nEnter Element to Search : ";
    cin >> data;


    if(search(t, data))
        cout << "Element Found";
    else
        cout << "Element Not Found";


    cout << "\n\nEnter Element to Delete : ";
    cin >> data;


    if(search(t, data))
    {
        t = deleteNode(t, data);

        cout << "Inorder after Deletion : ";
        inOrder(t);

        cout << "\nPreorder after Deletion : ";
        preOrder(t);
    }
    else
    {
        cout << "Element Not Found";
    }


    return 0;
}

/*
Insertion Logic : 
if(balance>1 && data<t->left->data)
    return rightRotate(t);

if(balance<-1 && data>t->right->data)
    return leftRotate(t);

if(balance>1 && data>t->left->data)
{
    t->left=leftRotate(t->left);
    return rightRotate(t);
}

if(balance<-1 && data<t->right->data)
{
    t->right=rightRotate(t->right);
    return leftRotate(t);
}

Let's decode each condition using a complex insertion example.
First: What are we checking?
After normal BST insertion, we do:
int balance=getBalance(t);

Remember:
balance = height(left) - height(right)

So:
balance > 1   → left side is too heavy
balance < -1  → right side is too heavy

But that alone isn't enough.
We also need to know:
Which side of the heavy subtree did the new node enter?

That's what data<t->left->data, etc. tells us.
CASE 1 — LL
Condition:
if(balance>1 && data<t->left->data)
    return rightRotate(t);

Break it into TWO questions.
Question 1
balance > 1

Means:
t's LEFT side is heavy

Question 2
data < t->left->data

Means:
the newly inserted value went to
the LEFT of t's LEFT child

So:
       t
      /
   left
   /
 new

That's:
LEFT → LEFT

Therefore:
LL

And LL requires:
RIGHT ROTATION

Example
Insert:
50, 30, 20

After insertion:
       50
      /
    30
   /
 20

At this point:
t = 50

Calculate:
balance = 2

So:
balance > 1

is TRUE.
Now:
data < t->left->data

means:
20 < 30

TRUE.
Therefore:
rightRotate(50)

Result:
      30
     /  \
   20    50

CASE 2 — RR
Condition:
if(balance<-1 && data>t->right->data)
    return leftRotate(t);

Again, two questions.
Question 1
balance < -1

Means:
t's RIGHT side is heavy

Question 2
data > t->right->data

Means:
new value went to the RIGHT
of t's RIGHT child

So:
       t
        \
        right
           \
           new

That's:
RIGHT → RIGHT

Therefore:
RR

And RR requires:
LEFT ROTATION

Example
Insert:
50, 70, 80

Tree:
50
  \
   70
     \
      80

At 50:
balance = -2

Therefore:
balance < -1

TRUE.
And:
80 > 70

TRUE.
So:
leftRotate(50)

Result:
      70
     /  \
   50    80

CASE 3 — LR
This one confuses almost everyone.
Condition:
if(balance>1 && data>t->left->data)
{
    t->left=leftRotate(t->left);
    return rightRotate(t);
}

Again:
First condition
balance > 1

means:
LEFT side is heavy

Second condition
data > t->left->data

means:
new value went to RIGHT
of t's LEFT child

So:
        t
       /
    left
       \
       new

That's:
LEFT → RIGHT

Therefore:
LR

Complex LR example
Insert:
50
30
40

Normal BST gives:
       50
      /
    30
      \
       40

Now at:
t = 50

calculate:
balance = 2

So:
balance > 1

TRUE.
Now check:
data > t->left->data

That's:
40 > 30

TRUE.
Therefore:
LR

Why can't we just right rotate 50?
If we right rotate immediately:
       50
      /
    30
      \
       40

becomes:
      30
        \
         50
        /
       40

That's still not the balanced structure we want.
So we need two rotations.
Step 1 — Left rotate the left child
t->left=leftRotate(t->left);

Before:
       50
      /
    30
      \
       40

Here:
t = 50
t->left = 30

So:
leftRotate(t->left)

means:
leftRotate(30)

Result:
       50
      /
    40
   /
 30

Step 2 — Right rotate t
return rightRotate(t);

Since:
t = 50

we do:
rightRotate(50)

Final:
      40
     /  \
   30    50

CASE 4 — RL
Condition:
if(balance<-1 && data<t->right->data)
{
    t->right=rightRotate(t->right);
    return leftRotate(t);
}

Again:
balance < -1

means:
RIGHT side is heavy

And:
data < t->right->data

means:
new value went to LEFT
of t's RIGHT child

So:
       t
        \
        right
        /
       new

That's:
RIGHT → LEFT

Therefore:
RL

Example
Insert:
50
70
60

Normal BST:
50
  \
   70
   /
 60

At:
t = 50

Balance:
balance = -2

So:
balance < -1

TRUE.
Then:
60 < 70

TRUE.
Therefore RL.
Step 1
t->right=rightRotate(t->right);

Here:
t = 50
t->right = 70

So:
rightRotate(70)

gives:
      50
        \
         60
           \
            70

Step 2
return leftRotate(t);

t is still:
50

So:
leftRotate(50)

Final:
      60
     /  \
   50    70

Now the four conditions become very simple
Look only at the direction.
                    t
                  /   \
                 L     R
                / \   / \
               LL LR RL RR

LL
balance > 1
data < t->left->data

       t
      /
     L
    /
   X

→ RIGHT ROTATE

RR
balance < -1
data > t->right->data

   t
    \
     R
      \
       X

→ LEFT ROTATE

LR
balance > 1
data > t->left->data

       t
      /
     L
      \
       X

→ LEFT ROTATE(L)
→ RIGHT ROTATE(t)

RL
balance < -1
data < t->right->data

   t
    \
     R
    /
   X

→ RIGHT ROTATE(R)
→ LEFT ROTATE(t)

The easiest way to remember the conditions
Don't memorize the code.
Just ask two questions:
Question 1: Which side of t is heavy?
balance > 1  → LEFT
balance < -1 → RIGHT

Question 2: Where did the new node go inside that heavy side?
LEFT heavy:
    new went LEFT  → LL
    new went RIGHT → LR

RIGHT heavy:
    new went RIGHT → RR
    new went LEFT  → RL

Then:
LL → Right
RR → Left
LR → Left + Right
RL → Right + Left

One more important point about t
Suppose this:
       100
       /
      50
     /
    30

and imbalance is at 100.
Then:
t = 100

We do:
rightRotate(t);

NOT:
rightRotate(t->left);

because t is the root of the subtree that became unbalanced.
For LR:
t->left=leftRotate(t->left);
return rightRotate(t);

there are TWO different t-related nodes:
t        = 50
t->left  = 30

First rotate the child:
leftRotate(t->left)
        ↑
       30

Then rotate the whole unbalanced subtree:
rightRotate(t)
             ↑
            50

That distinction is the key to understanding the AVL insertion code.




Deletion Logic :


*/

