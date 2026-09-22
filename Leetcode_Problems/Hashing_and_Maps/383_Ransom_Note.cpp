/*
Problem: 383. Ransom Note
Pattern: Hashing + Frequency Counting
Difficulty: Easy

Time Complexity: O(n+m) average
(The ransomNote and magazine strings are traversed once.
unordered_map operations take O(1) average time.)

Space Complexity: O(k)
(The two unordered_maps store frequencies of the distinct characters.
Here, k is the number of distinct characters.)

Key Idea:
- Use two unordered_maps 'm1' and 'm2' to store the frequency of
  characters in ransomNote and magazine.
- If magazine is shorter than ransomNote, return false immediately.
- Traverse ransomNote and store the frequency of each character in 'm1'.
- Traverse magazine and store the frequency of each character in 'm2'.
- Traverse 'm1' using:
    for(auto x:m1)
- For every required character:
    - x.first represents the character.
    - x.second represents the required frequency.
- Compare the required frequency with the available frequency:
    if(x.second>m2[x.first])
        return false;
- If every required character has enough occurrences in magazine,
  return true.
- Accessing m2[x.first] also returns 0 if the character does not exist
  in the map, so no separate existence check is required.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n,m,i;
        n=ransomNote.size();
        m=magazine.size();
        if(m<n)
        {
            return false;
        }
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(i=0;i<n;i++)
        {
            m1[ransomNote[i]]++;
        }
        for(i=0;i<m;i++)
        {
            m2[magazine[i]]++;
        }
        for(auto x:m1)
        {
            if(x.second>m2[x.first])
            {
                return false;
            }
        }
        return true;
    }
};