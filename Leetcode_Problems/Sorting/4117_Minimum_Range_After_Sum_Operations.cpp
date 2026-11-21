/*
Problem: 4117. Minimum Range After Sum Operations
Pattern: Sorting (Manual)
Difficulty: Medium

Time Complexity: O(1)
- Uses three conditional swaps to sort the values.
- Performs a constant number of comparisons and arithmetic operations.

Space Complexity: O(1)
- Uses only one temporary variable.

Key Idea:
- Sort the three values in ascending order using conditional swaps.
- If the largest value is greater than the sum of the other two, return the middle value.
- Otherwise, return the difference between the largest and smallest values.
*/

class Solution {
public:
    int minRange(int a, int b, int c) {
        int temp;
        if(a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        if(b>c)
        {
            temp=b;
            b=c;
            c=temp;
        }
        if(a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        if(c>a+b)
        {
            return b;
        }
        return c-a;
    }
};