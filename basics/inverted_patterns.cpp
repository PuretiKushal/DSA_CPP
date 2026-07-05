/*
#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,n,num;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        num=i;
        for(j=1;j<i;j++)
        {
          cout << " ";
        }
        for(k=1;k<=n-i;k++)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
    */

#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,n,num;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        num=i;
        for(j=1;j<=n-i-1;j++)
        {
            cout << " ";
        }
        for(j=1;j<=i;j++)
        {
            cout << num;
            num++;
        }
        for(j=1;j<=i;j++)
        {
            cout << i-1;
            i--;
        }
        cout << endl;
    }
    return 0;
}