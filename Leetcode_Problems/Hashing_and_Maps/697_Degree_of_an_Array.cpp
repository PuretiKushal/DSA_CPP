/*
Problem: 697. Degree of an Array
Pattern: Hashing / Frequency Counting
Difficulty: Easy

Time Complexity: O(n)
- First traversal calculates frequencies and records first and last occurrences.
- Second traversal finds the shortest subarray among elements with maximum frequency.

Space Complexity: O(n)
- Three hash maps store frequencies, first occurrences and last occurrences.

Key Idea:
- Use mp to track the frequency of each element.
- Use f to store the first occurrence and l to store the last occurrence.
- Find the maximum frequency (degree) of the array.
- For every element with that frequency, calculate its subarray length using last - first + 1.
- Return the minimum length found.
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n,i,ans,mx=0;
        n=nums.size();
        ans=n;
        unordered_map<int,int> mp,f,l;
        for(i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(!f.count(nums[i]))
            {
                f[nums[i]]=i;
            }
            l[nums[i]]=i;
            mx=max(mx,mp[nums[i]]);
        }
        for(auto x:mp)
        {
            if(x.second==mx)
            {
                ans=min(ans,l[x.first]-f[x.first]+1);
            }
        }
        return ans;
    }
};