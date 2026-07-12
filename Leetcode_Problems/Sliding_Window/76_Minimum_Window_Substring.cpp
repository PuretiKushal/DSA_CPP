/*
Problem: 76. Minimum Window Substring
Pattern: Variable Size Sliding Window
Difficulty: Hard

Time Complexity: O(n)
(Right pointer 'r' moves from 0 to m-1 once.
 Left pointer 'l' also moves from 0 to m-1 at most once.
 Every character is processed at most twice (once while expanding and once while shrinking).
 Overall: O(2m) --> O(m).)

Space Complexity: O(1)
(Two frequency arrays of size 128 are used for ASCII characters.)

Key Idea:
- Store the required frequency of each character of t in frequency array 'f1'.
- Store the current window frequency in frequency array 'f2'.
- Count the number of distinct characters present in t using:
    if(f1[ch]==0)
        dist++;
  (dist = Number of distinct characters whose frequencies must be satisfied.)

- While expanding:
    f2[s[r]]++;
- If a character's required frequency becomes exactly satisfied:
    if(f2[s[r]]==f1[s[r]])
        count++;
  (Increase count only when frequencies become exactly equal.
   Do NOT use >= because count should increase only once for each distinct character.)

Window Valid Condition:
- count == dist
  (All distinct required characters have their required frequencies satisfied.
   Extra characters in the window do not matter.)

When Window Becomes Valid:
- Store the current window if it is the smallest so far:
    if(r-l+1 < len)
    {
        len = r-l+1;
        start = l;
    }
- Then shrink the window to try finding a smaller valid window.

While Shrinking:
- Remove the left character:
    f2[s[l]]--;
- If its frequency becomes less than required:
    if(f2[s[l]] < f1[s[l]])
        count--;
  (Window becomes invalid because one required frequency is no longer satisfied.)
- Move left pointer:
    l++;

Important Notes:
- f1 stores frequencies required by string t.
- f2 stores frequencies of the current window in s.
- ASCII values are used directly as indices:
    f1[t[i]]++;
    f2[s[i]]++;
  (Works for both uppercase and lowercase characters.)
- start stores the starting index of the minimum valid window.
- len stores the length of the minimum valid window.
- Return:
    s.substr(start, len);
  (Returns the minimum valid substring.)
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int i,l,r,m,n,count,dist,start,len;
        vector<int> f1(128,0),f2(128,0);
        l=count=start=dist=0;
        len=INT_MAX;
        m=s.size();
        n=t.size();
        if(m<n)
        {
            return "";
        }
        for(i=0;i<n;i++)
        {
            if(f1[t[i]]==0)
            {
                dist++;
            }
            f1[t[i]]++;
        }
        for(r=0;r<m;r++)
        {
            f2[s[r]]++;
            if(f1[s[r]]>0&&f2[s[r]]==f1[s[r]])
            {
                count++;
            }
            while(count==dist)
            {
                if(r-l+1<len)
                {
                    len=r-l+1;
                    start=l;
                }
                f2[s[l]]--;
                if(f1[s[l]]>0&&f2[s[l]]<f1[s[l]])
                {
                    count--;
                }
                l++;
            }
        }
        if(len==INT_MAX)
        {
            return "";
        }
        return s.substr(start,len);
    }
};