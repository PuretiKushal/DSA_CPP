/*
Problem: 930. Binary Subarrays With Sum
Pattern: Prefix Sum + Hashing
Difficulty: Medium

Time Complexity: O(n)
(The array is traversed once. At each index, updating the prefix sum,
checking the frequency map, and incrementing the current prefix sum's
frequency take O(1) average time. Therefore, the overall average time
complexity is O(n).)

Space Complexity: O(n)
(The unordered_map stores the frequencies of the prefix sums encountered.
In the worst case, it can contain up to n+1 distinct prefix sums,
requiring O(n) auxiliary space.)

Key Idea:
- Use a prefix sum and a hash map to count subarrays whose sum equals goal.
- Initialize mp[0]=1 to account for subarrays starting at index 0.
- Traverse the array and maintain the running prefix sum in sum.
- For the current prefix sum, calculate sum-goal to find the previous
  prefix sum needed to form a subarray with sum equal to goal.
- If sum-goal exists in the map, add its frequency to count because
  each occurrence represents a valid subarray ending at the current index.
- Increment mp[sum] to record the current prefix sum for future elements.
- Return count.
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n,i,sum,count;
        n=nums.size();
        sum=count=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(mp.find(sum-goal)!=mp.end())
            {
                count=count+mp[sum-goal];
            }
            mp[sum]++;
        }
        return count;
    }
};