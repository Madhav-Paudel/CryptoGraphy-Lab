// Write a c program to check  if given number is prime or not using miller rabin algorithm 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Modular exponentiation to compute (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Miller-Rabin primality test iteration
int millerTest(long long d, long long n) {
    // Pick a random number in [2..n-2]
    long long a = 2 + rand() % (n - 4);
    
    // Compute x = a^d % n
    long long x = power(a, d, n);
    
    if (x == 1 || x == n - 1)
        return 1;
    
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        
        if (x == 1) return 0;
        if (x == n - 1) return 1;
    }
    return 0;
}

// Returns true if n is prime, false otherwise. k is number of iterations
int isPrime(long long n, int k) {
    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;
    
    // Find r and d such that n - 1 = 2^r * d
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;
        
    for (int i = 0; i < k; i++) {
        if (!millerTest(d, n))
            return 0;
    }
    return 1;
}

int main() {
    long long n;
    int k = 4; // Accuracy parameter
    
    srand(time(0));
    printf("Enter a number: ");
    scanf("%lld", &n);
    
    if (isPrime(n, k))
        printf("%lld is probably prime (Miller-Rabin test).\n", n);
    else
        printf("%lld is composite.\n", n);
        
    return 0;
}
