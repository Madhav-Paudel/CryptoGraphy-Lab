// write a program to illustrate the Hill Chipher for Monoaphabetic Chipher
#include <stdio.h>
#include <string.h>

#define MAX 100

int mod26(int x) {
    return (x % 26 + 26) % 26;
}

void encrypt(int n, int key[n][n], char text[]) {
    int i, j, k;
    int len = strlen(text);

    for (i = 0; i < len; i += n) {
        int block[n];
        int result[n];

        for (j = 0; j < n; j++)
            block[j] = text[i + j] - 'A';

        for (j = 0; j < n; j++) {
            result[j] = 0;
            for (k = 0; k < n; k++)
                result[j] += key[j][k] * block[k];
            result[j] = mod26(result[j]);
        }

        for (j = 0; j < n; j++)
            text[i + j] = result[j] + 'A';
    }
}

int main() {
    int n, choice;
    char text[MAX];
    int key[3][3];

    printf("Hill Cipher Program\n");
    printf("Select Matrix Size (2 or 3): ");
    scanf("%d", &n);

    if (n != 2 && n != 3) {
        printf("Invalid matrix size!\n");
        return 0;
    }

    printf("Enter key matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &key[i][j]);

    printf("1. Encrypt\n");
    printf("2. Decrypt (manual inverse key required)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter message (UPPERCASE only): ");
    scanf("%s", text);

    // Padding
    while (strlen(text) % n != 0)
        strcat(text, "X");

    if (choice == 1) {
        encrypt(n, key, text);
        printf("Encrypted Text: %s\n", text);
    }
    else if (choice == 2) {
        printf("\nNOTE:\n");
        printf("For decryption, ENTER THE INVERSE KEY MATRIX (mod 26)\n");

        printf("Enter inverse key matrix (%dx%d):\n", n, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &key[i][j]);

        encrypt(n, key, text);  // same logic works with inverse key
        printf("Decrypted Text: %s\n", text);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
