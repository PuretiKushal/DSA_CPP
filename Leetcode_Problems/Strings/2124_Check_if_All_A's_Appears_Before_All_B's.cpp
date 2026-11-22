/*
Problem: 2124. Check if All A's Appears Before All B's
Pattern: Strings 
Difficulty: Easy

Time Complexity: O(n)
- First traversal finds the index of the first 'b'.
- Second traversal checks whether any 'a' appears after that index.

Space Complexity: O(1)
- Uses only a constant number of extra variables.

Key Idea:
- Find the first occurrence of 'b'.
- Starting from that position, check whether any 'a' appears.
- If an 'a' is found after a 'b', the string violates the required order.
- Otherwise, return true.
*/

class Solution {
public:
    bool checkString(string s) {
        int n,bl,i;
        n=s.size();
        for(i=0;i<n;i++)
        {
            if(s[i]=='b')
            {
                bl=i;
                break;
            }
        }
        for(i=bl;i<n;i++)
        {
            if(s[i]=='a')
            {
                return false;
            }
        }
        return true;
    }
};