/*
Problem Link : https://leetcode.com/problems/number-of-enclaves/
Problem 1020 : Number of Enclaves

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or
walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.




*/


class Solution {
public:

    void dfs(vector<vector<int>>& grid, int r, int c)
    {
        // Out of boundary
        if(r < 0 || r >= grid.size() ||
           c < 0 || c >= grid[0].size())
        {
            return;
        }

        // If sea or already visited
        if(grid[r][c] != 1) // 0 is sea and 2 is already visited
        {
            return;
        }

        // Mark as visited
        grid[r][c] = 2; 

        // Up
        dfs(grid, r - 1, c);

        // Down
        dfs(grid, r + 1, c);

        // Left
        dfs(grid, r, c - 1);

        // Right
        dfs(grid, r, c + 1);
    }

    int numEnclaves(vector<vector<int>>& grid)
    {
        int count = 0;

        int r = grid.size();
        int c = grid[0].size();

        //We are finding all the 1s that are on the boundary of the grid and starting DFS from them.

        // First row
        for(int j = 0; j < c; j++)
        {
            if(grid[0][j] == 1)
                dfs(grid, 0, j);
        }

        // Last row
        for(int j = 0; j < c; j++)
        {
            if(grid[r - 1][j] == 1)
                dfs(grid, r - 1, j); 
        }

        // First column
        for(int i = 0; i < r; i++)
        {
            if(grid[i][0] == 1)
                dfs(grid, i, 0);
        }

        // Last column
        for(int i = 0; i < r; i++)
        {
            if(grid[i][c - 1] == 1)
                dfs(grid, i, c - 1);
        }

        // Count remaining land which are enclaved ie. land surrounded by sea and cannot get off the grid
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};