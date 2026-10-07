/*
Problem: 347. Top K Frequent Elements
Pattern: Hashing + Sorting
Difficulty: Medium

Time Complexity: O(n + m log m)
(We traverse the array once to calculate the frequency of each element
using an unordered_map, which takes O(n) average time. Let m be the
number of distinct elements. We then sort the m distinct elements by
their frequencies in O(m log m) time. Finally, we take the first k
elements in O(k) time.)

Space Complexity: O(m)
(The unordered_map stores the frequency of each distinct element, and
the vector of pairs also stores the m distinct elements with their
frequencies.)

Key Idea:
- Count the frequency of every element using an unordered_map.

- Store the elements and their frequencies as pairs:
    {element, frequency}

- Sort the pairs in descending order of frequency using a custom
  comparator:

    return x.second > y.second;

  Here:
    x.first  = element
    x.second = frequency

- After sorting, the elements with the highest frequencies appear at
  the beginning of the vector.

- Take the first k elements from the sorted vector and store them in
  the answer.

- Example:
    nums = [1,1,1,2,2,3]
    k = 2

    Frequencies:
        1 -> 3
        2 -> 2
        3 -> 1

    After sorting by frequency:
        {1,3}
        {2,2}
        {3,1}

    Take the first 2 elements:
        [1,2]

- The main pattern is:
    Frequency Counting → Sort by Frequency → Take Top K

- The custom comparator is important because the default pair sorting
  would sort primarily by the element value, not by its frequency.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n,i;
        n=nums.size();
        unordered_map<int,int> mp;
        for(i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int>> a(mp.begin(),mp.end());
        sort(a.begin(),a.end(),[](auto x,auto y)
        {
            return x.second>y.second;
        });
        vector<int> ans;
        for(i=0;i<k;i++)
        {
            ans.push_back(a[i].first);
        }
        return ans;
        
    }
};