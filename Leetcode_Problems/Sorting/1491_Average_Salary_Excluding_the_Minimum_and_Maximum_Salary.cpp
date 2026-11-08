/*
Problem: 1491. Average Salary Excluding the Minimum and Maximum Salary
Pattern: Sorting
Difficulty: Easy

Time Complexity: O(n log n)
- Sorts the salary array in O(n log n).
- Traverses the array once, excluding the first and last elements.

Space Complexity: O(1) Auxiliary Space
- Uses only a constant amount of extra space.
- Excluding sorting implementation.

Key Idea:
- Sort the salary array in ascending order.
- The first element represents the minimum salary.
- The last element represents the maximum salary.
- Traverse the array from index 1 to n-2 and calculate the sum.
- Divide the sum by (n-2) to calculate the average.
- Convert the sum to double to avoid integer division.
*/

class Solution {
public:
    double average(vector<int>& salary) {
        int n,i,count=0;
        n=salary.size();
        sort(salary.begin(),salary.end());
        for(i=1;i<n-1;i++)
        {
            count+=salary[i];
        }
        return (double)count/(n-2);
    }
};