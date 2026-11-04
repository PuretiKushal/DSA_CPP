/*
Problem: 1051. Height Checker
Pattern: Sorting
Difficulty: Easy

Time Complexity: O(n log n)
- Creates a copy of the original heights array.
- Sorts the copied array in O(n log n).
- Traverses both arrays once to count mismatched positions.

Space Complexity: O(n)
- Creates an additional array to store the sorted heights.

Key Idea:
- Create a copy of the original heights array.
- Sort the copied array to obtain the expected order.
- Compare each element of the sorted array with the original array.
- Increment count whenever the elements at the same index differ.
- Return the total number of mismatched positions.
*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n,count=0,i;
        n=heights.size();
        vector<int> arr(heights);
        sort(arr.begin(),arr.end());
        for(i=0;i<n;i++)
        {
            if(arr[i]!=heights[i])
            {
                count++;
            }
        }
        return count;
    }
};