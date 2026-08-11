/*
Problem: 144. Binary Tree Preorder Traversal
Pattern: Tree Traversal (DFS / Preorder)
Difficulty: Easy

Time Complexity: O(n)
(Every node is visited exactly once.)

Space Complexity: O(h)
(Due to the recursion call stack.
 h = height of the tree.

 Worst Case: O(n)
 Balanced Tree: O(log n))

Key Idea:
- Preorder traversal follows:
    Root → Left → Right
- Process the current node first.
- Then recursively traverse the left subtree.
- Finally recursively traverse the right subtree.
- Store each visited value in the answer vector.

Helper Function:

void preorder(TreeNode* p)

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

ans.push_back(p->val);
preorder(p->left);
preorder(p->right);

- First add the current node.
- Then visit the complete left subtree.
- Finally visit the complete right subtree.
- This produces Root → Left → Right order.

Example:

        1
       / \
      2   3
     / \
    4   5

Preorder:

1 → 2 → 4 → 5 → 3

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
    void preorder(TreeNode* p)
    {
        if(p==NULL)
        {
            return;
        }
        ans.push_back(p->val);
        preorder(p->left);
        preorder(p->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};