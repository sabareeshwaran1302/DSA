/*
Implement Heap Sort to sort an array of line segments, where each segment is represented by its starting and ending points.

*/


#include <iostream>
using namespace std;

#define MAX 100

struct Segment
{
    int x1, y1, x2, y2;
};

Segment arr[MAX];

void heapify(int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left].x1 > arr[largest].x1)
        largest = left;

    if(right < n && arr[right].x1 > arr[largest].x1)
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(n, largest);
    }
}

void heapSort(int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(n, i);

    for(int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i].x1 >> arr[i].y1
            >> arr[i].x2 >> arr[i].y2;

    heapSort(n);

    for(int i = 0; i < n; i++)
        cout << "(" << arr[i].x1 << "," << arr[i].y1
             << ") to (" << arr[i].x2 << "," << arr[i].y2
             << ")" << endl;

    return 0;
}
