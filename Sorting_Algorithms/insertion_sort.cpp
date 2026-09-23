/*

Insertion Sort : 
Insertion Sort is a sorting algorithm that builds the sorted array one element at a time by taking each element and inserting it into its correct position among the previously sorted elements.
In simple words:
Take one element → find its correct position in the sorted part → insert it there.


Suppose:
int arr[] = {7, 3, 8, 2, 6};
We start from index 1 because index 0 is considered sorted.
i = 1
i = 2
i = 3
i = 4
For every i:
1. Store arr[i] in key.
2. Compare key with elements before it.
3. If the previous element is greater, shift it one position right.
4. Continue until the correct position is found.
5. Insert key.

Insertion Sort in Ascending Order in Iterative approach : 

*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {7, 3, 8, 2, 6};
    int n = 5;

    insertionSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*

Insertion Sort in Descending Order in Iterative approach : 

*/

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


/*

Insertion Sort in Ascending Order in Recursive approach : 

*/

void insertionSort(int arr[], int n)
{
    if(n <= 1)
        return;

    insertionSort(arr, n - 1);

    int key = arr[n - 1];
    int j = n - 2;

    while(j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}

/*

Insertion Sort in Descending Order in Recursive approach : 

*/

void insertionSort(int arr[], int n)
{
    if(n <= 1)
        return;

    insertionSort(arr, n - 1);

    int key = arr[n - 1];
    int j = n - 2;

    while(j >= 0 && arr[j] < key)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}