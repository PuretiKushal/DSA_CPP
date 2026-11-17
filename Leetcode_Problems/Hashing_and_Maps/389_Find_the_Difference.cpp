/*
Problem: 389. Find the Difference
Pattern: Hashing / Frequency Counting
Difficulty: Easy

Time Complexity: O(n)
- Traverse both strings and update character frequencies.
- Iterate through the hash map to find the character with frequency 1.

Space Complexity: O(1)
- Hash map stores at most 26 lowercase English characters.

Key Idea:
- Increment the frequency of each character in t.
- Decrement the frequency of each character in s.
- The extra character will have a frequency difference of 1.
- Return the character whose frequency is 1.
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n,i;
        n=t.size();
        unordered_map<char,int> mp;
        for(i=0;i<n-1;i++)
        {
            mp[t[i]]++;
            mp[s[i]]--;
        }
        mp[t[n-1]]++;
        for(auto x:mp)
        {
            if(x.second==1)
            {
               return x.first;
            }
        }
    return 0;
    }
};