/*
Problem: 1572. Matrix Diagonal Sum
Pattern: Matrix + Simulation
Difficulty: Easy

Time Complexity: O(n^2)
- Uses nested loops to traverse the entire n x n matrix.
- Checks whether each element belongs to either diagonal.

Space Complexity: O(1)
- Uses only a constant number of variables.
- No additional data structures are used.

Key Idea:
- Traverse the square matrix using nested loops.
- Primary diagonal elements satisfy i == j.
- Secondary diagonal elements satisfy i + j == n - 1.
- Add an element if it belongs to either diagonal.
- Using OR (||) ensures the center element of an odd-sized matrix is counted only once.
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int r,i,j,sum=0;
        r=mat[0].size();
        for(i=0;i<r;i++)
        {
            for(j=0;j<r;j++)
            {
                if(i==j||i+j==r-1)
                {
                    sum=sum+mat[i][j];
                }
            }
        }
        return sum;
    }
};