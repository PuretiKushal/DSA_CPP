/*
Problem: 238. Product of Array Except Self
Pattern: Prefix Sum + Suffix Product
Difficulty: Medium

Time Complexity: O(n)
(The array is traversed three times to build the prefix product,
build the suffix product, and calculate the final answer.
All three traversals are O(n).)

Space Complexity: O(n)
(Three additional vectors 'pref', 'suf', and 'ans' of size n are used.)

Key Idea:
- Use a prefix product array 'pref' where pref[i] stores the product
  of all elements before index i.
- Initialize:
    pref[0]=1
  because there are no elements before index 0.
- Build the prefix product array:
    pref[i]=pref[i-1]*nums[i-1]

- Use a suffix product array 'suf' where suf[i] stores the product
  of all elements after index i.
- Initialize:
    suf[n-1]=1
  because there are no elements after the last index.
- Build the suffix product array:
    suf[i]=suf[i+1]*nums[i+1]

- For every index i:
    ans[i]=pref[i]*suf[i]
- This works because:
    pref[i] = product of all elements before i
    suf[i]  = product of all elements after i
- Multiplying them gives the product of every element except nums[i].
- The solution does not use division, so it also works correctly when
  the input contains zeroes.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n,i,j;
        n=nums.size();
        vector<int> pref(n),suf(n),ans(n);
        pref[0]=1;
        for(i=1;i<n;i++)
        {
            pref[i]=pref[i-1]*nums[i-1];
        }
        suf[n-1]=1;
        for(i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]*nums[i+1];
        }
        for(i=0;i<n;i++)
        {
            ans[i]=pref[i]*suf[i];
        }
        return ans;
    }
};