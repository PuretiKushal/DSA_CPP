/*
Problem: 199. Binary Tree Right Side View
Pattern: BFS (Breadth-First Search) / Queue
Difficulty: Medium

Time Complexity: O(n)
(Every node is pushed into and removed from the queue once.)

Space Complexity: O(n)
(The queue can contain O(n) nodes in the worst case.)

Key Idea:
- Use the same BFS level-order pattern as Problem 102.
- Process the tree level by level using a queue.
- For every level, only store the value of the LAST
  node processed.
- The last node of each level is the node visible from
  the right side.

Initialization:

q.push(root);

- Start BFS with the root node.

Level Processing:

while(!q.empty())
{
    n=q.size();

    for(i=0;i<n;i++)
    {
        ...
    }
}

- n stores the number of nodes in the current level.
- The loop processes exactly those n nodes.

Processing:

TreeNode* p=q.front();
q.pop();

- Take the next node from the queue.

if(p->left!=NULL)
{
    q.push(p->left);
}

if(p->right!=NULL)
{
    q.push(p->right);
}

- Add both children to the queue.
- They belong to the next level.
- We do NOT ignore the left child just because we want
  the right-side view.

Finding the Rightmost Node:

if(i==n-1)
{
    ans.push_back(p->val);
}

- i starts at 0.
- Therefore, the last node of a level has index n-1.
- Only that node is added to ans.

Example:

        1
       / \
      2   3
       \   \
        5   4

Level 1:
[1]
→ last node = 1

Level 2:
[2,3]
→ last node = 3

Level 3:
[5,4]
→ last node = 4

Answer:

[1,3,4]

Important Notes:
- 199 is almost the same BFS pattern as 102.
- In 102:
    Every node → current level vector

- In 199:
    Last node of every level → answer

- The key idea is NOT to push only right children.
- We still push both left and right children so that
  the complete next level is available.
- i==n-1 identifies the rightmost node because BFS is
  processing the current level from left to right.

Pattern:

102:
queue → process level → store whole level

199:
queue → process level → store last node
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
    vector<int> rightSideView(TreeNode* root) {
        int n,i;
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
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
                        if(i==n-1)
                        {
                            ans.push_back(p->val);
                        }
                    }
                
            }
        return ans;
    }
};