/*
-------------------------------------------------------
Problem: 34. Find First and Last Position of Element in Sorted Array
Pattern: Binary Search
Difficulty: Medium

Time Complexity:
- O(log n) + O(log n) = O(log n)

Space Complexity:
- O(1)

Key Idea:
- Perform Binary Search twice.
- First Binary Search finds the first occurrence of the target by continuing
  to search on the left even after finding the target.
- Second Binary Search finds the last occurrence by continuing
  to search on the right after finding the target.
- Return {first, last}. If the target is not present, both remain -1.

Important Notes:
- When nums[mid] == target:
    • First Occurrence  -> ans = mid, r = mid - 1
    • Last Occurrence   -> ans = mid, l = mid + 1
- Reset l and r before starting the second Binary Search.
- Binary Search is used twice, so the overall complexity remains O(log n).

-------------------------------------------------------
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l,r,n,mid,first,last,ans;
        n=nums.size();
        l=0;
        r=n-1;
        first=last=ans=-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                r=mid-1;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        first=ans;
        l=0;
        r=n-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        last=ans;
        return {first,last};

    }
};