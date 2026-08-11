/*
Problem: 94. Binary Tree Inorder Traversal
Pattern: Tree Traversal (DFS / Inorder)
Difficulty: Easy

Time Complexity: O(n)
(Every node is visited exactly once.)

Space Complexity: O(h)
(Due to the recursion call stack.
 h = height of the tree.

 Worst Case: O(n)
 Balanced Tree: O(log n))

Key Idea:
- Inorder traversal follows:
    Left → Root → Right
- Recursively traverse the left subtree first.
- Process the current node.
- Then recursively traverse the right subtree.
- Store each visited value in the answer vector.

Helper Function:

void inorder(TreeNode* p)

- The helper returns void because we don't need
  information returned from the child calls.
- We directly store each visited node in the shared
  ans vector.

Base Case:

if(p==NULL)
{
    return;
}

- If there is no node, stop this recursive call.

Traversal:

inorder(p->left);
ans.push_back(p->val);
inorder(p->right);

- First visit the complete left subtree.
- Then add the current node.
- Finally visit the complete right subtree.
- This produces Left → Root → Right order.

Example:

        1
       / \
      2   3
     / \
    4   5

Inorder:

4 → 2 → 5 → 1 → 3

Important Notes:
- The position of ans.push_back(p->val) determines
  the traversal type.
- Before both recursive calls → Preorder.
- Between the two recursive calls → Inorder.
- After both recursive calls → Postorder.
- ans is a class variable so every recursive call
  adds to the same result vector.
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
    vector<int> ans;
    void inorder(TreeNode* p)
    {
        if(p==NULL)
        {
            return;
        }
        inorder(p->left);
        ans.push_back(p->val);
        inorder(p->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};