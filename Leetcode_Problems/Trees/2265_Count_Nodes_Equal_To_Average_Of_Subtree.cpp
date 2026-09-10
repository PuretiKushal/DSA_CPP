/*
Problem: 2265. Count Nodes Equal to Average of Subtree
Pattern: Binary Tree + DFS
Difficulty: Medium

Time Complexity: O(n)
(Each node is visited exactly once by DFS.)

Space Complexity: O(h)
(The recursive call stack can go up to the height 'h' of the tree.)

Key Idea:
- For every node, calculate the sum and number of nodes in its subtree.
- The DFS function returns both values using pair<int,int>.
- pair.first stores the subtree sum.
- pair.second stores the number of nodes in the subtree.
- First calculate the information from the left and right subtrees.
- Then calculate the current subtree:
    sum=left.first+right.first+root->val
    count=left.second+right.second+1
- Check whether:
    root->val==sum/count
- If true, increment 'ans'.
- The string/int '&ans' is passed by reference so that every recursive
  call can directly update the same answer variable.
- The current node is processed after both children, making this
  post-order DFS.
*/

class Solution {
public:
    pair<int,int> dfs(TreeNode* root,int &ans)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int> left=dfs(root->left,ans);
        pair<int,int> right=dfs(root->right,ans);
        int sum=left.first+right.first+root->val;
        int count=left.second+right.second+1;
        if(root->val==sum/count)
        {
            ans++;
        }
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root)
    {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};