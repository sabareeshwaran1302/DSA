/*
Problem Link : https://leetcode.com/problems/01-matrix/
Problem 542 : 01 Matrix


Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]



*/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int r = mat.size();
        int c = mat[0].size();
        queue<pair<int,int>> q; // row and col 

        for(int i =0 ; i <r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j] == 0) // pushing row and col of having 0's
                    q.push({i,j});
                else
                    mat[i][j]= -1; // changing unvisited to -1
            }
        }

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
// changing the value at each position to the distance from nearest 0 by adding 1 to the the nearest value's distance
                if(row+1 < r && mat[row+1][col] == -1)
                {
                    q.push({row+1,col});
                    mat[row+1][col]=mat[row][col]+1; // incrementing the neighbour of each zero by 1 each time 
                }
                if(row-1 >= 0 && mat[row-1][col] == -1)
                {
                    q.push({row-1,col});
                    mat[row-1][col]=mat[row][col]+1;
                }
                if(col+1 < c && mat[row][col+1] == -1)
                {
                    q.push({row,col+1});
                    mat[row][col+1]=mat[row][col]+1;
                }
                if(col-1 >= 0  && mat[row][col-1] == -1)
                {
                    q.push({row,col-1});
                    mat[row][col-1]=mat[row][col]+1;
                }
            }
        }
        return mat;
        
    }
};