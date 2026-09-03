#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;

    vector<int> a(n);
    vector<int> pref(n);

    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }

    pref[0]=a[0];

    for(i=1;i<n;i++)
    {
        pref[i]=pref[i-1]+a[i];
    }

    for(i=0;i<n;i++)
    {
        cout << pref[i] << " ";
    }

    return 0;
}