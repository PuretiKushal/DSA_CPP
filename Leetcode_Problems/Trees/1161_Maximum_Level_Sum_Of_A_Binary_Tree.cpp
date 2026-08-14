/*
Problem: 1161. Maximum Level Sum of a Binary Tree
Pattern: BFS (Breadth-First Search) / Queue
Difficulty: Medium

Time Complexity: O(n)
(Every node is processed exactly once.)

Space Complexity: O(n)
(The queue can contain O(n) nodes in the worst case.)

Key Idea:
- Use BFS to process the tree level by level.
- For every level, calculate the sum of all node values.
- Keep track of the largest level sum.
- Store the level number that produces that largest sum.

Variables:

q
- Queue used for BFS.
- Stores nodes waiting to be processed.

n
- Number of nodes in the current level.

sum
- Sum of all node values in the current level.

count
- Current level number.
- Starts at 0 and is increased after each level.

mx
- Largest level sum found so far.
- Initialized to INT_MIN so that negative level sums
  are handled correctly.

ans
- Stores the level number having the maximum sum.

BFS Initialization:

q.push(root);

- Put the root into the queue to start BFS.

Note:
- The given implementation assumes root is not NULL,
  which is valid for the problem constraints.

Starting Level:

count=0;

- No level has been processed yet.

Level Processing:

while(!q.empty())
{
    n=q.size();
    sum=0;

    for(i=0;i<n;i++)
    {
        ...
    }

    count++;

    if(sum>mx)
    {
        mx=sum;
        ans=count;
    }
}

- At the beginning of every while iteration, q contains
  exactly the nodes belonging to the current level.
- n=q.size() records how many nodes belong to this level.
- sum is reset to 0 for the new level.
- The for loop processes exactly n nodes.
- After the level is completely processed, count is
  increased to represent its level number.
- sum is then compared with the largest sum found so far.

Processing a Node:

TreeNode* p=q.front();
q.pop();

- Take the first node from the queue and remove it.

sum=sum+p->val;

- Add the current node's value to this level's sum.

Adding Children:

if(p->left!=NULL)
{
    q.push(p->left);
}

if(p->right!=NULL)
{
    q.push(p->right);
}

- Add the children to the queue.
- They will be processed in the next level.

Finding the Maximum Level Sum:

if(sum>mx)
{
    mx=sum;
    ans=count;
}

- If the current level has a larger sum than every
  previous level:
    1. Update mx.
    2. Store the current level number in ans.

Example:

        1
       / \
      7   0
     / \
    7  -8

Level 1:
sum = 1
count = 1
mx = 1
ans = 1

Level 2:
sum = 7
count = 2
mx = 7
ans = 2

Level 3:
sum = -1
count = 3
mx = 7
ans = 2

Final Answer:
2

Important Notes:
- This is the same BFS skeleton used in 102, 199,
  637 and 515.
- The only thing changing is what we calculate for
  each level.
- 102 → store all values.
- 199 → store the last value.
- 637 → calculate average.
- 515 → find maximum value.
- 1161 → calculate level sum and remember which level
  has the maximum sum.
- n=q.size() is what separates one level from the next.
- INT_MIN is important because level sums can be negative.
*//**
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
    int maxLevelSum(TreeNode* root) {
        int n,i,mx,count,ans,sum;
        queue<TreeNode*> q;
        q.push(root);
        count=0;
        mx=INT_MIN;
        while(!q.empty())
        {
            n=q.size();
            sum=0;
            for(i=0;i<n;i++)
            {
                TreeNode* p=q.front();
                q.pop();
                sum=sum+p->val;
                if(p->left!=NULL)
                {
                    q.push(p->left);
                }
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
            }
            count++;
            if(sum>mx)
            {
                mx=sum;
                ans=count;
            }
        }
        
    return ans;      
    }
};