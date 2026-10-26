/*
Problem: 228. Summary Ranges
Pattern: Array + Two Pointers
Difficulty: Easy

Time Complexity: O(n)
- Traverses the array once.
- Each element is processed a constant number of times.

Space Complexity: O(1) auxiliary space
- Uses a constant number of variables.
- Output vector requires O(n) space in the worst case.

Key Idea:
- Initialize the start of the current range with the first element.
- Traverse the array and check whether adjacent elements are consecutive.
- If a gap is found, close the current range and add it to the answer.
- Start a new range from the current element.
- After the loop, add the final range to the answer.
- If the start and end are equal, store a single number; otherwise, store the range as "start->end".
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n,i,s,e;
        n=nums.size();
        vector<string> ans;
        if(n==0)
        {
            return ans;
        } 
        s=nums[0];
        for(i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1]+1)
            {
                e=nums[i-1];
                if(s==e)
                {
                    ans.push_back(to_string(s));
                }
                else
                {
                    ans.push_back(to_string(s)+"->"+to_string(e));
                }
                s=nums[i];
            }
        }
        e=nums[n-1];
        if(s==e)
        {
            ans.push_back(to_string(s));
        }
        else
        {
            ans.push_back(to_string(s)+"->"+to_string(e));
        }
        return ans;
    }
};