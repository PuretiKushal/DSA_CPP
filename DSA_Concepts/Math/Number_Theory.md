# Number Theory

Number Theory deals with the properties and relationships of integers.
In competitive programming, it is commonly used for problems involving
primes, factors, divisibility, GCD, LCM, modular arithmetic, and powers.

---

## 1. Divisibility

If `a` divides `b`, we write:

```text
a | b
````

This means `b` is completely divisible by `a`.

Example:

```text
3 | 12
```

because:

```text
12 % 3 = 0
```

If:

```cpp
b % a == 0
```

then `a` is a divisor/factor of `b`.

---

## 2. Factors and Multiples

### Factor

A factor of `n` is a number that divides `n` exactly.

Example:

```text
Factors of 12:
1, 2, 3, 4, 6, 12
```

### Multiple

A multiple of `n` is obtained by multiplying `n` by an integer.

Example:

```text
Multiples of 5:
5, 10, 15, 20, 25, ...
```

Relationship:

```text
If a divides b,
then a is a factor of b
and b is a multiple of a.
```

---

## 3. Prime Numbers

A prime number is a positive integer greater than 1 that has exactly
two factors:

```text
1 and itself
```

Examples:

```text
2, 3, 5, 7, 11, 13, 17, ...
```

Important:

```text
2 is the only even prime number.
1 is NOT a prime number.
```

### Checking if a Number is Prime

Instead of checking every number from `2` to `n-1`, we only need to
check up to `sqrt(n)`.

Why?

If:

```text
n = a * b
```

and both `a` and `b` were greater than `sqrt(n)`, their product would
be greater than `n`.

Therefore, if `n` has a factor other than `1` and itself, at least
one factor must be `<= sqrt(n)`.

Time Complexity:

```text
O(sqrt(n))
```

---

## 4. Composite Numbers

A composite number is a positive integer greater than 1 that has more
than two factors.

Examples:

```text
4, 6, 8, 9, 10, 12, ...
```

Every integer greater than 1 is either:

```text
Prime
or
Composite
```

---

## 5. GCD / HCF

GCD means Greatest Common Divisor.

It is the largest number that divides two numbers exactly.

Example:

```text
12 = 1, 2, 3, 4, 6, 12
18 = 1, 2, 3, 6, 9, 18

GCD(12,18) = 6
```

GCD is also called HCF (Highest Common Factor).

---

## 6. Euclidean Algorithm

The Euclidean Algorithm efficiently calculates GCD.

The key relationship is:

```text
gcd(a,b) = gcd(b,a%b)
```

Continue until the second number becomes `0`.

Example:

```text
gcd(48,18)

48 % 18 = 12
18 % 12 = 6
12 % 6  = 0

GCD = 6
```

Time Complexity:

```text
O(log(min(a,b)))
```

### Recursive Implementation

```cpp
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
```

C++ also provides:

```cpp
gcd(a,b)
```

through the standard library.

---

## 7. LCM

LCM means Least Common Multiple.

It is the smallest positive number that is divisible by both numbers.

Example:

```text
Multiples of 4:
4, 8, 12, 16, 20, ...

Multiples of 6:
6, 12, 18, 24, ...

LCM(4,6) = 12
```

For positive integers:

```text
GCD(a,b) * LCM(a,b) = a * b
```

Therefore:

```text
LCM(a,b) = (a / GCD(a,b)) * b
```

Dividing before multiplying can help reduce overflow.

Example:

```cpp
long long lcm(long long a,long long b)
{
    return (a/gcd(a,b))*b;
}
```

---

## 8. Prime Factorization

Prime factorization represents a number as a product of prime numbers.

Example:

```text
60 = 2 * 2 * 3 * 5

