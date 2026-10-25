/*
Problem: 4093. Maximize Sum After at Most K Digit Rearrangements
Pattern: Greedy + String Manipulation + Sorting
Difficulty: Easy

Time Complexity: O(n log n + n*d log d)
- n is the size of nums and d is the maximum number of digits in an element.
- Sorts each number's digits in descending order.
- Sorts the gains in descending order.

Space Complexity: O(n + d)
- Stores the gains in the ex vector.
- Uses a string to rearrange the digits of each number.

Key Idea:
- Calculate the original sum of all elements.
- Convert each number to a string and sort its digits in descending order.
- Convert the rearranged number back to an integer.
- Store the gain (rearranged number - original number) in ex.
- Sort all gains in descending order.
- Add the largest k gains to the original sum.
- Return the maximum sum.
*/

class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n,i,x;
        long long sum=0;
        vector<int> ex;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            sum=sum+nums[i];
            string s=to_string(nums[i]);
            sort(s.rbegin(),s.rend());
            x=stoi(s);
            ex.push_back(x-nums[i]);
        }
        sort(ex.rbegin(),ex.rend());
        for(i=0;i<k;i++)
        {
            sum=sum+ex[i];
        }
        return sum;
    }
};