/*

Problem Link : https://leetcode.com/problems/median-of-two-sorted-arrays/
Problem 4 : Median of Two Sorted Arrays


Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
// This solution is not optimal and has a time complexity of O((m+n)log(m+n)) due to the sorting step.

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 


1.Create a new vector num3 to store the merged elements of nums1 and nums2.
2.Use a for loop to iterate through nums1 and push each element into num3.
3.Use another for loop to iterate through nums2 and push each element into num3.
4.Sort the merged vector num3 in ascending order using the sort function.
5.Calculate the midIndex as the size of num3 divided by 2.
6.Check if the size of num3 is even or odd.
   - If even, calculate the median as the average of the two middle elements.
   - If odd, the median is the middle element.
   

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>num3;
        for(int i=0;i<nums1.size();i++)
            num3.push_back(nums1[i]);
        for(int j = 0 ;j<nums2.size() ; j++)
            num3.push_back(nums2[j]);
        sort(num3.begin(),num3.end());
        int midIndex = num3.size() / 2;
        double mid;
        if(num3.size() % 2 == 0)
            mid = (num3[midIndex - 1] + num3[midIndex]) / 2.0;
        else
            mid  = num3[midIndex];
        return mid;
        
    }
};