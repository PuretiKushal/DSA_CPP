/*
Problem: 977. Squares of a Sorted Array
Pattern: Two Pointers (Opposite Direction)
Difficulty: Easy

Time Complexity: O(n)
- Each element is processed exactly once.

Space Complexity: O(n)
- An extra array is used to store the sorted squares.

Key Idea:
- The largest square always comes from either the leftmost
  or the rightmost element because the array is sorted.

- Use:
    l -> leftmost element
    r -> rightmost element
    i -> last empty position in answer array

- Compare:
    abs(nums[l]) and abs(nums[r])

- If left absolute value is larger:
    - Store nums[l]² in ans[i]
    - Move l++

- Otherwise:
    - Store nums[r]² in ans[i]
    - Move r--

- Decrement i after every insertion.

Important Notes:
- l and r are indices, not values.
- Always compare:
    abs(nums[l]) and abs(nums[r])
- The answer is filled from the end because we place the
  largest remaining square first.
- Use while(l<=r) because when l==r, one element is still
  left to be processed.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l,r,n,i;
        n=nums.size();
        vector<int> ans(n);
        l=0;
        r=n-1;
        i=n-1;
        while(l<=r)
        {
            if(abs(nums[l])>=abs(nums[r]))
            {
                ans[i]=nums[l]*nums[l];
                l++;
            }
            else
            {
                ans[i]=nums[r]*nums[r];
                r--;
            }
            i--;
        }
        return ans;
    }
};