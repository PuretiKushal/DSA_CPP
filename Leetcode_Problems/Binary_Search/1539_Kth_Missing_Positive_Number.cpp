/*
Problem: 1539. Kth Missing Positive Number
Pattern: Binary Search on Index
Difficulty: Easy

Time Complexity: O(log n)
(Binary Search is performed on the array indices.
 In every iteration, half of the search space is discarded.)

Space Complexity: O(1)
(Only a few variables are used.)

Key Idea:
- Instead of finding the missing numbers one by one,
  calculate how many numbers are missing before every array element.
- Binary Search is used to find the first index where the number of
  missing integers becomes greater than or equal to k.

Missing Count Formula:
    missing = arr[i] - i - 1;

Why?

- If no numbers were missing, then:

    Index : 0 1 2 3
    Value : 1 2 3 4

  Every element should satisfy:

    arr[i] = i + 1

- If arr[i] is larger than (i+1),
  the extra values represent the missing numbers.

Example:

    arr = [2,3,4,7,11]

    i = 3

    arr[3] = 7

    Expected value at index 3 = 4

    Missing numbers = 7 - 4 = 3

Formula:

    arr[i] - (i+1)

or

    arr[i] - i - 1

Search Space:
- l = 0
  (First index.)

- r = n-1
  (Last index.)

Middle Calculation:
    mid = l + (r-l)/2;

Why?
- Prevents integer overflow that may occur with:
    (l+r)/2

Binary Search Decision:

    m = arr[mid] - mid - 1;

Why?
- Finds how many positive integers are missing before arr[mid].

------------------------------------

if(m < k)
    l = mid + 1;

Why?
- Fewer than k numbers are missing before arr[mid].
- The kth missing number must be after this index.

------------------------------------

else
    r = mid - 1;

Why?
- At least k numbers are already missing.
- The answer could be at this index or before it.
- Continue searching on the left.

Why return l + k ?

- Binary Search does NOT directly find the kth missing number.
- It finds the first index where the missing count becomes >= k.

After the loop:

- l = number of array elements before the answer.

These existing elements shift the kth missing number by 'l'.

Therefore,

Answer = k + l

Example:

arr = [2,3,4,7,11]
k = 5

After Binary Search:

l = 4

Answer =

4 + 5 = 9

Missing numbers:

1 5 6 8 9 ...

5th missing = 9

Important Notes:
- Do not Binary Search on the answer itself.
- Binary Search is performed on the indices.
- The answer is derived after Binary Search using:
    return l + k;
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l,r,i,mid,m,n,ans=0;
        n=arr.size();
        l=0;
        r=n-1;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            m=arr[mid]-mid-1;
            if(m<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return l+k;
    }
};