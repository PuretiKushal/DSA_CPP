/*
Problem: 283. Move Zeroes
Pattern: Two Pointers (Same Direction)
Difficulty: Easy

Time Complexity: O(n)
(Right pointer 'r' scans the array once.
 Left pointer 'l' also moves at most n times.
 Overall: O(n).)

Space Complexity: O(1)
(Only a temporary variable is used for swapping.)

Key Idea:
- Left pointer (l) stores the next position where a non-zero element should be placed.
- Right pointer (r) scans the array from left to right.
- Whenever a non-zero element is found:
    - Swap it with nums[l].
    - Move l forward.
- Ignore zeroes while scanning.
- By placing every non-zero element at the front, all zeroes automatically move to the end.

Important Notes:
- Move the non-zero elements, NOT the zeroes.
- Check the value:
    if(nums[r]!=0)
  (Do NOT check the index like if(r!=0).)
- Increment l only after placing a non-zero element.
- Swapping with itself is completely fine when l==r, so no extra condition is required.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l,r,temp,n;
        n=nums.size();
        l=0;
        for(r=0;r<n;r++)
        {
            if(nums[r]!=0)
            {
                temp=nums[l];
                nums[l]=nums[r];
                nums[r]=temp;
                l++;
            }
        }
    }
};