/*
Problem Link : https://leetcode.com/problems/number-of-islands/
Problem 200 : Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
 return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/

class Solution {
public:
    void dfs(vector<vector<char>> &grid , int i ,int j)
    {
        if( i< 0 || i >= grid.size()  || j < 0  ||  j >=grid[0].size()  )
        {
            return;
        }
        if(grid[i][j] == '0')
            return;

        grid[i][j] = '0'; // marking the visited as 0
        // neighbours of grid[i][j]
        dfs(grid , i-1 , j);
        dfs(grid , i , j-1);
        dfs(grid , i+1 , j);
        dfs(grid , i , j+1);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0;i<m ; i++)
        {
            for(int j=0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    count++; // counting the number of components
                    dfs( grid , i ,j); // completes a single component .It makes all the reaching nodes from a starting given node as 0
                }
            }
        }
        return count;
        
    }
};