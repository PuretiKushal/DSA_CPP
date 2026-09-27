/*
Problem: 231. Power of Two
Pattern: Bit Manipulation
Difficulty: Easy

Time Complexity: O(k)
(Each operation n=n&(n-1) removes one set bit from 'n'.
Here, k is the number of set bits in the binary representation of n.
For an integer, k is bounded by the number of bits.)

Space Complexity: O(1)
(Only the variables 'n' and 'count' are used.)

Key Idea:
- A positive number is a power of two if and only if its binary
  representation contains exactly one set bit.
- First check if n is negative:
    - Negative numbers cannot be powers of two, so return false.
- Use:
    n=n&(n-1)
  to remove the rightmost set bit from 'n'.
- Count how many set bits are present using 'count'.
- After all set bits are removed:
    - If count==1, the original number had exactly one set bit,
      so it is a power of two.
    - Otherwise, it is not a power of two.
- Example:
    8  = 1000
    7  = 0111

    8&(8-1)
    1000&0111
    = 0000

  Only one set bit was present, so 8 is a power of two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        if(n<0)
        {
            return false;
        }
        while(n!=0)
        {
            n=n&(n-1);
            count++;
        }
        return (count==1);
    }
};