/*
    Problem: 875. Koko Eating Bananas
    Pattern: Binary Search on Answer
    Difficulty: Medium

    Time Complexity: O(n * log(maxPile))
    Space Complexity: O(1)

    Key Idea:
    The answer is Koko's eating speed.

    Search the speed in the range:
    - Minimum speed = 1
    - Maximum speed = largest pile

    For every candidate speed (mid), calculate the total
    hours required to finish all piles.

    - If hours <= h, the speed works.
      Save it as a possible answer and search for a smaller speed.
    - If hours > h, the speed is too slow.
      Search for a larger speed.

    Important Notes:
    - Hours for one pile = (pile + speed - 1) / speed
      (Ceiling division without using ceil()).
    - Use long long for total hours to avoid integer overflow.
    - Use mid = l + (r - l) / 2 to avoid overflow.
    - This is a Binary Search on Answer problem because
      the result follows a monotonic pattern:
      F F F ... T T T ...
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h){
        int l,r,i,mid,n,ans;
        n=piles.size();
        long long hrs=0;
        l=1;
        r=*max_element(piles.begin(),piles.end());
        while(l<=r)
            {
                mid=(l+r)/2;
                hrs=0;
                for(i=0;i<n;i++)
                    {
                        hrs=hrs+(piles[i]+mid-1)/mid;
                    }
                if(hrs<=h)
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