/*
Problem: 1207. Unique Number of Occurrences
Pattern: Hashing + Frequency Counting + Set
Difficulty: Easy

Time Complexity: O(n)
(We traverse the array once to calculate the frequency of each
element using an unordered_map. We then traverse the distinct
elements once to check whether any frequency appears more than
once using an unordered_set. Both unordered_map and unordered_set
operations take O(1) average time.)

Space Complexity: O(n)
(The unordered_map stores the frequency of each distinct element,
and the unordered_set stores the distinct frequencies. In the
worst case, all elements are different, so both structures can
store O(n) elements.)

Key Idea:
- Count the frequency of every element using an unordered_map.

- The map stores:
    x.first  = element
    x.second = frequency of that element

- After calculating all frequencies, use an unordered_set to keep
  track of frequencies that have already been encountered.

- Traverse the frequency map:
    - If x.second is already present in the set, two different
      elements have the same frequency, so return false.
    - Otherwise, insert x.second into the set.

- Example:
    arr = [1,1,1,2,2,3]

    Frequencies:
        1 -> 3
        2 -> 2
        3 -> 1

    Set of frequencies:
        {3, 2, 1}

    All frequencies are unique, so return true.

- If the frequencies were:
        1 -> 3
        2 -> 3
        3 -> 1

  then frequency 3 would appear twice, so return false.

- The main pattern is:
    Frequency Counting → Store Frequencies in Set → Detect Duplicate

- Important:
    When using:

        for(auto x:mp)

    x is a pair:
        x.first  = key
        x.second = value

    Here, x.second represents the frequency.
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n,i;
        n=arr.size();
        unordered_map<int,int> mp;
        for(i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto x:mp)
        {
            if(s.find(x.second)!=s.end())
            {
                return false;
            }
            else
            {
                s.insert(x.second);
            }
        }
        return true;
    }
};