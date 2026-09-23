/*
Problem: 349. Intersection of Two Arrays
Pattern: Hashing + Frequency Counting
Difficulty: Easy

Time Complexity: O(n+m) average
(The first array is traversed once, the second array is traversed once,
and the hashmap is traversed once. unordered_map operations take O(1)
average time.)

Space Complexity: O(n+m)
(In the worst case, both unordered_maps can store all elements from
their respective arrays.)

Key Idea:
- Use two unordered_maps 'm1' and 'm2' to store the elements from
  nums1 and nums2.
- Traverse nums1 and store the frequency of each element in 'm1'.
- Traverse nums2 and store the frequency of each element in 'm2'.
- Traverse 'm1' using:
    for(auto x:m1)
- Here:
    x.first  → the element
    x.second → its frequency in nums1
- Check whether the same element exists in 'm2':
    m2.count(x.first)
- If it exists, the element is present in both arrays, so add it to
  'ans'.
- Since 'm1' stores each distinct element only once, every common
  element is added to 'ans' only once.
- The frequencies themselves are not required for the final check;
  only the existence of each element matters.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n,m,i;
        n=nums1.size();
        m=nums2.size();
        vector<int> ans;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(i=0;i<n;i++)
        {
            m1[nums1[i]]++;
        }
        for(i=0;i<m;i++)
        {
            m2[nums2[i]]++;
        }
        for(auto x:m1)
        {
            if(m2.count(x.first))
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};