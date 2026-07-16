/*
Problem: 1004. Max Consecutive Ones III
Pattern: Variable Size Sliding Window
Difficulty: Medium

Time Complexity: O(n)
(Right pointer 'r' moves from 0 to n-1 once.
 Left pointer 'l' also moves from 0 to n-1 at most once.
 Total pointer movements <= 2n --> O(n).)

Space Complexity: O(1)
(Only a few variables are used.)

Key Idea:
- Expand the window by moving the right pointer.
- Store the number of zeroes present in the current window using 'count'.
- Window Valid Condition:
    Number of Zeroes <= k
  (At most k zeroes can be flipped to 1.)

- While Expanding:
    if(nums[r]==0)
        count++;
  (A new zero enters the window.)

- If the window becomes invalid:
    count > k
  (More than k zeroes are present, so this window can never become a valid answer.)

- Shrink the window until it becomes valid again:
    while(count>k)
    {
        if(nums[l]==0)
            count--;
        l++;
    }
  (Decrease count only when a zero leaves the window.)

- After the window becomes valid again:
    ans=max(ans,r-l+1);
  (Update the maximum valid window length.)

Important Notes:
- Count stores the number of zeroes currently present in the window.
- We never actually flip any zeroes.
- We only check whether the current window can be made all 1s using at most k flips.
- Since the problem asks for the maximum window, update the answer only after the window becomes valid.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l,r,i,count,n,ans;
        n=nums.size();
        l=count=ans=0;
        for(r=0;r<n;r++)
            {
                if(nums[r]==0)
                {
                    count++;
                }
                while(count>k)
                    {
                        if(nums[l]==0)
                        {
                            count--;
                        }
                        l++;
                    }
                ans=max(ans,r-l+1);
            }
        return ans;
    }
};