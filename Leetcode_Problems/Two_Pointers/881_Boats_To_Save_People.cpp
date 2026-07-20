/*
Problem: 881. Boats to Save People
Pattern: Two Pointers (Opposite Direction)
Difficulty: Medium

Time Complexity: O(n log n)
- Sorting: O(n log n)
- Two pointers: O(n)

Space Complexity: O(1)

Key Idea:
- Sort the array.
- Use two pointers:
    l -> lightest person
    r -> heaviest person
- If people[l] + people[r] <= limit:
    - Send both together.
    - l++, r--
- Otherwise:
    - Send the heaviest person alone.
    - r--
- Count one boat in every iteration.

Important Notes:
- If the heaviest person cannot pair with the lightest,
  they cannot pair with anyone else.
- Handle the last remaining person separately when l==r.
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l,r,count,n;
        n=people.size();
        l=count=0;
        r=n-1;
        sort(people.begin(),people.end());
        while(l<r)
            {
                if(people[r]==limit)
                {
                    count++;
                    r--;
                }
                else if(people[r]+people[l]<=limit)
                {
                    count++;
                    l++;
                    r--;
                }
                else
                {
                    count++;
                    r--;
                }
                
            }
        if(l==r)
        {
            return count+1;
        }
        else
        {
            return count;
        }
        
    }
};