/*
Problem: 236. Lowest Common Ancestor of a Binary Tree
Pattern: DFS + Returning Information Upward
Difficulty: Medium

Time Complexity: O(n)
- In the worst case, every node is visited once.

Space Complexity: O(h)
- Recursive call stack depends on the height of the tree.

Key Idea:
- Find p and q using DFS.
- Each recursive call returns information to its parent.
- If p is found in one subtree and q in the other,
  the current node is their Lowest Common Ancestor.

DFS Return Meaning:

return NULL
→ neither p nor q was found in this subtree.

return p or q
→ one of the target nodes was found.

return another TreeNode*
→ the LCA has already been found in this subtree.

Base Case:

if(root==NULL||root==p||root==q)
{
    return root;
}

- NULL → nothing found.
- root==p/q → target found, so return it upward.

Recursive Calls:

TreeNode* l=dfs(root->left,p,q);
TreeNode* r=dfs(root->right,p,q);

l → result from left subtree.
r → result from right subtree.

If both are non-NULL:

if(l!=NULL&&r!=NULL)
{
    return root;
}

One target was found on each side, so the current
node is the LCA.

If only the left side found something:

if(l!=NULL)
{
    return l;
}

Return the left result upward.

Otherwise:

return r;

Return the right result upward.

Important DFS Concept:

In 1448:
Parent → Child
Maximum value was passed down as a parameter.

In 543:
Child → Parent
Height was returned to the parent.

In 236:
Child → Parent
A TreeNode* result is returned to the parent.

Parameter:
Parent → Child

Return:
Child → Parent

Core Pattern:

        current node
          /      \
         ↓        ↓
      left DFS  right DFS
         ↓        ↓
         l        r
          \      /
           ↓    ↓
       combine results
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
    TreeNode* dfs(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL||root==p||root==q)
        {
            return root;
        }
        TreeNode* l=dfs(root->left,p,q);
        TreeNode* r=dfs(root->right,p,q);
        if(l!=NULL&&r!=NULL)
        {
            return root;
        }
        if(l!=NULL)
        {
            return l;
        }
        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};