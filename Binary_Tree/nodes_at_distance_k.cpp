/*
Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
Problem 863 : All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Take the binary tree, target, and k.
Traverse the tree using BFS from the root.
Store the parent of every node in parent_track.
Create a visited map.
Start another BFS from the target.
Mark the target as visited.
For every current node, check:
- left child
- right child
- parent
Add unvisited nodes to the queue.
After processing one complete level, increase curr_level.
When curr_level == k, stop.
All nodes remaining in the queue are at distance k.
Put their values into result.


Normally we can traverse  a binary tree from parent to child nodes.
But in this problem, we need to traverse from child to parent as well. 
So we need to store the parent of each node in a map. Then we can traverse the tree in any direction.
*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void markParent(TreeNode *root , unordered_map<TreeNode*,TreeNode*>&parent_track) 
{ // to store the parent of each node in a map
    queue<TreeNode*>queue;
    queue.push(root);
    while(!queue.empty())
    {
        TreeNode *current = queue.front();
        queue.pop();
        if(current->left) // the parent of current->left is current
        {
            parent_track[current->left] =current;
            queue.push(current->left); 
        }
        if(current->right) // the parent of current->right is current
        {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>parent_track; // child,parent ie. parent_track[child] = parent
        markParent(root , parent_track);
        unordered_map<TreeNode* , bool>visited; // to keep track of visited nodes
        queue<TreeNode*>queue;
        queue.push(target); // start BFS from the target node
        visited[target]=true;
        int curr_level = 0;
        while(!queue.empty())
        {
            int size = queue.size();
            if(curr_level == k)break; // if we have reached the required level, we can stop the BFS
            for(int i=0;i<size;i++)
            {
                TreeNode *current = queue.front();
                queue.pop();
                if(current->left && !visited[current->left]) // if left child exists and is not visisted
                {
                    queue.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]) // if right child exists and is not visited
                {
                    queue.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) // if parent exists and is not visited
                {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            curr_level++; // increase the level after processing all nodes at the current level
        }
        vector<int>result; // the nodes remaining in the queue are at distance k from the target node
        while(!queue.empty())
        {
            TreeNode *current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }
        return result;
        
    }
};