/*
Problem: 204. Count Primes
Pattern: Sieve of Eratosthenes + Number Theory
Difficulty: Medium

Time Complexity: O(n log log n)
(The Sieve of Eratosthenes marks the multiples of prime numbers.
Only odd numbers are stored, reducing the amount of work and memory
compared to the standard sieve implementation.)

Space Complexity: O(n)
(The vector 'isPrime' stores information for approximately n/2 odd
numbers.)

Key Idea:
- The problem asks for the number of prime numbers strictly less than n.
- Handle small values separately:
    - If n<3, there are no primes less than n.
    - If n==3, the only prime less than n is 2.
- Ignore all even numbers greater than 2 because they cannot be prime.
- Store only odd numbers starting from 3 in 'isPrime'.
- The index-to-value mapping is:
    value = 2*i+3
- For every index i:
    - If isPrime[i] is true, the corresponding value is prime.
    - Let:
        p=2*i+3
    - Start marking multiples from p² because smaller multiples of p
      have already been marked by smaller prime factors.
    - Convert p² into its corresponding index:
        start_pos=(p*p-3)/2
    - Mark every multiple of p as non-prime using:
        j=j+p
- Finally, count all remaining true values in 'isPrime'.
- Add 1 to include the only even prime number, 2.
- The resulting value is the number of primes strictly less than n.
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<3)
        {
            return 0;
        }
        if(n==3)
        {
            return 1;
        }
        int size=((n-4)/2)+1;
        vector<bool> isPrime(size,true);
        int i,j,count=0,ans=0;
        for(i=0;i<sqrt(n);i++)
        {
            if(isPrime[i])
            {
                long long p=2*i+3;
                long long q=p*p;
                long long start_pos=(q-3)/2;
                for(j=start_pos;j<size;j=j+p)
                {
                    isPrime[j]=false;
                }
            }
        }
        for(i=0;i<size;i++)
        {
            if(isPrime[i])
            {
                count++;
            }
        }
        ans=count+1;
        return ans;
    }
};