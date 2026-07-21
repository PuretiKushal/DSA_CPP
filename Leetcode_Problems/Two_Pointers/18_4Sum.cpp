/*
Problem: 18. 4Sum
Pattern: Two Pointers (Opposite Direction)
Difficulty: Medium

Time Complexity: O(n³)
- Sorting takes O(n log n).
- Two nested loops fix the first two elements.
- Two pointers traverse the remaining array in linear time.

Space Complexity: O(1)
- Only a few extra variables are used (excluding the output array and sorting algorithm's internal space).

Key Idea:
- Sort the array.
- Fix the first element using index i.
- Fix the second element using index j.
- Use two pointers:
    l -> j + 1
    r -> n - 1

- Calculate the sum of the four elements.
- If the sum is smaller than the target:
    - Move l++ to increase the sum.
- If the sum is greater than the target:
    - Move r-- to decrease the sum.
- If the sum equals the target:
    - Store the quadruplet.
    - Move both pointers.
    - Skip duplicate values for l and r.

Important Notes:
- Skip duplicate values for i and j before processing to avoid generating duplicate quadruplets.
- After finding a valid quadruplet, skip duplicate values for l and r before continuing the search.
- Use long long while calculating the sum to avoid integer overflow.
- Store element values in the answer, not their indices.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int l,r,n,i,j;
        long long sum=0;
        n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(i=0;i<n;i++)
            {
                if(i>0&&nums[i]==nums[i-1])
                {
                    continue;
                }
                for(j=i+1;j<n;j++)
                    {
                        if(j>i+1&&nums[j]==nums[j-1])
                        {
                            continue;
                        }
                            
                        {
                            l=j+1;
                            r=n-1;
                            while(l<r)
                                {
                                   sum=(long long) nums[i]+nums[j]+nums[l]+nums[r];
                                if(sum<target)
                                    {
                                        l++;
                                    }
                                    else if(sum>target)
                                    {
                                        r--;
                                    }
                                    else
                                    {
                                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                                        l++;
                                        r--;
                                        while(l<r&&nums[l]==nums[l-1])
                                        {
                                            l++;
                                        }
                                    while(l<r&&nums[r]==nums[r+1])
                                        {
                                            r--;
                                        }
                                   
                                    }
                                    
                                }
                        }
                    }
            }
        return ans;
        
    }
};