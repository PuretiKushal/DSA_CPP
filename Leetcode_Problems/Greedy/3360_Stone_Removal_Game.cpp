/*
Problem: 3360. Stone Removal Game
Pattern: Greedy / Simulation
Difficulty: Easy

Time Complexity: O(1)
- Iterates through a fixed sequence from 10 down to 1.

Space Complexity: O(1)
- Uses only a constant number of variables.

Key Idea:
- Alice and Bob alternately remove decreasing amounts of stones, starting from 10.
- Simulate each move by subtracting the required amount from n.
- Count the number of successful moves.
- If the number of moves is odd, Alice wins; otherwise, Bob wins.
*/

class Solution {
public:
    bool canAliceWin(int n) {
        int i,c=0;
        for(i=10;i>=1;i--)
        {
            if(n<i)
            {
                break;
            }
            n-=i;
            c++;
        }
        return(c%2!=0);
    }
};