// 4.Write a C program  find additive inverse of the given number
#include <stdio.h>
int mod_additive_inverse(int a, int m) {
    return (m - (a % m)) % m;
}
int main() {
    int a, m;
    printf("Enter number and modulus: ");
    scanf("%d %d", &a, &m);
    int inverse = mod_additive_inverse(a, m);
    printf("Additive inverse of %d modulo %d is %d\n", a, m, inverse);
    return 0;
}

