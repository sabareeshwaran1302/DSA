/*
Generate 50 pairs of integers, where the first integer is between 1 and 25. Sort the pairs using Counting Sort based on the first integer.

*/

#include <iostream>
using namespace std;

#define MAX 50

struct Pair
{
    int first, second;
};

Pair arr[MAX], output[MAX];
int count[26];

void countingSort(int n)
{
    for(int i = 0; i <= 25; i++)
        count[i] = 0;

    for(int i = 0; i < n; i++)
        count[arr[i].first]++;

    for(int i = 1; i <= 25; i++)
        count[i] += count[i-1];

    for(int i = n-1; i >= 0; i--)
    {
        int x = arr[i].first;
        output[count[x]-1] = arr[i];
        count[x]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    countingSort(n);

    for(int i = 0; i < n; i++)
        cout << arr[i].first << " "
             << arr[i].second << endl;

    return 0;
}
