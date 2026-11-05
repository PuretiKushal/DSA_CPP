/*
Problem: 1323. Maximum 69 Number
Pattern: Strings
Difficulty: Easy

Time Complexity: O(log n)
- Converts the integer into a string.
- Traverses the digits until the first 6 is found.
- Converts the modified string back into an integer.

Space Complexity: O(log n)
- Stores the digits of the number in a string.

Key Idea:
- Convert the given integer into a string.
- Traverse the string from left to right.
- Replace the first occurrence of 6 with 9.
- Break immediately because changing the leftmost 6
  produces the maximum possible number.
- Convert the modified string back into an integer.
*/

class Solution {
public:
    int maximum69Number (int num) {
        int i,ans;
        string n;
        n=to_string(num);
        for(i=0;i<n.size();i++)
        {
            if(n[i]=='6')
            {
                n[i]='9';
                break;
            }
        }
       ans=stoi(n);
       return ans;
    }
};