/*
Problem: 101. Symmetric Tree
Pattern: Tree Recursion (Mirror Comparison)
Difficulty: Easy

Time Complexity: O(n)
(Each node is visited exactly once.
 Corresponding nodes from the left and right
 subtrees are compared recursively.)

Space Complexity: O(h)
(Due to the recursion call stack.
 h = Height of the tree.

 Worst Case (Skewed Tree): O(n)
 Balanced Tree: O(log n))

Key Idea:
- A tree is symmetric if its left and right
  subtrees are mirror images of each other.
- Two nodes are mirrors if:
    1. Their values are equal.
    2. Left subtree of one matches the right
       subtree of the other.
    3. Right subtree of one matches the left
       subtree of the other.

Base Cases:

if(p==NULL && q==NULL)
{
    return true;
}

- Both subtrees ended at the same position.
- They are mirror images up to this point.

if(p==NULL || q==NULL)
{
    return false;
}

- One subtree has a node while the other does not.
- Therefore, they cannot be mirrors.

if(p->val!=q->val)
{
    return false;
}

- Current node values are different.
- The subtrees cannot be mirror images.

Current Work:

bool l=check(p->left,q->right);

bool r=check(p->right,q->left);

- Compare the left subtree of one tree with
  the right subtree of the other.
- Compare the right subtree of one tree with
  the left subtree of the other.

Recursive Case:

return l&&r;

- Both mirror comparisons must be true.
- If either comparison fails, the tree is not
  symmetric.

Important Notes:
- This is a Postorder DFS because the answer
  for the current nodes depends on the results
  of both recursive calls.
- Unlike Same Tree, the recursive calls are
  made in a mirror fashion:
    left ↔ right
    right ↔ left
- An empty tree is considered symmetric.
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
    bool check(TreeNode* p, TreeNode* q)
    {
        if(p==NULL&&q==NULL)
        {
            return true;
        }
        if(p==NULL||q==NULL)
        {
            return false;
        }
        if(p->val!=q->val)
        {
            return false;
        }
        bool l=check(p->left,q->right);
        bool r=check(p->right,q->left);
        return l&&r;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        return check(root->left,root->right);
    }
};