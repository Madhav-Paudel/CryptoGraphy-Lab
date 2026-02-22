// write a c program to implement RSA Algorithm 
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

// Function to calculate GCD
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular inverse (d)
long long modInverse(long long e, long long phi)
{
    long long d = 1;

    while ((d * e) % phi != 1)
        d++;

    return d;
}

int main()
{
    long long p, q;
    long long n, phi;
    long long e, d;
    long long msg;
    long long enc, dec;

    // Input prime numbers
    printf("Enter first prime number (p): ");
    scanf("%lld", &p);

    printf("Enter second prime number (q): ");
    scanf("%lld", &q);

    // Compute n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose e
    printf("Enter public key (e): ");
    scanf("%lld", &e);

    if (gcd(e, phi) != 1)
    {
        printf("Invalid e. gcd(e, phi) must be 1.\n");
        return 0;
    }

    // Compute private key d
    d = modInverse(e, phi);

    printf("\nPublic Key  (e, n) = (%lld, %lld)", e, n);
    printf("\nPrivate Key (d, n) = (%lld, %lld)", d, n);

    // Input message
    printf("\n\nEnter message (number < %lld): ", n);
    scanf("%lld", &msg);

    // Encryption
    enc = power(msg, e, n);
    printf("\nEncrypted Message: %lld", enc);

    // Decryption
    dec = power(enc, d, n);
    printf("\nDecrypted Message: %lld", dec);

    return 0;
}
