# Prefix Sum

## Idea

Prefix Sum stores the cumulative sum of elements up to each index.

For:
a = [2,4,1,5]

prefix = [2,6,7,12]

prefix[i] = prefix[i-1] + a[i]

## Why?

It allows us to calculate the sum of a range quickly.

Sum from l to r:

prefix[r] - prefix[l-1]

When l = 0:

sum = prefix[r]

## Time Complexity

Building prefix sum: O(n)

Range sum query: O(1)

Space: O(n)