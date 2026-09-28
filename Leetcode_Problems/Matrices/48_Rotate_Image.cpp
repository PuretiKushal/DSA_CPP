/*
Problem: 48. Rotate Image
Pattern: Matrix + Transpose + Reverse
Difficulty: Medium

Time Complexity: O(n^2)
(The matrix contains n*n elements. The transpose operation processes
the upper triangle of the matrix, and reversing each row processes
all n rows. Overall, the matrix elements are processed in O(n^2) time.)

Space Complexity: O(1)
(The matrix is modified in-place and only a single temporary variable
'temp' is used apart from the input matrix.)

Key Idea:
- Rotate the n*n matrix 90 degrees clockwise in-place using two steps:
    1. Transpose the matrix.
    2. Reverse every row.

- Step 1: Transpose the matrix:
    - Traverse only the upper triangular portion of the matrix.
    - Swap:
        matrix[i][j] and matrix[j][i]
    - Start j from i+1 so that:
        - Elements are not swapped twice.
        - Diagonal elements are not unnecessarily processed.

- After transposing:
    Example:
        1 2 3
        4 5 6
        7 8 9

    becomes:

        1 4 7
        2 5 8
        3 6 9

- Step 2: Reverse every row:
    - Use reverse() on each row.
    - This produces:

        7 4 1
        8 5 2
        9 6 3

- The resulting matrix is the original matrix rotated 90 degrees
  clockwise.
- Both operations are performed directly on the input matrix, so
  no additional matrix is required.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row,col,n,temp,i,j;
        n=matrix.size();
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};