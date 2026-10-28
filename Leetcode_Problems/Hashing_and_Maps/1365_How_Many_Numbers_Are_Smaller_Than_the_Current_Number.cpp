/*
Problem: 1365. How Many Numbers Are Smaller Than the Current Number
Pattern: Sorting + Hash Map
Difficulty: Easy

Time Complexity: O(n log n)
- Sorting the copied array takes O(n log n).
- Building the hash map and constructing the answer take O(n) average time.

Space Complexity: O(n)
- Stores a copy of the input array, the answer vector, and the hash map.

Key Idea:
- Create a copy of the original array and sort it in ascending order.
- Store each distinct value's first index in the sorted array.
- The first index represents the number of elements strictly smaller than that value.
- Traverse the original array and use the hash map to fill the answer.
- Duplicate values receive the same count because only their first sorted index is stored.
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n,i;
        n=nums.size();
        vector<int> a=nums;
        vector<int> ans(n);
        unordered_map<int,int> mp;
        sort(a.begin(),a.end());
        for(i=0;i<n;i++)
        {
            if(mp.find(a[i])==mp.end())
            {
                mp[a[i]]=i;
            }
        }
        for(i=0;i<n;i++)
        {
            ans[i]=mp[nums[i]];
        }
        return ans;
    }
};