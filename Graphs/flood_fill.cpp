/*

Problem Link : https://leetcode.com/problems/flood-fill/
Problem 733 : Flood Fill

You are given an image represented by an m x n grid of integers image, 
where image[i][j] represents the pixel value of the image. 
You are also given three integers sr, sc, and color. 
Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), 
all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation:
The starting pixel is already colored with 0, which is the same as the target color. 
Therefore, no changes are made to the image


1.Start from the cell image[sr][sc]
2.The color of image[sr][sc] is the original color.
3.We need to change the color of all the nodes connected to image[sr][sc] having the  same original color
to the given 'color'.



*/

class Solution {
public:
void dfs(vector<vector<int>>& image , int sr , int sc , int color, int original)
{
    if( sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ) 
        return;

    if(image[sr][sc] != original) // if the color of the node is not original return
        return;

    image[sr][sc] = color; // change the color of the current node to 'color'
    
    //checking its neighbours
    dfs(image , sr - 1 , sc , color , original);
    dfs(image , sr + 1 , sc , color , original);
    dfs(image , sr , sc - 1 , color , original);
    dfs(image , sr , sc + 1 , color , original);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int original = image[sr][sc]; // storing the original(starting) color

        if(original == color) // if starting color is same as the given 'color' then nothing has to be changed.
            return image; // since we r changing the color of the connected noded to starting node to color,there is nothing to do.So return image as it is.

        dfs(image , sr , sc ,color , original);
        
        return image;
    }
};