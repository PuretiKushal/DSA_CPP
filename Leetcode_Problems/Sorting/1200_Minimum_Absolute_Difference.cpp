/*
Problem: 1200. Minimum Absolute Difference
Pattern: Sorting
Difficulty: Easy

Time Complexity: O(n log n)
- Sorts the array in O(n log n).
- First traversal finds the minimum absolute difference.
- Second traversal collects all pairs having that difference.

Space Complexity: O(1) Auxiliary Space
- Uses only a constant number of extra variables.
- Excluding the output vector and sorting implementation.

Key Idea:
- Sort the array in ascending order.
- The minimum absolute difference can only occur between adjacent elements.
- First, find the minimum difference between all adjacent elements.
- Traverse the array again and collect every adjacent pair whose difference equals the minimum.
- Return all such pairs.
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n,i,mn=INT_MAX;
        n=arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(i=1;i<n;i++)
        {
            mn=min(mn,arr[i]-arr[i-1]);   
        }
        for(i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]==mn)
            {
                ans.push_back({arr[i-1],arr[i]});
            }  
        }
        return ans;
    }
};