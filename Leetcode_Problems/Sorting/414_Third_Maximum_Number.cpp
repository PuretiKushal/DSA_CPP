/*
Problem: 414. Third Maximum Number
Pattern: Sorting + Duplicate Removal
Difficulty: Easy

Time Complexity: O(n log n)
- Sorting takes O(n log n).
- Removing duplicates using unique() takes O(n).

Space Complexity: O(1) auxiliary space
- Sorts the input vector in place.
- unique() rearranges elements in place.

Key Idea:
- Sort the array in ascending order.
- Use unique() to remove duplicate values.
- If fewer than 3 distinct elements exist, return the maximum.
- Otherwise, return the third-largest distinct element at index n-3.
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n,i;
        n=nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        n=nums.size();
        if(n<3)
        {
            return nums[n-1];
        } 
        return nums[n-3];
    }
};