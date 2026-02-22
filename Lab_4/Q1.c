// Write a c program to implement diffie-hellmon key exchange 
#include <stdio.h>
#include <math.h>

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

int main()
{
    long long P, G;
    long long a, b;
    long long x, y;
    long long keyA, keyB;

    // Input public values
    printf("Enter Prime number (P): ");
    scanf("%lld", &P);

    printf("Enter Primitive root (G): ");
    scanf("%lld", &G);

    // Input private keys
    printf("Enter Private key of A (a): ");
    scanf("%lld", &a);

    printf("Enter Private key of B (b): ");
    scanf("%lld", &b);

    // Calculate public keys
    x = power(G, a, P);   // A's public key
    y = power(G, b, P);   // B's public key

    printf("\nPublic Key of A: %lld", x);
    printf("\nPublic Key of B: %lld", y);

    // Generate shared secret key
    keyA = power(y, a, P);
    keyB = power(x, b, P);

    printf("\n\nSecret Key for A: %lld", keyA);
    printf("\nSecret Key for B: %lld", keyB);

    if (keyA == keyB)
        printf("\n\nKey Exchange Successful!");
    else
        printf("\n\nKey Exchange Failed!");

    return 0;
}
