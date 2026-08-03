/*
Problem: 344. Reverse String
Pattern: Two Pointers + Recursion
Difficulty: Easy

Time Complexity: O(n)
(At every recursive call, one character from the left
 and one character from the right are processed.
 The recursion continues until the pointers meet or cross.)

Space Complexity: O(n)
(Due to the recursion call stack.
 The maximum recursion depth is approximately n/2,
 which is O(n).)

Key Idea:
- Use two pointers:
    l → Beginning of the string.
    r → End of the string.
- Swap the characters at l and r.
- Recursively solve the smaller problem by moving
  both pointers towards the center.

Base Case:

if(l>=r)
{
    return;
}

- When the pointers meet or cross,
  there are no more characters left to swap.
- This stops the recursion.

Current Work:

swap(s[l],s[r]);

- Swap the current left and right characters.
- This places both characters in their correct positions.

Recursive Case:

reverse(s,l+1,r-1);

- Move the left pointer one step forward.
- Move the right pointer one step backward.
- Recursively reverse the remaining inner part of the string.

Helper Function:

void reverse(vector<char>& s,int l,int r)

- A helper function is used because recursion needs
  the left and right pointers.
- The given LeetCode function only receives the vector.

Pass by Reference:

vector<char>& s

- '&' passes the vector by reference.
- No copy of the vector is created.
- Every swap directly modifies the original vector.

Important Notes:
- The string is reversed in-place.
- No extra array or vector is required.
- No return value is needed because the original vector
  itself is modified.
- This is the recursive version of the classic
  Two Pointers technique.
*/

class Solution {
public:
    void reverse(vector<char>& s,int l, int r)
    {
        if(l>=r)
        {
            return;
        }
        swap(s[l],s[r]);
        reverse(s,l+1,r-1);
    }
    void reverseString(vector<char>& s) {
        reverse(s,0,s.size()-1);
    }
};