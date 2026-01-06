// write a program to illustrate the Row Transposition Cipher for Transposition Cipher
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], int key[], int klen) {
    int len = strlen(text);
    int rows = (len + klen - 1) / klen;

    char matrix[rows][klen];
    int i, j, idx = 0;

    // Fill matrix row-wise
    for (i = 0; i < rows; i++) {
        for (j = 0; j < klen; j++) {
            if (idx < len)
                matrix[i][j] = text[idx++];
            else
                matrix[i][j] = 'X';   // padding
        }
    }

    // Read columns in key order
    idx = 0;
    for (i = 1; i <= klen; i++) {
        for (j = 0; j < klen; j++) {
            if (key[j] == i) {
                for (int r = 0; r < rows; r++)
                    text[idx++] = matrix[r][j];
            }
        }
    }
    text[idx] = '\0';
}

void decrypt(char text[], int key[], int klen) {
    int len = strlen(text);
    int rows = (len + klen - 1) / klen;

    char matrix[rows][klen];
    int i, j, idx = 0;

    // Fill columns in key order
    for (i = 1; i <= klen; i++) {
        for (j = 0; j < klen; j++) {
            if (key[j] == i) {
                for (int r = 0; r < rows; r++)
                    matrix[r][j] = text[idx++];
            }
        }
    }

    // Read matrix row-wise
    idx = 0;
    for (i = 0; i < rows; i++)
        for (j = 0; j < klen; j++)
            text[idx++] = matrix[i][j];

    text[idx] = '\0';
}

int main() {
    char text[200], keyStr[50];
    int key[50], klen, choice;

    printf("Row Transposition Cipher Program\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter numeric key (e.g. 4312567): ");
    scanf("%s", keyStr);

    klen = strlen(keyStr);
    for (int i = 0; i < klen; i++)
        key[i] = keyStr[i] - '0';

    if (choice == 1) {
        encrypt(text, key, klen);
        printf("Encrypted Text: %s\n", text);
    }
    else if (choice == 2) {
        decrypt(text, key, klen);
        printf("Decrypted Text: %s\n", text);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
