/*
Problem: 112. Path Sum
Pattern: Tree Recursion (DFS + Passing Information Downward)
Difficulty: Easy

Time Complexity: O(n)
(In the worst case, every node is visited once.)

Space Complexity: O(h)
(Due to the recursion call stack.
 h = Height of the tree.

 Worst Case (Skewed Tree): O(n)
 Balanced Tree: O(log n))

Key Idea:
- We need to determine whether there exists a
  root-to-leaf path whose values add up to targetSum.
- Instead of calculating information from the
  children and returning it upward, we pass the
  remaining target downward.
- At every node, subtract its value from the
  remaining target.
- A valid path is found only when the remaining
  target becomes 0 at a leaf node.

Helper Function:

bool check(TreeNode* p,int t)

- p represents the current node.
- t represents the remaining target sum.
- The helper is used because recursion needs to
  carry the additional information t.

Base Case:

if(p==NULL)
{
    return false;
}

- There is no path through a NULL node.
- This also prevents accessing p->val when p is NULL.

Leaf Check:

if(t-(p->val)==0&&p->left==NULL&&p->right==NULL)
{
    return true;
}

- Subtract the current node's value from the
  remaining target.
- If the result is 0 and the current node is a
  leaf, a valid root-to-leaf path has been found.

Current Work:

t=t-p->val;

- Include the current node's value in the path.
- The remaining target is passed to the children.

Recursive Case:

return check(p->left,t)||check(p->right,t);

- Recursively check both subtrees.
- OR is used because only one valid root-to-leaf
  path is required.
- If either subtree contains a valid path,
  return true.

Important Notes:
- The path must start at the root and end at a leaf.
- Reaching a target sum of 0 at a non-leaf node
  is not enough because the path must end at a leaf.
- Information is passed downward:
    remaining target → child
- The helper returns a boolean because the parent
  needs to know whether a valid path exists.
- Both recursive calls still traverse the tree;
  the OR operator combines their boolean results.
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
    bool check(TreeNode* p, int t)
    {
        if(p==NULL)
        {
            return false;
        }
        if(t-(p->val)==0&&p->left==NULL&&p->right==NULL)
        {
            return true;
        }
        t=t-p->val;
        return check(p->left,t)||check(p->right,t);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return false;
        }
        return check(root,targetSum);
    }
};