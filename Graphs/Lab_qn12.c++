/*
Implement Quick Sort to sort student records based on registration number (regno) and date of birth (DOB).

*/


#include <iostream>
using namespace std;

#define MAX 100

struct Student
{
    int regno;
    int day, month, year;
};

Student arr[MAX];

void swapStudent(Student &a, Student &b)
{
    Student temp = a;
    a = b;
    b = temp;
}

int partition(int low, int high)
{
    int pivot = arr[high].regno;
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j].regno < pivot)
        {
            i++;
            swapStudent(arr[i], arr[j]);
        }
    }

    swapStudent(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(int low, int high)
{
    if(low < high)
    {
        int p = partition(low, high);

        quickSort(low, p-1);
        quickSort(p+1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i].regno
            >> arr[i].day
            >> arr[i].month
            >> arr[i].year;

    quickSort(0, n-1);

    for(int i = 0; i < n; i++)
        cout << arr[i].regno << " "
             << arr[i].day << "/"
             << arr[i].month << "/"
             << arr[i].year << endl;

    return 0;
}
