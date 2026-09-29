/*
Problem: 231. Power of Two
Pattern: Bit Manipulation + Recursion
Difficulty: Easy

Time Complexity: O(log n)
(At each recursive call, `n` is divided by 2. Therefore, the number of
recursive calls is proportional to log₂(n).)

Space Complexity: O(log n)
(Each recursive call is stored on the recursion stack. Since `n` is
divided by 2 at every call, the maximum recursion depth is O(log n).)

Key Idea:
- A positive integer is a power of two if it can be repeatedly divided
  by 2 until it reaches 1 without encountering an odd number.

- First handle the base cases:
    - If `n <= 0`, return false because powers of two are positive.
    - If `n == 1`, return true because 1 = 2^0.

- If `n` is odd and greater than 1, it cannot be a power of two, so
  return false.

- Otherwise, recursively divide `n` by 2 and check the resulting value.

- Example:
    n = 16
    16 → 8 → 4 → 2 → 1
    Therefore, 16 is a power of two.

    n = 12
    12 → 6 → 3
    Since 3 is odd and greater than 1, 12 is not a power of two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        {
            return false;
        }
        if(n==1)
        {
            return true;
        }
        if(n%2!=0)
        {
            return false;
        }
        return isPowerOfTwo(n/2);
    }
};