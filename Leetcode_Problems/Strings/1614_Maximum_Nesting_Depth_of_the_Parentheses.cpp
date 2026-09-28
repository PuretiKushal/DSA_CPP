/*
Problem: 1614. Maximum Nesting Depth of the Parentheses
Pattern: String + Counting
Difficulty: Easy

Time Complexity: O(n)
(The string is traversed once from left to right. Each character is
processed only once, so the overall time complexity is O(n).)

Space Complexity: O(1)
(Only the variables `count`, `mx`, `n`, `i`, and `j` are used.
No additional data structure is required.)

Key Idea:
- Maintain `count` to track the current nesting depth of parentheses.
- When `(` is encountered:
    - Increment `count`.
    - Update `mx` with the maximum value of `count`.
- When `)` is encountered:
    - Decrement `count` because one level of nesting is closed.

- Example:
    Input: "(1+(2*3)+((8)/4))+1"

    As the string is traversed, the maximum value of `count` becomes 3.

- The maximum value reached by `count` represents the maximum nesting
  depth of the parentheses.
*/

class Solution {
public:
    int maxDepth(string s) {
        int n,i,j,count=0,mx=0;
        n=s.size();
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                count++;
                mx=max(mx,count);
            }
            if(s[i]==')')
            {
                count--;
                mx=max(mx,count);
            }
        }
        return mx;
    }
};