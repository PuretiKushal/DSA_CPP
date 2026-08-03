/*
Problem: 509. Fibonacci Number
Pattern: Basic Recursion
Difficulty: Easy

Time Complexity: O(2^n)
(Each function call makes two more recursive calls:
    fib(n-1)
    fib(n-2)
This creates a recursion tree with an exponential number of calls.)

Space Complexity: O(n)
(Due to the recursion call stack.
 The maximum depth of recursion is n.)

Key Idea:
- The Fibonacci sequence follows the relation:
    F(n) = F(n-1) + F(n-2)
- Instead of calculating the sequence iteratively,
  recursively solve the two smaller subproblems.
- Keep reducing n until the smallest possible values are reached.

Base Case:
if(n<=1)
{
    return n;
}

- If n is 0, return 0.
- If n is 1, return 1.
- These are the smallest Fibonacci numbers and stop further recursion.

Recursive Case:
return fib(n-1)+fib(n-2);

- Calculate the previous Fibonacci number:
    fib(n-1)
- Calculate the one before that:
    fib(n-2)
- Add both results to obtain the current Fibonacci number.

Important Notes:
- Every recursive call reduces the problem size.
- The Base Case prevents infinite recursion.
- Many subproblems are calculated multiple times.
  Example:
      fib(3)
  is computed repeatedly while calculating larger values.
- This solution is simple but inefficient.
- Dynamic Programming (Memoization / Tabulation) is used to optimize it later.
*/

class Solution {
public:
    int fib(int n) {
        if(n<=1&&n>=0)
        {
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};