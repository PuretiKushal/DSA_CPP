/*
Problem: 242. Valid Anagram
Pattern: Hashing + Frequency Counting
Difficulty: Easy

Time Complexity: O(n)
(Both strings are traversed once, and unordered_map operations such as
access and insertion take O(1) average time.)

Space Complexity: O(n)
(In the worst case, the unordered_maps store n different characters.)

Key Idea:
- First compare the lengths of the two strings.
- If n!=m, the strings cannot be anagrams, so return false.
- Use two unordered_maps 'm1' and 'm2' to store the frequency of
  characters in strings 's' and 't'.
- Traverse both strings together:
    - Increase the frequency of s[i] in 'm1'.
    - Increase the frequency of t[i] in 'm2'.
- Traverse the characters of 's' and compare their frequencies in
  both maps.
- If the frequency of any character is different:
    - The strings are not anagrams, so return false.
- If all frequencies match, return true.
- Two strings are anagrams when they contain exactly the same
  characters with the same frequencies.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n,m,i,j;
        n=s.size();
        m=t.size();
        if(n!=m)
        {
            return false;
        }
        unordered_map<char,int> m1(n);
        unordered_map<char,int> m2(m);
        for(i=0;i<n;i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(i=0;i<n;i++)
        {
            if(m1[s[i]]!=m2[s[i]])
            {
                return false;
            }
        }
        return true;      
    }
};