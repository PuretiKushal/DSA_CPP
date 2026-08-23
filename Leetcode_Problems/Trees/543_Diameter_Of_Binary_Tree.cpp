/*
Problem: 543. Diameter of Binary Tree
Pattern: DFS + Recursion
Difficulty: Easy

Time Complexity: O(n)
- Every node is visited once.

Space Complexity: O(h)
- Recursive call stack can go up to the height of the tree.

Key Idea:
- The diameter is the longest path between any two nodes.
- For every node, calculate:
    left height + right height
- Keep the maximum of these values in `ans`.
- At the same time, return the current node's height to its parent.

Why `dfs()` returns int:
- The parent needs the height of the child's subtree.
- Therefore, DFS must return a number.

Base Case:

if(p==NULL)
{
    return 0;
}

A NULL subtree has height 0.

For every node:

l=dfs(p->left);
r=dfs(p->right);

- `l` = left subtree height.
- `r` = right subtree height.

Diameter through current node:

ans=max(ans,l+r);

- The longest path passing through the current node
  uses the deepest path from the left + deepest path from the right.
- Diameter is measured in edges, so we use `l+r`.

Return height:

return 1+max(l,r);

- The parent only needs the height of this subtree.
- `1` represents the current node.

Important:
`dfs()` does TWO jobs:

1. Updates the global `ans` with the best diameter found.
2. Returns the subtree height to the parent.

Why `ans` is a class variable:
- Every recursive call must update the SAME answer.
- If `ans` were declared inside `dfs()`, it would be reset
  for every recursive call.

Initialization:

ans=0;

- The minimum possible diameter is 0.
- Then DFS updates it while traversing the tree.

Core Pattern:

        dfs(node)
          /    \
         ↓      ↓
    left height right height
         \      /
          ↓    ↓
        l + r → update answer

Then:

return 1+max(l,r);

Important DFS concept learned:
- A recursive function can return information to its parent
  AND update a shared/global answer at the same time.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    int dfs(TreeNode* p)
    {
        int l,r;
        l=r=0;
        if(p==NULL)
        {
            return 0;
        }
        l=dfs(p->left);
        r=dfs(p->right);
        ans=max(ans,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};