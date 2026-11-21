/*
Problem: 4116. Assign Umbrella on Rainy Days
Pattern: Arrays
Difficulty: Easy

Time Complexity: O(n)
- Traverse the rain array once and assign an umbrella for each day.

Space Complexity: O(n)
- Output vector stores the umbrella assignment for every day.
- Only a constant amount of extra space is used for counters.

Key Idea:
- If it does not rain, assign "None".
- If it rains on two consecutive days, assign the umbrella to the person with fewer previous assignments.
- If both have equal assignments, prioritize Alice.
- Otherwise, assign the umbrella to Bob.
- Handle the last day separately because the loop stops at n - 1.
*/

class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n,i,bc,ac;
        n=rain.size();
        bc=ac=0;
        vector<string> ans;
        for(i=0;i<n-1;i++)
        {
            if(rain[i]==0)
            {
                ans.push_back("None");
            }
            else if(rain[i]==1&&rain[i+1]==1)
            {
                if(ac<=bc)
                {
                    ans.push_back("Alice");
                    ac++;
                }
                else
                {
                    ans.push_back("Bob");
                    bc++;
                }
            }
            else
            {
                ans.push_back("Bob");
                bc++;
            }
        }
        if(rain[n-1]==0)
        {
            ans.push_back("None");
        }
        else
        {
            ans.push_back("Bob");
        }
        return ans;
    }
};