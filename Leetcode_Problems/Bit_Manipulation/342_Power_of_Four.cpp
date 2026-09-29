/*
Problem: 342. Power of Four
Pattern: Bit Manipulation + Binary Representation
Difficulty: Easy

Time Complexity: O(log n)
(The loop repeatedly divides `n` by 2 until it becomes 0. Therefore,
the number of iterations is proportional to the number of bits in `n`.)

Space Complexity: O(1)
(Only a constant number of variables are used and no additional data
structure is required.)

Key Idea:
- A positive power of four has exactly one `1` in its binary
  representation, and the number of `0`s after that `1` must be even.

- Track:
    - `o` = number of `1`s encountered in the binary representation.
    - `z` = number of `0`s encountered.

- Use `n % 2` to check the current least significant bit:
    - If `n % 2 == 0`, increment `z`.
    - Otherwise, increment `o`.

- Divide `n` by 2 after processing each bit to move to the next bit.

- At the end:
    - `o == 1` ensures that `n` has exactly one set bit.
    - `z % 2 == 0` ensures that the number of zeros after that set bit
      is even, which means the set bit is at an even position.

- Therefore, the number is a power of four.

- Example:
    16 = 10000₂
    Number of `1`s = 1
    Number of `0`s = 4
    Since `4` is even, 16 is a power of four.

    8 = 1000₂
    Number of `1`s = 1
    Number of `0`s = 3
    Since `3` is odd, 8 is not a power of four.
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        int z=0,o=0;
        while(n>0)
        {
            if(n%2==0)
            {
                z++;
            }
            else 
            {
                o++;
            }
            n=n/2;
        }
        if(o==1&&z%2==0)
        {
            return true;
        }
        return false;
        
    }
};