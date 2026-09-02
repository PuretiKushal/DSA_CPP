/*
Problem: 1991. Find the Middle Index in Array
Pattern: Prefix Sum
Difficulty: Easy

Time Complexity: O(n)
(The array is traversed three times.
 One traversal builds the prefix sum array.
 One traversal builds the suffix sum array.
 One traversal checks for the middle index.
 Overall: O(n).)

Space Complexity: O(n)
(Two separate arrays 'pref' and 'suf' of size n are used.)

Key Idea:
- Create a prefix sum array 'pref' where pref[i] stores the sum of
  all elements to the left of index i.
- Create a suffix sum array 'suf' where suf[i] stores the sum of
  all elements to the right of index i.
- Initialize:
    pref[0]=0
    suf[n-1]=0
  because index 0 has nothing to its left and index n-1 has nothing
  to its right.
- Build the prefix sum array:
    pref[i]=pref[i-1]+nums[i-1]
- Build the suffix sum array:
    suf[i]=suf[i+1]+nums[i+1]
- For every index i:
    - If pref[i]==suf[i], then i is the middle index.
    - Return the first such index.
- If no middle index exists, return -1.
*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n,i;
        n=nums.size();
        vector<int> pref(n);
        vector<int> suf(n);
        pref[0]=suf[n-1]=0;
        for(i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i-1];
        }
        for(i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+nums[i+1];
        }
        for(i=0;i<n;i++)
        {
            if(pref[i]==suf[i])
            {
                return i;
            }
        }
        return -1;
    }
};