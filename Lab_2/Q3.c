// 3.Write a C program find multiplicative iververse of given number using extend euliden algorithm.
#include <stdio.h>
int extended_gcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_gcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_gcd(a, m, &x, &y);
    if (g != 1) {
        return -1; // Inverse doesn't exist
    } else {
        int res = (x % m + m) % m;
        return res;
    }
}
int main() {
    int a, m;
    printf("Enter number and modulus: ");
    scanf("%d %d", &a, &m);
    int inverse = mod_inverse(a, m);
    if (inverse == -1) {
        printf("Multiplicative inverse doesn't exist.\n");
    } else {
        printf("Multiplicative inverse of %d modulo %d is %d\n", a, m, inverse);
    }
    return 0;
}
