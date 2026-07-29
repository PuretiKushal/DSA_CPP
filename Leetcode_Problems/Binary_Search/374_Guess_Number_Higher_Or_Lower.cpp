/*
Problem: 374. Guess Number Higher or Lower
Pattern: Classic Binary Search
Difficulty: Easy

Time Complexity: O(log n)
(In every iteration, half of the search space is discarded.
 Therefore, the number of iterations is logarithmic.)

Space Complexity: O(1)
(Only a few variables are used.)

Key Idea:
- The picked number lies between 1 and n.
- Use Binary Search to repeatedly guess the middle number.
- The predefined API guess(mid) tells whether the guess is:
    - Too high
    - Too low
    - Correct

Search Space:
- l = 1
  (The smallest possible picked number.)

- r = n
  (The largest possible picked number.)

Middle Calculation:
    mid = l + (r-l)/2;

Why?
- Prevents integer overflow that may occur with:
    (l+r)/2

API Response:
    x = guess(mid);

Returns:
- x == 0
  -> Correct guess.

- x == -1
  -> mid is higher than the picked number.
     Search the left half.

- x == 1
  -> mid is lower than the picked number.
     Search the right half.

Binary Search Decision:
- if(x == 0)
      return mid;

  Why?
  - The problem asks to return the picked number,
    not the value returned by the API.

- else if(x == -1)
      r = mid - 1;

  Why?
  - The picked number is smaller than mid,
    so discard the right half.

- else
      l = mid + 1;

  Why?
  - The picked number is larger than mid,
    so discard the left half.

Important Notes:
- Do NOT return 0 when x == 0.
  Return 'mid' because it is the correct number.

- The final 'return 0;' is never reached under valid constraints.
  It is present only to satisfy the compiler.
*/


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l,r,mid,x=0;
        l=1;
        r=n;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            x=guess(mid);
            if(x==0)
            {
                return mid;
            }
            else if(x==-1)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return 0;    
    }
};