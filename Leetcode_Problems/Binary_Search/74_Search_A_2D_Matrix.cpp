/*
    Problem: 74. Search a 2D Matrix
    Pattern: Binary Search
    Difficulty: Medium

    Time Complexity: O(log(m * n))
    Space Complexity: O(1)

    Key Idea:
    Treat the 2D matrix as a single sorted 1D array.

    Perform binary search on indices from 0 to (m * n - 1).
    Convert the 1D index back to 2D coordinates:
    - row = mid / n
    - col = mid % n

    Compare matrix[row][col] with the target and
    discard the appropriate half until the target is found
    or the search space becomes empty.

    Important Notes:
    - m = number of rows, n = number of columns.
    - row = mid / n
    - col = mid % n
    - Use mid = l + (r - l) / 2 to avoid overflow.
    - The matrix is sorted such that each row is sorted,
      and the first element of every row is greater than the
      last element of the previous row.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l,r,mid,m,n,row,col;
        m=matrix.size();
        n=matrix[0].size();
        l=0;
        r=m*n-1;
        while(l<=r)
            {
                mid=(l+r)/2;
                row=mid/n;
                col=mid%n;
                if(matrix[row][col]==target)
                {
                    return true;
                }
                else if(matrix[row][col]<target)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
                
            }
        return false;
    }
};