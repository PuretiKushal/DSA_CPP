/*
Problem: 268. Missing Number
Pattern: Bit Manipulation + XOR
Difficulty: Easy

Time Complexity: O(n)
(The array is traversed once, and each XOR operation takes O(1) time.)

Space Complexity: O(1)
(Only a few integer variables are used apart from the input array.)

Key Idea:
- The array contains n distinct numbers taken from the range [0,n],
  with exactly one number missing.
- Use the XOR properties:
    x^x=0
    x^0=x
- XOR all elements of the array using 'xor1'.
- XOR all numbers from 1 to n using 'xor2'.
- Every number that appears in both groups cancels out because:
    x^x=0
- The only value left after:
    xor1^xor2
  is the missing number.
- 'xor2' starts from 0 and XORs (i+1) for every index i, covering
  all values from 1 to n.
- The number 0 does not need to be explicitly included because
  XORing with 0 does not change the result.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1,xor2,i,j,n;
        xor1=xor2=0;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            xor1=xor1^nums[i];
            xor2=xor2^(i+1);
        }
        return (xor1^xor2);
    }
};