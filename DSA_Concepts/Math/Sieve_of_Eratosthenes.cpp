/* Sieve of Eratosthenes - Most Efficient approach to count the prime numbers within the given number */

#include<bits/stdc++.h>
using namespace std;
long long countPrime(long long n)
{
    long long i,j,count=0,ans=0;
    long long size=((n-1-3)/2)+1; //Removed all the even numbers, so size is number of odd numbers starting from number 3 till n (excluded)= ((n-1-3)/2)+1
    vector<bool> is_prime(size,true); //Create and initialize all the values of the vector to true
    for(i=0;2*i+3<=sqrt(n);i++) //2*i+3 is the actual value, not i,i is just an index
    {
        if(is_prime[i])
        {
            long long p=2*i+3; //p means the prime_value
            long long q=p*p; //q means the start_value from which we've to start cancelling multiples of prime_value
            long long start_pos=(q-3)/2; //start_pos is the index of start_value (q=2*start_pos+3)
            for(j=start_pos;j<size;j=j+p)
            {
                is_prime[j]=false; //Iterate through the loop from start_pos and increment by p everytime to get multiples
            }
        }
    }
    for(i=0;i<size;i++)
    {
        if(is_prime[i])
        {
            count++;
        }
    }
    ans=count+1; //Do not forget to add the only even prime 2, to the answer
    return ans;
    
}
int main()
{
    long long n;
    cout << "Enter the number: " << endl;
    cin >> n;
    if(n<3)
    {
        cout << 0 << endl; //The number will be excluded (strictly less than the number), so 0
        return 0;
    }
    if(n==3)
    {
        cout << 1 << endl; //3 has 2 as the only prime number
        return 0;
    }
    if(n==4)
    {
        cout << 2 << endl; //4 has 2 and 3
        return 0;
    }
    cout << "The number of prime numbers within the given number is: " << countPrime(n) << endl;
}