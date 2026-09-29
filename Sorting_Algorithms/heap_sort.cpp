/*
Heap Sort :

Heap Sort is a sorting algorithm that uses a heap data structure to 
repeatedly find the largest or smallest element and place it in its correct position.


2. Simple idea
For ascending order:
        Array
        ↓
        Build Max Heap
        ↓
        Largest element comes to root
        ↓
        Swap root with last element
        ↓
        Reduce heap size
        ↓
        Heapify again
        ↓
        Repeat


3. What is a Max Heap?
A Max Heap follows:
        50
       /  \
     30    40
    / \    /
   10 20  35
The parent is always greater than its children.
So the largest element is always at:
    arr[0]

4. Important formulas
For an element at index i:
Left child  = 2*i + 1
Right child = 2*i + 2
Parent      = (i-1)/2


5. Main steps
Suppose:
5  3  8  4  1
First build a Max Heap:
        8
       / \
      4   5
     / \
    3   1
Array representation:
8  4  5  3  1
Now swap the root with the last element:
1  4  5  3  8
            ↑
          sorted
Heapify the remaining part:
5  4  1  3 | 8
Repeat:
4  3  1 | 5 8
Then:
3  1 | 4 5 8
Finally:
1 3 4 5 8
⭐ Key point
For ascending Heap Sort → use Max Heap
For descending Heap Sort → use Min Heap



Part 1: heapify()
The purpose of heapify() is to make the given subtree a Max Heap.
1. Assume the current element is the largest:
   largest = i;
2. Find its children:
   left = 2*i + 1;
   right = 2*i + 2;
3. Compare the left child with the current largest.
   - If left is bigger → make largest = left.
4. Compare the right child with the current largest.
   - If right is bigger → make largest = right.
5. If the largest element is not the current element:
   - Swap them.
6. The smaller element has now moved down.
   - So call heapify() again on its new position.


Compare children
      ↓
Find largest
      ↓
Swap if needed
      ↓
Heapify the new position


Part 2: Build Max Heap
for(int i = n/2 - 1; i >= 0; i--)
    heapify(arr, n, i);

1. Start from the last non-leaf node.
2. Call heapify() for each node going backwards.
3. Finally, the entire array becomes a Max Heap.
4. Therefore, the largest element is at arr[0].
        Largest
           ↓
         arr[0]

         

Part 3: Sorting
for(int i = n-1; i > 0; i--)

1. The largest element is at arr[0].
2. Swap arr[0] with arr[i].
3. Now the largest element is in its correct final position.
4. Reduce the heap size from n to i.
5. Call heapify(arr, i, 0) to rebuild the Max Heap.
6. Repeat until the array is sorted.
Example:
8 4 5 3 1
↑       ↑
max     last

Swap:

1 4 5 3 8
        ↑
      sorted

Then heapify only:
1 4 5 3   |   8
<--heap--> sorted


*/

void heapify(int arr[], int n, int i)
{
    int largest = i;

    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

// parent should be greater than both children in max heap

    if(left < n && arr[left] > arr[largest]) 
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

// swap(arr[largest] , arr[i] ) if  the parent is less than their child
    if(largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr, n, largest); // start from the largest after swapping
    }
}

void heap_sort(int arr[], int n)
{
// elements from n/2 to n are leaf nodes ie.nodes without child.
    // Build Max Heap
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Move largest element to the end
    for(int i = n - 1; i > 0; i--)
    {
        // swap ( arr[0] , arr[i]) i is the last position and will decrease by one for each iteration.
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0); // pass i as n as array size to be heapified will decrease after moving front element and last element
    }
}