/*
Problem: 113. Path Sum II
Pattern: DFS (Depth-First Search) + Backtracking
Difficulty: Medium

Time Complexity: O(n * h)
- Every node is visited once.
- When a valid path is found, copying the path into ans
  can take O(h), where h is the tree height.
- Therefore, overall complexity is O(n*h) in the worst case.

Space Complexity: O(h)
- path can contain at most h nodes.
- Recursive DFS uses O(h) call-stack space.
- ans is not included in auxiliary space because it is
  the required output.

Key Idea:
- Use DFS to explore every root-to-leaf path.
- Keep the current path in the vector `path`.
- Keep the remaining target in `target`.
- When entering a node:
    1. Add its value to path.
    2. Subtract its value from target.
- If the node is a leaf and target becomes 0,
  the current path is a valid answer.
- Explore both left and right children.
- After finishing both branches, remove the current
  node from path using pop_back().
- This last step is BACKTRACKING.

Variables:

path
- Stores the current root-to-current-node path.

ans
- Stores every valid root-to-leaf path.

target
- Stores the remaining sum required.
- It is passed by value, so every recursive call gets
  its own copy.

Base Case:

if(p==NULL)
{
    return;
}

- If there is no node, there is nothing to explore.

Adding Current Node:

path.push_back(p->val);

- Add the current node to the current path.

target=target-p->val;

- Remove the current node's value from the remaining
  target.

Checking a Valid Path:

if(p->left==NULL&&p->right==NULL&&target==0)
{
    ans.push_back(path);
}

Two conditions must be satisfied:

1. `p` must be a leaf:
       p->left==NULL&&p->right==NULL

2. The path must have exactly the required sum:
       target==0

Only then is the current path added to ans.

Exploring Children:

if(p->left!=NULL)
{
    dfs(p->left,target);
}

if(p->right!=NULL)
{
    dfs(p->right,target);
}

- Both branches must be explored independently.
- We cannot use `else if` because a node can have both
  a left and a right child.

Backtracking:

path.pop_back();

- After both child branches have been completely explored,
  remove the current node from path.
- This allows the same path vector to be reused when DFS
  goes back and explores another branch.

Example:

        5
       / \
      4   8
     / \
    11  2

Suppose target = 20.

DFS path:

[5]
target = 15

↓ 4

[5,4]
target = 11

↓ 11

[5,4,11]
target = 0

If 11 is a leaf:
→ valid path
→ add [5,4,11] to ans

Then:

path.pop_back()

[5,4]

DFS can now return to the parent and explore another branch.

Important Notes:

- `void` is appropriate for `dfs` because the helper does
  not need to return a value.
- The actual result is stored in the class-level `ans`.
- `path` is also class-level so that the same vector can
  be modified and backtracked throughout DFS.
- `target` is passed into each recursive call because each
  branch has its own remaining target.
- `path.push_back()` = go deeper.
- `path.pop_back()` = come back up.

Core Pattern:

    push current node
            ↓
    subtract from target
            ↓
    check leaf + target == 0
            ↓
        DFS left
            ↓
        DFS right
            ↓
       pop current node

This is your first proper combination of:

DFS + Path Tracking + Backtracking.
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
    vector<int> path;
    vector<vector<int>> ans;
    void dfs(TreeNode* p,int target)
    {
        if(p==NULL)
        {
            return;
        }
        path.push_back(p->val);
        target=target-p->val;
        if(p->left==NULL&&p->right==NULL&&target==0)
        {
            ans.push_back(path);
        }
        if(p->left!=NULL)
        {
            dfs(p->left,target);
        }
        if(p->right!=NULL)
        {
            dfs(p->right,target);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;

    }
};