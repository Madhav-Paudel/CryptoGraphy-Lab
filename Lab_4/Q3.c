// Write a c program to implement Elgamal cryptographic System 
#include <stdio.h>

// Function to calculate (base^exp) % mod
long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp / 2;
        base = (base * base) % mod;
    }

    return result;
}

// Function to find modular inverse
long long modInverse(long long a, long long p)
{
    long long i;

    for (i = 1; i < p; i++)
    {
        if ((a * i) % p == 1)
            return i;
    }

    return -1;
}

int main()
{
    long long p, g;
    long long x;   // Private key
    long long y;   // Public key
    long long k;   // Random key
    long long m;   // Message

    long long a, b;
    long long decrypted;

    // Input public parameters
    printf("Enter large prime number (p): ");
    scanf("%lld", &p);

    printf("Enter primitive root (g): ");
    scanf("%lld", &g);

    // Private key
    printf("Enter private key (x): ");
    scanf("%lld", &x);

    // Public key
    y = power(g, x, p);

    printf("\nPublic Key (y) = %lld", y);

    // Message
    printf("\nEnter message (number < %lld): ", p);
    scanf("%lld", &m);

    // Random number k
    printf("Enter random key (k): ");
    scanf("%lld", &k);

    // Encryption
    a = power(g, k, p);
    b = (power(y, k, p) * m) % p;

    printf("\nEncrypted Pair (a, b) = (%lld, %lld)", a, b);

    // Decryption
    long long ax = power(a, x, p);
    long long ax_inv = modInverse(ax, p);

    if (ax_inv == -1)
    {
        printf("\nModular inverse does not exist!");
        return 0;
    }

    decrypted = (b * ax_inv) % p;

    printf("\nDecrypted Message = %lld", decrypted);

    return 0;
}
