/*
Problem: 599. Minimum Index Sum of Two Lists
Pattern: Hashing 
Difficulty: Easy

Time Complexity: O(n + m)
- First traversal stores each string from list1 with its index.
- Second traversal checks common strings and calculates their index sums.

Space Complexity: O(n + k)
- Hash map stores the strings and their indices from list1.
- Output vector stores the common strings with the minimum index sum.

Key Idea:
- Store each string from list1 as a key and its index as the value in an unordered_map.
- Traverse list2 and check whether each string exists in the map.
- Calculate the index sum for every common string.
- If a smaller sum is found, update the minimum and clear the previous results.
- If the sum equals the minimum, add the string to the result.
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n,m,i,sum,mn=INT_MAX;
        n=list1.size();
        m=list2.size();
        unordered_map<string,int> mp;
        vector<string> ans;
        for(i=0;i<n;i++)
        {
            mp[list1[i]]=i;
        }
        for(i=0;i<m;i++)
        {
            if(mp.count(list2[i]))
            {
                sum=i+mp[list2[i]];
                if(sum<mn)
                {
                    mn=sum;
                    ans.clear();
                    ans.push_back(list2[i]);
                }
                else if(sum==mn)
                {
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};