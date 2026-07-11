/*
Problem: 567. Permutation in String
Pattern: Fixed Size Sliding Window
Difficulty: Medium

Time Complexity: O(n)
(First for loop --> O(n), Second for loop --> O(26) --> O(1), Third while loop runs from n to s2.size() --> O(s2.size()-n) --> O(n)
 and inner for loop --> O(26) --> O(1). Overall: O(n).)

Space Complexity: O(1)
(Two frequency arrays of size 26.)

Key Idea:
- Window size is always fixed and equal to s1.length().
- Build the frequency arrays of:
    - s1 (f1)
    - First window of s2 (f2)
- Compare the frequency arrays only after the complete first window is built.
- If all 26 frequencies match (count==26), return true.
- Remember that r is already incremented after the first window is built, so the next character to be added to the window is s2[r].
- Slide the window using while(r<s2.size()) so that it keeps iterating until the end of s2.
  Inside the while loop:
    - Remove the left character (f2[s2[l]-'a']--)
    - Add the next right character (f2[s2[r]-'a']++)
    - Move the left pointer (l++)
    - Compare the frequency arrays again.
    - Increment r again at the end of the while loop.
- Return true if any window matches, otherwise return false.

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i,j,n,l,r,count;
        vector<int> f1(26,0),f2(26,0);
        n=s1.size();
        if(n>s2.size())
        {
            return false;
        }
        l=count=0;
        for(r=0;r<n;r++)
        {
            f1[s1[r]-'a']++;
            f2[s2[r]-'a']++;
        }
        for(i=0;i<26;i++)
            {
                if(f1[i]==f2[i])
                {
                    count++;
                }
            }
        if(count==26)
        {
            return true;
        }
        while(r<s2.size())
        {
            f2[s2[r]-'a']++;
            f2[s2[l]-'a']--;
            l++;
            count=0;
            for(i=0;i<26;i++)
            {
                if(f1[i]==f2[i])
                {
                    count++;
                }
            }
            if(count==26)
            {
                break;

            }
            r++;

        }
        return count==26;
    }
};