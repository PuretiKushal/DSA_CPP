/*
Problem: 110. Balanced Binary Tree
Pattern: Tree Recursion (Height + Balance Check)
Difficulty: Easy

Time Complexity: O(n)
(Each node is visited exactly once.
 The height of each subtree is calculated only once.)

Space Complexity: O(h)
(Due to the recursion call stack.
 h = Height of the tree.

 Worst Case (Skewed Tree): O(n)
 Balanced Tree: O(log n))

Key Idea:
- A binary tree is balanced if, for every node,
  the heights of its left and right subtrees
  differ by at most 1.
- The helper function returns two types of information:
    - -1 → the subtree is unbalanced.
    - 0 or a positive value → the subtree is balanced
      and the value represents its height.
- This allows us to calculate height and check
  balance at the same time.
- This avoids repeatedly calculating subtree heights.

Base Case:

if(p==NULL)
{
    return 0;
}

- An empty subtree has height 0.
- This stops the recursion.

Recursive Case:

l=height(p->left);
r=height(p->right);

- Recursively calculate the heights of the
  left and right subtrees.

Unbalanced Subtree Check:

if(l==-1||r==-1)
{
    return -1;
}

- If either subtree is already unbalanced,
  the current subtree is also unbalanced.
- Return -1 so the information propagates
  upward through the recursion.

Current Node Balance Check:

if(abs(l-r)>1)
{
    return -1;
}

- If the difference between the left and right
  subtree heights is greater than 1, the current
  subtree is not balanced.
- Return -1.

Height Calculation:

return 1+max(l,r);

- If the current subtree is balanced, return
  its height.
- max(l,r) gives the height of the taller subtree.
- +1 accounts for the current node.

Final Check:

return (height(root)!=-1);

- If height(root) returns -1, the tree is unbalanced.
- Otherwise, the tree is balanced.

Important Notes:
- The problem only asks for a boolean answer,
  but height is needed to determine whether each
  node is balanced.
- -1 is used as a special value to represent
  "unbalanced".
- The height of a node is calculated only once,
  giving an O(n) solution.
- This is naturally a Postorder DFS because the
  current node needs the heights/results of both
  subtrees before it can determine its own result.
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
    int height(TreeNode* p)
    {
        int l,r;
        if(p==NULL)
        {
            return 0;
        }
        l=height(p->left);
        r=height(p->right);
        if(l==-1||r==-1)
        {
            return -1;
        }
        if(abs(l-r)>1)
        {
            return -1;
        }
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        return (height(root)!=-1);
    }
};