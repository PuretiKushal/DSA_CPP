/*
Problem: 4092. Binary Digit Score
Pattern: Bit Manipulation
Difficulty: Easy

Time Complexity: O(log a + log b)
- Each number is repeatedly divided by 2.
- Counts the set bits (1s) in the binary representation of both numbers.

Space Complexity: O(1)
- Uses only a fixed number of integer variables.

Key Idea:
- Count the number of set bits in a and store it in n.
- Count the number of set bits in b and store it in m.
- If n >= m, return the product n * m.
- Otherwise, return the integer division m / n.

Note:
- Assumes non-negative inputs.
- If n = 0 and m > 0, the division m / n causes a runtime error.
*/

class Solution {
public:
    int calculateScore(int a, int b) {
        int n,m,i,ans;
        n=m=0;
        while(a!=0)
        {
            if(a%2==1)
            {
               n++; 
            }
            a=a/2;
        }
        while(b!=0)
        {
            if(b%2==1)
            {
                m++;
            }
            b=b/2;
        }
        if(n>=m)
        {
            ans=n*m;
        }
        else
        {
            ans=m/n;
        }
        return ans;
    }
};