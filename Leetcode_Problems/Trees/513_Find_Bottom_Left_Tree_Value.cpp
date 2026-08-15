/*
Problem: 513. Find Bottom Left Tree Value
Pattern: BFS (Breadth-First Search) / Queue
Difficulty: Medium

Time Complexity: O(n)
(Every node is processed exactly once.)

Space Complexity: O(n)
(The queue can contain O(n) nodes in the worst case.)

Key Idea:
- Use BFS to process the tree level by level.
- At every level, the first node processed is the
  leftmost node of that level.
- Since BFS processes levels from top to bottom, the
  first node of the LAST level is the bottom-left value.
- Therefore, whenever i==0, store p->val in mx.
- Later levels overwrite the previous value, so after
  BFS finishes, mx contains the bottom-left value.

Variables:

q
- Queue used for BFS.

n
- Number of nodes in the current level.

i
- Used to identify the position of a node within
  the current level.

mx
- Stores the leftmost value of the current level.
- Because every new level overwrites it, the final
  value is the leftmost value of the bottom level.

Traversal:

while(!q.empty())
{
    n=q.size();

    for(i=0;i<n;i++)
    {
        ...
    }
}

- n separates the current level from the next level.

Identifying the Leftmost Node:

if(i==0)
{
    mx=p->val;
}

- i==0 means this is the first node processed in
  the current level.
- Because BFS processes nodes from left to right,
  this is the leftmost node of that level.

Example:

        2
       / \
      1   3
         / \
        4   5
       /
      6

Level 1:
[2]
i==0 → mx=2

Level 2:
[1,3]
i==0 → mx=1

Level 3:
[4,5]
i==0 → mx=4

Level 4:
[6]
i==0 → mx=6

Final:
mx = 6

Important Notes:
- You don't need to explicitly track the level number.
- You don't need an answer vector because only one value
  is required.
- The key observation is:

    BFS
    ↓
    first node of each level = leftmost node
    ↓
    last level processed = bottom level
    ↓
    last leftmost node = answer

- This is another variation of the same BFS pattern:
    102  → entire level
    199  → last node of level
    637  → average of level
    515  → maximum of level
    1161 → maximum sum of level
    513  → first node of final level
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
    int findBottomLeftValue(TreeNode* root) {
        int n,i,mx;
        queue<TreeNode*> q;
        q.push(root);
        mx=INT_MIN;
        while(!q.empty())
        {
            n=q.size();
            for(i=0;i<n;i++)
            {
                TreeNode* p=q.front();
                q.pop();
                if(p->left!=NULL)
                {
                    q.push(p->left);
                }
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
                if(i==0)
                {
                    mx=p->val;
                }
            }
        }
        return mx;
    }
};