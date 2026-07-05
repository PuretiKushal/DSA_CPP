#include<bits/stdc++.h>
using namespace std;
void printone(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout << " ";
        }
        for(int j=1;j<=2*i-1;j++)
        {
            cout << "*";
        }
        cout << endl;

    }
 
}
void printtwo(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            cout << " ";
        }
        for(int j=1;j<=2*n-2*i+1;j++)
        {
            cout << "*";
        }
        cout << endl;

    }
}
void printthree(int n) /*symmetrical*/
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout << " ";
        }
        for(int j=1;j<=2*i-1;j++)
        {
            cout << "*";
        }
        cout << endl;

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            cout << " ";
        }
        for(int j=1;j<=2*n-2*i+1;j++)
        {
            cout << "*";
        }
        cout << endl;

    }
    
}

void print1(int n)
{
    for(int i=1;i<=2*n-1;i++)
    {
        if(i<=5)
        {
        for(int j=1;j<=i;j++)
        {
         cout << "*";   
            
        }
        }
        else
        {
            for(int j=1;j<=2*n-i;j++)
            {
                cout << "*";
            }
        }
        cout << endl;
        
    }
}
void print2(int n)
{
    int start;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            start =1;
        }
        else
        {
            start=0;
        }
        for(int j=1;j<=i;j++)
        {
            cout << start;
            cout << " ";
            start=1-start;
        }
        cout << endl;
        
    }
}
void print3(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << j;
            
        }
        for(int j=1;j<=2*n-2*i;j++)
        {
            cout << " ";
        }
        for(int j=i;j>=1;j--)
        {
            cout << j;
            

        }
        cout << endl;
    }
}
void print4(int n){
    int num=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << num;
            cout << " ";
            num++;
        }
        cout << endl;
    }
}
void print5(int n)
{
    char p='A';
    for(int i=1;i<=n;i++)
    {
        p='A';
        for(int j=1;j<=i;j++)
        {
            cout << p;
            p++;
        }
        cout << endl;
    }
}
void print6(int n)
{
    char p='A';
    for(int i=1;i<=n;i++)
    {
        p='A';
        for(int j=i;j<=n;j++)
        {
            cout << p;
            p++;
        }
        cout << endl;
    }
}
void print7(int n)
{
    char p='A';
    for(int i=1;i<=n;i++)
    {
        
        for(int j=i;j<=n;j++)
        {
            cout << p;
            
        }
        p++;
        cout << endl;
    }
}
void print8(int n)
{
    char p='A';
    for(int i=1;i<=n;i++)
    {
        
        for(int j=1;j<=i;j++)
        {
            cout << p;
            
        }
        p++;
        cout << endl;
    }
}
void print9(int n)
{
    char p='A';
    for(int i=1;i<=n;i++)
    {
        p='A';
        for(int j=1;j<=n-i;j++)
        {
            cout << " ";
            
        }
        for(int j=1;j<=2*i-1;j++)
        {
            cout << p;
            if(j>=i)
            {
                p--;
            }
            else
            {
                p++;
            }
        }
        cout << endl;
    }
}
void print10(int n)
{
    char p='A';
    for(int i=1;i<=n;i++)
    {
        p='A'+n-i;
        for(int j=1;j<=i;j++)
        {
            cout << p;
            cout << " ";
            p++;
        }
        cout << endl;
        
    }
}
void print11(int n)
{
    int spaces=0;
    for(int i=1;i<=n;i++)
    {
        
        for(int j=1;j<=n-i+1;j++)
        {
            cout << "*";
        }
        for(int j=1;j<=spaces;j++)
        {
            cout << " ";
            
        }
        for(int j=1;j<=n-i+1;j++)
        {
            cout << "*";
        }
        cout << endl;
        spaces=spaces+2;
        
    }
    
}
void print12(int n)
{
    int spaces=2*n-2;
    for(int i=1;i<=n;i++)
    {
        
        for(int j=1;j<=i;j++)
        {
            cout << "*";
            
        }
        for(int j=1;j<=spaces;j++)
        {
            cout << " ";
        }
        for(int j=1;j<=i;j++)
        {
            cout << "*";
            
        }
        cout << endl;
        spaces=spaces-2;
        
    }
    
}
void print13(int n)
{
    int spaces=0;
    for(int i=1;i<=2*n-1;i++)
    {
        if(i<=n)
        {
            spaces=2*(n-i);
        for(int j=1;j<=i;j++)
        {
            cout << "*";
        }
        for(int j=1;j<=spaces;j++)
        {
            cout << " ";
        }
        for(int j=1;j<=i;j++)
        {
            cout << "*";
        }
        cout << endl;
        }
        
        else
        {
            spaces=2*(i-n);
        for(int j=1;j<=2*n-i;j++)
        {
            cout << "*";
        }
        for(int j=1;j<=spaces;j++)
        {
            cout << " ";
        }
        for(int j=1;j<=2*n-i;j++)
        {
            cout << "*";
        }
        cout << endl;
        }
        
        
    }
}
void print14(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1||i==n||j==1||j==n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            
        }
        cout << endl;
    }
}
void print15(int n)
{ 
    int top,bottom,right,left;
    int mind;
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            top=i;
            bottom=2*n-i-2;
            left=j;
            right=2*n-j-2;
            mind=min(min(top,bottom),min(left,right));
            cout << n-mind;
        }
        cout << endl;
    }
}

int main() {
   int n;
   cin >> n;
   print15(n);
   
  
    return 0;
}
