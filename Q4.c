#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to perform monoalphabetic substitution cipher
char monoalphabeticSubstitution(char c, char key) {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return ((c - base + key) % 26) + base;
    }
    return c;
}

// Function to perform polyalphabetic substitution cipher
void polyalphabeticSubstitution(char *plaintext, char *key, char *ciphertext) {
    int keyLength = strlen(key);
    int i;

    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = monoalphabeticSubstitution(plaintext[i], key[i % keyLength]);
    }

    ciphertext[i] = '\0';
}

int main() {
    char plaintext[1000];
    char key[100];
    char ciphertext[1000];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from input
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    polyalphabeticSubstitution(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
