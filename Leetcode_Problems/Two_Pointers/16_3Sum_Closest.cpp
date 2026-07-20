/*
Problem: 16. 3Sum Closest
Pattern: Two Pointers (Opposite Direction)
Difficulty: Medium

Time Complexity: O(n²)
- Sorting takes O(n log n).
- For each fixed element, the two pointers traverse the remaining array once.

Space Complexity: O(1)
- Only a few variables are used (excluding the sorting algorithm's internal space).

Key Idea:
- Sort the array.
- Fix one element using a loop.
- Use two pointers:
    l -> i + 1
    r -> n - 1

- Calculate the current triplet sum.

- If the current sum is closer to the target than the
  previously recorded sum:
    - Update the minimum difference.
    - Store the current sum as the answer.

- If:
    sum < target
    - Move l++ to increase the sum.

- If:
    sum > target
    - Move r-- to decrease the sum.

- If:
    sum == target
    - Return immediately since an exact match is the
      closest possible answer.

Important Notes:
- Unlike 3Sum, an exact target sum is not required.
- Keep track of the closest triplet sum found so far.
- Store both the minimum absolute difference and the
  corresponding triplet sum.
- Pointer movement follows the same logic as the classic
  3Sum problem.
- Use while(l<r) to explore all possible pairs for each
  fixed element.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i,l,r,n,sum,mndiff,ans;
        n=nums.size();
        sum=0;
        mndiff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(i=0;i<n;i++)
            {
                l=i+1;
                r=n-1;
                while(l<r)
                {
                    
                    sum=nums[i]+nums[l]+nums[r];
                    if(sum==target)
                    {
                        return sum;
                    }
                    else if(sum<target)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                    if(abs(sum-target)<mndiff)
                    {
                        mndiff=abs(sum-target);
                        ans=sum;
                    }
                }
            }
        return ans;
    }
};