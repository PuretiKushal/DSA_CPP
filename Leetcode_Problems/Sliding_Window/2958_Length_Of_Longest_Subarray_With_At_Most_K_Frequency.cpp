/*
Problem: 2958. Length of Longest Subarray With at Most K Frequency
Pattern: Sliding Window
Difficulty: Medium

Time Complexity: O(n)
(Each element is added to the window once and removed
from the window at most once.)

Space Complexity: O(n)
(The unordered_map stores frequencies of elements.)

Key Idea:
- Maintain a sliding window from l to r.
- freq[x] stores the frequency of each number inside
  the current window.
- Expand the window by moving r forward.
- If the frequency of the newly added element becomes
  greater than k, shrink the window from the left until
  the frequency becomes valid again.
- At every valid window, update the maximum length.

Variables:

freq
- Stores the frequency of every number in the current window.

l
- Left boundary of the sliding window.

r
- Right boundary of the sliding window.
- Here r=i, so it could technically be avoided,
  but using it makes the window boundaries explicit.

mx
- Stores the maximum valid window length found so far.

Traversal:

for(i=0;i<n;i++)
{
    r=i;
    freq[nums[r]]++;
    ...
}

- Move r one position to the right.
- Add nums[r] to the current window.
- Increase its frequency.

Shrinking:

while(freq[nums[r]]>k)
{
    freq[nums[l]]--;
    l++;
}

- If the newly added element occurs more than k times,
  the window is invalid.
- Remove elements from the left until the window becomes
  valid again.
- Since the only possible violation is the frequency of
  nums[r], we check that frequency.

Updating Answer:

mx=max(mx,r-l+1);

- Once the window is valid, its length is r-l+1.
- Keep the largest valid length.

Important Notes:
- This is a variable-size sliding window.
- The window always represents a valid subarray after
  the while loop finishes.
- We do NOT reset the window when a frequency exceeds k.
  We only move l forward until the constraint is satisfied.
- The key sliding-window pattern is:

    Expand right
        ↓
    Constraint violated?
        ↓
    Shrink left
        ↓
    Update answer

Example:

nums = [1,2,2,1,1], k = 2

When the third 1 enters the window, its frequency
becomes 3, so we move l forward until its frequency
is at most 2.

The window therefore remains valid throughout the process.
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int i,l,r,mx,n;
        l=mx=0;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            r=i;
            freq[nums[r]]++;
            while(freq[nums[r]]>k)
            {
                freq[nums[l]]--;
                l++;
            }
            mx=max(mx,r-l+1);
        }
        return mx;
    }
};