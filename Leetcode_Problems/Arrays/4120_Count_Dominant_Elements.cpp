/*
Problem: 4120. Count Dominant Elements
Pattern: Arrays 
Difficulty: Easy

Time Complexity: O(n)
- Traverse the array once and compare each element with its adjacent elements.

Space Complexity: O(1)
- Uses only a constant number of variables.

Key Idea:
- Handle the single-element array separately.
- For the first element, compare it with the second element.
- For the last element, compare it with the previous element.
- For every middle element, check whether twice its value is greater than or equal to the sum of its two neighbors.
- Increment the count whenever the condition is satisfied.
*/

class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n,i,count=0;
        n=nums.size();
        if(n==1)
        {
            return 1;
        }
        if(nums[0]>=nums[1])
        {
            count++;
        }
        for(i=1;i<n-1;i++)
        {
            if(2*nums[i]>=nums[i-1]+nums[i+1])
            {
                count++;
            }
        }
        if(nums[n-1]>=nums[n-2])
        {
            count++;
        }
        return count;
    }
};