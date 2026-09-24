/*
Problem: 128. Longest Consecutive Sequence
Pattern: Hashing + Unordered Set
Difficulty: Medium

Time Complexity: O(n) average
(Each element is inserted into the unordered_set once.
The second loop checks each unique element, and each consecutive
sequence is traversed only from its starting element.)

Space Complexity: O(n)
(The unordered_set stores all unique elements from the input array.)

Key Idea:
- Use an unordered_set 'st' to store all unique elements.
- Insert every element of nums into the set.
- Traverse the unique elements using:
    for(auto x:st)
- An element 'x' is the start of a consecutive sequence if:
    !st.count(x-1)
- This means there is no smaller consecutive element before 'x'.
- For every sequence start:
    - Initialize 'count' to 1.
    - Keep checking for consecutive elements:
        st.count(x+count)
    - Increment 'count' while consecutive elements exist.
- Update 'ans' with the maximum sequence length found.
- By starting the search only from sequence-start elements, the same
  consecutive sequence is not unnecessarily processed from every
  element.
- 'unordered_set' provides average O(1) existence checking.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n,i,count,ans=0;
        unordered_set<int> st;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        for(auto x:st)
        {
            if(!st.count(x-1))
            {
                count=1;
                while(st.count(x+count))
                {
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};