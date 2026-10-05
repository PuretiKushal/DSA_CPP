/*
Problem: 171. Excel Sheet Column Number
Pattern: Math + String + Base Conversion
Difficulty: Easy

Time Complexity: O(n)
(We traverse the column title once. For each character, we perform
constant-time arithmetic operations.)

Space Complexity: O(1)
(Only a few integer variables are used apart from the input string.)

Key Idea:
- Convert the Excel column title into its corresponding column number.

- Excel columns follow a base-26-like representation:
    A = 1
    B = 2
    ...
    Z = 26

- Unlike normal base-26 representation, there is no digit representing
  0. Each character contributes a value from 1 to 26.

- For every character:
    1. Multiply the current result by 26 to shift the previous
       characters one position to the left.
    2. Add the value of the current character.

- The character value is calculated using:
    columnTitle[i] - 'A' + 1

- The update is:
    count = 26 * count + (columnTitle[i] - 'A' + 1)

- Example:
    columnTitle = "AB"

    Start:
        count = 0

    Process 'A':
        count = 26 * 0 + 1
              = 1

    Process 'B':
        count = 26 * 1 + 2
              = 28

    Therefore:
        "AB" = 28

- Another example:
    "ZY"

    Process 'Z':
        count = 26

    Process 'Y':
        count = 26 * 26 + 25
              = 701

- The main idea is the same as converting a number from another base:
    new_result = base * previous_result + current_digit

  Here, the base is 26 and the character values range from 1 to 26.
*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int i,count=0,n;
        n=columnTitle.size();
        for(i=0;i<n;i++)
        {
            count=26*count;
            count=count+(columnTitle[i]-'A'+1);
        }
        return count;
    }
};