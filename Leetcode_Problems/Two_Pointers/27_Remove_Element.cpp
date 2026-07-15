/*
Problem: 27. Remove Element
Pattern: Two Pointers (Same Direction)
Difficulty: Easy

Time Complexity: O(n)
(Right pointer 'r' scans the array once.
 Left pointer 'l' moves only when an element not equal to val is found.
 Overall: O(n).)

Space Complexity: O(1)
(No extra space is used.)

Key Idea:
- Left pointer (l) stores the next position where a valid element should be placed.
- Right pointer (r) scans the array.
- Whenever nums[r] != val:
    - Place nums[r] at nums[l].
    - Move l forward.
- Ignore all occurrences of val.
- At the end, l represents the number of remaining elements.

Important Notes:
- Elements after index l-1 do not matter according to the problem statement.
- Swapping is not required; simply overwrite the unwanted elements.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0,r,n;
        n=nums.size();
        for(r=0;r<n;r++)
        {
            if(nums[r]!=val)
            {
                nums[l]=nums[r];
                l++;
            }
        }
        return l;
    }
};