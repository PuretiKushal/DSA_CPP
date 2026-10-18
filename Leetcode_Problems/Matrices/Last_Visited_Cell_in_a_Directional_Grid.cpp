/*
Problem: Last Visited Cell in a Directional Grid (Weekly Contest 524, Problem 2
Pattern: Matrices 
Difficulty: Medium

Time Complexity: O(row * col)
- In the worst case, every cell is visited at most once.
- Each iteration performs a constant amount of work to determine the next cell and check its validity.

Space Complexity: O(row * col)
- The 2D boolean vector v stores whether each cell has been visited.
- In the worst case, it stores one visited flag for every cell.

Key Idea:
- Start at cell (0,0) and mark it as visited.
- Use cr and cc to track the current row and column.
- Determine the next cell based on the current cell's direction:
  - 'L': Move left.
  - 'R': Move right.
  - 'U': Move up.
  - 'D': Move down.
- Before moving, check whether the next cell is outside the grid or has already been visited.
- If either condition is true, stop the simulation.
- Otherwise, move to the next cell and mark it as visited.
- Return the coordinates of the last valid cell visited.
*/

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int row,col,cr,cc,nr,nc;
        row=grid.size();
        col=grid[0].size();
        cr=cc=0;
        vector<vector<bool>> v(row,vector<bool>(col,false));
        v[0][0]=true;
        while(true)
        {
            nr=cr;
            nc=cc;
            if(grid[cr][cc]=='L')
            {
                nc--;
            }
            else if(grid[cr][cc]=='R')
            {
                nc++;
            }
            else if(grid[cr][cc]=='U')
            {
                nr--;
            }
            else
            {
                nr++;
            }
            if(nr<0||nc<0||nr>=row||nc>=col||v[nr][nc])
            {
                break;
            }
            cr=nr;
            cc=nc;
            v[cr][cc]=true;
        }
        return {cr,cc};
    }
};