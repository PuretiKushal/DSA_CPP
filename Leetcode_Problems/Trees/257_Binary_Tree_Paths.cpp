/*
Problem: 257. Binary Tree Paths
Pattern: Tree Recursion (DFS + Passing Information Downward)
Difficulty: Easy

Time Complexity: O(n)
(Every node is visited once.
 Building and storing the path strings also
 contributes to the overall work.)

Space Complexity: O(h)
(Due to the recursion call stack.
 The current path string also requires space.

 h = Height of the tree.

 Worst Case (Skewed Tree): O(n)
 Balanced Tree: O(log n)

 Note:
 The output vector itself requires additional
 space to store all root-to-leaf paths.)

Key Idea:
- We need to find every root-to-leaf path.
- Carry the current path as a string while
  recursively moving downward through the tree.
- Whenever a leaf is reached, add the complete
  path to the answer vector.
- Each recursive call receives its own updated
  string, so no manual backtracking is required.

Helper Function:

void returnPath(TreeNode* p,string s)

- p represents the current node.
- s represents the path from the root to the
  current node.
- The helper returns void because it does not
  need to send a result back to its parent.
- Instead, completed paths are directly stored
  in the common ans vector.

Base Case:

if(p==NULL)
{
    return;
}

- Stop when there is no node.
- This also prevents accessing p->val when p is NULL.

Building the Path:

if(s=="")
{
    s=to_string(p->val);
}
else
{
    s=s+"->"+to_string(p->val);
}

- For the root, start the path with its value.
- For every other node, append "->" followed
  by the node's value.

Leaf Check:

if(p->right==NULL&&p->left==NULL)
{
    ans.push_back(s);
}

- A leaf has no left or right child.
- Once a leaf is reached, the current string
  represents a complete root-to-leaf path.
- Store it in ans.

Recursive Case:

returnPath(p->left,s);
returnPath(p->right,s);

- Visit the left subtree.
- After the left subtree is completely explored,
  return to the current node and explore the
  right subtree.
- Both recursive calls are needed because we need
  every root-to-leaf path.
- No return value is needed because the answer is
  being built directly inside ans.

Important Notes:
- This problem uses DFS recursion.
- Information is passed downward:
    current path → child
- Unlike Path Sum, the helper does not return
  bool/int information to the parent.
- The function returns void because its purpose is
  to traverse the tree and add completed paths
  directly to ans.
- No pop_back() is needed because each recursive
  call receives its own string value.
- ans is a class variable so every recursive call
  contributes to the same final answer.
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
    vector<string> ans;
    string s;
    void returnPath(TreeNode* p, string s)
    {
        if(p==NULL)
        {
            return;
        }
        if(s=="")
        {
            s=to_string(p->val);
        }
        else
        {
            s=s+"->"+to_string(p->val);
        }
        if(p->right==NULL&&p->left==NULL)
        {
            ans.push_back(s);
        }
        returnPath(p->left,s);
        returnPath(p->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        returnPath(root,"");
        return ans;
    }
};