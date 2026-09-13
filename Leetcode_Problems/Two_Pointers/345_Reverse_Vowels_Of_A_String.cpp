/*
Problem: 345. Reverse Vowels of a String
Pattern: Two Pointers
Difficulty: Easy

Time Complexity: O(n)
(The two pointers move towards each other, and each character is
processed at most once.)

Space Complexity: O(1)
(Only a few variables are used, and the string is modified in-place.)

Key Idea:
- Use two pointers 'i' and 'j' starting from the beginning and end
  of the string.
- Move 'i' forward until it points to a vowel.
- Move 'j' backward until it points to a vowel.
- When both pointers point to vowels, swap the two characters.
- Continue until the pointers meet.
- Use a helper function 'check()' to determine whether a character
  is a vowel.
- Pass the string to 'check()' by reference using 'string& s' so that
  no copy of the string is created.
- Use 'tolower()' so that both uppercase and lowercase vowels are
  handled.
*/

class Solution {
public:
    bool check(string& s,int p)
    {
        if(tolower(s[p])=='a'||tolower(s[p])=='e'||tolower(s[p])=='i'||tolower(s[p])=='o'||tolower(s[p])=='u')
        {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int n,i,j;
        char temp;
        n=s.size();
        i=0;
        j=n-1;
        while(i<j)
        {
            if(!check(s,i))
            {
                i++;
            }
            else if(!check(s,j))
            {
                j--;
            }
            else
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
        }
    return s;
    }
};