/*
    Problem: 69. Sqrt(x)
    Pattern: Binary Search
    Difficulty: Easy

    Time Complexity: O(log x)
    Space Complexity: O(1)

    Key Idea:
    Search for the largest number whose square is less than
    or equal to x.

    - If mid * mid == x, return mid.
    - If mid * mid > x, search the left half.
    - If mid * mid < x, search the right half.

    When the loop ends, r points to the floor of sqrt(x).

    Important Notes:
    - Use mid = l + (r - l) / 2 to avoid overflow.
    - Use (long long)mid * mid to prevent integer overflow
      while squaring mid.
    - Return r because it stores the largest value whose
      square is less than or equal to x.
*/

class Solution {
public:
    int mySqrt(int x) {
        int l,r,mid;
        l=1;
        r=x;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if((long long)mid*mid==x)
            {
                return mid;
            }
            else if((long long)mid*mid>x)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return r;
    }
};