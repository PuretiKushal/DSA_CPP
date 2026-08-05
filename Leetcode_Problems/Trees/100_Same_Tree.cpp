/*
Problem: 100. Same Tree
Pattern: Tree Recursion (Postorder DFS)
Difficulty: Easy

Time Complexity: O(n)
(Each corresponding pair of nodes from both trees
 is visited exactly once.)

Space Complexity: O(h)
(Due to the recursion call stack.
 h = Height of the tree.

 Worst Case (Skewed Tree): O(n)
 Balanced Tree: O(log n))

Key Idea:
- Two trees are identical if:
    1. Their current node values are equal.
    2. Their left subtrees are identical.
    3. Their right subtrees are identical.
- Recursively compare the left and right subtrees.
- Return true only if all three conditions are satisfied.

Base Cases:

if(p==NULL && q==NULL)
{
    return true;
}

- Both trees ended at the same position.
- So they are identical up to this point.

if(p==NULL || q==NULL)
{
    return false;
}

- One tree has a node while the other does not.
- Therefore, the trees cannot be identical.

Current Work:

bool l=isSameTree(p->left,q->left);

bool r=isSameTree(p->right,q->right);

- Recursively compare the left subtrees.
- Recursively compare the right subtrees.

Recursive Case:

return (p->val==q->val) && l && r;

- Current node values must be equal.
- Left subtrees must be identical.
- Right subtrees must be identical.
- Return true only if all three conditions are true.

Important Notes:
- This is a Postorder DFS because the current node's
  final answer depends on the results of both
  left and right subtree comparisons.
- The recursion immediately stops whenever the
  tree structures differ or node values are different.
- This problem introduces the boolean-returning
  recursion pattern used in many tree problems.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool l,r;
        if(p==NULL&&q==NULL)
        {
            return true;
        }
        if(p==NULL||q==NULL)
        {
            return false;
        }
        l=isSameTree(p->left,q->left);
        r=isSameTree(p->right,q->right);
        return ((p->val==q->val)&&l&&r);
    }
};