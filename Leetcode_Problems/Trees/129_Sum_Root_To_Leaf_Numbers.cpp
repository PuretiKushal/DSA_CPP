/*
Problem: 129. Sum Root to Leaf Numbers
Pattern: DFS (Depth-First Search)
Difficulty: Medium

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(h)
- `h` is the height of the tree.
- Recursive DFS uses O(h) call-stack space.
- No path vector is needed.

Key Idea:
- Every root-to-leaf path represents a number.
- Instead of storing the entire path and converting it later,
  build the number while doing DFS.
- For every node:
      num = num*10 + p->val
- When a leaf is reached, add the completed number to `ans`.

Example:

        1
       / \
      2   3

Starting with num = 0:

At 1:
    num = 0*10 + 1 = 1

At 2:
    num = 1*10 + 2 = 12

At 3:
    num = 1*10 + 3 = 13

Answer:
    12 + 13 = 25


Variables:

ans
- Stores the sum of all root-to-leaf numbers.
- Initialized to 0.

num
- Stores the number formed along the current path.
- It is passed to the next recursive call.

p
- Current tree node.


Base Case:

if(p==NULL)
{
    return;
}

- Nothing to process when there is no node.


Building the Number:

num=num*10+p->val;

- Appends the current node's digit to the number.
- Example:
      12 → next node 3 → 123


Checking for a Leaf:

if(p->left==NULL&&p->right==NULL)
{
    ans=ans+num;
}

- A leaf means the root-to-leaf number is complete.
- Add that number to the final answer.


DFS:

if(p->left!=NULL)
{
    sum(p->left,num);
}

if(p->right!=NULL)
{
    sum(p->right,num);
}

- Explore both branches independently.
- `num` is passed to each branch separately.


Initialization:

ans=0;
sum(root,0);

- Start with no number formed yet.
- The first node then creates the first digit.


Important Notes:

- Unlike LeetCode 113, we don't need a `path` vector.
- We don't need `push_back()` or `pop_back()`.
- We don't need backtracking because `num` is passed by value.
- Each recursive call gets its own copy of `num`.

Core Pattern:

    enter node
        ↓
    num=num*10+p->val
        ↓
    leaf?
      ↓ yes
    add num to ans
        ↓
    DFS left + right

Important new idea learned:
    num = num*10 + p->val

This lets us construct the root-to-leaf number
directly during DFS instead of storing the path first.
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
    int ans;
    void sum(TreeNode* p, int num)
    {
        if(p==NULL)
        {
            return;
        }
        num=num*10+p->val;
        if(p->left==NULL&&p->right==NULL)
        {
            ans=ans+num;
        }
        if(p->left!=NULL)
        {
            sum(p->left,num);
        }
        if(p->right!=NULL)
        {
            sum(p->right,num);
        }
    }
    int sumNumbers(TreeNode* root) {
        ans=0;
        sum(root,0);
        return ans;
        
    }
};