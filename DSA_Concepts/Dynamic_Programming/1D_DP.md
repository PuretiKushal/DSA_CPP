# 1D Dynamic Programming

## 1. What is Dynamic Programming?

Dynamic Programming (DP) is a technique used to solve problems by:

1. Breaking a problem into smaller subproblems.
2. Solving those subproblems.
3. Storing their answers.
4. Reusing stored answers instead of solving the same subproblem again.

DP is especially useful when a problem has:

* **Overlapping Subproblems** — the same smaller problem appears multiple times.
* **Optimal Substructure** — the answer to a larger problem can be built from answers to smaller problems.

---

## 2. Recursion vs DP

Normal recursion may calculate the same subproblem repeatedly.

For example, Fibonacci:

```cpp
int fib(int n)
{
if(n<=1)
return n;

return fib(n-1)+fib(n-2);
}
```

For `fib(5)`, `fib(3)` and `fib(2)` are calculated multiple times.

DP avoids this repeated work by storing the result of each subproblem.

### Memoization

Memoization is **Top-Down DP**:

* Start with the original problem.
* Recursively solve smaller problems.
* Store each result.
* If the same state is requested again, return the stored result.

```cpp
int fib(int n,vector<int>& dp)
{
if(n<=1)
return n;

if(dp[n]!=-1)
return dp[n];

return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}
```

### Tabulation

Tabulation is **Bottom-Up DP**:

* Start with the smallest known states.
* Build larger states iteratively.

```cpp
dp[0]=0;
dp[1]=1;

for(i=2;i<=n;i++)
dp[i]=dp[i-1]+dp[i-2];
```

---

# 3. What is a DP State?

The **state** describes exactly what a subproblem represents.

Ask:

> "What information do I need to identify this smaller problem?"

For a simple 1D DP problem:

```text
dp[i]
```

usually represents the answer to the problem up to or at position `i`.

For example:

```text
dp[i] = maximum sum using elements 0...i
```

or:

```text
dp[i] = minimum cost to reach position i
```

The meaning of `dp[i]` must be clearly defined before writing the transition.

---

# 4. Transition

The **transition** describes how the current state is calculated from smaller states.

Ask:

> "How can I reach or construct the current state from previously solved states?"

For example, in Fibonacci:

```text
dp[i] = dp[i-1] + dp[i-2]
```

because `fib(i)` depends on `fib(i-1)` and `fib(i-2)`.

---

# 5. Base Cases

Base cases are the smallest states whose answers are already known.

For example, Fibonacci:

```text
dp[0] = 0
dp[1] = 1
```

For a new DP problem, ask:

> "What is the smallest version of this problem that I already know the answer to?"

---

# 6. General 1D DP Process

When solving a 1D DP problem:

```text
1. Define the state
        ↓
2. Identify the choices / previous states
        ↓
3. Derive the transition
        ↓
4. Find the base cases
        ↓
5. Decide memoization or tabulation
        ↓
6. Check time and space complexity
```

Do not memorize a recurrence before understanding what `dp[i]` represents.

---

# 7. Common 1D DP Patterns

## A. Previous-State DP

The current state depends on one or more previous states.

Example:

```text
dp[i] = dp[i-1] + dp[i-2]
```

Typical problems:

* Fibonacci
* Climbing Stairs

---

## B. Min / Max DP

The current state is obtained by choosing the minimum or maximum among possible previous states.

Example:

```text
dp[i] = min(dp[i-1],dp[i-2]) + cost[i]
```

or:

```text
dp[i] = max(dp[i-1],dp[i-2] + value[i])
```

Typical problems:

* Min Cost Climbing Stairs
* House Robber
* Maximum Sum of Non-Adjacent Elements

---

## C. Take / Don't-Take DP

At each position, there are two choices:

```text
TAKE
    ↓
use a previous compatible state

DON'T TAKE
    ↓
use the previous state
```

For example:

