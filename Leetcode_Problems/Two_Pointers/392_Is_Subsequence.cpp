/*
Problem: 392. Is Subsequence
Pattern: Two Pointers (Same Direction)
Difficulty: Easy

Time Complexity: O(n)
- Both pointers move only forward.
- Each character is visited at most once.

Space Complexity: O(1)
- Only two pointers are used.

Key Idea:
- Use two pointers:
    i -> points to string s.
    j -> points to string t.

- If s[i] == t[j]:
    - Character matched.
    - Move both pointers.

- Otherwise:
    - Move only j.
    - Continue searching for the current character of s.

- If i reaches the end of s:
    - Every character of s was found in order.
    - Return true.

- Otherwise:
    - Return false.

Important Notes:
- A subsequence must preserve the relative order of characters.
- We never move j backwards because once a character in t is skipped,
  it cannot be used later.
- It is possible for every character of s to exist in t but still
  return false if the order is different.
- Example:
    s = "ba"
    t = "ab"
  Answer = false because the order is not preserved.
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;
        i=0;
        j=0;
        while(i<s.size()&&j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i==s.size();
    }
};