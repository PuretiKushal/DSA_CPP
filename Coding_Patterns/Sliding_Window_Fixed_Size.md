# Sliding Window

# When should I think of Sliding Window?

Whenever the problem contains words like:

- Contiguous subarray
- Contiguous substring
- Consecutive elements
- Window
- Exactly K elements
- At most K elements
- At least K elements
- Longest substring
- Smallest subarray

Always ask:

"Can I reuse the previous window?"

If yes, Sliding Window is probably the solution.

---

# Types of Sliding Window

1. Fixed Size Sliding Window
2. Variable Size Sliding Window

---

# Fixed Size Sliding Window

## Definition

The window size never changes.

Example:

K = 3

Window 1

[2 1 5] 1 3 2

↓

Slide

2 [1 5 1] 3 2

↓

Slide

2 1 [5 1 3] 2

Every window always contains exactly 3 elements.

---

# Recognition

Use Fixed Size Sliding Window when the question contains:

- Exactly K elements
- Subarray of size K
- Substring of length K
- K consecutive elements

Examples:

✔ Maximum sum of subarray of size K
✔ Maximum average subarray
✔ Number of vowels in substring of length K
✔ K Radius Subarray Average

---

# Brute Force

For every possible window

Calculate answer again

Time Complexity:

O(n × k)

because every window is recalculated.

---

# Optimized Idea

Calculate the first window only once.

For every next window:

Remove the left element.

Add the right element.

Update the answer.

Instead of recalculating the whole window.

Time Complexity becomes O(n).

---

# Mental Process

Step 1

Build the first window.

Step 2

Store its answer.

Step 3

Slide the window.

Step 4

Remove the outgoing element.

Step 5

Add the incoming element.

Step 6

Update the answer.

Repeat until the end.

---

# Generic Template

Build first window

Store answer

for(all remaining windows)

{

Remove left element

Add right element

Update answer

}

---

# Core Formula

sum = sum - nums[i-k] + nums[i];

Why?

Current window ends at i.

Window size = k.

The element leaving is

nums[i-k]

The new element entering is

nums[i]

---

# Dry Run

nums

2 1 5 1 3 2

k = 3

First window

2 1 5

sum = 8

↓

Remove 2

Add 1

Window

1 5 1

sum = 7

↓

Remove 1

Add 3

Window

5 1 3

sum = 9

↓

Remove 5

Add 2

Window

1 3 2

sum = 6

Maximum = 9

---

# Complexity

Time

First loop

O(k)

Second loop

O(n-k)

Total

O(n)

Space

Only variables used

O(1)

Exception:

If the problem asks to return another array/vector
(like LeetCode 2090),

Space becomes O(n).

---

# Common Mistakes

❌ Forgetting to calculate the first window.

❌ Starting the sliding loop from i = 0.

Correct:

i = k

❌ Removing nums[i-1]

Correct:

nums[i-k]

❌ Forgetting to update the answer after sliding.

❌ Integer overflow.

Use long long when window sums can exceed int.

❌ Integer division when a floating-point answer is required.

Use

(double)sum / k

---

# Problems Solved

Easy

✅ LeetCode 643 - Maximum Average Subarray I

Learnt:
Store sum.

---------------------------------------

Easy

✅ LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length

Learnt:
Window can store count instead of sum.

---------------------------------------

Medium

✅ LeetCode 2090 - K Radius Subarray Averages

Learnt:

Window size can be different.

Answer may belong to the center of the window.

Need long long to avoid overflow.


---

# Pattern Summary

Fixed Size Sliding Window

↓

Build first window

↓

Store answer

↓

Slide

↓

Remove left

↓

Add right

↓

Update answer

↓

Repeat