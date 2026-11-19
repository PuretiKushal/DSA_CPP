/*
Problem: 495. Teemo Attacking
Pattern: Arrays / Interval Overlap
Difficulty: Medium

Time Complexity: O(n)
- Traverse the attack times once and calculate the effective poisoned duration between consecutive attacks.

Space Complexity: O(1)
- Only a constant number of variables are used.

Key Idea:
- For each attack except the last, add the minimum of duration and the time difference until the next attack.
- This handles overlapping poison durations without counting the same time twice.
- Add the full duration of the last attack.
*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n,i,ans=0;
        n=timeSeries.size();
        for(i=0;i<n-1;i++)
        {
            ans+=min(duration,timeSeries[i+1]-timeSeries[i]);
        }
        ans+=duration;
        return ans;
    }
};