/*
Problem: 1619. Mean of Array After Removing Some Elements
Pattern: Sorting · Array
Difficulty: Easy

Time Complexity: O(n log n)
- Sorts the array in O(n log n).
- Traverses the remaining elements once to calculate their sum.

Space Complexity: O(1) Auxiliary Space
- Uses only a constant amount of extra space.
- Excluding sorting implementation.

Key Idea:
- Sort the array in ascending order.
- Calculate 5% of the array size to determine how many
  elements must be removed from each end.
- Traverse the array, skipping the smallest and largest 5%.
- Calculate the sum of the remaining elements.
- Divide the sum by the number of remaining elements.
- Convert the sum to double to avoid integer division.
*/

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n,i,count=0,val;
        n=arr.size();
        sort(arr.begin(),arr.end());
        val=(5*n)/100;
        for(i=val;i<n-val;i++)
        {
            count+=arr[i];
        }
        return (double)count/(n-2*val);
    }
};