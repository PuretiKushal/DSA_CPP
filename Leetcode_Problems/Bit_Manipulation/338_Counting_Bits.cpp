/*
Problem: 338. Counting Bits
Pattern: Bit Manipulation
Difficulty: Easy

Time Complexity: O(n log n) in the worst case
(For every number from 1 to n, the number of set bits is counted
using n=n&(n-1). Each number takes O(number of set bits), which is
O(log n) in the worst case.)

Space Complexity: O(n)
(The vector 'ans' stores the number of set bits for every integer
from 0 to n.)

Key Idea:
- Create a vector 'ans' where ans[i] stores the number of set bits
  in the binary representation of i.
- Initialize ans[0]=0 because 0 has no set bits.
- For every number 'i' from 1 to n:
    - Store 'i' in 'num' so that the original value of i is preserved.
    - Use:
        num=num&(num-1)
      to remove the rightmost set bit.
    - Increment 'count' for every set bit removed.
    - Add 'count' to 'ans'.
- The number of times n=n&(n-1) executes is equal to the number of
  set bits in that number.
- Therefore, ans contains the Hamming Weight of every number from
  0 to n.
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int count=0,i,j,num;
        ans.push_back(0);
        for(i=1;i<=n;i++)
        {
            count=0;
            num=i;
            while(num!=0)
            {
                num=num&(num-1);
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};