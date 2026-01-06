// write a program to illustrate the vigenere chipher for polyalphabetic Chipher
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[200], key[100];
    int choice;
    int i, j = 0;

    printf("Vigenere Cipher Program\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();   // clear newline

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters
    text[strcspn(text, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    int keyLen = strlen(key);

    for (i = 0; text[i] != '\0'; i++) {

        if (isalpha(text[i])) {
            int base = isupper(text[i]) ? 'A' : 'a';

            int t = text[i] - base;
            int k = tolower(key[j % keyLen]) - 'a';

            if (choice == 1) {
                // Encryption
                text[i] = (t + k) % 26 + base;
            }
            else if (choice == 2) {
                // Decryption
                text[i] = (t - k + 26) % 26 + base;
            }
            else {
                printf("Invalid choice!\n");
                return 0;
            }

            j++;  // advance key ONLY for letters
        }
        // else: spaces & symbols stay unchanged
    }

    if (choice == 1)
        printf("Encrypted Text: %s\n", text);
    else
        printf("Decrypted Text: %s\n", text);

    return 0;
}
