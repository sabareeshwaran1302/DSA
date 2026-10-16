/*

A binary tree is represented using an array. For a node stored at index i, its left child is stored at index 2i, and its right child is stored at index 2i+1.
Write functions to perform the following traversals of the binary tree:
1. Inorder Traversal — Left, Root, Right
2. Preorder Traversal — Root, Left, Right
3. Postorder Traversal — Left, Right, Root
The functions should take the array representation of the binary tree and the current node's index as input, and print the elements in the specified traversal order.


*/
#include <iostream>
using namespace std;

#define MAX 100

void inorder(int arr[], int i, int n)
{
    if(i > n)
        return;

    if(arr[i] == -1)
        return;

    inorder(arr, 2*i, n);
    cout << arr[i] << " ";
    inorder(arr, 2*i+1, n);
}

void preorder(int arr[], int i, int n)
{
    if(i > n)
        return;

    if(arr[i] == -1)
        return;

    cout << arr[i] << " ";
    preorder(arr, 2*i, n);
    preorder(arr, 2*i+1, n);
}

void postorder(int arr[], int i, int n)
{
    if(i > n)
        return;

    if(arr[i] == -1)
        return;

    postorder(arr, 2*i, n);
    postorder(arr, 2*i+1, n);
    cout << arr[i] << " ";
}

int main()
{
    int arr[MAX];
    int n;

    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter tree elements (-1 for empty node): ";
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    cout << "Inorder: ";
    inorder(arr, 1, n);

    cout << "\nPreorder: ";
    preorder(arr, 1, n);

    cout << "\nPostorder: ";
    postorder(arr, 1, n);

    return 0;
}
