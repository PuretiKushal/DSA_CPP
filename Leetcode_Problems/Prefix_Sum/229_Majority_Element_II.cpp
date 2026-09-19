/*
Problem: 229. Majority Element II
Pattern: Hashing + Frequency Counting
Difficulty: Medium

Time Complexity: O(n) average
(The first loop processes all n elements once.
The second loop processes at most n different hashmap entries.
unordered_map operations take O(1) average time.)

Space Complexity: O(n)
(In the worst case, all n elements are different, so the unordered_map
can store n different keys.)

Key Idea:
- Use an unordered_map 'mp' to store the frequency of each element.
- Traverse the array once and increase the frequency of every element:
    mp[nums[i]]++
- Traverse the hashmap using:
    for(auto x:mp)
- For every element:
    - x.first represents the element.
    - x.second represents its frequency.
- An element is a majority element if its frequency is greater than
  n/3.
- If x.second>ceil(n/3), add the element to 'ans'.
- Return 'ans' containing all elements that satisfy the condition.
- There can be at most two elements occurring more than n/3 times,
  because three such elements would require more than n elements.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n,i,j;
        n=nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second>ceil(n/3))
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};