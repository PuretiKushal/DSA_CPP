/*
Problem: 453. Minimum Moves to Equal Array Elements III
Pattern: Array 
Difficulty: Medium

Time Complexity: O(n)
- Finding the maximum element using max_element() takes O(n).
- Traversing the array to calculate the total difference takes O(n).

Space Complexity: O(1)
- Uses only a constant amount of extra space.

Key Idea:
- Find the maximum element in the array.
- Calculate the difference between the maximum and every element.
- Add all differences to get the total number of moves.
- Return the accumulated sum.
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int i,n,mx,count=0;
        n=nums.size();
        mx=*max_element(nums.begin(),nums.end());
        for(i=0;i<n;i++)
        {
            count+=mx-nums[i];
        }
        return count;
    }
};

