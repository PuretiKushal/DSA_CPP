/*
    Problem: 268. Missing Number
    Pattern: Binary Search
    Difficulty: Easy

    Time Complexity: O(n log n)
    Space Complexity: O(1)

    Key Idea:
    Sort the array and compare each value with its index.

    - If nums[mid] == mid, all numbers up to mid are present.
      Search the right half.
    - If nums[mid] != mid, the missing number is at mid
      or before it. Search the left half.

    When the loop ends, l points to the missing number.

    Important Notes:
    - Sorting is required before applying binary search.
    - Return l after the loop.
    - An XOR or Gauss Sum solution exists in O(n) time
      without sorting, but this solution demonstrates
      the Binary Search approach.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l,r,mid,n;
        n=nums.size();
        sort(nums.begin(),nums.end());
        l=0;
        r=n-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(nums[mid]==mid)
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