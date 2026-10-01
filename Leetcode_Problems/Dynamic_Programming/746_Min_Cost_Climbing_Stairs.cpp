/*
Problem: 746. Min Cost Climbing Stairs
Pattern: Dynamic Programming + 1D DP
Difficulty: Easy

Time Complexity: O(n)
(We calculate the minimum cost for each step from 2 to n exactly once.
Each state requires only constant-time min() operations.)

Space Complexity: O(n)
(The dp array stores the minimum cost required to reach every step from
0 to n.)

Key Idea:
- Define dp[i] as the minimum cost required to reach step i.

- We can reach step i in two ways:
    1. From step i-2 by taking a 2-step jump.
    2. From step i-1 by taking a 1-step jump.

- Therefore:
    dp[i] = min(dp[i-2] + cost[i-2],
                dp[i-1] + cost[i-1])

- The important point is that cost[i] represents the cost of stepping
  on stair i, while dp[n] represents reaching the top.

- Initialization:
    dp[0] = 0
    dp[1] = min(cost[0], 0) = 0

  We can start from either stair 0 or stair 1 without paying a cost
  before climbing.

- For every step from 2 to n:
    - If we came from i-2, we pay cost[i-2].
    - If we came from i-1, we pay cost[i-1].
    - Take the smaller total cost.

- Example:
    cost = [10, 15, 20]

    dp[0] = 0
    dp[1] = 0

    dp[2] = min(0 + 10, 0 + 15)
          = 10

    dp[3] = min(0 + 15, 10 + 20)
          = 15

    Answer = dp[3] = 15

- We return dp[n] because step n represents the top of the staircase,
  and reaching the top itself does not require paying any additional
  cost.
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n,i;
        n=cost.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=min(cost[0],0);
        for(i=2;i<n+1;i++)
        {
            dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
        }
        return dp[n];
    }
};