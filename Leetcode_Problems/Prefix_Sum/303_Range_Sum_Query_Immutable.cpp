/*
Problem: 303. Range Sum Query - Immutable
Pattern: Prefix Sum
Difficulty: Easy

Time Complexity: O(n) for prefix sum construction
(Each element is visited once while building the prefix sum array.)

Time Complexity: O(1) for each sumRange query
(The sum is calculated using two prefix sum values.)

Space Complexity: O(n)
(A prefix sum array 'pref' of size n is used.)

Key Idea:
- Create a prefix sum array 'pref' where pref[i] stores the sum of
  all elements from index 0 to i.
- Initialize pref[0]=nums[0].
- Build the prefix sum array:
    pref[i]=pref[i-1]+nums[i]
- For sumRange(left,right):
    - If left==0:
        - The required sum is simply pref[right].
    - Otherwise:
        - Subtract the prefix sum before 'left' from pref[right].
        - Formula:
            Sum = pref[right] - pref[left-1]
- This allows every range sum query to be answered in O(1) after
  the prefix sum array is built.
*/

class NumArray {
public:
    vector<int> pref;
    NumArray(vector<int>& nums) {
        int i,n;
        n=nums.size();
        pref.resize(n);
        pref[0]=nums[0];
        for(i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int sum=0;
        if(left==0)
        {
            sum=pref[right];
        }
        else
        {
            sum=pref[right]-pref[left-1];
        }
        return sum;        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */