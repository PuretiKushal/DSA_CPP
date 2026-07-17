/*
Problem: 11. Container With Most Water
Pattern: Two Pointers (Opposite Direction)
Difficulty: Medium

Time Complexity: O(n)
(Left pointer 'l' moves from left to right at most n times.
 Right pointer 'r' moves from right to left at most n times.
 Total pointer movements <= 2n --> O(n).)

Space Complexity: O(1)
(Only a few variables are used.)

Key Idea:
- The amount of water stored depends on:
    Area = Width × Minimum Height

- Width:
    r - l
  (Distance between the two lines.)

- Height:
    min(height[l], height[r])
  (The shorter line limits the amount of water.)

- Start with:
    l = 0
    r = n-1
  (This gives the maximum possible width.)

- Calculate the current area:
    area = (r-l) * min(height[l], height[r])

- Store the maximum area found so far:
    ans = max(ans, area)

- Move only the shorter wall:
    if(height[l] < height[r])
        l++;
    else
        r--;

  (Moving the taller wall only decreases the width while the
   shorter wall still limits the area, so it can never produce
   a better answer. Moving the shorter wall gives a chance to
   find a taller line and increase the limiting height.)

Important Notes:
- Width is always (r-l), not (l-r).
- We use 'while(l<r)' because a container needs two different lines.
- If both heights are equal, moving either pointer is correct.
- Every pair is not checked explicitly. The shorter-wall rule
  safely eliminates impossible candidates, allowing an O(n)
  solution instead of O(n²).
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l,r,n,area;
        n=height.size();
        l=area=0;
        r=n-1;
        while(l<r)
        {
            area=max(area,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return area;
    }
};