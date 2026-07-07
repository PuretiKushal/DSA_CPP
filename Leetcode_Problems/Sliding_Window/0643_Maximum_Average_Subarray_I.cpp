/*
Problem: 643. Maximum Average Subarray I
Pattern: Fixed Size Sliding Window
Difficulty: Easy
Time Complexity: O(n) (2 for loops; one from 0 to k and another from k to n --> 0 to n --> O(n))
Space Complexity: O(1) (Only 4 variables are used --> O(4) --> O(1))

Key Idea:
- Calculate first window sum (first for loop)
- Slide the window (second for loop)
- Remove left element (sum=sum-nums[i-k])
- Add right element (sum=sum+nums[i])
- Keep track of maximum sum (ans=max(sum,ans)
*/

class Solution {
public:
    double findMaxAverage(vector <int>& nums, int k) {
        int i,n,sum=0,ans;
        n=nums.size();
        for(i=0;i<k;i++)
            {
                sum=sum+nums[i];
            }
        ans=sum;
        for(i=k;i<n;i++)
            {
                sum=sum-nums[i-k]+nums[i];
                ans=max(sum,ans);
            }
        return (double)ans/k; //average is floating point number so we need to typecast it to double
    }
};