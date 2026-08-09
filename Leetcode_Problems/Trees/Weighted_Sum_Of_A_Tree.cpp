/*
Problem: Weighted Sum Of A Tree (Weekly Contest 514, Problem 2)
Pattern: Tree DFS + Depth
Difficulty: Medium

Time Complexity: O(n)
(Each node is visited once during DFS and once
while calculating the final weighted sum.)

Space Complexity: O(n)
(The child adjacency list, depth array, and
recursion stack require O(n) space.)

Key Idea:
- The parent array describes the tree.
- Convert the parent array into a child adjacency
  list so that each node stores its children.
- Run DFS from the root to calculate the depth
  of every node.
- Find the maximum depth of the tree.
- For every node, its contribution is:
    nums[i] * (h-depth[i]+1)
- Add all contributions to get the weighted sum.

Building the Tree:

child.resize(n);

for(i=1;i<n;i++)
{
    child[parent[i]].push_back(i);
}

- parent[i] gives the parent of node i.
- Add node i to the parent's list of children.
- Node 0 is the root, so we start from i=1.

DFS:

void dfs(int node,int d)
{
    depth[node]=d;

    for(int x:child[node])
    {
        dfs(x,d+1);
    }
}

- Store the current depth of each node.
- Recursively visit every child.
- Each child is one level deeper than its parent.

Finding Maximum Depth:

for(i=0;i<n;i++)
{
    if(depth[i]>h)
    {
        h=depth[i];
    }
}

- h stores the maximum depth in the tree.
- This represents the depth of the deepest node.

Calculating the Weighted Sum:

ans=ans+nums[i]*1LL*(h-depth[i]+1);

- h-depth[i]+1 gives the number of levels
  remaining from node i to the maximum depth.
- Multiply this value by nums[i] to get the
  contribution of node i.
- 1LL ensures the multiplication is performed
  using long long arithmetic.

Important Notes:
- The parent array is converted into a child
  adjacency list before DFS.
- Depth starts from 1 because dfs(0,1) is called
  for the root.
- The root has depth 1.
- Every child gets depth d+1.
- long long is used for ans because the weighted
  sum can exceed the range of int.
- This is a DFS-based tree problem.
*/

class Solution {
public:
    vector<vector<int>> child;
    vector<int> depth;
    void dfs(int node, int d)
    {
        depth[node]=d;
        for(int x:child[node])
        {
            dfs(x,d+1);
        }
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n,i,h;
        long long ans;
        n=nums.size();
        ans=h=0;
        child.resize(n);
        depth.resize(n);
        for(i=1;i<n;i++)
        {
            child[parent[i]].push_back(i);
        }
        dfs(0,1);
        for(i=0;i<n;i++)
        {
            if(depth[i]>h)
            {
                h=depth[i];
            }
        }
        for(i=0;i<n;i++)
        {
            ans=ans+nums[i]*1LL*(h-depth[i]+1);
        }
        return ans;
    }
};

