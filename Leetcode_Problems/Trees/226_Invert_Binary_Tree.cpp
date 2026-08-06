/*
Problem: 226. Invert Binary Tree
Pattern: Tree Recursion (Preorder DFS)
Difficulty: Easy

Time Complexity: O(n)
(Each node is visited exactly once.
 At every node, the left and right child pointers
 are swapped.)

Space Complexity: O(h)
(Due to the recursion call stack.
 h = Height of the tree.

 Worst Case (Skewed Tree): O(n)
 Balanced Tree: O(log n))

Key Idea:
- At every node, swap its left and right child.
- Recursively invert the left subtree.
- Recursively invert the right subtree.
- The tree is modified in-place.

Base Case:

if(root==NULL)
{
    return NULL;
}

- A NULL node has no children.
- Nothing needs to be inverted.
- This stops the recursion.

Current Work:

swap(root->left,root->right);

- Swap the left and right child pointers.
- The current node is now inverted.

Recursive Case:

invertTree(root->left);

invertTree(root->right);

- Recursively invert the new left subtree.
- Recursively invert the new right subtree.

Return:

return root;

- The original root remains the root of the tree.
- Only the child pointers are modified.

Important Notes:
- This is a Preorder DFS because the current node
  is processed before recursively visiting its children.
- Only the pointers are swapped, not the actual nodes.
- The tree is inverted in-place, so no new nodes
  are created.
- A Postorder solution also works because every node
  is eventually visited exactly once and its children
  are swapped once.
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};