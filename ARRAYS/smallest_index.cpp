/*
Problem Link : https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
Problem 3550 : Smallest index with digit sum equal to index

You are given an integer array nums.

Return the smallest index i such that the sum of the digits of nums[i] is equal to i.

If no such index exists, return -1.

 

Example 1:
Input: nums = [1,3,2]
Output: 2
Explanation:
For nums[2] = 2, the sum of digits is 2, which is equal to index i = 2. Thus, the output is 2.

Example 2:
Input: nums = [1,10,11]
Output: 1
Explanation:
For nums[1] = 10, the sum of digits is 1 + 0 = 1, which is equal to index i = 1.
For nums[2] = 11, the sum of digits is 1 + 1 = 2, which is equal to index i = 2.
Since index 1 is the smallest, the output is 1.

Example 3:
Input: nums = [1,2,3]
Output: -1
Explanation:
Since no index satisfies the condition, the output is -1.


*/
class Solution {
public:
    int smallestIndex(vector<int>& nums) 
    {
        for(int i = 0;i<nums.size();i++)
        {
            int sum=0;
            while(nums[i]>0) // finding sum of digits
            {
                sum = sum+(nums[i]%10);
                nums[i]=nums[i]/10;
            }
            if(sum == i)
                return i;
        }
        return -1;
    }
};