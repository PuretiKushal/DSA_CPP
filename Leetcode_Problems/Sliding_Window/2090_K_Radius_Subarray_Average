/*
Problem: 2090. K Radius Subarray Averages
Pattern: Fixed Size Sliding Window
Difficulty: Medium
Time Complexity: O(n) (2 for loops; one from 0 to 2*k+1 and another from 2*k+1 to n --> 0 to n --> O(n))
Space Complexity: O(n) (The answer vector of size n is used --> O(n))

Key Idea:
- Calculate first window sum (first for loop)
- Slide the window (second for loop)
- Remove left element (sum=sum-nums[i-2*k-1])
- Add right element (sum=sum+nums[i])
- Store the average at the center index of the window (ans[i-k]=avg)
- Return the answer vector
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int i,n,avg=0;
        long long sum=0;
        n=nums.size();
        vector<int> ans(n,-1);
        if(n>=2*k+1)
        {
            for(i=0;i<2*k+1;i++)
            {
                sum=sum+nums[i];
                avg=sum/(2*k+1);
            }
            ans[k]=avg;
            for(i=2*k+1;i<n;i++)
            {
                sum=sum+nums[i]-nums[i-2*k-1];
                avg=sum/(2*k+1);
                ans[i-k]=avg;
                
            }
            return ans;
        }
        else
        {
            return ans;
        }      
    }
};