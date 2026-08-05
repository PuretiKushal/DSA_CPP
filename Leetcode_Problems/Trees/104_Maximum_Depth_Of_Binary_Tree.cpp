/*
Problem: 104. Maximum Depth of Binary Tree
Pattern: Tree Recursion (Postorder DFS)
Difficulty: Easy

Time Complexity: O(n)
(Each node is visited exactly once.
 At every node, the recursion explores both
 the left and right subtrees.)

Space Complexity: O(h)
(Due to the recursion call stack.
 h = Height of the tree.

 Worst Case (Skewed Tree): O(n)
 Balanced Tree: O(log n))

Key Idea:
- The maximum depth of a tree depends on the
  maximum depth of its left and right subtrees.
- Recursively calculate the depth of both subtrees.
- The current node contributes one level.
- Return:
    1 + maximum(left depth, right depth)

Base Case:

if(root==NULL)
{
    return 0;
}

- A NULL node represents an empty tree.
- The depth of an empty tree is 0.
- This stops the recursion.

Current Work:

int l=maxDepth(root->left);

int r=maxDepth(root->right);

- Recursively calculate the maximum depth
  of the left subtree.
- Recursively calculate the maximum depth
  of the right subtree.

Recursive Case:

return 1+max(l,r);

- The current node contributes one level.
- Choose the deeper of the two subtrees.
- Return the maximum depth of the current tree.

Important Notes:
- LeetCode defines depth as the number of nodes
  on the longest path from the root to a leaf.
- This is a Postorder DFS because the answer for
  the current node is calculated only after
  solving both left and right subtrees.
- This problem introduces the standard recursion
  template used in many tree problems.
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
    int maxDepth(TreeNode* root) {
        int l,r;
        if(root==NULL)
        {
            return 0;
        }
        l=maxDepth(root->left);
        r=maxDepth(root->right);
        return 1+max(l,r);
    }
};