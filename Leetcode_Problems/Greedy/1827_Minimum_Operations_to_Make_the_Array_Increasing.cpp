/*
Problem: 1827. Minimum Operations to Make the Array Increasing
Pattern: Greedy
Difficulty: Easy

Time Complexity: O(n)
- Traverses the array once.
- Each element is processed in constant time.

Space Complexity: O(1)
- Modifies the input array directly.
- Uses only a constant amount of extra space.

Key Idea:
- Traverse the array from left to right.
- Compare each element with its next element.
- If nums[i] >= nums[i+1], the next element must be
  increased to nums[i] + 1 to maintain strict increase.
- Add the required increments to count.
- Update nums[i+1] to reflect the modified value.
- Return the total number of operations.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n,i,count=0;
        n=nums.size();
        for(i=0;i<n-1;i++)
        {
            if(nums[i]>=nums[i+1])
            {
                count+=(nums[i]+1-nums[i+1]);
                nums[i+1]=nums[i]+1;
            }
        }
        return count;
    }
};