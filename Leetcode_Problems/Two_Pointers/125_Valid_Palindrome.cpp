/*
Problem: 125. Valid Palindrome
Pattern: Two Pointers (Opposite Direction)
Difficulty: Easy

Time Complexity: O(n)
(Both pointers move towards each other at most once.
 Total pointer movements <= 2n --> O(n).)

Space Complexity: O(1)
(Only a few variables are used.)

Key Idea:
- Place:
    l = 0
    r = n-1

- Move both pointers towards each other.

- If the left character is not alphanumeric:
    l++
    (Skip spaces and punctuation.)

- Else if the right character is not alphanumeric:
    r--
    (Skip spaces and punctuation.)

- Otherwise compare:
    tolower(s[l]) and tolower(s[r])

- If they are equal:
    l++;
    r--;

- If they are not equal:
    return false;

- If the loop finishes:
    return true;

Important Notes:
- isalnum(ch) checks whether the character is a letter or digit.
- tolower(ch) converts uppercase letters to lowercase.
- Ignore spaces, punctuation and capitalization while comparing.
- We only compare valid alphanumeric characters.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l,r,n;
        n=s.size();
        l=0;
        r=n-1;
        while(l<r)
            { 
                if(!isalnum(s[l]))
                {
                    l++;
                }
                else if(!isalnum(s[r]))
                {
                    r--;
                }
                
                else if(tolower(s[l])==tolower(s[r]))
                {
                    l++;
                    r--;
                }
                else
                {
                    return false;
                }
                
            }
            return true;
    }