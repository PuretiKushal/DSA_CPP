/*
Problem: 169. Majority Element
Pattern: Hashing + Frequency Counting
Difficulty: Easy

Time Complexity: O(n) average
(Each element is processed once, and unordered_map operations such as
access and insertion take O(1) average time.)

Space Complexity: O(n)
(In the worst case, the unordered_map stores n different elements.)

Key Idea:
- Use an unordered_map 'mp' to store the frequency of each element.
- Traverse the array from left to right.
- For every element nums[i]:
    - Increase its frequency using:
        mp[nums[i]]++
    - If its frequency becomes greater than the current maximum
      frequency 'mx':
        - Update 'mx' with the new frequency.
        - Store nums[i] as the current majority candidate in 'ans'.
- After processing all elements, 'ans' contains the element with
  the highest frequency.
- The problem guarantees that a majority element exists, so the
  element with the highest frequency is the required answer.
- 'mx' is initialized to INT_MIN so that the first frequency can
  always become the initial maximum.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i,n,mx,ans=0;
        n=nums.size();
        unordered_map<int,int> mp;
        mx=INT_MIN;
        for(i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>mx)
            {
                mx=mp[nums[i]];
                ans=nums[i];
            }
        }
        return ans;
    }
};