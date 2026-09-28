/*

Quick Sort : 

Based on Divide and conquer.
We are choosing a random element as a pivot element and 
move the elements less than pivot to the left of the pivot and
move the elements greater than pivot to the right of the pivot and


Initial : 
pivot | remaining elements
End of Partition : 
less than pivot | pivot | greater than pivot


pivot = first element

start → move right until arr[start] > pivot
end   → move left until arr[end] <= pivot

swap start and end

when start >= end:
    swap pivot with arr[end]

return end


*/


int partition(int arr[], int low, int high)
{ 
// low and high are the indices of  lowerbound and upperbound elements

    int pivot = arr[low]; // choose first element as pivot element

    int start = low;
    int end = high;

    while(start < end)
    {
        while(start < high && arr[start] <= pivot) // move start forward till the arr[start] < pivot
            start++;

        while(end > low && arr[end] > pivot)
            end--;

        if(start < end) // if the arr[start] is greater than pivot and arr[end] is less than pivot, swap arr[start] and arr[end]. 
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
// if start > end , then swap arr[low] and arr[end] and return end (index of the pivot element)
    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;

    return end; // return the index and not the element
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

// Call using : 
quick_sort(arr, 0, n - 1);