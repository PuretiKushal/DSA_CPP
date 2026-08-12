/*
Problem: 102. Binary Tree Level Order Traversal
Pattern: BFS (Breadth-First Search) / Queue
Difficulty: Medium

Time Complexity: O(n)
(Every node is pushed into and removed from the queue once.)

Space Complexity: O(n)
(The queue and the answer can contain O(n) nodes/values.)

Key Idea:
- Level order traversal visits the tree level by level.
- BFS uses a queue because it follows FIFO order.
- At the beginning of each level, q.size() tells us
  how many nodes belong to that level.
- Store those nodes in a temporary vector.
- After processing the complete level, add that vector
  to the final answer.

Variables:

ans
- Stores all levels of the tree.
- Each inner vector represents one level.

q
- Queue of TreeNode pointers.
- Stores nodes waiting to be processed.

n
- Number of nodes present in the queue at the beginning
  of the current level.

temp
- Stores the values of the current level.

Base Case:

if(root==NULL)
{
    return ans;
}

- If the tree is empty, return an empty answer.

Initialization:

q.push(root);

- The root is the first node we need to process.

BFS:

while(!q.empty())
{
    n=q.size();
    vector<int> temp;

    for(i=0;i<n;i++)
    {
        ...
    }

    ans.push_back(temp);
}

- q.empty() tells us whether there are more nodes to process.
- n=q.size() captures the number of nodes in the
  current level.
- The for loop processes exactly those n nodes.
- Children added during this loop belong to the next level.
- After the loop finishes, temp contains the complete
  current level.

Processing a Node:

TreeNode* p=q.front();
q.pop();

- Take the first waiting node from the queue.
- Remove it from the queue.

temp.push_back(p->val);

- Store the current node's value in the current level.

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

Example:

        3
       / \
      9   20
         /  \
        15   7

Start:
q = [3]

Level 1:
n = 1
temp = [3]

After processing 3:
q = [9,20]

ans = [[3]]

Level 2:
n = 2
temp = [9,20]

After processing 9 and 20:
q = [15,7]

ans = [[3],[9,20]]

Level 3:
n = 2
temp = [15,7]

Final:
ans = [[3],[9,20],[15,7]]

Important Notes:
- The key trick is n=q.size().
- Without n, we could still perform BFS, but we would
  not know where one level ends and the next begins.
- q handles the traversal.
- temp handles the current level.
- ans handles all levels.
- Unlike DFS, no recursive helper function is required.
  The queue + while loop performs the traversal.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n,i;
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            n=q.size();
            vector<int> temp;
            for(i=0;i<n;i++)
            {
                TreeNode* p=q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->left!=NULL)
                {
                    q.push(p->left);
                }
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
            }
            ans.push_back(temp);
        }
    return ans;      
    }
};