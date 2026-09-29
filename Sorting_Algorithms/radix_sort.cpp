/*

Radix Sort : 

Instead of comparing whole numbers, we sort numbers digit by digit.
For example:
170  45  75  90  802  24  2  66

We sort by:
1. Units digit
2. Tens digit
3. Hundreds digit
After all digits are processed:
2  24  45  66  75  90  170  802

1. Start from the last digit.
2. Sort according to that digit.
3. Move to the next digit.
4. Sort again.
5. Continue until all digits are processed.
6. Array becomes sorted.
Memory:  
Units → Tens → Hundreds → Sorted



*/


//Get the maximum number
int getMax(int arr[], int n)
{
    int max = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

//Counting sort for each digit
void counting_Sort(int arr[], int n, int place)
{
    int output[n];
    int count[10] = {0}; // each single digit is between 0 to 9

    // Count the digits
    for(int i = 0; i < n; i++)
    {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    // Convert count into positions
    for(int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // Build output array
    for(int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / place) % 10;

        output[count[digit] - 1] = arr[i];

        count[digit]--;
    }

    // Copy back
    for(int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

//Radix Sort
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for(int place = 1; max / place > 0; place *= 10)
    {
        countingSort(arr, n, place);
    }
}

//Call using
radixSort(arr, n);