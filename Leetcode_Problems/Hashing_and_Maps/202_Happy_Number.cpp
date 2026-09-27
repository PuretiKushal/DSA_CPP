/*
Problem: 202. Happy Number
Pattern: Hashing + Number Manipulation
Difficulty: Easy

Time Complexity: O(log n) per number transformation
(The number of digits of n determines the cost of calculating the
sum of squared digits. The process repeats until either 1 is reached
or a previously seen number is detected.)

Space Complexity: O(k)
(The unordered_set stores the numbers encountered during the process.
Here, k is the number of distinct values encountered before reaching
1 or detecting a cycle.)

Key Idea:
- A happy number eventually reaches 1 after repeatedly replacing the
  number with the sum of the squares of its digits.
- Use an unordered_set 's' to store every number encountered.
- Continue the process while n is not 1.
- Before processing the current number:
    - Check whether it already exists in the set using:
        s.count(n)
    - If it exists, a cycle has been detected, so the number is not
      happy and we return false.
- Insert the current number into the set.
- Calculate the sum of squares of its digits:
    - Extract the last digit using:
        rem=n%10
    - Add its square to 'sum':
        sum=sum+(rem*rem)
    - Remove the last digit using:
        n=n/10
- Set n equal to the calculated sum and repeat the process.
- If n becomes 1, return true because the original number is happy.
*/

class Solution {
public:
    bool isHappy(int n) {
        int sum=0,rem;
        unordered_set<int> s;
        while(n!=1)
        {
            if(s.count(n))
            {
                return false;
            }
            s.insert(n);
            sum=0;
            while(n>0)
            {
                rem=n%10;
                sum=sum+(rem*rem);
                n=n/10;
            }
            n=sum;
        }
        return true;
    }
};