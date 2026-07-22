/*
===========================================================
Problem: 153. Find Minimum in Rotated Sorted Array
Pattern: Binary Search
Difficulty: Medium

Time Complexity: O(log n)
Space Complexity: O(1)

Key Idea:
- Compare nums[mid] with nums[r].
- nums[mid] > nums[r]  -> minimum is in the right half.
- nums[mid] < nums[r]  -> minimum is in the left half (including mid).

Important Notes:
- Compare with nums[r], not nums[l].
- nums[l] only tells whether the left half is sorted, not where the minimum is.
- Example: [4,5,6,7,0,1,2]
  nums[mid]=7 > nums[l]=4, but the minimum is still on the right.
- l = mid + 1 because nums[mid] cannot be the minimum.
- r = mid because nums[mid] might be the minimum.
- Use while(l < r) since r = mid can make l == r.
- Return nums[l] because when the loop ends, l == r and points to the minimum.
===========================================================
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l,r,mid,n;
        n=nums.size();
        l=0;
        r=n-1;
        while(l<r)
        {
            mid=(l+r)/2;
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return nums[l];
    }
};