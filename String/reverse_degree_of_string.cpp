/*
Problem Link : https://leetcode.com/problems/reverse-degree-of-a-string/
Given a string s, calculate its reverse degree.
The reverse degree is calculated as follows:
For each character, multiply its position in the reversed alphabet
 ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
Sum these products for all characters in the string.
Return the reverse degree of s.

*/


class Solution {
public:
    int reverseDegree(string s) 
    {
        int sum = 0;
        for(int i=1;i<=s.size();i++)
        {
            sum+= (26 - (s[i-1] - 'a'))*i;
        }
        return sum;
        
    }
};