60 = 2² * 3 * 5
```

Prime factorization is useful for:

* Finding divisors
* Counting divisors
* Finding GCD/LCM
* Divisibility problems
* Number theory problems

---

## 9. Number of Divisors

Suppose:

```text
n = p₁^a * p₂^b * p₃^c
```

where `p₁`, `p₂`, `p₃` are distinct primes.

Then the number of positive divisors is:

```text
(a+1)(b+1)(c+1)
```

### Example

```text
12 = 2² * 3¹
```

Number of divisors:

```text
(2+1)(1+1)
= 3 * 2
= 6
```

The six divisors are:

```text
1, 2, 3, 4, 6, 12
```

### Why Does This Formula Work?

For:

```text
2² * 3¹
```

A divisor can contain:

```text
2^0, 2^1, or 2^2
```

So there are `3` choices for the power of `2`.

For `3`:

```text
3^0 or 3^1
```

So there are `2` choices.

Therefore:

```text
3 * 2 = 6
```

---

## 10. Finding Divisors Efficiently

Instead of checking every number from `1` to `n`, we can check only
up to `sqrt(n)`.

If:

```text
i divides n
```

then both are divisors:

```text
i
n/i
```

Example:

```text
n = 36

i = 1 → 1, 36
i = 2 → 2, 18
i = 3 → 3, 12
i = 4 → 4, 9
i = 6 → 6, 6
```

Time Complexity:

```text
O(sqrt(n))
```

Be careful when:

```text
i == n/i
```

because the same divisor should not be added twice.

Example:

```cpp
for(int i=1;i*i<=n;i++)
{
    if(n%i==0)
    {
        cout<<i<<" ";
        
        if(i!=n/i)
        {
            cout<<n/i<<" ";
        }
    }
}
```

---

## 11. Modular Arithmetic

The modulo operator gives the remainder:

```cpp
a % b
```

Example:

```text
17 % 5 = 2
```

because:

```text
17 = 5 * 3 + 2
```

Modulo is heavily used in competitive programming for:

* Checking divisibility
* Extracting digits
* Detecting even/odd numbers
* Cyclic patterns
* Large number calculations
* Keeping values within a fixed range

---

## 12. Common Modulo Patterns

### Even / Odd

```cpp
n%2==0
```

→ Even

```cpp
n%2!=0
```

→ Odd

### Last Digit

```cpp
n%10
```

Example:

```text
1237 % 10 = 7
```

### Removing Last Digit

```cpp
n/=10;
```

Example:

```text
1237 → 123 → 12 → 1 → 0
```

These two operations are commonly used for digit-based problems.

---

## 13. Digit Extraction

Modulo and integer division can be used to process every digit.

Example:

```cpp
while(n>0)
{
    int digit=n%10;
    n=n/10;
}
```

For:

```text
n = 1234
```

the extracted digits are:

```text
4
3
2
1
```

This technique is useful for:

* Sum of digits
* Reverse of a number
* Palindrome number
* Counting digits
* Armstrong numbers
* Digit frequency
* Digit-based mathematical problems

---

## 14. Modular Addition and Multiplication

For a modulus `m`:

```text
(a+b)%m
```

can be calculated as:

```text
((a%m)+(b%m))%m
```

Similarly:

```text
(a*b)%m
```

can be calculated as:

```text
((a%m)*(b%m))%m
```

This allows large intermediate values to be reduced during calculations.

### Important

Even when using modulo, multiplication can still overflow before
the modulo is applied if the values are too large.

For example:

```cpp
(a*b)%m
```

may overflow if `a*b` exceeds the data type's range.

For standard `long long` constraints, always check the problem's limits
before choosing the data type or multiplication technique.

---

## 15. Modular Subtraction

For subtraction:

```text
(a-b)%m
```

can produce a negative result in C++ if `a < b`.

A common normalized form is:

```text
((a%m)-(b%m)+m)%m
```

This keeps the result in the range:

```text
0 to m-1
```

Example:

```text
a = 3
b = 8
m = 5

(3-8) = -5

((-5)%5) = 0
```

For a non-multiple example:

```text
a = 2
b = 7
m = 5

