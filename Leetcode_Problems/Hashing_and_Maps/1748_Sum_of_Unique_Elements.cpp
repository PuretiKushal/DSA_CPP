/*
Problem: 1748. Sum of Unique Elements
Pattern: Hashing + Frequency Count
Difficulty: Easy

Time Complexity: O(n)
- The first loop traverses the array and counts the frequency of each element in the unordered_map.
- The second loop traverses the map and adds elements whose frequency is exactly 1.
- Both operations take O(n) time on average.

Space Complexity: O(n)
- The unordered_map stores the frequency of each distinct element.
- In the worst case, all n elements are distinct.

Key Idea:
- Use an unordered_map to store the frequency of every element in nums.
- Traverse the array and increment the frequency of each element.
- Traverse the map and check whether each element occurs exactly once.
- If its frequency is 1, add the element's value to sum.
- Return sum after processing all distinct elements.
*/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n,i,sum=0;;
        n=nums.size();
        unordered_map<int,int> mp;
        for(i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second==1)
            {
                sum=sum+x.first;
            }
        }
        return sum;  
    }
};