/*
Problem: 1480. Running Sum of 1d Array
Pattern: Prefix Sum
Difficulty: Easy

Time Complexity: O(n)
(The array is traversed once from index 1 to n-1.
Each prefix sum is calculated in O(1).
Overall: O(n).)

Space Complexity: O(n)
(A separate prefix sum array 'pref' of size n is used.)

Key Idea:
- Create a prefix sum array 'pref' where pref[i] stores the sum of
  all elements from index 0 to i.
- Set pref[0]=nums[0] because the first prefix sum contains only
  the first element.
- For every index i from 1 to n-1:
    pref[i]=pref[i-1]+nums[i]
- This uses the previously calculated prefix sum to build the
  current prefix sum.
- Return the prefix sum array.
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n,i,j;
        n=nums.size();
        vector<int> pref(n);
        pref[0]=nums[0];
        for(i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
        }
        return pref;
    }
};