(2-7) = -5
```

The normalized result is:

```text
((-5)%5 + 5)%5 = 0
```

---

## 16. Powers

A common number theory operation is calculating:

```text
a^b
```

For small values, normal multiplication can be sufficient.

For very large exponents, repeatedly multiplying `a` is inefficient.

This leads to:

```text
Binary Exponentiation
```

which calculates powers in:

```text
O(log b)
```

This becomes especially useful when combined with modulo:

```text
(a^b) % m
```

This is called Modular Exponentiation.

---

## 17. Binary Exponentiation

Instead of multiplying `a` by itself `b` times, binary exponentiation
uses the binary representation of `b`.

Basic idea:

* If `b` is odd, multiply the answer by `a`.
* Square `a`.
* Divide `b` by 2.
* Repeat until `b` becomes 0.

Example:

```text
a^13

13 in binary = 1101
```

Instead of performing 13 multiplications, the exponent is repeatedly
halved.

Time Complexity:

```text
O(log b)
```

Basic implementation:

```cpp
long long power(long long a,long long b)
{
    long long ans=1;
    
    while(b>0)
    {
        if(b%2==1)
        {
            ans=ans*a;
        }
        
        a=a*a;
        b=b/2;
    }
    
    return ans;
}
```

---

## 18. Modular Exponentiation

When calculating:

```text
(a^b)%m
```

we can apply modulo during every multiplication.

```cpp
long long power(long long a,long long b,long long m)
{
    long long ans=1;
    a=a%m;
    
    while(b>0)
    {
        if(b%2==1)
        {
            ans=(ans*a)%m;
        }
        
        a=(a*a)%m;
        b=b/2;
    }
    
    return ans;
}
```

Time Complexity:

```text
O(log b)
```

Space Complexity:

```text
O(1)
```

This is extremely useful when `b` is very large.

---

## 19. Sieve of Eratosthenes

When we need to find **all prime numbers smaller than or equal to n**,
checking every number individually is inefficient.

The Sieve of Eratosthenes finds all primes together.

### Basic Idea

1. Assume numbers from `2` to `n` are prime.
2. Start with `2`.
3. Mark its multiples as composite.
4. Move to the next unmarked number.
5. Repeat.

The multiples of a prime `p` can start from:

```text
p*p
```

because smaller multiples would already have been marked by smaller
prime factors.

Time Complexity:

```text
O(n log log n)
```

Space Complexity:

```text
O(n)
```

---

## 20. Prime Factorization Using Trial Division

A simple way to find the prime factors of `n` is to repeatedly divide
by possible factors.

Example:

```text
n = 60

60 / 2 = 30
30 / 2 = 15
15 / 3 = 5
5 / 5 = 1

Prime factorization:

60 = 2² * 3 * 5
```

Basic implementation:

```cpp
void primeFactors(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n=n/i;
        }
    }
    
    if(n>1)
    {
        cout<<n;
    }
}
```

Time Complexity:

```text
O(sqrt(n))
```

in the basic approach.

---

## 21. GCD Properties

Some useful properties:

```text
gcd(a,0) = a
```

```text
gcd(a,a) = a
```

```text
gcd(a,b) = gcd(b,a%b)
```

If:

```text
gcd(a,b) = 1
```

then `a` and `b` are called:

```text
Coprime
```

Example:

```text
8 and 15
```

Their only common positive divisor is `1`, so they are coprime.

---

## 22. LCM and GCD Relationship

For positive integers:

```text
GCD(a,b) * LCM(a,b) = a * b
```

Example:

```text
a = 12
b = 18

GCD = 6
LCM = 36

6 * 36 = 216
12 * 18 = 216
```

Therefore:

```text
GCD * LCM = a * b
```

---

## 23. Coprime Numbers

Two numbers are coprime if their GCD is `1`.

Examples:

```text
8 and 15
9 and 10
7 and 20
```

are coprime.

Important:

Coprime does NOT mean both numbers are prime.

For example:

```text
8 and 15
```

are both composite, but:

```text
gcd(8,15) = 1
```

so they are coprime.

---

## 24. Useful Divisibility Rules

### Divisibility by 2

A number is divisible by `2` if its last digit is even.

```text
0, 2, 4, 6, 8
```

### Divisibility by 3

A number is divisible by `3` if the sum of its digits is divisible by `3`.

Example:

```text
123

