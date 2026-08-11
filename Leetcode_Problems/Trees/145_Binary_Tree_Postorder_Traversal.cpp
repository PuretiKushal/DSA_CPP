/*
Problem: 145. Binary Tree Postorder Traversal
Pattern: Tree Traversal (DFS / Postorder)
Difficulty: Easy

Time Complexity: O(n)
(Every node is visited exactly once.)

Space Complexity: O(h)
(Due to the recursion call stack.
 h = height of the tree.

 Worst Case: O(n)
 Balanced Tree: O(log n))

Key Idea:
- Postorder traversal follows:
    Left → Right → Root
- Recursively traverse the left subtree first.
- Then recursively traverse the right subtree.
- Process the current node only after both children
  have been processed.
- Store each visited value in the answer vector.

Helper Function:

void postorder(TreeNode* p)

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

postorder(p->left);
postorder(p->right);
ans.push_back(p->val);

- First visit the complete left subtree.
- Then visit the complete right subtree.
- Finally add the current node.
- This produces Left → Right → Root order.

Example:

        1
       / \
      2   3
     / \
    4   5

Postorder:

4 → 5 → 2 → 3 → 1

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
    void postorder(TreeNode* p)
    {
        if(p==NULL)
        {
            return;
        }
        postorder(p->left);
        postorder(p->right);
        ans.push_back(p->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};