/*
Problem: 2904. Shortest and Lexicographically Smallest Beautiful String
Pattern: Variable Size Sliding Window

Time Complexity: O(n)
- `l` and `r` each move from left to right at most once.
- String creation/comparison adds some overhead, but the overall
  sliding-window traversal is linear.

Space Complexity: O(n)
- `temp` and `ans` can store substrings.

Key Idea:
- A beautiful substring must contain exactly `k` ones.
- Expand the window using `r`.
- If the window contains more than `k` ones, move `l` forward
  until it contains at most `k` ones.
- When the window contains exactly `k` ones, remove unnecessary
  zeros from both ends to get the shortest valid substring.

Window State:

l → left end of the window
r → right end of the window
o → number of ones in the current window

Expansion:

if(s[r]=='1')
{
    o++;
}

If there are too many ones:

while(o>k)
{
    if(s[l]=='1')
    {
        o--;
    }

    l++;
}

Now:

o==k
→ current window contains exactly k ones.

Removing leading zeros:

while(s[l]=='0')
{
    l++;
}

This does not change the number of ones, so the substring
becomes shorter while remaining beautiful.

Removing trailing zeros:

string temp=s.substr(l,r-l+1);

while(temp.back()=='0')
{
    temp.pop_back();
}

Now `temp` is the shortest substring for this right endpoint.

Updating the answer:

if(ans==""||temp.size()<ans.size()||
   (temp.size()==ans.size()&&temp<ans))
{
    ans=temp;
}

Priority:

1. Shorter length is better.
2. If lengths are equal, lexicographically smaller is better.

Important Sliding Window Idea:
- The window maintains the condition `ones <= k`.
- Once `ones == k`, we try to minimize the window.
- Leading/trailing zeros can be removed without affecting the
  number of ones.

Pattern:

expand right
    ↓
count ones
    ↓
ones > k?
    ↓ yes
move left until ones <= k
    ↓
ones == k?
    ↓ yes
remove unnecessary zeros
    ↓
compare with answer

Core Concept:
The window is not simply looking for one valid substring.
It continuously finds the best valid substring for every possible
right endpoint and keeps the shortest/lexicographically smallest one.
*/

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l,r,n,o;
        string ans="";
        n=s.size();
        l=r=o=0;
        while(r<n)
        {
            if(s[r]=='1')
            {
                o++;
            }
            while(o>k)
            {
                if(s[l]=='1')
                {
                    o--;
                }
                l++;
            }
            if(o==k)
            {
                while(s[l]=='0')
                {
                    l++;
                }
                string temp=s.substr(l,r-l+1);
                while(temp.back()=='0')
                {
                    temp.pop_back();
                }
                if(ans==""||temp.size()<ans.size()||(temp.size()==ans.size()&&temp<ans))
                {
                    ans=temp;
                }
            }
            r++;
        }
        return ans;
    }
};