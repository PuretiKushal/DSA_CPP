/*
Problem: 3727 - Maximum Alternating Sum of Squares
Pattern: Greedy + Sorting
Difficulty: Medium

Time Complexity: O(n log n)
(Sorting the array by absolute magnitude takes O(n log n) time.
Traversing the sorted array and adding or subtracting the square of
each element takes O(n) time. Therefore, the overall time complexity
is O(n log n).)

Space Complexity: O(log n)
(The sorting algorithm typically uses O(log n) auxiliary stack space
for introsort in C++. The algorithm does not create any additional
data structures proportional to the input size, as the sorting is
performed in-place.)

Key Idea:
- The alternating score adds squares at even indices and subtracts
  squares at odd indices.
- Since squaring removes the sign, the absolute magnitude of each
  element determines its contribution.
- Sort the elements by descending absolute magnitude.
- Place the largest magnitudes in positive positions and the smallest
  magnitudes in negative positions to maximize the score.
- For an odd-sized array, there is one extra positive position.
- Traverse the sorted array:
    1. Add nums[i] * nums[i] for the first (n+1)/2 elements.
    2. Subtract nums[i] * nums[i] for the remaining elements.
- Use long long for the score and squared values to avoid integer
  overflow.
*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n,i;
        long long ans=0,x;
        n=nums.size();
        sort(nums.begin(),nums.end(),[](int x,int y)
        {
            return abs(x)>abs(y);
        });
        for(i=0;i<n;i++)
        {
            long long x=nums[i];
            if(i<n/2||n%2==1&&i==n/2)
            {
                ans=ans+x*x;
            }
            else 
            {
                ans=ans-x*x;
            }
        }
        return ans;
    }
};