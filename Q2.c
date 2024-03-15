#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to perform monoalphabetic substitution encryption
void monoalphabeticEncrypt(char *plaintext, char *key) {
    int i;

    for (i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            // Determine the position of the character in the alphabet
            int position = tolower(plaintext[i]) - 'a';

            // Encrypt the character using the key
            if (isupper(plaintext[i]))
                plaintext[i] = toupper(key[position]);
            else
                plaintext[i] = key[position];
        }
    }
}

int main() {
    char plaintext[100];
    char key[ALPHABET_SIZE + 1]; // We add 1 to accommodate the null terminator
    int i;

    printf("Enter plaintext to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the key (26 unique letters of the alphabet, case insensitive): ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from input
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Validate key
    if (strlen(key) != ALPHABET_SIZE) {
        printf("Error: Key must be exactly 26 characters long.\n");
        return 1;
    }

    // Convert key to lowercase
    for (i = 0; i < ALPHABET_SIZE; ++i) {
        key[i] = tolower(key[i]);
        if (!isalpha(key[i])) {
            printf("Error: Key must contain only alphabetic characters.\n");
            return 1;
        }
    }

    // Check for duplicate characters in the key
    for (i = 0; i < ALPHABET_SIZE; ++i) {
        for (int j = i + 1; j < ALPHABET_SIZE; ++j) {
            if (key[i] == key[j]) {
                printf("Error: Key must contain unique characters.\n");
                return 1;
            }
        }
    }

    monoalphabeticEncrypt(plaintext, key);

    printf("Encrypted text: %s\n", plaintext);

    return 0;
}
