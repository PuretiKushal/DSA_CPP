/*
Problem: 387. First Unique Character in a String
Pattern: Hashing / Frequency Counting
Difficulty: Easy

Time Complexity: O(n)
(First loop stores the frequency of every character.
 Second loop checks each character once to find the first character
 whose frequency is 1.
 Overall: O(n).)

Space Complexity: O(k)
(An unordered_map stores the frequency of the characters.
 Here, k is the number of distinct characters.)

Key Idea:
- Traverse the string and store the frequency of each character in 'mp'.
- Traverse the string again from left to right.
- If mp[s[i]] == 1, the character occurs only once.
- Return its index immediately because we need the first unique character.
- If no character has frequency 1, return -1.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int i,n,j,count;
        unordered_map<char,int> mp;
        n=s.size();
        for(i=0;i<n;i++)
        {
           mp[s[i]]++; 
        }
        for(i=0;i<n;i++)
        {
           if(mp[s[i]]==1)
           {
               return i;
           } 
        }
        return -1;
    }
};