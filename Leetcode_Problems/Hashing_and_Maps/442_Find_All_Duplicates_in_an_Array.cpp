/*
Problem: 442. Find All Duplicates in an Array
Pattern: Arrays + Hashing 
Difficulty: Medium

Time Complexity: O(n) average
- Traverse the array once.
- Each unordered_map insertion or lookup takes O(1) average time.
- Therefore, the overall average time complexity is O(n).

Space Complexity: O(n)
- The unordered_map stores the frequency of each distinct number.
- The answer vector stores all duplicate elements.
- In the worst case, the additional space used is O(n).

Key Idea:
- Use an unordered_map to count the occurrences of each number.
- Increment the frequency whenever a number is encountered.
- When its frequency becomes exactly 2, add it to the answer.
- Since each number appears at most twice, every duplicate is added exactly once.
- Return the vector containing all duplicate elements.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n,i;
        n=nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==2)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};