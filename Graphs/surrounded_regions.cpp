/*
Problem Link : https://leetcode.com/problems/surrounded-regions/
Problem 130 : Surrounded Regions

"O" is surrounded by 'X'
We need to change the 'O' to "X" that can't be escaped.
The "O" in boundary and "O" connected to them can be escaped.


*/



class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c)
    {
        if(r < 0 || r >= board.size() ||
           c < 0 || c >= board[0].size())
            return;

        if(board[r][c] != 'O')
            return;

        board[r][c] = '#'; // change "O" to "#" to mark them as "They can be escaped via "O" in boundary " ".

        // move to the neighbours
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board)
    {
        int r = board.size();
        int c = board[0].size();

        //Start dfs  from the boundary having "O"

        // First column and last column
        for(int i = 0; i < r; i++)
        {
            if(board[i][0] == 'O')
                dfs(board, i, 0);

            if(board[i][c-1] == 'O')
                dfs(board, i, c-1);
        }

        // First row and last row
        for(int i = 0; i < c; i++)
        {
            if(board[0][i] == 'O')
                dfs(board, 0, i);

            if(board[r-1][i] == 'O')
                dfs(board, r-1, i);
        }


        // Now "O" are cannot be escaped ie. surrounded by "X".We need to change them to "X".
        // "#" can be escaped via "O" in boundary.

        // Convert surrounded O to X
        // Convert safe # back to O
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                // changing "O" that is surrounded by "X" and can't be escaped to "X"
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                
                // changing "#" again to "O" as they can be escaped via "O" in boundary.
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};