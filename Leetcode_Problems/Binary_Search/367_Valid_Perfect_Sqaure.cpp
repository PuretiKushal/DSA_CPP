/*
    Problem: 367. Valid Perfect Square
    Pattern: Binary Search
    Difficulty: Easy

    Time Complexity: O(log n)
    Space Complexity: O(1)

    Key Idea:
    Search for the square root of the given number.

    - If mid * mid == num, the number is a perfect square.
    - If mid * mid > num, search the left half.
    - If mid * mid < num, search the right half.

    If no value satisfies mid * mid == num, then the number
    is not a perfect square.

    Important Notes:
    - Use long long while multiplying:
      (long long)mid * mid
      to avoid integer overflow.
    - Use mid = l + (r - l) / 2 to prevent overflow
      while calculating the midpoint.
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l,r,mid;
        l=1;
        r=num;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if((long long)mid*mid==num)
            {
                return true;
            }
            else if((long long)mid*mid>num)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return false;
    }
};