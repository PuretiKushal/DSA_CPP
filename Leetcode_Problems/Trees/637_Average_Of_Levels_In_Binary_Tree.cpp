/*
Problem: 637. Average of Levels in Binary Tree
Pattern: BFS (Breadth-First Search) / Queue
Difficulty: Easy

Time Complexity: O(n)
(Every node is pushed into and removed from the queue once.)

Space Complexity: O(n)
(The queue can contain O(n) nodes in the worst case.)

Key Idea:
- Use BFS to process the tree level by level.
- For every level, calculate the sum of all node values.
- Divide the sum by the number of nodes in that level.
- Store the average in the answer vector.

Variables:

ans
- Stores the average of every level.

q
- Queue used for BFS.
- Stores nodes waiting to be processed.

n
- Number of nodes in the current level.

sum
- Stores the sum of values of the current level.

Initialization:

q.push(root);

- Start BFS with the root node.

Level Processing:

while(!q.empty())
{
    n=q.size();
    sum=0;

    for(i=0;i<n;i++)
    {
        ...
    }

    ans.push_back(sum/n);
}

- n tells us how many nodes belong to the current level.
- sum is reset to 0 for every new level.
- The for loop processes exactly n nodes.

Processing a Node:

TreeNode* p=q.front();
q.pop();

- Take the first node from the queue.

sum=sum+p->val;

- Add its value to the current level's sum.

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
- They will be processed during the next level.

Calculating Average:

ans.push_back(sum/n);

- sum contains the total value of the current level.
- n contains the number of nodes in that level.
- Their division gives the average.
- Since sum is double, the division produces a decimal
  result.

Example:

        3
       / \
      9   20
         /  \
        15   7

Level 1:
sum = 3
n = 1
average = 3

Level 2:
sum = 9+20 = 29
n = 2
average = 14.5

Level 3:
sum = 15+7 = 22
n = 2
average = 11

Answer:

[3,14.5,11]

Important Notes:
- This problem uses exactly the same BFS structure as 102.
- The only change is what we do with each level.
- 102 → store every value.
- 199 → store the last value.
- 637 → calculate sum / count.
- n=q.size() remains the key trick that lets us separate
  the levels.
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
    vector<double> averageOfLevels(TreeNode* root) {
        int n,i;
        double sum;
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            n=q.size();
            sum=0;
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
                sum=sum+p->val;
            }
            ans.push_back(sum/n);
        }
        return ans;
    }
};