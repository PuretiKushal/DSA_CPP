/*
Problem: 453. Minimum Moves to Equal Array Elements
Pattern: Array + Mathematics
Difficulty: Medium

Time Complexity: O(n)
- First traversal finds the minimum element.
- Second traversal calculates the total difference from the minimum.

Space Complexity: O(1)
- Uses only a constant number of variables.

Key Idea:
- Incrementing exactly n-1 elements by 1 is equivalent to decrementing one element by 1.
- To minimize operations, consider the minimum element as the target value.
- Calculate the difference between every element and the minimum.
- Sum all differences to get the minimum number of operations.
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n,i,mn,ans=0;
        n=nums.size();
        mn=nums[0];
        for(i=1;i<n;i++)
        {
            mn=min(mn,nums[i]);
        }
        for(i=0;i<n;i++)
        {
            ans=ans+nums[i]-mn;
        }
        return ans;
    }
};