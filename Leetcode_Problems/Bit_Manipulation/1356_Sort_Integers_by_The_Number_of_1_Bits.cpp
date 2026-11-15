/*
Problem: 1356. Sort Integers by The Number of 1 Bits
Pattern: Bit Manipulation, Custom Sorting
Difficulty: Easy

Time Complexity: O(n log n + n log M)
- Count set bits for each number in O(log M).
- Sort the pairs in O(n log n).
- Build the answer vector in O(n).

Space Complexity: O(n)
- Store each number with its set-bit count in a pair vector.
- Use an additional vector to store the sorted result.

Key Idea:
- Count the number of set bits (1s) in the binary representation of each number using % 2 and / 2.
- Store each number along with its set-bit count.
- Sort the pairs using a custom comparator:
  - First, sort by set-bit count in ascending order.
  - If set-bit counts are equal, sort by the actual number in ascending order.
- Extract the numbers from the sorted pairs to construct the answer.
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n,i,j,numb,count;
        n=arr.size();
        vector<pair<int,int>> v;
        for(i=0;i<n;i++)
        {
            numb=arr[i];
            count=0;

            while(numb!=0)
            {
                if(numb%2==1)
                {
                    count++;
                }
                numb=numb/2;
            }

            v.push_back({arr[i],count});
        }
        sort(v.begin(),v.end(),[](auto x,auto y)
        {
            if(x.second==y.second)
            {
                return x.first<y.first;
            }
            return x.second<y.second;
        });
        vector<int> ans;
        for(auto x:v)
        {
            ans.push_back(x.first);
        }
        return ans;
    }
};