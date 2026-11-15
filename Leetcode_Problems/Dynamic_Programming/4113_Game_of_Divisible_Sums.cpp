/*
Problem: 4113. Game of Divisible Sums
Pattern: Dynamic Programming, 1D DP
Difficulty: Medium

Time Complexity: O(n)
- Traverse the array once from right to left.
- Calculate each DP state in constant time.

Space Complexity: O(n)
- Use a 1D DP vector of size n + 2.

Key Idea:
- Use dp[i] to store the maximum difference achievable from index i.
- At each index, consider two choices:
  1. Select the current element alone.
  2. Select the current element and the next element, if available.
- If the selected sum is divisible by 3, subtract the remaining DP result.
- Otherwise, add the remaining DP result.
- Store the maximum of the two choices in dp[i].
- Return dp[0] as the final answer.
*/

class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n,i;
        n=nums.size();
        vector<long long> dp(n+2,0);
        long long don,dt;
        for(i=n-1;i>=0;i--)
        {
            don=nums[i];
            if(don%3==0)
            {
               don-=dp[i+1]; 
            }
            else
            {
                don+=dp[i+1];
            }
            dt=LLONG_MIN;
            if(i+1<n)
            {
                dt=nums[i]+nums[i+1];
                if(dt%3==0)
                {
                    dt-=dp[i+2];
                }
                else
                {
                    dt+=dp[i+2];
                }
            }
        dp[i]=max(don,dt);
        }
        return dp[0];
    }
};