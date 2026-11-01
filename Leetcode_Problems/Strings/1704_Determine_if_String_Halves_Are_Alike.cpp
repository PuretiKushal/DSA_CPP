/*
Problem: 1704. Determine if String Halves Are Alike
Pattern: String + Two Pointers + Counting
Difficulty: Easy

Time Complexity: O(n)
- Traverses half of the string.
- Checks vowels in both halves in a single loop.

Space Complexity: O(1)
- Uses only two counters and a fixed number of variables.

Key Idea:
- Divide the string into two equal halves.
- Traverse both halves simultaneously.
- Count the vowels in the first half using a.
- Count the vowels in the second half using b.
- Consider both uppercase and lowercase vowels.
- Return true if both vowel counts are equal; otherwise, return false.
*/


class Solution {
public:
    bool halvesAreAlike(string s) {
        int n,i,a=0,b=0;
        n=s.size();
        for(i=0;i<n/2;i++)
        {
if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
                a++;
            }
if(s[i+n/2]=='a'||s[i+n/2]=='e'||s[i+n/2]=='i'||s[i+n/2]=='o'||s[i+n/2]=='u'||s[i+n/2]=='A'||s[i+n/2]=='E'||s[i+n/2]=='I'||s[i+n/2]=='O'||s[i+n/2]=='U')
            {
                b++;
            }
        }
        return a==b;
    }
};