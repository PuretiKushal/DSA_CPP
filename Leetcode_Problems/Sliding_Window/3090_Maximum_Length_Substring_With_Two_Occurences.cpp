/*
Problem: 3090. Maximum Length Substring With Two Occurrences
Pattern: Sliding Window
Difficulty: Easy

Time Complexity: O(26*n) ≈ O(n)
- Each element is added to the window once.
- Each element is removed from the window at most once.
- max_element() checks 26 frequencies, which is constant.

Space Complexity: O(26) = O(1)
- freq stores frequencies for only 26 lowercase letters.

Key Idea:
- Maintain a variable-size sliding window [l,r].
- freq stores the frequency of every character inside
  the current window.
- Expand the window by moving r.
- If any character appears more than 2 times, the
  window becomes invalid.
- Shrink the window from the left until every character
  appears at most 2 times.
- Keep track of the maximum valid window length.

Variables:

l
- Left boundary of the sliding window.

r
- Right boundary of the sliding window.

n
- Length of the string.

freq
- Stores the frequency of each lowercase character.
- freq[s[r]-'a'] gives the frequency of character s[r].

m
- Stores the maximum frequency of any character inside
  the current window.

ml
- Stores the maximum valid window length found so far.

Window Expansion:

freq[s[r]-'a']++;

- Add the character at r to the window.
- Increase its frequency.

Checking the Constraint:

m=*max_element(freq.begin(),freq.end());

- Find the highest frequency among all 26 characters.
- If m>2, some character appears more than twice,
  so the window is invalid.

Shrinking:

while(m>2)
{
    freq[s[l]-'a']--;
    l++;
    m=*max_element(freq.begin(),freq.end());
}

- Remove the leftmost character.
- Move l forward.
- Recalculate the maximum frequency.
- Continue until every character occurs at most twice.

Updating Answer:

ml=max(ml,r-l+1);

- Once the window is valid, calculate its length.
- Keep the largest valid length.

Example:

s = "aabbc"

Window progression:

"a"    → valid
"aa"   → valid
"aab"  → valid
"aabb" → valid
"aabbc" → valid

Answer = 5

For a string such as:

"aaab"

When the third 'a' enters:

"aaa" → invalid

So we shrink from the left:

"aa" → valid

Important Notes:
- This is a variable-size sliding window.
- The condition is:
      Every character appears at most 2 times.
- m represents the maximum frequency in the window.
- The window is valid when:
      m <= 2
- The general pattern is:

    Expand r
        ↓
    Check constraint
        ↓
    Invalid?
        ↓
    Move l until valid
        ↓
    Update maximum length

Your implementation correctly maintains the window and
returns the maximum valid substring length.
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l,r,n,i,j,m,ml=0;
        vector<int> freq(26,0);
        l=r=0;
        n=s.size();
        while(l<=r&&r<n)
            {
                freq[s[r]-'a']++;
                m=*max_element(freq.begin(),freq.end());
                while(m>2)
                    {
                        freq[s[l]-'a']--;
                        l++;
                        m=*max_element(freq.begin(),freq.end());
                    }
                ml=max(ml,r-l+1);
                r++;
            }
        return ml;
        
    }
};