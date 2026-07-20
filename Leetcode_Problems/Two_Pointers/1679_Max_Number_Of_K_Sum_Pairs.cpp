/*
Problem: 1679. Max Number of K-Sum Pairs
Pattern: Two Pointers (Opposite Direction)
Difficulty: Medium

Time Complexity: O(n log n)
- Sorting the array takes O(n log n).
- The two pointers traverse the array only once in O(n).

Space Complexity: O(1)
- Only a few variables are used (excluding the sorting algorithm's internal space).

Key Idea:
- Sort the array so that the numbers are in increasing order.
- Use two pointers:
    l -> smallest available element
    r -> largest available element

- Compare:
    nums[l] + nums[r]

- If:
    nums[l] + nums[r] < k

    - Current sum is too small.
    - Move l++ to increase the sum.

- If:
    nums[l] + nums[r] > k

    - Current sum is too large.
    - Move r-- to decrease the sum.

- Otherwise:

    - A valid pair is found.
    - Increment the answer.
    - Move both l++ and r-- since both elements are already used.

- Continue until the pointers cross.

Important Notes:
- Sorting is necessary because pointer movement relies on the array being ordered.
- l always points to the smallest remaining element.
- r always points to the largest remaining element.
- Moving l increases the current sum.
- Moving r decreases the current sum.
- When a valid pair is formed, both elements are removed from consideration, so both pointers move.
- Use while(l<r) because a pair requires two different indices, and once the pointers meet, no more pairs can be formed.
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l,r,count,n;
        n=nums.size();
        l=count=0;
        r=n-1;
        sort(nums.begin(),nums.end());
        while(l<r)
            {
                if(nums[l]+nums[r]<k)
                {
                    l++;
                }
                else if(nums[l]+nums [r]>k)
                {
                    r--;
                }
                else
                {
                    count++;
                    l++;
                    r--; 
                }
            }
        return count;
    }
};