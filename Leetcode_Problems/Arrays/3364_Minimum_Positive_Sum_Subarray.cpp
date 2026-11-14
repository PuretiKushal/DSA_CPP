/*
Problem: 3364. Minimum Positive Sum Subarray
Pattern: Brute Force + Nested Loops
Difficulty: Easy

Time Complexity: O(n^2)
- Uses two nested loops to generate all possible subarrays.
- Maintains the subarray sum incrementally in each iteration.

Space Complexity: O(1)
- Uses only a constant number of variables.

Key Idea:
- Fix the starting index i of the subarray.
- Extend the subarray using the second loop with index j.
- Maintain the current subarray sum using sum.
- Check whether the subarray length is between l and r (inclusive).
- If the sum is positive, update ans with the minimum sum found.
- If no valid positive-sum subarray exists, return -1.
*/

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n,i,j,sum,ans=INT_MAX;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=i;j<n;j++)
            {
                sum+=nums[j];
                if(j-i+1>=l&&j-i+1<=r&&sum>0)
                {
                    ans=min(ans,sum);
                }
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};