/*
Problem: 476. Number Complement
Pattern: Bit Manipulation + String Manipulation
Difficulty: Easy

Time Complexity: O(log n)
- Converts the number into its binary representation.
- Reverses the binary string.
- Traverses the binary string to generate its complement.

Space Complexity: O(log n)
- Stores the binary representation and its complemented string.

Key Idea:
- Convert the given integer into its binary representation.
- Reverse the string to obtain the correct bit order.
- Traverse the binary string and flip every bit:
  - Replace 0 with 1.
  - Replace 1 with 0.
- Convert the complemented binary string back to a decimal integer.
- Return the resulting value.
*/

class Solution {
public:
    int findComplement(int num) {
        int i,ans;
        string b1,b2;
        b1=b2="";
        while(num!=0)
        {
            b1=b1+to_string(num%2);
            num=num/2;
        }
        reverse(b1.begin(),b1.end());
        for(auto x:b1)
        {
            if(x=='0')
            {
                b2=b2+'1';
            }
            else
            {
                b2=b2+'0';
            }
        }
        ans=stoi(b2,0,2);
        return ans;
    }
};