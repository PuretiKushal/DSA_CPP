/*
    Problem: 1283. Find the Smallest Divisor Given a Threshold
    Pattern: Binary Search on Answer
    Difficulty: Medium

    Time Complexity: O(n * log(maxElement))
    Space Complexity: O(1)

    Key Idea:
    The answer is the divisor.

    Search for the divisor in the range:
    - Minimum divisor = 1
    - Maximum divisor = largest element in the array

    For each divisor (mid), calculate the sum of
    ceil(nums[i] / mid) for all elements.

    - If sum <= threshold, the divisor works.
      Save it as a possible answer and search for a smaller divisor.
    - If sum > threshold, the divisor is too small.
      Search for a larger divisor.

    Important Notes:
    - Ceiling division:
      (num + divisor - 1) / divisor
    - Use max_element() to find the upper bound.
    - Use mid = l + (r - l) / 2 to avoid overflow.
    - Binary Search on Answer works because the result follows
      a monotonic pattern:
      F F F ... T T T ...
*/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l,r,mid,i,sum,n,ans;
        n=nums.size();
        l=1;
        r=*max_element(nums.begin(),nums.end());
        ans=r;
        while(l<=r)
            {
                mid=l+(r-l)/2;
                sum=0;
                for(i=0;i<n;i++)
                    {
                        sum=sum+(nums[i]+mid-1)/mid;
                    }
                if(sum<=threshold)
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

