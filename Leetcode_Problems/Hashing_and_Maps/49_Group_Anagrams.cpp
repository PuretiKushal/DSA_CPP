/*
Problem: 49. Group Anagrams
Pattern: Hashing + String
Difficulty: Medium

Time Complexity: O(n*klogk)
(Each of the n strings is copied and sorted.
Here, k is the average length of a string.)

Space Complexity: O(n*k)
(The hashmap stores the grouped strings and their sorted keys.)

Key Idea:
- Use an unordered_map to group strings with the same character composition.
- For every string, create a copy in 'temp'.
- Sort 'temp' alphabetically.
- Anagrams produce the same sorted string.
    Example:
        "eat" → "aet"
        "tea" → "aet"
        "ate" → "aet"
- Use the sorted string as the hashmap key.
- Add the original string to the vector associated with that key.
- Finally, add every group from the hashmap to 'ans'.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n,i,j,count;
        string temp;
        vector<vector<string>> ans;
        n=strs.size();
        unordered_map<string,vector<string>> mp;
        for(i=0;i<n;i++)
        {
            temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
    return ans;
    }
};