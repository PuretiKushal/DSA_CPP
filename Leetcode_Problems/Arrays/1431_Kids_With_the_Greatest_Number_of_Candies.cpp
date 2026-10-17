/*
Problem: 1431. Kids With the Greatest Number of Candies
Pattern: Arrays + Greedy
Difficulty: Easy

Time Complexity: O(n)
- max_element() traverses the array once to find the maximum number of candies.
- The for loop traverses the array once and checks whether each kid can reach or exceed the maximum after receiving extraCandies.
- Both operations take O(n) time.

Space Complexity: O(n)
- The ans vector stores one boolean result for each kid.
- Therefore, the result vector requires O(n) space.

Key Idea:
- Find the current maximum number of candies using max_element().
- Traverse the candies array and consider each kid independently.
- Add extraCandies to the current kid's candies.
- If the resulting count is greater than or equal to the current maximum, push true into ans; otherwise, push false.
- Return the ans vector containing the result for every kid.
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n,i,mx;
        n=candies.size();
        vector<bool> ans;
        mx=*max_element(candies.begin(),candies.end());
        for(i=0;i<n;i++)
        {
                ans.push_back(candies[i]+extraCandies>=mx);
        }
        return ans;        
    }
};