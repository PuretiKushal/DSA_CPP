/*
Problem: 189. Rotate Array
Pattern: Arrays + In-place Manipulation + Reversal Algorithm
Difficulty: Medium

Time Complexity: O(n)
- Reversing the entire array takes O(n) time.
- Reversing the first k elements takes O(k) time.
- Reversing the remaining n-k elements takes O(n-k) time.
- Overall, the time complexity is O(n).

Space Complexity: O(1)
- The array is modified in-place.
- No additional array or data structure is used.

Key Idea:
- Normalize k using k % n to handle rotations greater than the array size.
- Reverse the entire array.
- Reverse the first k elements.
- Reverse the remaining n-k elements.
- These three reversals rotate the array to the right by k positions while preserving the required element order.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n;
        n=nums.size();
        if(k>n)
        {
            k=k%n;
        }
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};