/*
Problem: 2913. Subarrays Distinct Element Sum of Squares I
Pattern: Brute Force + Hashing
Difficulty: Easy

Time Complexity: O(n^2) average
- The outer loop considers every starting index.
- The inner loop extends the subarray to every possible ending index.
- Inserting an element into the unordered_set takes O(1) time on average.

Space Complexity: O(n)
- The unordered_set stores the distinct elements of the current subarray.
- In the worst case, it can contain up to n distinct elements.

Key Idea:
- Fix the starting index i and extend the subarray using j.
- Use an unordered_set to maintain the distinct elements in the current subarray.
- Insert nums[j] into the set as the subarray expands.
- The set automatically ignores duplicate elements.
- After each insertion, get the number of distinct elements using s.size().
- Add the square of this count to ans.
- Return ans after considering all possible subarrays.
*/

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n,i,j,ans=0;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            unordered_set<int> s;
            for(j=i;j<n;j++)
            {
                s.insert(nums[j]);
                ans=ans+s.size()*s.size();
            }
        }
        return ans;
    }
};