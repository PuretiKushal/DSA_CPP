/*
    Problem: 540. Single Element in a Sorted Array
    Pattern: Binary Search
    Difficulty: Medium

    Time Complexity: O(log n)
    Space Complexity: O(1)

    Key Idea:
    In a sorted array where every element appears exactly twice
    except one, pairs appear in a fixed pattern.

    Before the single element:
    - The first occurrence of every pair is at an even index.
    - The second occurrence is at an odd index.

    After the single element:
    - This pattern is reversed.

    Make 'mid' even so it always points to the first element
    of a possible pair.

    - If nums[mid] == nums[mid + 1], the single element lies
      on the right side.
    - Otherwise, it lies on the left side (including mid).

    Continue until l == r. That index stores the single element.

    Important Notes:
    - If mid is odd, decrement it by one to make it even.
    - Compare only nums[mid] with nums[mid + 1].
    - The search space always contains the answer.
    - Stop when l == r and return nums[l].
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l,r,mid,n;
        n=nums.size();
        l=0;
        r=n-1;
        while(l<r)
        {
            mid=l+(r-l)/2;
            if(mid%2!=0)
            {
                mid--;
            }
            if(nums[mid]==nums[mid+1])
            {
                l=mid+2;
            }
            else
            {
                r=mid;
            }
            
        }
        return nums[l];
    }
};