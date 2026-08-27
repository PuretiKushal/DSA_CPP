/*
Problem: 617. Merge Two Binary Trees
Pattern: DFS on Two Trees
Difficulty: Easy

Time Complexity: O(n)
- Each corresponding pair of nodes is visited once.
- `n` represents the number of nodes processed across the two trees.

Space Complexity: O(h)
- Due to the recursive call stack.
- `h` is the height of the trees.

Key Idea:
- Traverse both trees at the same time.
- `p` represents the current node of the first tree.
- `q` represents the current node of the second tree.

DFS:

TreeNode* dfs(TreeNode* p,TreeNode* q)

The recursive function works on TWO nodes instead of one.

Base Cases:

if(p==NULL)
{
    return q;
}

If the first tree has no node here, use the node from the second tree.

if(q==NULL)
{
    return p;
}

If the second tree has no node here, use the node from the first tree.

If both nodes exist:

p->val=p->val+q->val;

The merged node contains the sum of both values.

Then merge their corresponding children:

p->left=dfs(p->left,q->left);

p->right=dfs(p->right,q->right);

The result of each recursive call is assigned back to the
corresponding child.

Why return `p`?

The first tree is being modified directly.

After merging:

return p;

returns the root of the merged subtree to the parent.

Important DFS Concept:

Unlike previous problems where DFS operated on one tree:

dfs(p)

Here we need to compare/process two trees simultaneously:

dfs(p,q)

So the recursive state can contain multiple nodes.

Direction of Information:

Child → Parent:
The merged subtree root is returned.

Parent → Child:
The corresponding nodes `p->left/q->left` and
`p->right/q->right` are passed into the recursive calls.

Core Pattern:

        p          q
        ↓          ↓
     current    current
        \          /
         ↓        ↓
       merge them
          ↓
     merge left
          ↓
     merge right
          ↓
      return p

Important:
The trees do not need to be traversed separately.
Corresponding nodes are processed together in the same DFS.
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
    TreeNode* dfs(TreeNode* p,TreeNode* q)
    {
        if(p==NULL)
        {
            return q;
        }
        if(q==NULL)
        {
            return p;
        }
        p->val=p->val+q->val;
        p->left=dfs(p->left,q->left);
        p->right=dfs(p->right,q->right);
        return p;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        return dfs(root1,root2);
    }
};