/*
Problem: 4121. Minimum Cost to Make All Array Elements Equal
Pattern: Arrays 
Difficulty: Medium

Time Complexity: O(n)
- Traverse the array once, skipping consecutive groups of equal elements.
- Calculate the cost for each eligible group.

Space Complexity: O(1)
- Uses only a constant number of extra variables.

Key Idea:
- Identify consecutive groups of equal elements.
- Consider groups that have at least one element before and after them.
- Calculate the cost of making the elements outside the group equal to the group's value.
- Keep track of the minimum cost among all eligible groups.
*/

class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n,i,j;
        long long ans=LLONG_MAX,cost;
        n=nums.size();
        for(i=0;i<n;)
        {
            j=i;
            while(j+1<n&&nums[j]==nums[j+1])
            {
                j++;
            }
            if(i<=n-2&&j>=1)
            {
                cost=0;
                if(i>0)
                {
                    cost+=(long long)i*nums[i];
                }
                if(j<n-1)
                {
                    cost+=(long long)(n-j-1)*nums[i];
                }
                ans=min(ans,cost);
            }
            i=j+1;
        }
        return ans;
    }
};