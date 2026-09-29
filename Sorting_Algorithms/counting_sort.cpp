/*
Counting Sort : 
Counting Sort is a sorting algorithm that counts how many times each 
value occurs and then uses those counts to place the elements in sorted order.

Suppose:
4  2  2  8  3  3  1

Step 1: Find the largest number
int max = arr[0];

Go through the array and find the biggest value.
Here:
max = 8

Step 2: Create a count array
int count[max + 1] = {0};

Create an array to store how many times each number appears.
Value:  0  1  2  3  4  5  6  7  8
Count:  0  1  2  2  1  0  0  0  1

Step 3: Count each element
count[arr[i]]++;

For every number in the original array, increase its count.
For example:
2 appears → count[2]++
2 appears → count[2]++
3 appears → count[3]++

So:
2 → 2 times
3 → 2 times

Step 4: Go through the count array
for(int i = 0; i <= max; i++)

Here i represents the actual number.
So i goes:
    0 → 1 → 2 → 3 → 4 → ... → 8

Step 5: Put numbers back into the original array
while(count[i] > 0)
{
    arr[k] = i;
    k++;
    count[i]--;
}

If:
count[2] = 2

put 2 into the array twice:
2 2

If:
count[3] = 2

put 3 twice:
3 3

Continue for all numbers.
Final result:
1 2 2 3 3 4 8


*/


void counting_sort(int arr[], int n)
{
    int max = arr[0];

    // Find maximum
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    // Create count array
    int count[max + 1] = {0};

    // Count each element
    for(int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Put elements back in sorted order

    int k = 0; // for traversing the original array from zero

    for(int i = 0; i <= max; i++)
    {
        while(count[i] > 0) // run for number of times each element present in the array
        {
            arr[k] = i; 
            k++;
            count[i]--; 
        }
    }
}
