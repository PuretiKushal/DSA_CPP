/*
Problem: 3. Longest Substring Without Repeating Characters
Pattern: Variable Size Sliding Window
Difficulty: Medium

Time Complexity: O(n log n)
(Right pointer 'r' moves from 0 to n-1 once.
 Left pointer 'l' also moves from 0 to n-1 at most once.
 Each insert(), erase() and count() operation on set takes O(log n).)

Space Complexity: O(n)
(Set stores the characters currently present in the window.)

Key Idea:
- Expand the window by moving the right pointer.
- Keep adding characters to the current window.
- If a duplicate character is found:
    - Shrink the window by removing characters from the left.
    - Keep shrinking until the window contains no duplicate characters.
- Insert the current character into the window.
- Update the maximum window length.
- If the string is empty, return 0.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j,n,ans,l,r;
        set<char> set;
        n=s.size();
        l=0;
        ans=1;
        for(r=0;r<n;r++)
        {
            while(set.count(s[r])==1)
            {
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            ans=max(ans,r-l+1);
        }
        if(n==0)
        {
            ans=0;
            return ans;
        }
        else
        {
            return ans;
        }
        
    }
};