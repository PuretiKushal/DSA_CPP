/*
    Problem: 1552. Magnetic Force Between Two Balls
    Pattern: Binary Search on Answer
    Difficulty: Medium

    Time Complexity: O(n * log(position[n-1] - position[0]))
    Space Complexity: O(1)

    Key Idea:
    We need to maximize the minimum distance between any two balls.

    Sort the basket positions and binary search on the answer
    (minimum distance).

    For each candidate distance (mid), greedily place the first
    ball in the first basket. Then place every next ball in the
    earliest basket that is at least 'mid' distance away from
    the previously placed ball.

    If at least 'm' balls can be placed, the distance is
    possible. Store it as the current answer and try a larger
    distance. Otherwise, try a smaller distance.

    Important Notes:
    - Search space:
        l = 1
        r = maximum position - minimum position
    - Always sort the positions before applying Binary Search.
    - Greedily placing each ball in the earliest valid basket
      maximizes the chances of placing all remaining balls.
    - If count >= m, search right (l = mid + 1) since we want
      to maximize the minimum distance.
*/

class Solution {
public:
    int maxDistance(vector<int>& position, int m){
        int l,r,mid,n,ans=0,i,j,last,count;
        n=position.size();
        sort(position.begin(),position.end());
        l=1;
        r=position[n-1]-position[0];
        while(l<=r)
            {
                mid=l+(r-l)/2;
                last=position[0];
                count=1;
                for(i=0;i<n;i++)
                    {
                        if(position[i]>=last+mid)
                        {
                            count++;
                            last=position[i];
                        }
                    }
                if(count>=m)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        return ans;
    }
};