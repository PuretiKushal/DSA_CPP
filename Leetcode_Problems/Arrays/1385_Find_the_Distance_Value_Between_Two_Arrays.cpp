/*
Problem: 1385. Find the Distance Value Between Two Arrays
Pattern: Arrays · Nested Loops
Difficulty: Easy

Time Complexity: O(n * m)
- Checks each element of arr1 against elements of arr2.
- Stops checking an element as soon as a difference is <= d.

Space Complexity: O(1)
- Uses only a constant amount of extra space.

Key Idea:
- For every element in arr1, check its absolute difference
  with each element in arr2.
- If any difference is <= d, that element does not qualify.
- Increment count for every non-qualifying element.
- Return n - count to get the number of qualifying elements.
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n,m,i,j,count=0;
        n=arr1.size();
        m=arr2.size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(abs(arr1[i]-arr2[j])<=d)
                {
                    count++;
                    break;
                }
            }
        }
        return n-count;
    }
};