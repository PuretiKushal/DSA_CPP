/*
Problem: 278. First Bad Version
Pattern: Classic Binary Search (First True / Lower Bound)
Difficulty: Easy

Time Complexity: O(log n)
(In every iteration, half of the search space is discarded.
 Therefore, the number of API calls is logarithmic.)

Space Complexity: O(1)
(Only a few variables are used.)

Key Idea:
- Versions are arranged like this:

    Good Good Good Bad Bad Bad

- Once a version becomes bad, every version after it is also bad.
- This forms a monotonic sequence, making Binary Search applicable.
- Our goal is to find the FIRST bad version.

Search Space:
- l = 1
  (Smallest possible version.)

- r = n
  (Largest possible version.)

Middle Calculation:
    mid = l + (r-l)/2;

Why?
- Prevents integer overflow that may occur with:
    (l+r)/2

API Call:
    x = isBadVersion(mid);

Returns:
- true (1)
    -> Current version is bad.

- false (0)
    -> Current version is good.

Binary Search Decision:
- if(x)
      r = mid - 1;

  Why?
  - 'mid' is already bad.
  - There might be an earlier bad version.
  - Continue searching on the left.

- else
      l = mid + 1;

  Why?
  - 'mid' is good.
  - The first bad version must be after mid.
  - Discard the left half.

Why return l?

- The loop ends when:
      l > r

- At that point:
    • Every version before 'l' is confirmed GOOD.
    • 'l' is the first version that could be BAD.

Example:

Versions:
1 2 3 4 5

Good Good Good Bad Bad

After Binary Search:

l = 4
r = 3

Hence,
return l;

Important Notes:
- Do NOT return mid.
  'mid' is only the last version checked and is not guaranteed
  to be the first bad version.

- This problem is equivalent to finding the Lower Bound
  (first position where the condition becomes true).
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l,r,mid,x=0;
        l=1;
        r=n;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            x=isBadVersion(mid);
            if(x)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};