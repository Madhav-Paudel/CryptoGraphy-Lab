// write a program to illustrate the Ceasar Chipher Monoaphabetic Chipher
#include <stdio.h>

int main() {
    char text[100];
    int key = 3;   // Fixed shift value
    int choice;

    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();   // clear newline from buffer

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);

    if (choice == 1) {
        // Encryption
        for (int i = 0; text[i] != '\0'; i++) {
            char ch = text[i];

            if (ch >= 'A' && ch <= 'Z')
                ch = (ch - 'A' + key) % 26 + 'A';
            else if (ch >= 'a' && ch <= 'z')
                ch = (ch - 'a' + key) % 26 + 'a';

            text[i] = ch;
        }
        printf("Encrypted text: %s", text);
    }
    else if (choice == 2) {
        // Decryption
        for (int i = 0; text[i] != '\0'; i++) {
            char ch = text[i];

            if (ch >= 'A' && ch <= 'Z')
                ch = (ch - 'A' - key + 26) % 26 + 'A';
            else if (ch >= 'a' && ch <= 'z')
                ch = (ch - 'a' - key + 26) % 26 + 'a';

            text[i] = ch;
        }
        printf("Decrypted text: %s", text);
    }
    else {
        printf("Invalid choice!");
    }

    return 0;
}
