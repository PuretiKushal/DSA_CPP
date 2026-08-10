/*
Problem: 572. Subtree of Another Tree
Pattern: Tree Recursion (DFS + Searching + Same Tree)
Difficulty: Easy

Time Complexity: O(n*m)
(For every node in the main tree, we may compare
the subtree rooted at that node with subRoot.
In the worst case, each comparison can take O(m),
where n = number of nodes in root and
m = number of nodes in subRoot.)

Space Complexity: O(n+m)
(Due to the recursion call stacks of search() and
check().
In the worst case, the tree can be skewed, giving
O(n) recursion depth.
The second tree can also contribute O(m) recursion
depth during check().)

Key Idea:
- We need to determine whether subRoot appears
  as an entire subtree inside root.
- The problem can be divided into two separate jobs:
    1. Search for possible starting nodes in root.
    2. Check whether the trees rooted at the candidate
       node and subRoot are exactly the same.
- The search() helper finds candidate nodes.
- The check() helper performs the Same Tree comparison
  learned in Problem 100.

Helper Function 1:

bool search(TreeNode* p,TreeNode* q)

- p represents the current node while searching
  through the main tree.
- q represents the root of subRoot.
- If the current values do not match, continue
  searching through both children.
- If the values match, check whether the complete
  subtrees are identical.

Base Cases:

if(p==NULL&&q==NULL)
{
    return true;
}

if(p==NULL||q==NULL)
{
    return false;
}

- These prevent accessing a NULL pointer.
- In practice, q is the subtree root being searched
  for, while p moves through root.

Searching:

if(p->val!=q->val)
{
    return search(p->left,q)||search(p->right,q);
}

- If the current values don't match, p cannot be
  the starting point of subRoot.
- Continue searching in both the left and right
  subtrees.
- OR is used because the subtree only needs to be
  found in one location.

Matching Candidate:

if(p->val==q->val)
{
    if(check(p,q))
    {
        return true;
    }

    return search(p->left,q)||search(p->right,q);
}

- Equal values only indicate a possible match.
- They do not guarantee that the entire subtree
  is identical.
- First use check() to compare the complete trees.
- If check() succeeds, the subtree has been found.
- If check() fails, continue searching for another
  possible occurrence.

Helper Function 2:

bool check(TreeNode* p,TreeNode* q)

- This is the same tree comparison logic used in
  Problem 100.
- It checks whether the two trees rooted at p and q
  are structurally and value-wise identical.

Base Case:

if(p==NULL&&q==NULL)
{
    return true;
}

if(p==NULL||q==NULL)
{
    return false;
}

- Both NULL means the corresponding parts of the
  trees are identical.
- Only one NULL means the structures are different.

Value Check:

if(p->val!=q->val)
{
    return false;
}

- Different values mean the trees cannot be identical.

Recursive Case:

return check(p->left,q->left)&&check(p->right,q->right);

- Compare corresponding left children.
- Compare corresponding right children.
- Both sides must match, so && is used.

Important Notes:
- Matching root values are only a candidate match.
- A failed candidate comparison must not stop the
  search because another node with the same value
  may contain the actual subRoot.
- search() and check() have different responsibilities:
    search() → find where subRoot might occur.
    check() → verify whether two trees are identical.
- This problem combines the tree-search idea with
  the Same Tree recursion pattern.
- The recursive calls in search() traverse the entire
  main tree when necessary.
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
    bool search(TreeNode* p, TreeNode* q)
    {
        if(p==NULL&&q==NULL)
        {
            return true;
        }
        if(p==NULL||q==NULL)
        {
            return false;
        }
        if(p->val!=q->val)
        {
            return search(p->left,q)||search(p->right,q);
        }
        if(p->val==q->val)
        {
            if(check(p,q))
            {
                return check(p,q);
            }
            return search(p->left,q)||search(p->right,q);
        }
        return false;
    }
    bool check(TreeNode* p, TreeNode* q)
    {
        if(p==NULL&&q==NULL)
        {
            return true;
        }
        if(p==NULL||q==NULL)
        {
            return false;
        }
        if(p->val!=q->val)
        {
            return false;
        }
        if(p->val==q->val)
        {
            return check(p->left,q->left)&&check(p->right,q->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return search(root,subRoot);
    }
};