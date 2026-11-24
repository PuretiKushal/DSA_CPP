/*
Problem: 3411. Maximum Subarray With Equal Products
Pattern: Arrays / GCD and LCM
Difficulty: Easy

Time Complexity: O(n^2 * log M)
- Two nested loops generate every possible subarray.
- GCD and LCM calculations take logarithmic time, where M is the maximum element.

Space Complexity: O(1)
- Uses only a constant number of variables to maintain the product, GCD, LCM and maximum length.

Key Idea:
- Fix each starting index and extend the subarray one element at a time.
- Maintain the product, GCD and LCM incrementally as each element is added.
- Check whether the product equals the product of GCD and LCM.
- Update the maximum length whenever the condition is satisfied.
*/

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n,i,j,ans=0,g,l;
        double long long p;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            p=l=1;
            g=0;
            for(j=i;j<n;j++)
            {
                p*=nums[j];
                g=__gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                if(p==g*l)
                {
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
