/*
Problem: 1299. Replace Elements with Greatest Element on Right Side
Pattern: Arrays + Traversal + Running Maximum
Difficulty: Easy

Time Complexity: O(n)
- Traverse the array once from right to left.
- Each iteration performs a constant amount of work to update the answer and the maximum.
- Therefore, the overall time complexity is O(n).

Space Complexity: O(n)
- The ans vector stores the replacement value for every element.
- Therefore, the additional space required is O(n).

Key Idea:
- Traverse the array from right to left.
- Initialize mx to -1, representing the required value for the last element.
- For each index, store mx in ans[i], since it represents the greatest element to the right.
- Save the current element in x before updating the maximum.
- Update mx using max(mx, x) so it represents the greatest element encountered so far.
- Return the ans vector containing the replaced elements.
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n,i,x,mx;
        n=arr.size();
        vector<int> ans(n);
        mx=-1;a
        for(i=n-1;i>=0;i--)
        {
            x=arr[i];
            ans[i]=mx;
            mx=max(mx,x);
        }
       return ans;
    }
};