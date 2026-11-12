/*
Problem: 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
Pattern: Greedy + Array Traversal
Difficulty: Easy

Time Complexity: O(n)
- Traverses the array once to track increasing and decreasing subarray lengths.

Space Complexity: O(1)
- Uses only a few variables regardless of input size.

Key Idea:
- Maintain two counters:
  - ic: Length of the current strictly increasing subarray.
  - dc: Length of the current strictly decreasing subarray.
- If the current element is greater than the previous element, increment ic and reset dc to 1.
- If the current element is smaller than the previous element, increment dc and reset ic to 1.
- If both elements are equal, reset both counters to 1.
- Update mx with the maximum of ic and dc at every step.
- Return mx as the longest monotonic subarray length.
*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n,i,ic=1,dc=1,mx=1;
        n=nums.size();
        for(i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                ic++;
                dc=1;
            }
            else if(nums[i]<nums[i-1])
            {
                dc++;
                ic=1;
            }
            else
            {
                ic=dc=1;
            }
            mx=max(mx,max(ic,dc));
        }
        return mx;
    }
};