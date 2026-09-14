/*

Problem Link : https://leetcode.com/problems/binary-search/
Problem 704 : Binary Search

Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1


1. Start with l = 0 and r = n - 1.
2. Find the middle index: mid = (l + r) / 2.
3. Compare nums[mid] with the target.
4. If nums[mid] == target, return mid.
5. If nums[mid] < target, search the right half by setting l = mid + 1.
6. If nums[mid] > target, search the left half by setting r = mid - 1.
7. Repeat steps 2–6 while l <= r.
8. If the target is not found, return -1.
9.Suitable only for Sorted Array

*/

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0;
        int r = nums.size() - 1;
        while( l <= r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target )
            {
                return mid;
            }
            if(nums[mid] < target)
                l = mid+1;
            else if(nums[mid] > target)
                r = mid -1;
        }
        return -1;
        
    }
};