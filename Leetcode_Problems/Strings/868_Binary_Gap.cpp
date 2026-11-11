/*
Problem: 868. Binary Gap
Pattern: Bit Manipulation + Strings
Difficulty: Easy

Time Complexity: O(1)
- Converts the number into a 32-bit binary string.
- Traverses all 32 bits once.

Space Complexity: O(1)
- Uses a fixed-size 32-bit binary string.

Key Idea:
- Convert the given integer into its 32-bit binary representation using bitset.
- Traverse the binary string and identify positions containing '1'.
- Use f to store the position of the previously encountered '1'.
- Calculate the distance between consecutive '1's and update mx.
- Return the maximum distance found.
*/

class Solution {
public:
    int binaryGap(int n) {
        string bin;
        bin=bitset<32>(n).to_string();
        int si,i,mx=0,f=-1;
        si=bin.size();
        for(i=0;i<si;i++)
        {
            if(bin[i]=='1')
            {
                if(f!=-1)
                {
                    mx=max(mx,i-f);
                }
                f=i;
            }
        }
        return mx;
    }
};

