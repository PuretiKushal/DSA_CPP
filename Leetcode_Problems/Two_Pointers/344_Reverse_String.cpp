/*
Problem: 344. Reverse String
Pattern: Two Pointers
Difficulty: Easy

Time Complexity: O(n)
(Left pointer moves from 0 to middle.
 Right pointer moves from n-1 to middle.
 Total swaps = n/2 --> O(n).)

Space Complexity: O(1)
(Only a temporary variable is used.)

Key Idea:
- Place one pointer at the beginning (l).
- Place another pointer at the end (r).
- Swap the characters at l and r.
- Move:
    l++
    r--
- Repeat until l >= r.
- Reverse the string in-place without using extra space.
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n,l,r,temp;
        n=s.size();
        l=0;
        r=n-1;
        while(l<r)
        {
            temp=s[l];
            s[l]=s[r];
            s[r]=temp;
            l++;
            r--;
        }
    }
};