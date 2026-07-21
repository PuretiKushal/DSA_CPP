# Two Pointers

## What is Two Pointers?

Two Pointers is a technique where two indices are used to traverse an array or string efficiently instead of using nested loops.

It is commonly used on:

* Sorted arrays
* Strings
* Linked Lists

It helps reduce time complexity from **O(n²)** to **O(n)** in many problems.

---

# When to Identify Two Pointers?

Use Two Pointers when:

* The array is already sorted.
* You can sort the array without affecting the answer.
* Two elements together satisfy a condition.
* You need pairs, triplets or quadruplets.
* You need to compare elements from both ends.
* You need to reverse or validate a string.

Common keywords:

* Pair
* Sum
* Sorted
* Closest
* Triplet
* Quadruplet
* Reverse
* Palindrome

---

# Types of Two Pointers

### 1. Opposite Direction

```text
l ->           <- r
```

Used for:

* Pair Sum
* 3Sum
* 4Sum
* Container With Most Water
* Trapping Rain Water
* Boats to Save People

Rules:

* If current value is too small → move left pointer.
* If current value is too large → move right pointer.

---

### 2. Same Direction

```text
l ->
     r ->
```

Used when both pointers move forward.

Examples:

* Remove Duplicates
* Is Subsequence
* Merge Sorted Arrays

---

# General Template (Opposite Direction)

```cpp
sort(a.begin(),a.end());

l=0;
r=n-1;

while(l<r)
{
    if(condition)
    {
        // store/update answer
        l++;
        r--;
    }
    else if(condition)
    {
        l++;
    }
    else
    {
        r--;
    }
}
```

---

# Duplicate Handling

For problems like **3Sum** and **4Sum**:

Skip duplicate fixed elements.

```cpp
if(i>0 && nums[i]==nums[i-1])
{
    continue;
}
```

```cpp
if(j>i+1 && nums[j]==nums[j-1])
{
    continue;
}
```

After finding a valid answer:

```cpp
l++;
r--;

while(l<r && nums[l]==nums[l-1])
{
    l++;
}

while(l<r && nums[r]==nums[r+1])
{
    r--;
}
```

---

# Important Notes

* Sort first whenever required.
* Move only one pointer at a time unless a valid answer is found.
* Pointer movement depends on whether the current value is smaller or larger than the target.
* Use `long long` when the sum of multiple integers can overflow.
* Skip duplicates only in problems where unique answers are required.

---

# Time Complexity

Sorting:

```
O(n log n)
```

Two Pointer Traversal:

```
O(n)
```

Overall (most problems):

```
O(n log n)
```

3Sum:

```
O(n²)
```

4Sum:

```
O(n³)
```

---

# Problems Completed

### Easy

* 125. Valid Palindrome
* 392. Is Subsequence
* 977. Squares of a Sorted Array

### Medium

* 167. Two Sum II
* 11. Container With Most Water
* 15. 3Sum
* 16. 3Sum Closest
* 18. 4Sum
* 1679. Max Number of K-Sum Pairs
* 881. Boats to Save People

### Hard

* 42. Trapping Rain Water
