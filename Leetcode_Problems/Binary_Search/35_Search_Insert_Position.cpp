/*
Problem: 35. Search Insert Position
Pattern: Binary Search
Difficulty: Easy

Time Complexity: O(log n)
- In each iteration, half of the search space is discarded.

Space Complexity: O(1)
- Only a few extra variables are used.

Key Idea:
- Perform Binary Search on the sorted array.
- If nums[mid] equals the target:
    - Return mid.
- If nums[mid] is smaller than the target:
    - Move l = mid + 1.
- If nums[mid] is greater than the target:
    - Move r = mid - 1.
- If the target is not found:
    - Return l, which represents the correct insertion position to maintain the sorted order.

Important Notes:
- Binary Search works only on sorted arrays.
- Use mid = l + (r - l) / 2 to avoid integer overflow.
- Use while(l <= r) so the last remaining element is also checked.
- When the loop ends:
    - r points to the last element smaller than the target.
    - l points to the first element greater than or equal to the target.
- Returning l correctly handles insertion at the beginning, middle, or end of the array.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
        return l;
    }
};