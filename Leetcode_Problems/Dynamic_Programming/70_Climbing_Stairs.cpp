/*
Problem: 70. Climbing Stairs
Pattern: Dynamic Programming + 1D DP
Difficulty: Easy

Time Complexity: O(n)
(We calculate the number of ways to reach each step from 3 to n
exactly once. Each state requires only constant-time addition.)

Space Complexity: O(n)
(The dp array stores the number of distinct ways to reach every step
from 0 to n.)

Key Idea:
- Define dp[i] as the number of distinct ways to reach the i-th step.

- From any step, we can climb either:
    1. 1 step
    2. 2 steps

- Therefore, to reach step i:
    - We can come from step i-1 by taking 1 step.
    - We can come from step i-2 by taking 2 steps.

- This gives the recurrence:
    dp[i] = dp[i-1] + dp[i-2]

- Initialization:
    dp[1] = 1
    (There is only one way to reach the first step: 1)

    dp[2] = 2
    (The two ways are:
        1 + 1
        2
    )

- The values form the Fibonacci sequence:
    dp[3] = 3
    dp[4] = 5
    dp[5] = 8
    ...

- Example:
    n = 5

    dp[1] = 1
    dp[2] = 2
    dp[3] = 1 + 2 = 3
    dp[4] = 2 + 3 = 5
    dp[5] = 3 + 5 = 8

    Answer = 8

- The final answer is dp[n], representing the total number of
  distinct ways to reach the top of the staircase.
*/

class Solution {
public:
    int climbStairs(int n) {
        int i;
        vector<int> dp(n+2,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};