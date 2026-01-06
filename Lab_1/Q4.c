// write a program to illustrate the Play Fair for polyalphabetic Chipher
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

/* Generate 5x5 key matrix */
void generateMatrix(char key[]) {
    int used[26] = {0};
    int k = 0;

    used['J' - 'A'] = 1;   // I/J treated same

    for (int i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (!isalpha(ch)) continue;
        if (ch == 'J') ch = 'I';

        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!used[i]) {
            matrix[k / 5][k % 5] = i + 'A';
            k++;
        }
    }
}

/* Find character position */
void findPos(char ch, int *r, int *c) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                *r = i;
                *c = j;
                return;
            }
}

/* Encrypt one digraph */
void encryptPair(char a, char b, char *x, char *y) {
    int r1, c1, r2, c2;
    findPos(a, &r1, &c1);
    findPos(b, &r2, &c2);

    if (r1 == r2) {              // same row
        *x = matrix[r1][(c1 + 1) % 5];
        *y = matrix[r2][(c2 + 1) % 5];
    }
    else if (c1 == c2) {         // same column
        *x = matrix[(r1 + 1) % 5][c1];
        *y = matrix[(r2 + 1) % 5][c2];
    }
    else {                       // rectangle
        *x = matrix[r1][c2];
        *y = matrix[r2][c1];
    }
}

/* Decrypt one digraph */
void decryptPair(char a, char b, char *x, char *y) {
    int r1, c1, r2, c2;
    findPos(a, &r1, &c1);
    findPos(b, &r2, &c2);

    if (r1 == r2) {              // same row
        *x = matrix[r1][(c1 + 4) % 5];
        *y = matrix[r2][(c2 + 4) % 5];
    }
    else if (c1 == c2) {         // same column
        *x = matrix[(r1 + 4) % 5][c1];
        *y = matrix[(r2 + 4) % 5][c2];
    }
    else {                       // rectangle
        *x = matrix[r1][c2];
        *y = matrix[r2][c1];
    }
}

int main() {
    char text[200], key[100];
    int choice;

    printf("Playfair Cipher Program\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    generateMatrix(key);

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Result: ");

    for (int i = 0; i < strlen(text); i++) {
        if (!isalpha(text[i])) {
            printf("%c", text[i]);   // keep spaces/symbols
            continue;
        }

        char a = toupper(text[i]);
        char b = 'X';

        int j = i + 1;
        while (text[j] && !isalpha(text[j])) j++;

        if (text[j]) {
            b = toupper(text[j]);
        }

        if (a == b) {
            b = 'X';
        } else {
            i = j;
        }

        char x, y;
        if (choice == 1)
            encryptPair(a, b, &x, &y);
        else
            decryptPair(a, b, &x, &y);

        printf("%c%c", x, y);
    }

    printf("\n");
    return 0;
}
