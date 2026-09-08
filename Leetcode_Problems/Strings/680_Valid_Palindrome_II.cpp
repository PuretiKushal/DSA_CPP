/*
Problem: 680. Valid Palindrome II
Pattern: Two Pointers + Strings
Difficulty: Easy

Time Complexity: O(n)
(The two pointers move towards each other once.
At most one mismatch occurs, and the helper function checks the
remaining substring from one of the two possible deletions.)

Space Complexity: O(1)
(The string is passed by reference and the helper function uses
only the two pointer variables 'left' and 'right'.)

Key Idea:
- Use two pointers 'l' and 'r' starting from both ends of the string.
- Compare s[l] and s[r].
- If they are equal:
    - Move both pointers towards the center.
- If they are different:
    - We are allowed to delete at most one character.
    - Try deleting the left character:
        helper(s,l+1,r)
    - Try deleting the right character:
        helper(s,l,r-1)
    - If either substring is a palindrome, return true.
- The helper function checks whether the remaining substring is a
  palindrome using two pointers.
- If no mismatch is found, the original string is already a palindrome.
- Pass the string by reference using 'string& s' so that no copy of
  the string is created when calling the helper function.
*/

class Solution {
public:
    bool helper(string& s,int left, int right)
    {
        while(left<right)
        {
            if(s[left]!=s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l,r,n,count;
        n=s.size();
        l=0;
        r=n-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return (helper(s,l+1,r)||helper(s,l,r-1));
            }
            l++;
            r--;
        }
        return true;
    }
};