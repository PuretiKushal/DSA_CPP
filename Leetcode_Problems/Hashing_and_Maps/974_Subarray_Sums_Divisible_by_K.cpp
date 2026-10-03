/*
Problem: 974. Subarray Sums Divisible by K
Pattern: Prefix Sum + Hashing
Difficulty: Medium

Time Complexity: O(n)
(We traverse the array once. For every element, we calculate the
prefix sum remainder, perform a constant-time hash map lookup, and
update its frequency. Average unordered_map operations take O(1).)

Space Complexity: O(k)
(The hash map stores the frequency of prefix sum remainders. There can
be at most k different remainders, ranging from 0 to k-1.)

Key Idea:
- Use prefix sums to determine whether a subarray has a sum divisible
  by k.

- Let:
    sum = prefix sum up to the current index.

- For a subarray from index i+1 to j:
    subarray_sum = prefix[j] - prefix[i]

- This subarray is divisible by k when:
    (prefix[j] - prefix[i]) % k == 0

- Therefore:
    prefix[j] % k == prefix[i] % k

- So, instead of storing every prefix sum, store the frequency of each
  prefix sum remainder in a hash map.

- `mp[r]` represents how many previous prefix sums had remainder `r`.

- For every element:
    1. Add the element to the running prefix sum.
    2. Calculate its remainder:
        r = ((sum % k) + k) % k
    3. Add `mp[r]` to the answer.
    4. Increment the frequency of this remainder.

- Why do we initialize:
    mp[0] = 1

  This represents an empty prefix before the array starts. It allows
  subarrays starting from index 0 whose sum is directly divisible by k
  to be counted.

- Example:
    nums = [4, 5, 0, -2, -3, 1]
    k = 5

    As we calculate prefix sums, whenever the same remainder appears
    again, the elements between the two prefix sums form a subarray
    whose sum is divisible by 5.

- Negative numbers require special handling because C++ can produce a
  negative remainder for negative values.

    r = ((sum % k) + k) % k

  This converts the remainder into the standard range:
    0 to k-1

- The key pattern is:
    Same prefix sum remainder → subarray sum is divisible by k

- Instead of checking every possible subarray in O(n^2), prefix sum
  remainders and hashing allow all valid subarrays to be counted in
  O(n) average time.
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int i,sum,count,n,r;
        n=nums.size();
        sum=count=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(i=0;i<n;i++)
        {
            sum=sum+nums[i];
            r=((sum%k)+k)%k;
            count=count+mp[r];
            mp[r]++;
        }
        return count;
    }
};