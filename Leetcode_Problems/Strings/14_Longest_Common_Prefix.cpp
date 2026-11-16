/*
Problem: 14. Longest Common Prefix
Pattern: Strings, Vertical Scanning
Difficulty: Easy

Time Complexity: O(n * m)
- Compare each character of strs[0] across all remaining n - 1 strings in the worst case.
- Perform each character comparison in constant time.

Space Complexity: O(1)
- Use only scalar variables (i, j, n, ch) as auxiliary space, excluding the output string ans.

Key Idea:
- Use strs[0] as the reference string and scan characters column by column.
- For each index i of strs[0], store ch = strs[0][i] and compare it against strs[j][i] for all remaining strings.
- If i reaches the end of any string or a character mismatch occurs, return ans immediately.
- Otherwise, append ch to ans and move to the next index.
- Return ans after scanning all characters of strs[0].
*/

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int i,j,n;
        n=strs.size();
        string ans="";
        for(i=0;i<strs[0].size();i++)
        {
            char ch=strs[0][i];
            for(j=1;j<n;j++)
            {
                if(i>=strs[j].size()||strs[j][i]!=ch)
                {
                    return ans;
                }
            }
            ans+=ch;
        }
        return ans;
    }
};