// 2.Write a c program to check if the given two number is co prime or not 
#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    if (gcd(x, y) == 1)
        printf("The numbers are Co-Prime.\n");
    else
        printf("The numbers are NOT Co-Prime.\n");

    return 0;
}
