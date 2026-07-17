/*
Problem: 167. Two Sum II - Input Array Is Sorted
Pattern: Two Pointers (Opposite Direction)
Difficulty: Medium

Time Complexity: O(n)
(Left pointer 'l' moves from left to right at most n times.
 Right pointer 'r' moves from right to left at most n times.
 Total pointer movements <= 2n --> O(n).)

Space Complexity: O(1)
(Only a few variables are used.)

Key Idea:
- Since the array is sorted, we can use two pointers.
- Place:
    l = 0
    r = n-1

- Calculate:
    sum = numbers[l] + numbers[r]

- If sum == target:
    Return the 1-based indices.

- If sum < target:
    Move l++
    (Need a larger sum, so choose a larger number.)

- If sum > target:
    Move r--
    (Need a smaller sum, so choose a smaller number.)

Important Notes:
- This approach works only because the array is sorted.
- Moving the left pointer always increases (or keeps) the value.
- Moving the right pointer always decreases (or keeps) the value.
- Each pointer moves at most once across the array, giving O(n) time complexity.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l,r,n,sum;
        n=numbers.size();
        l=sum=0;
        r=n-1;
        while(l<r)
        {
            sum=numbers[l]+numbers[r];
            if(sum==target)
            {
                return {l+1,r+1};
            }
            else if(sum<target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return {};
    }
};