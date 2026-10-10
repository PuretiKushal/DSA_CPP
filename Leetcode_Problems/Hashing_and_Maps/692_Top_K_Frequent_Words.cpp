/*
Problem: 692. Top K Frequent Words
Pattern: Hashing + Sorting
Difficulty: Medium

Time Complexity: O(n + u log u)
(The frequency map processes all n words in O(n) time.
The unique words are stored in a vector of size u, which takes O(u) time.
Sorting the vector takes O(u log u) time, and selecting the first k
words takes O(k) time. Overall, the complexity is O(n + u log u).)

Space Complexity: O(u)
(The unordered_map stores the frequency of each unique word, requiring
O(u) space. The vector stores u word-frequency pairs, and the result
vector stores k words. Overall, the auxiliary space complexity is O(u).)

Key Idea:
- Use an unordered_map to count the frequency of each word.
- Store the word-frequency pairs in a vector.
- Sort the vector using a custom comparator:
    1. If frequencies differ, sort by frequency in descending order.
    2. If frequencies are equal, sort alphabetically in ascending order.
- Add the first k words from the sorted vector to the result.
- Return the result.
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n,i;
        n=words.size();
        unordered_map<string,int> mp;
        for(i=0;i<n;i++)
        {
            mp[words[i]]++;
        } 
        vector<pair<string,int>> a(mp.begin(),mp.end());
        sort(a.begin(),a.end(),[](auto x,auto y)
        {
            if(x.second==y.second)
            {
                return x.first<y.first;
            } 
            return x.second>y.second;
        });
        vector<string> ans;
        for(i=0;i<k;i++)
        {
            ans.push_back(a[i].first);
        } 
        return ans;
    }
};