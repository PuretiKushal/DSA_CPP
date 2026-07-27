/*
    Problem: 1482. Minimum Number of Days to Make m Bouquets
    Pattern: Binary Search on Answer
    Difficulty: Medium

    Time Complexity: O(n * log(maxBloomDay - minBloomDay))
    Space Complexity: O(1)

    Key Idea:
    The answer is the minimum number of days required to make
    at least `m` bouquets.

    Search the answer in the range:
    - Minimum day = minimum bloom day in the array.
    - Maximum day = maximum bloom day in the array.

    For every candidate day (mid), traverse the array and count
    consecutive bloomed flowers.

    - If `k` consecutive flowers have bloomed, one bouquet is
      formed and those flowers cannot be reused.
    - If an unbloomed flower is encountered, the consecutive
      count is reset since adjacency is broken.

    If at least `m` bouquets can be formed, the day works.
    Save it as a possible answer and search for a smaller day.
    Otherwise, search for a larger day.

    Important Notes:
    - Return `-1` if `m * k > n` since it is impossible.
    - The search space is from the minimum to the maximum
      bloom day.
    - Bouquets require adjacent flowers only.
    - Reset the consecutive flower count after forming a
      bouquet because flowers cannot be reused.
    - Reset the consecutive count whenever adjacency breaks.
    - Use mid = l + (r - l) / 2 to avoid overflow.
    - Binary Search on Answer follows the monotonic pattern:
      F F F ... T T T ...
*/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l,r,n,i,mid,f,ans,b;
        n=bloomDay.size();
        l=*min_element(bloomDay.begin(),bloomDay.end());
        r=*max_element(bloomDay.begin(),bloomDay.end());
        if((long long)m*k>bloomDay.size())
        {
            return -1;
        }
        f=b=ans=0;
        while(l<=r)
            {
                f=b=0;
                mid=l+(r-l)/2;
                for(i=0;i<n;i++)
                    {
                        if(bloomDay[i]<=mid)
                        {
                            f++;
                            if(f==k)
                            {
                                b++;
                                f=0;
                            }
                        }
                        else
                        {
                            f=0;
                        }
                    }
                    if(b>=m)
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

