/*
Problem: 1295. Find Numbers with Even Number of Digits
Pattern: Arrays · Math
Difficulty: Easy

Time Complexity: O(n * log(max(nums)))
- Traverses the array once.
- For each number, counts its digits using repeated division by 10.
- Each number requires O(log(num)) operations to count its digits.

Space Complexity: O(1)
- Uses only a constant amount of extra space.

Key Idea:
- Traverse each element of the array.
- Count the number of digits by repeatedly dividing the number by 10.
- If the digit count is even, increment count.
- Reset the digit counter for every new element.
- Return the total count of numbers having an even number of digits.

Note:
- The solution modifies the input array because nums[i] is
  repeatedly divided by 10.
- This is acceptable for the problem, but a temporary variable
  can be used if the original array needs to be preserved.
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n,i,count,d;
        n=nums.size();
        count=d=0;
        for(i=0;i<n;i++)
        {
            d=0;
            while(nums[i]!=0)
            {
                nums[i]=nums[i]/10;
                d++;
            }
            if(d%2==0)
            {
                count++;
            }
        }
        return count;
    }
};