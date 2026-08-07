/*
Problem: 404. Sum of Left Leaves
Pattern: Tree Recursion (Postorder DFS)
Difficulty: Easy

Time Complexity: O(n)
(Each node is visited exactly once.
 Every node checks whether its left child
 is a leaf.)

Space Complexity: O(h)
(Due to the recursion call stack.
 h = Height of the tree.

 Worst Case (Skewed Tree): O(n)
 Balanced Tree: O(log n))

Key Idea:
- A node itself does not know whether it is a
  left or right child.
- Therefore, the parent checks whether its
  left child is a leaf.
- If the left child is a leaf, add its value.
- Recursively solve both left and right
  subtrees and combine their answers.

Base Case:

if(p==NULL)
{
    return 0;
}

- An empty subtree contributes 0 to the sum.
- This stops the recursion.

Current Work:

int s=0;

if(p->left!=NULL &&
   p->left->left==NULL &&
   p->left->right==NULL)
{
    s=p->left->val;
}

- Check whether the current node's left child
  exists and is a leaf.
- If yes, add its value to the current answer.

Recursive Case:

return s+sum(p->left)+sum(p->right);

- Continue searching both subtrees.
- Return the current contribution plus the
  answers from the left and right subtrees.

Important Notes:
- This is a Postorder DFS because the final
  answer for the current subtree depends on
  the answers returned by both child subtrees.
- A leaf is a node with no left and right
  children.
- A node cannot determine whether it is a
  left child or a right child.
- Only the parent can identify whether its
  left child is a left leaf.
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
    int sum(TreeNode* p)
    {
        int s=0;
        if(p==NULL)
        {
            return 0;
        }
        if(p->left!=NULL&&p->left->left==NULL&&p->left->right==NULL)
        {
            s=p->left->val;
        }
        return s+sum(p->left)+sum(p->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        return sum(root);
    }
};