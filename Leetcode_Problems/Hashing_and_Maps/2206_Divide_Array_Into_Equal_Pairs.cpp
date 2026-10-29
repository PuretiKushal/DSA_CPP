/*
Problem: 2206. Divide Array Into Equal Pairs
Pattern: Hash Map + Frequency Counting
Difficulty: Easy

Time Complexity: O(n) average
- Traverse the array to count the frequency of each element.
- Traverse the hash map to check whether every frequency is even.

Space Complexity: O(n)
- The hash map stores the frequency of each distinct element.

Key Idea:
- Count the occurrences of every element using an unordered_map.
- Check whether each element has an even frequency.
- If any frequency is odd, return false because equal pairs cannot be formed.
- If all frequencies are even, return true.
*/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int i,f=0;
        for(i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second%2!=0)
            {
                f=1;
            }
        }
        if(f==1)
        {
            return false;
        }
        return true;
    }
};