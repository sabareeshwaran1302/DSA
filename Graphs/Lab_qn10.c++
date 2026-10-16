/*
Implement Merge Sort to sort student records based on registration number, CGPA, and credits.
*/


#include <iostream>
using namespace std;

#define MAX 100

struct Student
{
    int regno;
    float cgpa;
    int credits;
};

Student arr[MAX], temp[MAX];

void merge(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i].regno <= arr[j].regno)
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(int i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);

        merge(low, mid, high);
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i].regno
            >> arr[i].cgpa
            >> arr[i].credits;

    mergeSort(0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i].regno << " "
             << arr[i].cgpa << " "
             << arr[i].credits << endl;

    return 0;
}
