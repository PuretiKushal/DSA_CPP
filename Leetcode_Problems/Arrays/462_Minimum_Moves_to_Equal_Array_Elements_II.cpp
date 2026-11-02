/*
Problem: 462. Minimum Moves to Equal Array Elements II
Pattern: Sorting 
Difficulty: Medium

Time Complexity: O(n log n)
- Sorting the array takes O(n log n).
- Traversing the array to calculate the total moves takes O(n).

Space Complexity: O(1) auxiliary space
- Uses a constant number of variables.
- Sorting is performed in place.

Key Idea:
- Sort the array in ascending order.
- Select the median element as the target value.
- The median minimizes the sum of absolute differences.
- Calculate the absolute difference between every element and the median.
- Sum all differences to get the minimum number of moves.
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n,i,j,count=0,mid;
        n=nums.size();
        sort(nums.begin(),nums.end());
        mid=n/2;
        for(i=0;i<n;i++)
        {
            count+=abs(nums[mid]-nums[i]);
        }
        return count;
    }
};