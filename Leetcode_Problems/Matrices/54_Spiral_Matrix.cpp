/*
Problem: 54. Spiral Matrix
Pattern: Matrix Traversal + Boundary Simulation
Difficulty: Medium

Time Complexity: O(m*n)
(Every element in the matrix is visited exactly once.)

Space Complexity: O(m*n)
(The answer vector 'ans' stores all m*n elements of the matrix.
Apart from the output vector, only a constant number of variables
are used.)

Key Idea:
- Use four boundaries to represent the current unvisited layer:
    top
    bottom
    left
    right
- Start with:
    top=0
    bottom=row-1
    left=0
    right=col-1
- Continue while:
    top<=bottom && left<=right
- Traverse the current layer in four directions:

  1. Left → Right:
     - Traverse the top row.
     - Move 'top' down by one.

  2. Top → Bottom:
     - Traverse the right column.
     - Move 'right' left by one.

  3. Right → Left:
     - Only perform this traversal if top<=bottom.
     - Traverse the bottom row in reverse.
     - Move 'bottom' up by one.

  4. Bottom → Top:
     - Only perform this traversal if left<=right.
     - Traverse the left column in reverse.
     - Move 'left' right by one.

- The boundary checks before the third and fourth traversals are
  important because the remaining layer may contain only one row
  or one column.
- After every complete layer, the four boundaries move inward.
- Continue until all elements have been added to 'ans'.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row,col,i,j,count=0,top,bottom,left,right;
        vector<int> ans;
        row=matrix.size();
        col=matrix[0].size();
        top=left=0;
        bottom=row-1;
        right=col-1;
        while(top<=bottom&&left<=right)
        {
            for(i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom)
            {
                for(i=right;i>=left;i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right)
            {   
                for(i=bottom;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};