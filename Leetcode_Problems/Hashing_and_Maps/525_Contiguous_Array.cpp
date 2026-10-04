/*
Problem: 525. Contiguous Array
Pattern: Prefix Sum + Hashing
Difficulty: Medium

Time Complexity: O(n)
(We traverse the array exactly once. For every element, we update the
running prefix sum and perform an average O(1) hash map lookup or
insertion.)

Space Complexity: O(n)
(The hash map stores the first index at which each possible prefix sum
occurs. There can be at most O(n) different prefix sum values.)

Key Idea:
- The problem asks for the longest subarray containing an equal number
  of 0s and 1s.

- Convert the values conceptually:
    0 -> -1
    1 -> +1

- After this transformation, a subarray contains an equal number of
  0s and 1s exactly when its sum is 0.

- Maintain a running prefix sum:
    - If nums[i] == 0, decrease sum by 1.
    - If nums[i] == 1, increase sum by 1.

- If the same prefix sum occurs at two different indices, the elements
  between those indices have a sum of 0.

- Therefore, store:
    prefix sum -> first index where it appeared

- We store only the FIRST occurrence of each prefix sum because we want
  the longest possible subarray.

- If the current prefix sum has already appeared at index j and the
  current index is i:
    length = i - j

  Keeping the earliest j gives the maximum possible length.

- Initialization:
    mp[0] = -1

  This represents a prefix sum of 0 before the array starts. It allows
  a valid subarray beginning at index 0 to be counted correctly.

- Example:
    nums = [0, 1, 0, 1]

    After conversion:
        [-1, +1, -1, +1]

    Prefix sums:
        index:  0   1   2   3
        sum:   -1   0  -1   0

    The prefix sum -1 first appears at index 0 and appears again at
    index 2:
        length = 2 - 0 = 2

    The prefix sum 0 first appears at index -1 and appears again at
    index 1:
        length = 1 - (-1) = 2

    It appears again at index 3:
        length = 3 - (-1) = 4

    Therefore, the answer is 4.

- The main pattern is:
    Same prefix sum -> zero-sum subarray

  Combined with:
    0 -> -1
    1 -> +1

  this converts the equal-0-and-1 condition into a prefix-sum problem.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int i,n,sum,ans;
        n=nums.size();
        sum=ans=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                sum--;
            }
            else
            {
                sum++;
            }
            if(mp.find(sum)!=mp.end())
            {
                ans=max(ans,i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
        }
        return ans;
    }
};