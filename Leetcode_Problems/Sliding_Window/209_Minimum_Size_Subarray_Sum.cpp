/*
Problem: 209. Minimum Size Subarray Sum
Pattern: Variable Size Sliding Window
Difficulty: Medium

Time Complexity: O(n)
(Right pointer 'r' moves from 0 to n-1 once.
 Left pointer 'l' also moves from 0 to n-1 at most once.
 Total pointer movements <= 2n --> O(n))

Space Complexity: O(1)
(Only a few variables are used.)

Key Idea:
- Expand the window by moving the right pointer.
- Keep adding elements to the current window sum.
- When the window sum becomes >= target:
    - Update the minimum window length.
    - Shrink the window by removing the left element.
- Repeat until the end of the array.
- If no valid window is found, return 0.
  (INT_MAX is used as the initial answer. If it remains unchanged,
   no valid window was found.)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l,r,sum,n,ans;
        n=nums.size();
        l=sum=0;
        ans=INT_MAX;
        for(r=0;r<n;r++)
            {
                sum=sum+nums[r];
                while(sum>=target)
                    {
                        ans=min(ans,r-l+1);
                        sum=sum-nums[l];
                        l++;
                        
                        
                    }
            }
        if(ans==INT_MAX)
        {
            ans=0;

        }
        return ans;
        
    }
};