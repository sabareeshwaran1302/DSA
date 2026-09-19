/*
Problem Link : https://leetcode.com/problems/number-of-provinces/
Problem 574 : Number of Provinces

There are n cities. Some of them are connected, while some are not.
If city a is connected directly with city b, and city b is connected directly with city c,
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and 
no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 
if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

 

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

We need to find the Number of Components in the given graph.


*/
class Solution {
public:
    void dfs(int node , vector<vector<int>>& isConnected , vector<bool>& visit)
    {
        visit[node]=true; 
        for(int i=0;i<isConnected.size();i++) // isConnected.size() is number of vertices
        {
            if(isConnected[node][i] && !visit[i]) // i is another vertex connected with the cuurent vertex
            {
                dfs(i , isConnected , visit); // passing it as node to make visit[i] as true.     
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size(); // n is the total number of vertices in the graph
        int components = 0;
        vector<bool>visit(n);

        for(int i=0;i<n;i++) // iterating for all the number of vertices
        {
            if(!visit[i]) // if a vertex is not visited
            {
                components++;
                dfs(i,isConnected,visit); // dfs makes the visit[vertices] in a current component of graph as true.
            }
        }
        return components;
        
    }
    
};