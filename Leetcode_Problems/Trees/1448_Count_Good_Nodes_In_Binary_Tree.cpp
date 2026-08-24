/*
Problem: 1448. Count Good Nodes in Binary Tree
Pattern: DFS + Carrying State Down
Difficulty: Medium

Time Complexity: O(n)
- Every node is visited once.

Space Complexity: O(h)
- Recursive call stack depends on the height of the tree.

Key Idea:
- A node is good if its value is greater than or equal to
  the maximum value seen on the path from the root to that node.
- We carry the maximum value seen so far as a parameter.

DFS State:

void dfs(TreeNode* p,int mx)

p  → current node
mx → maximum value seen so far on the current path

At every node:

if(p->val>=mx)
{
    mx=p->val;
    count++;
}

Then pass the updated mx to both children:

dfs(p->left,mx);
dfs(p->right,mx);

Important:
- `mx` is a PARAMETER, so information travels DOWN
  from parent to child.
- The child does not need to return mx to the parent because
  the parent already knows the maximum seen so far.

Why `void`?
- The parent does not need any value back from the child.
- The DFS directly updates the shared `count`.

Parameter vs Return:

Parameter:
Parent → Child
Used to give information to the recursive call.

Return:
Child → Parent
Used when the parent needs information back.

Comparison with 543:

543:
- Child calculates height.
- Height must go back to parent.
- Therefore `int dfs()`.

1448:
- Parent gives maximum value to child.
- Nothing needs to come back.
- Therefore `void dfs(TreeNode*,int)`.

Important DFS Pattern:

Information going DOWN:
→ use parameters

Information coming UP:
→ use return value

Shared/final answer:
→ can be maintained using a class variable such as `count`.

Base Case:

if(p==NULL)
{
    return;
}

Root starts the maximum:

dfs(root,root->val);

Core Idea:
- Carry the maximum value seen so far down the path.
- Check the current node against it.
- Update the maximum if necessary.
- Continue DFS on both children.
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
    int count;
    void dfs(TreeNode* p, int mx)
    {
        if(p==NULL)
        {
            return;
        }
        if(p->val>=mx)
        {
            mx=p->val;
            count++;
        }
        dfs(p->left,mx);
        dfs(p->right,mx);
    }
    int goodNodes(TreeNode* root) {
        count=0;
        dfs(root,root->val);
        return count;
    }
};