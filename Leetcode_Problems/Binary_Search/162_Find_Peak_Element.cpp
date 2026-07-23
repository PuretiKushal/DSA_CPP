/*
    Problem: 162. Find Peak Element
    Pattern: Binary Search
    Difficulty: Medium

    Time Complexity: O(log n)
    Space Complexity: O(1)

    Key Idea:
    Compare nums[mid] with nums[mid+1].

    - If nums[mid] < nums[mid+1], a peak is guaranteed to exist on the right,
      so discard the left half including mid.
    - If nums[mid] > nums[mid+1], a peak is guaranteed to exist on the left
      (including mid), so discard the right half.

    Continue until l == r. That index is a peak element.

    Important Notes:
    - Array is not necessarily sorted.
    - Use while(l < r) to safely access nums[mid+1].
    - mid is always less than r, so nums[mid+1] is never out of bounds.
    - There may be multiple peaks; returning any one of them is valid.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l,r,mid,n;
        n=nums.size();
        l=0;
        r=n-1;
        while(l<r)
            {
                mid=(l+r)/2;
                if(nums[mid]<nums[mid+1])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid;
                }
            }
        return l;
    }
};