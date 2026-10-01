/*
Problem: 198. House Robber
Pattern: Dynamic Programming + 1D DP
Difficulty: Medium

Time Complexity: O(n)
(We iterate through the houses exactly once. For each house, we
perform constant-time max() and addition operations.)

Space Complexity: O(n)
(The dp array stores the maximum amount of money that can be robbed
up to each house.)

Key Idea:
- Define dp[i] as the maximum amount of money that can be robbed from
  houses 0 to i.

- For every house i, there are two choices:
    1. Do not rob house i:
        dp[i] = dp[i-1]

    2. Rob house i:
        We cannot rob the previous house, so:
        dp[i] = dp[i-2] + nums[i]

- Therefore, the recurrence is:
    dp[i] = max(dp[i-1], dp[i-2] + nums[i])

- Initialization:
    dp[0] = nums[0]

    dp[1] = max(nums[0], nums[1])

  For the first two houses, we simply choose the one containing more
  money because adjacent houses cannot both be robbed.

- For every house from index 2:
    - `dp[i-1]` represents skipping the current house.
    - `dp[i-2] + nums[i]` represents robbing the current house.
    - Take the larger of the two.

- Example:
    nums = [2, 7, 9, 3, 1]

    dp[0] = 2
    dp[1] = max(2, 7) = 7
    dp[2] = max(7, 2 + 9) = 11
    dp[3] = max(11, 7 + 3) = 11
    dp[4] = max(11, 11 + 1) = 12

    Answer = 12

- The important DP pattern here is:
    At every position, choose between:
        "Take the current element + best from two positions back"
        OR
        "Skip the current element."

- The final answer is dp[n-1], which represents the maximum amount
  that can be robbed from all n houses.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n,i;
        n=nums.size();
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return nums[0];
        }
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        for(i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};