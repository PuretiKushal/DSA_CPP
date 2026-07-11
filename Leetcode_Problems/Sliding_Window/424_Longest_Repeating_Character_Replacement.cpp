/*
Problem: 424. Longest Repeating Character Replacement
Pattern: Variable Size Sliding Window
Difficulty: Medium

Time Complexity: O(n)
(Right pointer 'r' moves from 0 to n-1 once.
 Left pointer 'l' also moves from 0 to n-1 at most once.
 Maximum frequency is found by scanning only 26 characters --> O(26) = O(1).
 Overall: O(n).)

Space Complexity: O(1)
(Frequency array of size 26.)

Key Idea:
- Expand the window by moving the right pointer.
- Store the frequency of each character in the current window (frequency array 'f'; s[r]-'A' converts characters 'A' to 'Z' into indices 0 to 25 using ASCII values).
- Find the maximum frequency character in the current window (h --> highest frequency).
- Formula:
    Changes Needed = Window Length (r-l+1) - Maximum Frequency (h)
- If Changes Needed <= k:
    - Window is valid.
    - Update the maximum window length.
- If Changes Needed > k:
    - Shrink the window by removing the left character.
    - Update its frequency.
    - Recalculate the maximum frequency.
- Repeat until the end of the string.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i,j,n,ans,l,r,c,h;
        vector<int> f(26,0);
        n=s.size();
        l=ans=c=h=0;
        for(r=0;r<n;r++)
        {
            h=0;
            f[s[r]-'A']++;
            for(i=0;i<26;i++)
            {
                h=max(h,f[i]);
            }
            c=r-l+1-h;
            while(c>k)
            {
                f[s[l]-'A']--;
                l++;
                c=r-l+1-h;
                h=0;
                for(i=0;i<26;i++)
                {
                    h=max(h,f[i]);
                }
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};