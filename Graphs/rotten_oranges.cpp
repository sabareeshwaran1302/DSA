/*
Problem Link : https://leetcode.com/problems/rotting-oranges/
Problem 994 : Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1.

 

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten,
because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.




Find all rotten oranges (2) in the grid.

Put all rotten oranges into a queue.
- We put all of them because they can spread simultaneously.

Set:
minutes = 0;

While the queue is not empty:
- Take the number of rotten oranges currently in the queue:size = q.size();
- These are the oranges that spread during this minute.

Process those size oranges one by one.

For each rotten orange, check its 4 directions:
- Down
- Up
- Right
- Left

If a neighboring cell is a fresh orange (1):
- Change it to rotten:grid[...] = 2;
- Add it to the queue:q.push(...);

The newly rotten oranges are kept in the queue for the next minute, not the current minute.

After processing all size oranges:
minutes++;
if new oranges are waiting in the queue.

When the queue becomes empty, no more spreading is possible.

Finally, scan the grid:
- If any 1 remains → return -1.
- Otherwise → return minutes.




We use multi-source BFS for this problem.
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q; // store row and column of each rotten orange

        for(int i = 0 ;i < r ;i++)
        {
            for(int j = 0 ;j<c;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j}); // pushing initially rotten oranges into the queue

                }
            }
        }

        int minutes = 0;

        while(!q.empty())
        {
            int size  = q.size(); 

            for(int i = 0 ;i<size;i++) // processing all the oranges rotten in last minute
            {
                int row = q.front().first; // row and col of one of the oranges rotten in last minute
                int col = q.front().second;
                q.pop();


                // make its neighbour rotten and push them into the queue.Newly rotten orange will be processed only after all the oranges rotten in last minutes gets processed. 
                if(row + 1 < r && grid[row+1][col] == 1)
                {
                    grid[row+1][col] = 2; 
                    q.push({row+1,col});
                    
                }
                if(row - 1 >= 0 && grid[row-1][col] == 1)
                {
                    grid[row-1][col] = 2;
                    q.push({row-1,col});
                    
                }
                if(col + 1 < c && grid[row][col+1] == 1)
                {
                    grid[row][col+1] = 2;
                    q.push({row,col+1});
                    
                }
                if(col - 1 >= 0 && grid[row][col - 1] == 1)
                {
                    grid[row][col-1] = 2;
                    q.push({row,col-1});
                    
                }

            }
            if(!q.empty()) // if there are no new oranges rotten in last minute then the queue will be empty
                minutes++; // minutes is incremented only after processing all the oranges rotten in last minute
        }

        for(int i = 0 ;i<r;i++)
        {
            for(int j =0;j<c;j++)
            {
                if(grid[i][j]==1) // if there are still any fresh orange
                    return -1;
            }
        }
        return minutes;

        
    }
};