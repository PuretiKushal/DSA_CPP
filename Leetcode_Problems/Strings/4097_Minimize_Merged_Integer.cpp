/*
Problem: 4097. Minimize Merged Integer
Pattern: Array + String Manipulation + Greedy
Difficulty: Easy

Time Complexity: O(n)
- Traverses the array in pairs.
- Each pair is converted to strings and concatenated.
- Conversion and concatenation take time proportional to the number of digits.

Space Complexity: O(d)
- Uses temporary strings to concatenate each pair.
- d represents the maximum number of digits in the merged integer.

Key Idea:
- Initialize mn with INT_MAX.
- Traverse the array by taking two adjacent elements at a time.
- Convert both elements into strings and concatenate them.
- Convert the merged string back into an integer using stoi().
- Update mn with the minimum merged integer.
- Return the minimum value found.
*/

class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n,i,mn,x;
        mn=INT_MAX;
        n=nums.size();
        for(i=0;i<n-1;i+=2)
        {
            string s;
            s=to_string(nums[i])+to_string(nums[i+1]);
            x=stoi(s);
            mn=min(mn,x);
        }
        return mn;
    }
};