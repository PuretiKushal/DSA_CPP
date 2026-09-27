#include<bits/stdc++.h>
using namespace std;
int main()
{
    string b;
    int i,j,o=0,n;
    /* BRUTE FORCE APPROACH
    cout << "Enter the binary number:" << endl;
    cin >> b;
    for(i=0;i<b.size();i++)
    {
        if(b[i]=='1')
        {
            o++;
        }
    }
    */
    
    //OPTIMISED APPROACH - BRIAN KERNIGHAN'S ALGORITHM
    cout << "Enter the number:" << endl;
    cin >> n;
    while(n)
    {
        n=n&(n-1);
        o++;
    }
    cout << "The number of ones in its binary representation are: " << o << endl;
    return 0;
    
    
}