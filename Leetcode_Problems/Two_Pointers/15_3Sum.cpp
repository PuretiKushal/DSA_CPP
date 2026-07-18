/*
Problem: 15. 3Sum
Pattern: Two Pointers + Sorting
Difficulty: Medium 

Time Complexity: O(n²)
- Sorting takes O(n log n).
- For each fixed element, the two pointers together move at most O(n).
- Overall: O(n²).

Space Complexity: O(1)
- Ignoring the output vector.
- Only a few variables are used.

Key Idea:
- Sort the array first.
- Fix one element using a for loop.
- Use Two Pointers on the remaining part of the array.
- If sum < 0, move the left pointer to increase the sum.
- If sum > 0, move the right pointer to decrease the sum.
- If sum == 0:
    - Store the triplet.
    - Skip duplicate values for both pointers.
    - Move both pointers inward and continue searching.

Important Notes:
- Skip duplicate values of i using:
    if(i>0 && nums[i]==nums[i-1]) continue;
  This prevents generating the same triplets again.

- Skip duplicate values of l and r only after finding a valid triplet.

- l starts from i+1 because nums[i] is already fixed.

- r starts from n-1 since we search the remaining part of the sorted array.

- push_back() stores every valid triplet in the answer vector.

- continue skips the current iteration and moves to the next value of i.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l,r,n,i,sum;
        n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            l=i+1;
            r=n-1;
            while(l<r)
            {
                sum=nums[i]+nums[r]+nums[l];
                if(sum<0)
                {
                    l++;
                }
                else if(sum>0)
                {
                    r--;
                }
                else
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l<r&&nums[l]==nums[l+1])
                    {
                        l++;
                    }
                    while(r>l&&nums[r]==nums[r-1])
                    {
                        r--;
                    }
                    l++;
                    r--;
                }
            }    
        }
        return ans;
    }
};

