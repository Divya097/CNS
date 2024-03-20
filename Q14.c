#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // Include <string.h> for strlen()

// Function to encrypt plaintext using the one-time pad Vigenère cipher
void encrypt(char plaintext[], int key[], int keyLength) {
    int i;
    int plaintextLength = strlen(plaintext);
    char ciphertext[plaintextLength + 1]; // Adding 1 for null terminator
    
    for (i = 0; i < plaintextLength; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            int shift = key[i % keyLength];
            ciphertext[i] = ((plaintext[i] - base + shift) % 26) + base;
        } else {
            // Non-alphabetic characters remain unchanged
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[plaintextLength] = '\0'; // Null terminator
    printf("Ciphertext: %s\n", ciphertext);
}

int main() {
    char plaintext[1000];
    int key[1000];
    int keyLength = 0;
    int num;
    char buffer[10]; // Buffer for reading input

    // Read plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    // Remove newline character if present
    if (plaintext[strlen(plaintext) - 1] == '\n') {
        plaintext[strlen(plaintext) - 1] = '\0';
    }

    // Read key
    printf("Enter key numbers (0-26, separated by space): ");
    fgets(buffer, sizeof(buffer), stdin);
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        num = atoi(token);
        if (num >= 0 && num <= 26) {
            key[keyLength++] = num;
        } else {
            printf("Invalid key number. Please enter a number between 0 and 26.\n");
        }
        token = strtok(NULL, " ");
    }

    // Print the key for debugging
    printf("Key numbers: ");
    for (int i = 0; i < keyLength; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");

    // Encrypt plaintext using the key
    encrypt(plaintext, key, keyLength);

    return 0;
}
