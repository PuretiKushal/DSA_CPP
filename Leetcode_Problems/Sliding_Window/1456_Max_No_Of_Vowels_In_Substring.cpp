/*
Problem: 1456. Maximum Number of Vowels in a Substring of Given Length
Pattern: Fixed Size Sliding Window
Difficulty: Medium
Time Complexity: O(n) (2 for loops; one from 0 to k and another from k to n --> 0 to n --> O(n))
Space Complexity: O(1) (Only 4 variables are used --> O(4) --> O(1))

Key Idea:
- Calculate first window vowels count (first for loop)
- Slide the window (second for loop)
- Remove left element (count--)
- Add right element (count++)
- Keep track of maximum count (ans=max(count,ans))
*/

class Solution {
public:
    int maxVowels(string s, int k) {
        int i,j,n,count=0,ans;
        n=s.size();
        for(i=0;i<k;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                count++;
            }
        }
        ans=count;
        for(i=k;i<n;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                count++;
            }
            if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u')
            {
                count--;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};