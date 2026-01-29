// Write a c program to find primitive root of give number 
#include <stdio.h>
#include <math.h>

// Function to calculate (base^exp) % mod
int power(int base, int exp, int mod) {
    int res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (long long)res * base % mod;
        base = (long long)base * base % mod;
        exp = exp / 2;
    }
    return res;
}

// Function to calculate Euler's totient function phi(n)
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Function to find the smallest primitive root of n
int findPrimitive(int n) {
    if (n == 1) return -1;
    
    int phi_n = phi(n);
    int p = phi_n;
    int factors[100];
    int k = 0;
    
    // Find prime factors of phi(n)
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            factors[k++] = i;
            while (p % i == 0)
                p /= i;
        }
    }
    if (p > 1)
        factors[k++] = p;
        
    // Check for every number from 2 to n-1
    for (int r = 2; r < n; r++) {
        int flag = 0;
        for (int i = 0; i < k; i++) {
            // Check if r^(phi(n)/factors[i]) % n is 1
            if (power(r, phi_n / factors[i], n) == 1) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return r;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    int root = findPrimitive(n);
    
    if (root == -1)
        printf("No primitive root found for %d\n", n);
    else
        printf("Smallest primitive root of %d is %d\n", n, root);
        
    return 0;
}
