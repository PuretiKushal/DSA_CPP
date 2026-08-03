/*
Problem: 326. Power of Three
Pattern: Basic Recursion
Difficulty: Easy

Time Complexity: O(log₃ n)
(In every recursive call, n is divided by 3.
 The recursion continues until n becomes 1 or can no longer be divided by 3.)

Space Complexity: O(log₃ n)
(Due to the recursion call stack.
 The maximum recursion depth is the number of times n can be divided by 3.)

Key Idea:
- A number is a power of 3 if it can be repeatedly divided by 3
  and eventually becomes 1.
- At every recursive call:
    Divide n by 3.
- Continue until reaching the Base Case.

Base Cases:

if(n==1)
{
    return true;
}

- Reaching 1 means n was successfully divided by 3
  all the way down.
- Therefore, n is a power of 3.

----------------------------

if(n<=0)
{
    return false;
}

- Powers of 3 are always positive.
- 0 and negative numbers can never be powers of 3.

----------------------------

if(n%3!=0)
{
    return false;
}

- If n is not divisible by 3,
  it cannot be reduced further into a power of 3.
- Therefore, return false immediately.

Recursive Case:

return isPowerOfThree(n/3);

- Reduce the problem by dividing n by 3.
- Recursively check whether the smaller number
  is also a power of 3.

Important Notes:
- Every recursive call reduces the problem size.
- The Base Cases prevent infinite recursion.
- The recursion stops as soon as:
    • n becomes 1 (Success)
    • n becomes non-positive
    • n is not divisible by 3
- Similar logic can be applied to:
    • Power of Two
    • Power of Four
    by changing the divisor accordingly.
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
        {
            return true;
        }
        if(n<=0)
        {
            return false;
        }
        if(n%3!=0)
        {
            return false;
        }
        return isPowerOfThree(n/3); 
    }
};