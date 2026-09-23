/*

Selection Sort :

Selection Sort is a sorting algorithm that repeatedly finds the smallest element 
from the unsorted part and places it at the beginning of that part.

In simple words:
Find the smallest → swap it with the first unsorted element → repeat.

Selection Sort in Ascending Order : 

*/
void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Selection sort in Descending order : 

void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}