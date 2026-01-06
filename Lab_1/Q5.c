// write a program to illustrate the Rail Fence Cipher for Transposition Cipher
#include <stdio.h>
#include <string.h>

void encryptRailFence(char text[], int key) {
    char rail[key][100];
    int i, j;

    // Fill with newline
    for (i = 0; i < key; i++)
        for (j = 0; j < strlen(text); j++)
            rail[i][j] = '\n';

    int row = 0;
    int dirDown = 0;

    for (i = 0; i < strlen(text); i++) {
        rail[row][i] = text[i];

        if (row == 0 || row == key - 1)
            dirDown = !dirDown;

        row += dirDown ? 1 : -1;
    }

    int index = 0;
    for (i = 0; i < key; i++)
        for (j = 0; j < strlen(text); j++)
            if (rail[i][j] != '\n')
                text[index++] = rail[i][j];
}

void decryptRailFence(char cipher[], int key) {
    char rail[key][100];
    int i, j;

    for (i = 0; i < key; i++)
        for (j = 0; j < strlen(cipher); j++)
            rail[i][j] = '\n';

    int row = 0, dirDown = 0;

    // Mark positions
    for (i = 0; i < strlen(cipher); i++) {
        rail[row][i] = '*';

        if (row == 0 || row == key - 1)
            dirDown = !dirDown;

        row += dirDown ? 1 : -1;
    }

    // Fill marked positions
    int index = 0;
    for (i = 0; i < key; i++)
        for (j = 0; j < strlen(cipher); j++)
            if (rail[i][j] == '*' && index < strlen(cipher))
                rail[i][j] = cipher[index++];

    // Read zig-zag
    row = 0; dirDown = 0;
    for (i = 0; i < strlen(cipher); i++) {
        cipher[i] = rail[row][i];

        if (row == 0 || row == key - 1)
            dirDown = !dirDown;

        row += dirDown ? 1 : -1;
    }
}

int main() {
    char text[100];
    int key, choice;

    printf("Rail Fence Cipher Program\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter number of rails: ");
    scanf("%d", &key);

    if (key <= 1) {
        printf("Invalid rail key!\n");
        return 0;
    }

    if (choice == 1) {
        encryptRailFence(text, key);
        printf("Encrypted Text: %s\n", text);
    }
    else if (choice == 2) {
        decryptRailFence(text, key);
        printf("Decrypted Text: %s\n", text);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
