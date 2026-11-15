/*
Problem: 1524. Number of Sub-arrays With Odd Sum
Pattern: Prefix Sum, Parity
Difficulty: Medium

Time Complexity: O(n)
- Traverse the array once, maintaining the prefix sum and counting odd-sum subarrays.

Space Complexity: O(1)
- Uses only a fixed number of variables.

Key Idea:
- Use prefix sum parity to determine whether a subarray has an odd sum.
- e stores the count of even prefix sums, initially 1 for the empty prefix.
- o stores the count of odd prefix sums, initially 0.
- If the current prefix sum is even, add o to count because an odd prefix minus an even prefix gives an odd subarray sum.
- If the current prefix sum is odd, add e to count because an odd prefix minus an even prefix gives an odd subarray sum.
- Update the corresponding parity count after processing each element.
- Use modulo 10^9 + 7 to keep the answer within the required limit.
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n,i,e=1,o=0,sum=0,count=0;
        int mod=1e9+7;
        n=arr.size();
        for(i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum%2==0)
            {
                count=(count+o)%mod;
                e++;
            }
            else
            {
                count=(count+e)%mod;
                o++;
            }
        }
        return count;
    }
};