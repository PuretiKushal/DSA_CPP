/*
Problem: 520. Detect Capital
Pattern: Strings 
Difficulty: Easy

Time Complexity: O(n)
- Traverses the string once to count uppercase and lowercase letters.
- Performs constant-time condition checks.

Space Complexity: O(1)
- Uses only a constant amount of extra space.

Key Idea:
- Check whether the first character is uppercase or lowercase.
- If the first character is lowercase, increment the lowercase count.
- Traverse the remaining characters and count uppercase and lowercase letters.
- There are three valid conditions:
  1. First character is uppercase and all remaining characters are uppercase.
  2. First character is uppercase and all remaining characters are lowercase.
  3. First character is lowercase and all characters are lowercase.
- Return true if any of these conditions is satisfied.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n,i,j=0,lc,uc;
        n=word.size();
        lc=uc=0;
        if(word[0]>=65&&word[0]<=90)
        {
            j=1;
        }
        else
        {
            lc++;
        }
        for(i=1;i<n;i++)
        {
            if(word[i]>=65&&word[i]<=90)
            {
                uc++;
            }
            else
            {
                lc++;
            }
        }
        if((j==1&&uc==n-1)||(j==1&&lc==n-1)||(j==0&&lc==n))
        {
            return true;
        }
        return false;
    }
};