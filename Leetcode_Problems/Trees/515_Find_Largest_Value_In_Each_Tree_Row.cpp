/*
Problem: 515. Find Largest Value in Each Tree Row
Pattern: BFS (Breadth-First Search) / Queue
Difficulty: Medium

Time Complexity: O(n)
(Every node is processed exactly once.)

Space Complexity: O(n)
(The queue can contain O(n) nodes in the worst case.)

Key Idea:
- Use BFS to process the tree level by level.
- For every level, find the maximum value among
  all nodes in that level.
- Store that maximum in ans.

Variables:

ans
- Stores the maximum value from each level.

q
- Queue used for BFS.
- Stores nodes waiting to be processed.

n
- Number of nodes in the current level.

mx
- Stores the maximum value of the current level.

Base Case:

if(root==NULL)
{
    return ans;
}

- If the tree is empty, return an empty vector.

Initialization:

q.push(root);

- Start BFS with the root.

Level Processing:

while(!q.empty())
{
    n=q.size();
    mx=INT_MIN;

    for(i=0;i<n;i++)
    {
        ...
    }

    ans.push_back(mx);
}

- n tells us exactly how many nodes belong to
  the current level.
- mx is reset for every new level.
- After processing all n nodes, mx contains the
  largest value from that level.

Processing a Node:

TreeNode* p=q.front();
q.pop();

- Take the next node from the queue.

mx=max(mx,p->val);

- Compare the current node's value with the
  maximum found so far.
- Since the loop processes only the n nodes from
  this level, mx represents the maximum of that level.

Adding Children:

if(p->left!=NULL)
{
    q.push(p->left);
}

if(p->right!=NULL)
{
    q.push(p->right);
}

- Add both children to the queue.
- They will be processed in the next level.

Important:
- Using INT_MIN instead of 0 is important because
  node values can be negative.

Example:

        1
       / \
      3   2
     / \   \
    5   3   9

Level 1:
[1]
mx = 1

Level 2:
[3,2]
mx = 3

Level 3:
[5,3,9]
mx = 9

Answer:

[1,3,9]

BFS Pattern:

102:
    process level → store ALL values

199:
    process level → store LAST value

637:
    process level → calculate AVERAGE

515:
    process level → find MAXIMUM

The important part is that the BFS skeleton stays
the same. Only what we calculate while processing
the current level changes.
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
    vector<int> largestValues(TreeNode* root) {
        int n,i,mx;
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL)
        {
            return ans;
        }
        q.push(root);
        while(!q.empty())
        {
            n=q.size();
            mx=INT_MIN;
            for(i=0;i<n;i++)
            {
                TreeNode* p=q.front();
                q.pop();
                mx=max(mx,p->val);
                if(p->left!=NULL)
                {
                    q.push(p->left);
                }
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
            }
            ans.push_back(mx);
        }
        return ans;
    }
};