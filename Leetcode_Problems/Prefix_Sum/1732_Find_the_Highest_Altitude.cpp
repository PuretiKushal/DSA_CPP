/*
Problem: 1732. Find the Highest Altitude
Pattern: Prefix Sum
Difficulty: Easy

Time Complexity: O(n)
- Traverses the gain array once.
- Updates the current altitude and maximum altitude at each step.

Space Complexity: O(1)
- Uses only a constant number of variables.

Key Idea:
- Initialize the current altitude x to 0.
- Traverse the gain array and add each gain to the current altitude.
- Track the maximum altitude reached using mx.
- Compare the maximum altitude with 0 because the starting altitude is also 0.
- Return the highest altitude.
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n,i,x,mx;
        x=0;
        n=gain.size();
        for(i=0;i<n;i++)
        {
            x+=gain[i];
            mx=max(mx,x);
        }
        return max(mx,0);
    }
};