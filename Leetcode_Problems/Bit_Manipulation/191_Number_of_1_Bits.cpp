/*
Problem: 191. Number of 1 Bits
Pattern: Bit Manipulation
Difficulty: Easy

Time Complexity: O(k)
(Each operation n=n&(n-1) removes one set bit from 'n'.
Here, k is the number of set bits in the binary representation of n.
In the worst case, k is bounded by the number of bits in the integer.)

Space Complexity: O(1)
(Only the integer variables 'n' and 'count' are used.)

Key Idea:
- Use the property:
    n&(n-1)
  which removes the rightmost set bit (1) from the binary
  representation of 'n'.
- Example:
    n   = 101100
    n-1 = 101011

    n&(n-1)
        = 101000

  The rightmost '1' is removed.
- Repeat this operation while n is not 0.
- Increment 'count' after every operation.
- The number of operations is therefore equal to the number of
  set bits (1s) in the binary representation of the original number.
- Return 'count' as the Hamming Weight.
*/

class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0)
        {
            n=n&(n-1);
            count++;
        }
        return count;
    }
};