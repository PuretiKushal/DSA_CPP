/*
    Problem: 1011. Capacity To Ship Packages Within D Days
    Pattern: Binary Search on Answer
    Difficulty: Medium

    Time Complexity: O(n * log(sum(weights)))
    Space Complexity: O(1)

    Key Idea:
    The answer is the ship's capacity.

    Search the capacity in the range:
    - Minimum capacity = maximum weight in the array.
    - Maximum capacity = sum of all package weights.

    For every candidate capacity (mid), simulate loading the
    packages in order without changing their order.

    - If all packages can be shipped within the given number
      of days, the capacity works.
      Save it as a possible answer and search for a smaller capacity.
    - Otherwise, the capacity is too small.
      Search for a larger capacity.

    Important Notes:
    - The lower bound must be the maximum weight since every
      package must fit on the ship.
    - The upper bound is the sum of all weights, meaning all
      packages can be shipped in one day.
    - Whenever the current load exceeds the capacity, start a
      new day and continue loading.
    - Use mid = l + (r - l) / 2 to avoid overflow.
    - Binary Search on Answer follows the monotonic pattern:
      F F F ... T T T ...
*/


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l,r,mid,total=0,sum=0,n,i,d,ans;
        n=weights.size();
        for(i=0;i<n;i++)
        {
            total=total+weights[i];
        }
        l=*max_element(weights.begin(),weights.end());
        r=total;
        ans=INT_MAX;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            d=1;
            sum=0;
            for(i=0;i<n;i++)
            {
                sum=sum+weights[i];
                if(sum>mid)
                {
                    d++;
                    sum=weights[i];
                }
            }
            if(d<=days)
            {
                ans=min(ans,mid);
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