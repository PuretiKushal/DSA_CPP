/*
Problem: 26. Remove Duplicates from Sorted Array
Pattern: Two Pointers (Same Direction)
Difficulty: Easy

Time Complexity: O(n)
(Right pointer 'r' scans the array once.
 Left pointer 'l' moves only when a new unique element is found.
 Overall: O(n).)

Space Complexity: O(1)
(No extra space is used.)

Key Idea:
- The array is already sorted, so duplicate elements are always adjacent.
- Left pointer (l) stores the next position where a new unique element should be placed.
- Right pointer (r) scans the array from left to right.
- Whenever nums[r] != nums[r-1]:
    - A new unique element is found.
    - Place it at nums[l].
    - Move l forward.
- At the end, l represents the number of unique elements.

Important Notes:
- Compare with the previous element because the array is sorted.
- Increment l only after placing a new unique element.
- Elements after index l-1 do not matter according to the problem statement.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=1,r,n;
        n=nums.size();
        for(r=1;r<n;r++)
        {
            if(nums[r]!=nums[r-1])
            {
                nums[l]=nums[r];
                l++;
            }
        }
        return l;
    }
};