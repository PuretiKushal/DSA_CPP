/*
Problem: 2053. Kth Distinct String in an Array
Pattern: Hash Map + String + Frequency Counting
Difficulty: Easy

Time Complexity: O(n) average
- First traversal counts the frequency of each string.
- Second traversal counts distinct strings in their original order.
- Hash map operations take O(1) average time.

Space Complexity: O(n)
- The unordered_map stores the frequency of each distinct string.

Key Idea:
- Use an unordered_map to count the frequency of every string.
- Count how many strings appear exactly once.
- If the total number of distinct strings is less than k, return an empty string.
- Traverse the original array to preserve the given order.
- Consider only strings with frequency 1.
- Return the kth distinct string.
*/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n,i,count=0,c=0;
        n=arr.size();
        string ans="";
        unordered_map<string,int> mp;
        for(i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second==1)
            {
                count++;
            }
        }
        if(count<k)
        {
            return "";
        }
        for(i=0;i<n;i++)
        {
            if(mp[arr[i]]==1)
            {
                c++;
            }
            if(c==k)
            {
                ans=arr[i];
                break;
            }
        }
        return ans;
    }
};