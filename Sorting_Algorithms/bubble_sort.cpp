/*
Bubble Sort :

Bubble Sort is a sorting algorithm that repeatedly compares adjacent elements and 
swaps them if they are in the wrong order.

In simple words:
Compare neighbors → swap if wrong → repeat.

The largest element gradually moves to the end, like a bubble rising to the top.



j < n - i - 1 because, after every pass, the largest unsorted element reaches its correct position at the end. 
So, we don't need to compare those already-sorted elements again.

*/

// Bubble Sort for Ascending Order  : 

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Bubble Sort for Descending Order  :

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

