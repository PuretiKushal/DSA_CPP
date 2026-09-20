/*
Problem: Reverse Degree of a String
Pattern: String + ASCII Manipulation
Difficulty: Easy

Time Complexity: O(n)
(The string is traversed once, and each character is processed in O(1) time.)

Space Complexity: O(1)
(Only a few integer variables are used apart from the input string.)

Key Idea:
- Traverse the string from left to right.
- Convert each lowercase character into its alphabetical position
  using ASCII:
      s[i]-96
  For example:
      'a' → 1
      'b' → 2
      ...
      'z' → 26
- The reverse alphabetical value is:
      27-(s[i]-96)
  Therefore:
      'a' → 26
      'b' → 25
      ...
      'z' → 1
- Multiply the reverse alphabetical value by the 1-based position
  of the character:
      (27-(s[i]-96))*(i+1)
- Add this value to 'count' for every character.
- Finally, return 'count' as the reverse degree of the string.
*/

class Solution {
public:
    int reverseDegree(string s) {
        int n,i,count=0;
        n=s.size();
        for(i=0;i<n;i++)
        {
            count=count+(27-(s[i]-96))*(i+1);
        }
        return count;
        
    }
};