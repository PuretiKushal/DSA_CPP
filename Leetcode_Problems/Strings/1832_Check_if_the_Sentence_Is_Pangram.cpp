/*
Problem: 1832. Check if the Sentence Is Pangram
Pattern: Strings, Frequency Counting
Difficulty: Easy

Time Complexity: O(n)
- Traverse the sentence once to count character frequencies.
- Check all 26 lowercase English letters.

Space Complexity: O(1)
- Uses a fixed-size frequency vector of 26 elements.

Key Idea:
- Use a frequency array to track the occurrence of each letter.
- Map each character to an index using sentence[i] - 'a'.
- If any letter has a frequency of 0, the sentence is not a pangram.
- If all 26 letters are present, return true.
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n,i;
        n=sentence.size();
        vector<int> freq(26,0);
        for(i=0;i<n;i++)
        {
            freq[sentence[i]-'a']++;
        }
        for(i=0;i<26;i++)
        {
            if(freq[i]==0)
            {
                return false;
            }
        }
        return true;
    }
};