/*
Problem: 217. Contains Duplicate
Pattern: Hashing + Frequency Counting
Difficulty: Easy

Time Complexity: O(n) average
(Each element is processed once, and unordered_map operations such as
access and insertion take O(1) average time.)

Space Complexity: O(n)
(In the worst case, all n elements are unique, so the unordered_map
stores n different keys.)

Key Idea:
- Use an unordered_map 'mp' to store the frequency of each number.
- Traverse the array from left to right.
- For every element nums[i]:
    - Increase its frequency using:
        mp[nums[i]]++
    - If its frequency becomes 2 or more:
        - The element has appeared before.
        - Therefore, a duplicate exists, so return true.
- If the complete array is traversed without finding a frequency
  of 2 or more, return false.
- The duplicate is detected immediately when it is encountered,
  so the remaining elements do not need to be processed.
*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n,i,j;
        unordered_map<int,int> mp;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>=2)
            {
                return true;
            }
        }
        return false;
    }
};