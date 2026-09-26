/*
Problem: 1807. Evaluate the Bracket Pairs of a String
Pattern: Hashing + String Manipulation
Difficulty: Medium

Time Complexity: O(n + k)
(Each knowledge pair is inserted into the unordered_map once.
The string is traversed, and bracket pairs are processed using
substring extraction and replacement.
Here, n is the length of the string and k represents the total
amount of string content processed during replacements.)

Space Complexity: O(m)
(The unordered_map stores all m key-value pairs from 'knowledge'.
The substring and replacement operations may also require temporary
string space.)

Key Idea:
- Use an unordered_map 'mp' to store each key and its corresponding
  value from 'knowledge'.
- For every knowledge pair:
    mp[knowledge[i][0]]=knowledge[i][1]
- Traverse the string from left to right.
- When '(' is found:
    - Store its index in 'st'.
- When ')' is found:
    - Store its index in 'e'.
    - Extract the key between the brackets:
        sub_str=s.substr(st+1,e-st-1)
    - Check whether the key exists in the hashmap using:
        mp.count(sub_str)
- If the key exists:
    - Replace the complete bracket pair with its corresponding value:
        s.replace(st,e-st+1,mp[sub_str])
    - Move 'i' to the position immediately after the inserted value
      so that the newly inserted characters are not processed again.
- If the key does not exist:
    - Replace the complete bracket pair with '?'.
    - Set 'i' back to 'st' because the replacement has length 1.
- Continue until the complete string has been processed.
- Return the modified string.
*/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n,i,j,count=0,e,m,st;
        string sub_str;
        n=s.size();
        m=knowledge.size();
        unordered_map<string,string> mp;
        for(i=0;i<m;i++)
        {
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st=i;
            }
            if(s[i]==')')
            {
                e=i;
                sub_str=s.substr(st+1,e-st-1);
                if(mp.count(sub_str))
                {
                    s.replace(st,e-st+1,mp[sub_str]);
                    i=st+mp[sub_str].size()-1;

                }
                else
                {
                    s.replace(st,e-st+1,"?");
                    i=st;
                }
            }   
        }
        return s;
        
    }
};