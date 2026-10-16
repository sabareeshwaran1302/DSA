/*
Modify the insertion sort algorithm to sort an array of strings in alphabetical order.

*/
#include <iostream>
#include <string>
using namespace std;

void insertionSort(string arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        string key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main()
{
    string arr[20];
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
