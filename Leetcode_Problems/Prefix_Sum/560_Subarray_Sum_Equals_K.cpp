/*
Problem: 560. Subarray Sum Equals K
Pattern: Prefix Sum + Hashing
Difficulty: Medium

Time Complexity: O(n) average
(Each element is processed once, and unordered_map operations such as
count, access, and insertion take O(1) average time.)

Space Complexity: O(n)
(In the worst case, the unordered_map stores a different prefix sum
for each position.)

Key Idea:
- Use a running prefix sum 'cur' to store the sum of elements from
  the beginning of the array up to the current index.
- For the current prefix sum 'cur', we need to find an earlier prefix
  sum equal to:
      prev = cur-k
- If an earlier prefix sum is 'prev', then the subarray between that
  earlier position and the current position has sum 'k'.
- Store the frequency of every prefix sum in the unordered_map 'mp'.
- Initialize:
      mp[0]=1
  This represents one prefix sum of 0 before processing any elements.
  It allows subarrays starting from index 0 to be counted.
- For every element nums[i]:
    - Add nums[i] to the running prefix sum:
        cur=cur+nums[i]
    - Calculate the required previous prefix sum:
        prev=cur-k
    - If 'prev' exists in the map:
        - Add mp[prev] to 'count'.
        - Its frequency is added because every previous occurrence
          of the same prefix sum represents a different subarray.
    - Store the current prefix sum:
        mp[cur]++
- Finally, return 'count', which represents the total number of
  subarrays whose sum is equal to k.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n,i,j,count=0,cur,prev;
        n=nums.size();
        unordered_map<int,int> mp;
        cur=prev=0;
        mp[0]=1;
        for(i=0;i<n;i++)
        {
            cur=cur+nums[i];
            prev=cur-k;
            if(mp.count(prev))
            {
                count=count+mp[prev];
            }
            mp[cur]++;
        }
        return count;
    }
};