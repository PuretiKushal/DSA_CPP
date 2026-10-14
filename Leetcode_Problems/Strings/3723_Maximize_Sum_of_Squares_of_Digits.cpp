/*
Problem: 3723. Maximize Sum of Squares of Digits
Pattern: Strings + Greedy
Difficulty: Medium

Time Complexity: O(num)
(The algorithm first checks whether the required digit sum is possible,
which takes O(1) time. It then iterates through num positions, choosing
the largest possible digit and updating the remaining sum in each
iteration. Therefore, the overall time complexity is O(num).)

Space Complexity: O(num)
(The result string ans contains exactly num characters. The algorithm
preallocates the string and modifies its characters in-place, requiring
O(num) space for the result.)

Key Idea:
- Each digit must be between 0 and 9, and the sum of all digits must
  equal the given sum.
- If sum > 9 * num, return an empty string because no valid number
  can achieve the required digit sum.
- Create a string of length num, initially filled with '0'.
- For each position:
    1. Choose d = min(9, sum) to use the largest possible digit.
    2. Convert the digit into a character using char(d + '0').
    3. Store the character at the current position.
    4. Subtract d from the remaining sum.
- Greedily placing the largest possible digits first maximizes the
  sum of squared digits.
- Placing larger digits at earlier positions also produces the
  maximum number when multiple arrangements achieve the same score.
- Preallocating the string avoids repeated appending and allows
  each character to be assigned directly.
*/

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)
        {
            return "";
        } 
        int i,d;
        string ans(num,'0');
        for(i=0;i<num;i++)
        {
            d=min(9,sum);
            ans[i]=char(d+'0');
            sum=sum-d;
        }
        return ans;
    }
};