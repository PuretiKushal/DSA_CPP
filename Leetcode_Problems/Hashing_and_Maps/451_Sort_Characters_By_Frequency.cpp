/*
Problem: 451. Sort Characters By Frequency
Pattern: Hashing + Sorting
Difficulty: Medium

Time Complexity: O(n + k log k)
(We traverse the string once to calculate the frequency of each
character using an unordered_map, which takes O(n) average time.
Let k be the number of distinct characters. We then sort the k
characters by their frequencies in O(k log k) time. Finally, we
construct the result by processing each character according to
its frequency, which takes O(n) time in total.)

Space Complexity: O(k)
(The unordered_map stores the frequency of each distinct character,
and the vector of pairs also stores the k distinct characters with
their frequencies. The input string s is reused to store the final
answer, so no separate result string is required.)

Key Idea:
- Count the frequency of every character using an unordered_map.

- Store the characters and their frequencies as pairs:
    {character, frequency}

- Sort the pairs in descending order of frequency using a custom
  comparator:

    return x.second > y.second;

  Here:
    x.first  = character
    x.second = frequency

- Use the original string s to construct the answer instead of
  creating a separate result string.

- Maintain a separate index k for the position where the next
  character should be placed in s.

- For every character in the sorted vector:
    - Get its frequency.
    - Insert that character into s exactly that many times.
    - Increment k after every insertion.

- Example:
    s = "tree"

    Frequencies:
        t -> 1
        r -> 1
        e -> 2

    After sorting:
        e -> 2
        t -> 1
        r -> 1

    Constructing the result:
        e e t r

    Result:
        "eetr"

- Three different indices have separate purposes:
    i -> traverses the sorted vector of characters.
    j -> stores/counts the frequency of the current character.
    k -> tracks the position in the result string.

- The main pattern is:
    Frequency Counting → Sort by Frequency → Construct Result

- The original string is reused for the output, avoiding the need
  for a separate answer string.
*/

class Solution {
public:
    string frequencySort(string s) {
        int n,i,j,k;
        n=s.size();
        unordered_map<char,int> mp;
        for(i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        vector<pair<char,int>> a(mp.begin(),mp.end());
        sort(a.begin(),a.end(),[](auto x,auto y)
        {
            return x.second>y.second;
        });
        k=0;
        for(i=0;i<a.size();i++)
        {
            j=a[i].second;
            while(j--)
            {
                s[k]=a[i].first;
                k++;
            }
        }
        return s;
    }
};