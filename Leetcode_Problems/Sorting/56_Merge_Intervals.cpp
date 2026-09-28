/*
Problem: 56. Merge Intervals
Pattern: Sorting + Greedy
Difficulty: Medium

Time Complexity: O(n log n)
(The intervals are first sorted, which takes O(n log n).
The intervals are then traversed once to merge overlapping intervals,
which takes O(n). Therefore, the overall complexity is O(n log n).)

Space Complexity: O(n)
(The answer vector 'ans' can contain up to n intervals.
The sorting operation may also use additional space depending on
the implementation.)

Key Idea:
- First sort the intervals.
- After sorting, intervals are ordered by their starting values.
- Handle the first two intervals separately:
    - If they overlap:
        - Find the minimum starting value.
        - Find the maximum ending value.
        - Store the merged interval in 'ans'.
    - Otherwise:
        - Add both intervals separately to 'ans'.
- Starting from the third interval:
    - Compare its starting value with the ending value of the last
      interval in 'ans'.
- If:
    ans.back()[1]>=intervals[i][0]
    - The current interval overlaps with the last merged interval.
    - Merge them by taking:
        minimum of the starting values
        maximum of the ending values
    - Update the last interval in 'ans'.
- Otherwise:
    - There is no overlap.
    - Add the current interval directly to 'ans'.
- Since the intervals are sorted by starting value, comparing with
  only the last merged interval is sufficient.
- Finally, return 'ans' containing all merged intervals.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n,i,j,mn,mx,f=0;
        n=intervals.size();
        if(n==1)
        {
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        mn=INT_MAX;
        mx=INT_MIN;
        if(intervals[0][1]>=intervals[1][0])
            {
                mn=min(intervals[0][0],intervals[1][0]);
                mx=max(intervals[0][1],intervals[1][1]);
                ans.push_back({mn,mx});
                i=2;
            }
        else
        {
            ans.push_back({intervals[0][0],intervals[0][1]});
            ans.push_back({intervals[1][0],intervals[1][1]});
        }
        for(i=2;i<n;i++)
        {
            mn=INT_MAX;
            mx=INT_MIN;
            if(ans.back()[1]>=intervals[i][0])
            {
                mn=min(ans.back()[0],intervals[i][0]);
                mx=max(ans.back()[1],intervals[i][1]);
                ans.back()[0]=mn;
                ans.back()[1]=mx;
            }
            else
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }        
        return ans;
    }
};