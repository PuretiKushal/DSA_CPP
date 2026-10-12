/*
Problem: 219. Contains Duplicate II
Pattern: Hashing + Last Seen Index
Difficulty: Easy

Time Complexity: O(n)
(The array is traversed once. For each element, the unordered_map
performs an average O(1) lookup and insertion/update operation.
Therefore, the overall average time complexity is O(n).)

Space Complexity: O(n)
(The unordered_map stores the most recent index of each distinct
element. In the worst case, all n elements are distinct, requiring
O(n) auxiliary space.)

Key Idea:
- Use an unordered_map to store each number's most recent index.
- Traverse the array from left to right.
- For each element nums[i]:
    1. Check whether the number already exists in the map.
    2. If it exists, calculate the distance between the current index
       and its previously stored index.
    3. If the distance is <= k, return true because a nearby duplicate
       has been found.
    4. Otherwise, update the map with the current index.
- Store the latest index every time so that future duplicate checks
  use the closest previous occurrence.
- If no valid pair is found after traversing the array, return false.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n,i;
        n=nums.size();
        unordered_map<int,int> mp;
        for(i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end()&&i-mp[nums[i]]<=k)
            {
                return true;
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};