/*
Problem: 103. Binary Tree Zigzag Level Order Traversal
Pattern: BFS (Breadth-First Search) / Queue
Difficulty: Medium

Time Complexity: O(n)
- Every node is processed once.
- reverse() processes the nodes of each level.
- Across all levels, the total number of elements
  reversed is O(n).

Space Complexity: O(n)
- Queue can contain O(n) nodes.
- ans stores O(n) values.
- temp stores one level.

Key Idea:
- Start with the normal BFS level-order traversal.
- Store every level in temp.
- Alternate the direction of every level.
- Reverse temp for the levels that need to be
  traversed from right to left.

Variables:

ans
- Stores all levels in their required zigzag order.

q
- Queue used for BFS.

n
- Number of nodes in the current level.

l
- Tracks the level number.
- Starts at 1.

temp
- Stores the values of the current level.

BFS:

n=q.size();

- Gives the number of nodes belonging to the current level.

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

- Queue processing remains exactly the same as normal BFS.
- We always push left first and right second.
- The queue itself does NOT need to change for zigzag.

Changing Direction:

l++;

if(l%2!=0)
{
    reverse(temp.begin(),temp.end());
}

- Level 1 should be L→R.
- Level 2 should be R→L.
- Level 3 should be L→R.
- Therefore, reverse every alternate level.

Example:

        3
       / \
      9   20
         /  \
        15   7

Normal BFS gives:

[3]
[9,20]
[15,7]

Zigzag requires:

[3]
[20,9]
[15,7]

So:

Level 1 → don't reverse
Level 2 → reverse
Level 3 → don't reverse

Important Notes:
- This is NOT a new traversal algorithm.
- It is the same BFS pattern you've already learned.
- The only change is what happens to temp after
  processing each level.

BFS progression:

102  → store entire level
199  → store last node
637  → calculate average
515  → find maximum
1161 → calculate level sum
513  → store first node of bottom level
103  → reverse alternate levels

Main takeaway:
The queue/traversal stays the same.
We simply change what we do with the information
collected from each level.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n,i,l;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL)
        {
            return ans;
        }
        q.push(root);
        l=1;
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
            l++;
            if(l%2!=0)
            {
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
        }
    return ans;      
    }
};