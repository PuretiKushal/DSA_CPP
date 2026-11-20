/*
Problem: 594. Longest Harmonious Subsequence
Pattern: Hashing / Frequency Counting
Difficulty: Easy

Time Complexity: O(n)
- First traversal builds the frequency map.
- Second traversal checks whether the next consecutive value exists.

Space Complexity: O(n)
- Hash map stores the frequency of each distinct element.

Key Idea:
- Count the frequency of every element using an unordered_map.
- For each distinct element, check whether its next consecutive value (x + 1) exists.
- If it exists, their combined frequency forms a harmonious subsequence.
- Keep track of the maximum combined frequency.
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int i,ans=0;
        unordered_map<int,int> mp;
        for(i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(mp.count(x.first+1))
            {
                ans=max(ans,x.second+mp[x.first+1]);
            }
        }
        return ans;
    }
};