/*
Problem: 125. Valid Palindrome
Pattern: Two Pointers + Recursion
Difficulty: Easy

Time Complexity: O(n)
(Each character is processed at most once.
 Non-alphanumeric characters are skipped,
 and valid characters are compared only once.)

Space Complexity: O(n)
(Due to the recursion call stack.
 In the worst case, the recursion depth is proportional
 to the length of the string.)

Key Idea:
- Use two pointers:
    l → Beginning of the string.
    r → End of the string.
- Ignore non-alphanumeric characters.
- Compare characters in a case-insensitive manner.
- If the current characters match,
  recursively check the remaining inner substring.

Base Case:

if(l>=r)
{
    return true;
}

- When the pointers meet or cross,
  every character has been successfully matched.
- Therefore, the string is a palindrome.

Skip Invalid Characters:

if(!isalnum(s[l]))
{
    return check(s,l+1,r);
}

- If the left character is not a letter or digit,
  skip it and continue checking.

----------------------------

if(!isalnum(s[r]))
{
    return check(s,l,r-1);
}

- If the right character is not a letter or digit,
  skip it and continue checking.

Character Comparison:

if(tolower(s[l])==tolower(s[r]))
{
    return check(s,l+1,r-1);
}

- Convert both characters to lowercase.
- If they match, recursively check the remaining
  inner substring.

Mismatch:

return false;

- If the current valid characters do not match,
  the string cannot be a palindrome.

Helper Function:

bool check(string &s,int l,int r)

- A helper function is required because recursion
  needs the left and right pointers.
- The given LeetCode function only receives the string.

Pass by Reference:

string &s

- '&' passes the original string by reference.
- No copy of the string is created.
- This improves efficiency by avoiding unnecessary copies.

Important Notes:
- isalnum() only checks whether a character is
  alphanumeric. It does not remove characters.
- tolower() converts uppercase letters to lowercase
  for case-insensitive comparison.
- Every recursive call reduces the search space
  by moving one or both pointers towards the center.
- This is the recursive version of the classic
  Two Pointers approach.
*/

class Solution {
public:
    bool check(string &s,int l,int r)
    {
        if(l>=r)
        {
            return true;
        }
        if(!isalnum(s[l]))
        {
            return check(s,l+1,r);
        }
        else if(!isalnum(s[r]))
        {
            return check(s,l,r-1);
        }
        else if(tolower(s[l])==tolower(s[r]))
        {
            return check(s,l+1,r-1);
        }
        else
        {
            return false;
        }
    }
    bool isPalindrome(string s) {
        return check(s,0,s.size()-1);
    }
};