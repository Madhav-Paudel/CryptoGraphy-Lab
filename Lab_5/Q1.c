// Write a c program to illustrate functioning of S-box of DES
#include <stdio.h>

// S-Box 1 of DES
int SBOX[4][16] =
{
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

int main()
{
    int input;
    int row, col;
    int output;

    printf("Enter 6-bit input (0 to 63): ");
    scanf("%d", &input);

    if (input < 0 || input > 63)
    {
        printf("Invalid input! Enter a number between 0 and 63.\n");
        return 0;
    }

    // Extract row: first and last bit
    row = ((input & 32) >> 4) | (input & 1);

    // Extract column: middle 4 bits
    col = (input & 30) >> 1;

    // Get S-box output
    output = SBOX[row][col];

    printf("\nRow = %d", row);
    printf("\nColumn = %d", col);
    printf("\nS-Box Output (4-bit) = %d", output);

    return 0;
}
