# Binary Search

# When should I think of Binary Search?

Whenever the problem contains words like:

- Sorted array
- Sorted list
- Monotonic
- Find first occurrence
- Find last occurrence
- Lower Bound
- Upper Bound
- Search in sorted array
- Minimum possible
- Maximum possible
- Minimize the maximum
- Maximize the minimum

Always ask:

"Can I eliminate half of the search space?"

If yes, Binary Search is probably the solution.

---

# Types of Binary Search

1. Classic Binary Search
2. Binary Search on Index
3. Binary Search on Answer

---

# Classic Binary Search

## Definition

Binary Search works only when the search space is sorted or monotonic.

Instead of checking every element,

Check the middle element.

Half of the remaining elements can immediately be discarded.

Time Complexity:

O(log n)

---

# Recognition

Use Classic Binary Search when the question contains:

- Search target
- Find index
- Sorted array
- Sorted vector

Examples:

✔ Binary Search (704)

✔ Search Insert Position (35)

✔ First and Last Position (34)

✔ Search in Rotated Sorted Array (33)

✔ Find Minimum in Rotated Sorted Array (153)

✔ Peak Element (162)

✔ Search a 2D Matrix (74)

✔ Sqrt(x) (69)

---

# Mental Process

Step 1

Choose search space

l = 0

r = n-1

↓

Step 2

Find middle

mid = l + (r-l)/2

↓

Step 3

Compare

↓

Step 4

Discard one half

↓

Repeat

---

# Why

mid = l + (r-l)/2

instead of

(l+r)/2 ?

Because

l+r

may overflow for very large integers.

---

# Generic Template

while(l<=r)

{

mid=l+(r-l)/2;

if(found)

return answer;

else if(go left)

r=mid-1;

else

l=mid+1;

}

---

# Lower Bound

Definition

First index whose value is

>= target

Example

1 2 4 4 4 6 8

target = 4

Answer = first 4

---

# Upper Bound

Definition

First index whose value is

> target

Example

1 2 4 4 4 6 8

target = 4

Answer = 6

---

# Binary Search on Answer

## Definition

The answer itself is searched using Binary Search.

Instead of asking

"Is this the answer?"

Ask

"Can this answer work?"

This is called the feasibility check.

---

# Recognition

Questions usually contain:

- Minimum possible
- Maximum possible
- Minimize the maximum
- Maximize the minimum
- Smallest value satisfying...
- Largest value satisfying...

Examples:

✔ Koko Eating Bananas (875)

✔ Smallest Divisor Given Threshold (1283)

✔ Capacity To Ship Packages Within D Days (1011)

✔ Minimum Days to Make m Bouquets (1482)

✔ Magnetic Force Between Two Balls (1552)

✔ Split Array Largest Sum (410)

✔ Minimized Maximum of Products Distributed to Any Store (2064)

---

# Mental Process

Step 1

Identify the answer.

(Not the index.)

↓

Step 2

Find minimum possible answer.

↓

Step 3

Find maximum possible answer.

↓

Step 4

Binary Search on this range.

↓

Step 5

For every mid,

ask:

"Can mid satisfy the condition?"

↓

Step 6

If YES

Store answer.

Move according to whether you're minimizing or maximizing.

↓

If NO

Move in the opposite direction.

---

# How to write can(mid)?

Always ask:

"If every answer is forced to be exactly mid,

can the problem still be completed?"

If the answer is YES,

mid is feasible.

Otherwise,

mid is not feasible.

---

# Binary Search Direction

### Minimizing Answer

If mid works

↓

Store answer

↓

Move Left

r=mid-1

Reason:

Try finding an even smaller valid answer.

------------------------------------

If mid does not work

↓

Move Right

l=mid+1

Reason:

Need a larger answer.

---

### Maximizing Answer

If mid works

↓

Store answer

↓

Move Right

l=mid+1

Reason:

Try finding an even larger valid answer.

------------------------------------

If mid does not work

↓

Move Left

r=mid-1

Reason:

Current answer is too large.

---

# Search Space

Choosing the search space is the most important step.

Ask yourself:

"What is the smallest possible answer?"

↓

"What is the largest possible answer?"

Those become

l

and

r.

---

# Common Mistakes

❌ Using

mid=(l+r)/2

Use

mid=l+(r-l)/2

------------------------------------

❌ Forgetting to store the answer before moving.

Correct:

ans=mid;

------------------------------------

❌ Wrong Binary Search direction.

Remember:

Minimize

↓

YES → Left

NO → Right

Maximize

↓

YES → Right

NO → Left

------------------------------------

❌ Wrong search space.

Always think about

minimum possible answer

maximum possible answer

------------------------------------

❌ Wrong feasibility condition.

The greedy check must answer

"Can mid work?"

NOT

"Is mid the answer?"

---

# Problems Solved

Easy

✅ LeetCode 704 - Binary Search

Learnt:

Basic Binary Search.

---------------------------------------

Easy

✅ LeetCode 35 - Search Insert Position

Learnt:

Lower Bound concept.

---------------------------------------

Medium

✅ LeetCode 34 - Find First and Last Position

Learnt:

Lower Bound + Upper Bound.

---------------------------------------

Medium

✅ LeetCode 33 - Search in Rotated Sorted Array

Learnt:

One half is always sorted.

---------------------------------------

Medium

✅ LeetCode 153 - Find Minimum in Rotated Sorted Array

Learnt:

Use sorted half to discard search space.

---------------------------------------

Medium

✅ LeetCode 162 - Find Peak Element

Learnt:

Slope decides the search direction.

---------------------------------------

Medium

✅ LeetCode 74 - Search a 2D Matrix

Learnt:

Treat the matrix as a sorted array.

---------------------------------------

Easy

✅ LeetCode 69 - Sqrt(x)

Learnt:

Binary Search on values.

---------------------------------------

Medium

✅ LeetCode 875 - Koko Eating Bananas

Learnt:

First Binary Search on Answer.

---------------------------------------

Medium

✅ LeetCode 1283 - Smallest Divisor Given a Threshold

Learnt:

Greedy feasibility using ceil division.

---------------------------------------

Medium

✅ LeetCode 1011 - Capacity To Ship Packages Within D Days

Learnt:

Simulate packing greedily.

---------------------------------------

Medium

✅ LeetCode 1482 - Minimum Days to Make m Bouquets

Learnt:

Greedy counting with feasibility.

---------------------------------------

Medium

✅ LeetCode 1552 - Magnetic Force Between Two Balls

Learnt:

Maximize the minimum distance.

---------------------------------------

Hard

✅ LeetCode 410 - Split Array Largest Sum

Learnt:

Greedy partitioning.

Condition:

subarrays <= k

---------------------------------------

Medium

✅ LeetCode 2064 - Minimized Maximum of Products Distributed to Any Store

Learnt:

Calculate minimum shops required.

Condition:

shops <= n

Using

(quantity+mid-1)/mid

to compute ceil(quantity/mid).

---

# Pattern Summary

Binary Search

↓

Choose Search Space

↓

Find mid

↓

Check feasibility

↓

If YES

Store answer

↓

Move according to

Minimize / Maximize

↓

Repeat

↓

Return answer