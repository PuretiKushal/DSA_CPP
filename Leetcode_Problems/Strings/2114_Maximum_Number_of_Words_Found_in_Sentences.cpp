/*
Problem: 2114. Maximum Number of Words Found in Sentences
Pattern: String + Counting
Difficulty: Easy

Time Complexity: O(n * m)
- n is the number of sentences.
- m is the average length of a sentence.
- Traverses every character to count spaces.

Space Complexity: O(1)
- Uses only a constant number of variables.

Key Idea:
- Traverse each sentence one by one.
- Initialize count to 1 because words = spaces + 1.
- Count the spaces in the current sentence.
- Update mx with the maximum word count.
- Starting from index 1 is valid because the constraints guarantee no leading spaces.
*/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int i,j,n,count,s,mx=INT_MIN;
        n=sentences.size();
        for(i=0;i<n;i++)
        {
            s=sentences[i].size();
            count=1;
            for(j=1;j<s;j++)
            {
                if(sentences[i][j]==' ')
                {
                    count++;
                }
            }
            mx=max(mx,count);
        }
        return mx;
    }
};