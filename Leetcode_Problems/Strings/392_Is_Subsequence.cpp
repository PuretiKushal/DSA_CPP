/*
Problem: 392. Is Subsequence
Pattern: Two Pointers + Strings
Difficulty: Easy

Time Complexity: O(n)
(The pointers move only forward through the strings.
The total number of pointer movements is at most O(n+m).)

Space Complexity: O(1)
(Only a few variables are used apart from the input strings.)

Key Idea:
- Use two pointers 'i' and 'j' for strings 's' and 't'.
- If s[i]==t[j]:
    - The current character of 's' is matched.
    - Move both pointers forward.
    - Increase 'count' to keep track of matched characters.
- Otherwise:
    - Move only 'j' forward and continue searching for s[i].
- If all characters of 's' are matched (count==n):
    - Return true.
- Otherwise:
    - Return false.
- If n>m, 's' cannot be a subsequence of 't', so return false immediately.
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;
        long long n=s.size();
        long long m=t.size();
        long long count=0;
        i=j=0;
        if(n>m)
        {
            return false;
        }
        while(i<n&&j<m)
        {
            if(s[i]==t[j])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(count==n)
        {
            return true;
        }
        return false;
        
    }
};