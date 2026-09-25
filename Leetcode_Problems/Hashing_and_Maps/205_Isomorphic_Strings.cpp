/*
Problem: 205. Isomorphic Strings
Pattern: Hashing + Character Mapping
Difficulty: Easy

Time Complexity: O(n)
(The strings are traversed once, and unordered_map operations such as
count and access take O(1) average time.)

Space Complexity: O(1)
(Only characters are stored in the two unordered_maps. Since the
character set is bounded, the number of possible mappings is constant.)

Key Idea:
- Use two unordered_maps to maintain a one-to-one mapping:
    mp1: maps characters from string 's' to string 't'.
    mp2: maps characters from string 't' to string 's'.
- Traverse both strings using the same index 'i'.
- If s[i] already has a mapping:
    - Check whether it maps to t[i].
    - If it maps to a different character, return false.
- Otherwise, check whether t[i] is already mapped to another character
  using mp2.
    - If it is already mapped, two different characters from 's' would
      map to the same character in 't', so return false.
- If neither character has a conflicting mapping:
    - Store:
        mp1[s[i]]=t[i]
        mp2[t[i]]=s[i]
- If the complete strings are processed without finding a conflict,
  return true.
- The two maps are required to ensure the mapping is one-to-one in
  both directions.
*/

class Solution {
public:
    bool isIsomorphic(string s,string t) {
        int n,i;
        unordered_map<char,char> mp1,mp2;
        n=s.size();
        for(i=0;i<n;i++)
        {
            if(mp1.count(s[i]))
            {
                if(mp1[s[i]]!=t[i])
                {
                    return false;
                }
            }
            else if(mp2.count(t[i]))
            {
                return false;
            }
            else
            {
                mp1[s[i]]=t[i];
                mp2[t[i]]=s[i];
            }
        }
        return true;
    }
};