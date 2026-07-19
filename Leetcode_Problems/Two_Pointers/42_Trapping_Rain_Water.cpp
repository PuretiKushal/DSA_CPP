/*
Problem: 42. Trapping Rain Water
Pattern: Two Pointers (Opposite Direction)
Difficulty: Hard

Time Complexity: O(n)
- Each bar is processed exactly once.

Space Complexity: O(1)
- Only a few variables are used.

Key Idea:
- Water trapped at a bar depends on:
    min(leftMax, rightMax) - currentHeight

- Use:
    l  -> current bar from left
    r  -> current bar from right
    lm -> tallest wall seen so far from left
    rm -> tallest wall seen so far from right

- Process the side with the smaller current height.

- If:
    height[l] <= height[r]

    - Update lm
    - Water at current left bar = lm - height[l]
    - Move l++

- Otherwise:

    - Update rm
    - Water at current right bar = rm - height[r]
    - Move r--

Important Notes:
- l and r are indices, not heights.
- lm and rm store the tallest walls seen so far.
- Update lm/rm before calculating water.
- Compare height[l] and height[r], not lm and rm.
- The smaller current height guarantees the opposite side
  has a wall at least that tall, making the current side's
  water level determinable.
- Use while(l<r) because each iteration processes exactly
  one bar, and no new bar remains once the pointers meet.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int l,r,lm,rm,w,n;
        n=height.size();
        l=0;
        r=n-1;
        lm=rm=w=0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                lm=max(lm,height[l]);
                w=w+lm-height[l];
                l++;
            }
            else
            {
                rm=max(rm,height[r]);
                w=w+rm-height[r];
                r--;
            }
        }
        return w;
    }
};