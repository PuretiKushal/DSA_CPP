/*
    Problem: 410. Split Array Largest Sum
    Pattern: Binary Search on Answer
    Difficulty: Hard

    Time Complexity: O(n * log(sum(nums)))
    Space Complexity: O(1)

    Key Idea:
    We need to minimize the largest subarray sum after splitting
    the array into exactly 'k' subarrays.

    Binary search on the answer (maximum allowed subarray sum).

    For each candidate value (mid), greedily keep adding
    elements to the current subarray. If adding the next element
    makes the sum exceed 'mid', start a new subarray.

    If the array can be split into at most 'k' subarrays,
    then 'mid' is a valid answer. Store it and try a smaller
    maximum sum. Otherwise, try a larger maximum sum.

    Important Notes:
    - Search space:
        l = maximum element in the array
        r = sum of all elements
    - Every individual element must fit inside a subarray,
      so l cannot be smaller than the maximum element.
    - Greedily creating a new subarray only when necessary
      produces the minimum number of subarrays for a given 'mid'.
    - If count <= k, search left (r = mid - 1) since we want
      to minimize the maximum subarray sum.
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l,r,mid,sum=0,n,count,ans,i;
        n=nums.size();
        l=*max_element(nums.begin(),nums.end());
        for(i=0;i<n;i++)
            {
                sum=sum+nums[i];
            }
        r=sum;
        sum=0;
        while(l<=r)
            {
                mid=l+(r-l)/2;
                sum=0;
                count=1;
                for(i=0;i<n;i++)
                    {
                        sum=sum+nums[i];
                        if(sum>mid)
                        {
                            count++;
                            sum=nums[i];
                        }
                        
                    }
                if(count<=k)
                {
                    ans=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
        return ans;
    }
};