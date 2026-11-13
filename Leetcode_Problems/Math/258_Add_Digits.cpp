/*
Problem: 258. Add Digits
Pattern: Math + Simulation
Difficulty: Easy

Time Complexity: O(log n)
- Each pass extracts and sums all digits of the number.
- Repeats until the number becomes a single digit.

Space Complexity: O(1)
- Uses only two variables (sum and rem).

Key Idea:
- Continue processing while num has more than one digit.
- Initialize sum to 0 at the beginning of each pass.
- Extract the last digit using num % 10.
- Add the extracted digit to sum.
- Remove the last digit using num / 10.
- After processing all digits, assign sum back to num.
- Repeat until num becomes a single-digit number.
*/

class Solution {
public:
    int addDigits(int num) {
        int sum,rem;
        while(num>=10)
        {
            sum=0;
            while(num>0)
            {
                rem=num%10;
                sum+=rem;
                num=num/10;
            }
            num=sum;
        }
        return num;
    }
};