```text
dp[i] = max(
    dp[i-1],
    dp[i-2] + nums[i]
)
```

The exact transition depends on what the problem allows.

This pattern becomes especially important in **0/1 Knapsack**.

---

## D. Counting DP

Instead of maximizing or minimizing, we count the number of valid ways.

For example, in Decode Ways:

```text
dp[i] = number of ways to decode the first i characters
```

At each position, check whether:

1. The current digit can form a valid one-digit letter.
2. The current two digits can form a valid two-digit letter.

If valid:

```text
dp[i] += dp[i-1]
```

and/or:

```text
dp[i] += dp[i-2]
```

The operation is addition because we are **counting possibilities**.

---

# 8. Example: Min Cost Climbing Stairs

Given:

```text
cost = [10,15,20]
```

You can climb either 1 or 2 steps.

### State

```text
dp[i] = minimum cost to reach step i
```

### Transition

To reach step `i`, we can come from:

```text
i-1
```

or:

```text
i-2
```

Therefore:

```text
dp[i] = min(
    dp[i-1] + cost[i-1],
    dp[i-2] + cost[i-2]
)
```

### Base cases

```text
dp[0] = 0
dp[1] = 0
```

---

# 9. Example: House Robber

Given:

```text
nums = [2,7,9,3,1]
```

Adjacent houses cannot both be robbed.

### State

```text
dp[i] = maximum money that can be robbed from houses 0...i
```

### Choices

If considering house `i`:

**Don't rob it:**

```text
dp[i-1]
```

**Rob it:**

```text
dp[i-2] + nums[i]
```

### Transition

```text
dp[i] = max(
    dp[i-1],
    dp[i-2] + nums[i]
)
```

### Base cases

```text
dp[0] = nums[0]
dp[1] = max(nums[0],nums[1])
```

---

# 10. Example: Decode Ways

Given:

```text
s = "226"
```

Valid mappings are:

```text
1 → A
2 → B
...
26 → Z
```

### State

```text
dp[i] = number of ways to decode the first i characters
```

At every position, check two possibilities.

### One-digit check

The current digit must be:

```text
1 to 9
```

If valid:

```text
dp[i] += dp[i-1]
```

### Two-digit check

The last two digits must form a number from:

```text
10 to 26
```

If valid:

```text
dp[i] += dp[i-2]
```

This is a **counting DP** because we add the number of valid possibilities.

---

# 11. How to Recognize 1D DP

A problem is a potential 1D DP problem when:

* The problem progresses through a single index, position, step, or prefix.
* The answer for the current position depends on previously solved positions.
* The same smaller states can occur repeatedly.
* You need to count, minimize, maximize, or determine something over those states.

Typical clues:

```text
maximum...
minimum...
number of ways...
how many ways...
best possible...
minimum cost...
maximum sum...
```

These words do not automatically mean DP, but they are useful signals to investigate.

---

# 12. Important Questions to Ask

Before coding, ask:

### State

> What does `dp[i]` mean?

### Transition

> How can I calculate `dp[i]` from smaller states?

### Choices

> What decisions or previous positions can lead to `i`?

### Base Case

> What are the smallest states?

### Direction

> Can I build the answer from smaller states to larger states?

---

# 13. Complexity

For a typical 1D DP with `n` states:

### Time

```text
O(n)
```

if each state takes constant work.

### Space

```text
O(n)
```

if the entire DP array is stored.

Sometimes the transition only depends on the previous one or two states, allowing space optimization to:

```text
O(1)
```

For example, Fibonacci does not need the entire DP array.

---

# Key Takeaway

The most important skill in DP is **not memorizing formulas**.

For every problem, think:

```text
What is my state?
        ↓
What choices do I have?
        ↓
Which smaller states do those choices lead to?
        ↓
How do I combine those answers?
        ↓
What are my base cases?
```

Once this becomes natural, moving from **1D DP → 2D DP → 0/1 Knapsack** becomes much easier.
