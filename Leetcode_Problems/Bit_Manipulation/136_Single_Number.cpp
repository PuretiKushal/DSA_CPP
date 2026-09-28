/*
Problem: 136. Single Number
Pattern: Bit Manipulation + XOR
Difficulty: Easy

Time Complexity: O(n)
(The array is traversed once, and each XOR operation takes O(1) time.)

Space Complexity: O(1)
(Only the variables 'n', 'i', and 'xor1' are used apart from the
input array.)

Key Idea:
- Every element appears exactly twice except for one element, which
  appears only once.
- Use the XOR operation to cancel out the elements that appear twice.
- XOR has the property:
    x^x=0
    x^0=x
- Traverse the array and XOR every element with 'xor1':
    xor1=xor1^nums[i]
- Every duplicate pair cancels:
    a^a=0
- The remaining value is the element that appears only once.
- No extra data structure is required, so the solution uses O(1)
  auxiliary space.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n,i,xor1=0;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            xor1=xor1^nums[i];
        }
        return xor1;
    }
};