1+2+3 = 6
6 is divisible by 3
```

Therefore:

```text
123 is divisible by 3.
```

### Divisibility by 5

Last digit must be:

```text
0 or 5
```

### Divisibility by 9

The sum of the digits must be divisible by `9`.

Example:

```text
729

7+2+9 = 18
18 is divisible by 9
```

### Divisibility by 10

Last digit must be:

```text
0
```

These rules can sometimes help solve problems without directly
performing division.

---

## 25. Important Number Theory Patterns

When reading a problem, look for clues.

### "Divisible by..."

Think:

```text
%
GCD
LCM
Factors
```

### "Prime"

Think:

```text
Prime Check
Sieve
Prime Factorization
```

### "Common divisor"

Think:

```text
GCD
```

### "Common multiple"

Think:

```text
LCM
```

### "Number of factors/divisors"

Think:

```text
sqrt(n)
Prime Factorization
```

### "Very large power"

Think:

```text
Binary Exponentiation
Modular Exponentiation
```

### "All primes up to n"

Think:

```text
Sieve of Eratosthenes
```

### "Digits"

Think:

```text
n%10
n/=10
```

### "Large answer modulo m"

Think:

```text
Modular Arithmetic
Modular Exponentiation
```

---

## 26. Common Mistakes

### Mistake 1: Treating 1 as Prime

`1` is neither prime nor composite.

```text
1 → Neither
```

### Mistake 2: Checking Every Number for Prime

Instead of checking from `2` to `n-1`, check only up to:

```text
sqrt(n)
```

### Mistake 3: Counting a Square Root Divisor Twice

When finding divisors:

```text
if(i*i==n)
```

do not add both `i` and `n/i`.

### Mistake 4: LCM Overflow

Avoid:

```cpp
a*b/gcd(a,b)
```

when `a*b` may overflow.

Prefer:

```cpp
(a/gcd(a,b))*b
```

### Mistake 5: Forgetting Negative Modulo

In C++, negative values can produce a negative remainder.

Normalize when required:

```text
((x%m)+m)%m
```

### Mistake 6: Normal Exponentiation for Huge Powers

Repeated multiplication takes:

```text
O(b)
```

Use binary exponentiation for:

```text
O(log b)
```

---

## 27. Complexity Summary

| Technique              |  Time Complexity | Space Complexity |
| ---------------------- | ---------------: | ---------------: |
| Prime Check            |       O(sqrt(n)) |             O(1) |
| Find Divisors          |       O(sqrt(n)) |             O(1) |
| Euclidean GCD          | O(log(min(a,b))) |   O(1) iterative |
| Prime Factorization    |       O(sqrt(n)) |             O(1) |
| Sieve of Eratosthenes  |   O(n log log n) |             O(n) |
| Binary Exponentiation  |         O(log b) |             O(1) |
| Modular Exponentiation |         O(log b) |             O(1) |

---

## 28. Quick Revision Sheet

```text
Prime:
Exactly 2 positive divisors → 1 and itself

1:
Neither prime nor composite

GCD:
Largest common divisor

LCM:
Smallest positive common multiple

Euclidean Algorithm:
gcd(a,b) = gcd(b,a%b)

GCD × LCM:
a × b

Prime Factorization:
Represent a number as a product of primes

Number of Divisors:
If n = p₁^a × p₂^b × ...,
divisors = (a+1)(b+1)...

Check Prime:
O(sqrt(n))

Find Divisors:
O(sqrt(n))

Sieve:
Find all primes up to n
O(n log log n)

Binary Exponentiation:
a^b in O(log b)

Modulo:
a % b = remainder

Last Digit:
n % 10

Remove Last Digit:
n / 10
```

---

