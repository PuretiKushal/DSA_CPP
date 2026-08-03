/*
Problem: 342. Power of Four
Pattern: Basic Recursion
Difficulty: Easy

Time Complexity: O(log₄ n)
(In every recursive call, n is divided by 4.
 The recursion continues until n becomes 1 or can no longer be divided by 4.)

Space Complexity: O(log₄ n)
(Due to the recursion call stack.
 The maximum recursion depth is the number of times n can be divided by 4.)

Key Idea:
- A number is a power of 4 if it can be repeatedly divided by 4
  and eventually becomes 1.
- At every recursive call:
    Divide n by 4.
- Continue until reaching the Base Case.

Base Cases:

if(n==1)
{
    return true;
}

- Reaching 1 means n was successfully divided by 4
  all the way down.
- Therefore, n is a power of 4.

----------------------------

if(n<=0)
{
    return false;
}

- Powers of 4 are always positive.
- 0 and negative numbers can never be powers of 4.

----------------------------

if(n%4!=0)
{
    return false;
}

- If n is not divisible by 4,
  it cannot be reduced further into a power of 4.
- Therefore, return false immediately.

Recursive Case:

return isPowerOfFour(n/4);

- Reduce the problem by dividing n by 4.
- Recursively check whether the smaller number
  is also a power of 4.

Important Notes:
- Every recursive call reduces the problem size.
- The Base Cases prevent infinite recursion.
- The recursion stops as soon as:
    • n becomes 1 (Success)
    • n becomes non-positive
    • n is not divisible by 4
- This approach is almost identical to Power of Two
  and Power of Three.
- Only the divisor changes from 2 or 3 to 4.
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
        {
            return true;
        }
        if(n<=0)
        {
            return false;
        }
        if(n%4!=0)
        {
            return false;
        }
        return isPowerOfFour(n/4);
    }
};