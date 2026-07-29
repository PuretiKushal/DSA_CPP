/*
Problem: 2064. Minimized Maximum of Products Distributed to Any Store
Pattern: Binary Search on Answer
Difficulty: Medium

Time Complexity: O(m log(max(quantities)))
(Binary search is performed on the answer.
 For every mid, all m product types are traversed once.)

Space Complexity: O(1)

Key Idea:
- We are minimizing the maximum number of products assigned to any shop.
- Since the answer lies between a minimum and maximum possible value,
  Binary Search on Answer can be applied.

Search Space:
- l = 1
  (A shop can never receive less than one product.)

- r = maximum quantity
  (In the worst case, one product type is assigned completely to one shop.
   Hence the answer can never exceed the largest quantity.)

Greedy Check (Can mid be the answer?):
- Assume every shop can hold at most 'mid' products.

- For each product type:
    shops += (quantity + mid - 1) / mid;

  Why?
  - One shop can hold only 'mid' products.
  - If quantity = 10 and mid = 3:
        Shop1 -> 3
        Shop2 -> 3
        Shop3 -> 3
        Shop4 -> 1
    Total shops = ceil(10/3) = 4.

  - (quantity + mid - 1) / mid
    is the integer formula for ceil(quantity/mid).

- Sum the shops required for every product type.

Window/Valid Condition:
- if(sum <= n)

  Why <= ?
  - 'sum' is the minimum number of shops required.
  - If required shops are less than or equal to available shops,
    distribution is possible.
  - Extra shops may remain unused.

Binary Search Decision:
- if(sum <= n)
    ans = mid;
    r = mid - 1;

  Why move left?
  - Current answer is possible.
  - We want to minimize the maximum products per shop,
    so try an even smaller maximum.

- else
    l = mid + 1;

  Why move right?
  - Current maximum is too small.
  - Increase the allowed maximum so fewer shops are needed.

Important Notes:
- Reset sum = 0 for every binary search iteration.
  (Each mid requires a fresh calculation.)

- (quantity + mid - 1) / mid
  works only for positive integers.

- ans stores the minimum feasible maximum found so far.
*/

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l,r,mid,i=0,m,ans=0,sum=0;
        m=quantities.size();
        l=1;
        r=*max_element(quantities.begin(),quantities.end());
        while(l<=r)
        {
            mid=l+(r-l)/2;
            sum=0;
            for(i=0;i<m;i++)
            {
                sum=sum+((quantities[i]+mid-1)/mid);
            }
            if(sum<=n)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};