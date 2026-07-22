/*
-------------------------------------------------------
Problem: 33. Search in Rotated Sorted Array
Pattern: Binary Search
Difficulty: Medium

Time Complexity:
- O(log n)

Space Complexity:
- O(1)

Key Idea:
- In a rotated sorted array, at least one half is always sorted.
- Identify the sorted half using nums[l] <= nums[mid].
- If the target lies within the sorted half, search there.
- Otherwise, discard it and search the other half.
- Repeat until the target is found or the search space becomes empty.

Important Notes:
- Check nums[mid] == target before determining the sorted half.
- Left Half Sorted:
    • nums[l] <= nums[mid]
    • Target Range: nums[l] <= target && target < nums[mid]
- Right Half Sorted:
    • nums[mid] < target && target <= nums[r]
- This approach works because at every iteration, at least one half
  of the current search space is guaranteed to be sorted.

-------------------------------------------------------
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l,r,n,mid;
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
                if(nums[l]<=nums[mid])
                {
                    if(nums[l]<=target&&target<nums[mid])
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                else
                {
                    if(nums[mid]<target&&target<=nums[r])
                    {
                        l=mid+1;
                    }
                    else
                    {
                        r=mid-1;
                    }
                    
                }
            }
        return -1;
    }
};