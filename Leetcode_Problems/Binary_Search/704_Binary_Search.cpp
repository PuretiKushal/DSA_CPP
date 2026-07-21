/*
Problem: 704. Binary Search
Pattern: Binary Search
Difficulty: Easy


Time Complexity: O(log n)
- Each comparison eliminates half of the remaining search space, giving O(log n) time complexity.


Space Complexity: O(1)
- Only a few extra variables are used (excluding the input array).


Key Idea:
- Maintain two pointers (l and r) representing the current search space.
- Find the middle element using:
      mid = l + (r - l) / 2
- If nums[mid] == target, return mid.
- If nums[mid] < target, search the right half by moving l = mid + 1.
- If nums[mid] > target, search the left half by moving r = mid - 1.
- Continue until l > r.
- If the target is not found, return -1.

Important Notes:
- Binary Search works only on a sorted array.
- Use l + (r - l) / 2 instead of (l + r) / 2 to avoid integer overflow.
- The condition should be while(l <= r) so the last remaining element is also checked.
- Each comparison eliminates half of the remaining search space, giving O(log n) time complexity.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l,r,mid,n;
        n=nums.size();
        l=0;
        r=n-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return -1; 
    }
};