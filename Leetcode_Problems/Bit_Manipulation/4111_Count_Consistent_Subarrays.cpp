/*
Problem: 4111. Count Consistent Subarrays
Pattern: Bit Manipulation, Brute Force
Difficulty: Easy

Time Complexity: O(n^2)
- Use two nested loops to consider every possible subarray.
- Update the minimum and bitwise AND in constant time for each element.

Space Complexity: O(1)
- Uses only a fixed number of variables.

Key Idea:
- Consider every possible subarray starting at index i.
- mn stores the minimum element in the current subarray.
- x stores the bitwise AND of all elements in the current subarray.
- Extend the subarray by including nums[j].
- If the bitwise AND equals the minimum element, increment ans.
- Return the total count of consistent subarrays.
*/

class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n,i,j,mn,x;
        long long ans=0;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            mn=nums[i];
            x=nums[i];
            for(j=i;j<n;j++)
            {
                mn=min(mn,nums[j]);
                x=x&nums[j];
                if(x==mn)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};