#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // Include <string.h> for strlen()

#define ALPHABET_SIZE 26

// Function to encrypt plaintext using the one-time pad Vigenère cipher
void encrypt(char plaintext[], int key[], int keyLength) {
    int i;
    int plaintextLength = strlen(plaintext);
    char ciphertext[plaintextLength + 1]; // Adding 1 for null terminator
    
    for (i = 0; i < plaintextLength; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            int shift = key[i % keyLength];
            ciphertext[i] = ((plaintext[i] - base + shift) % ALPHABET_SIZE) + base;
        } else {
            // Non-alphabetic characters remain unchanged
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[plaintextLength] = '\0'; // Null terminator
    printf("Ciphertext: %s\n", ciphertext);
}

// Function to decrypt ciphertext using the one-time pad Vigenère cipher
void decrypt(char ciphertext[], int key[], int keyLength) {
    int i;
    int ciphertextLength = strlen(ciphertext);
    char plaintext[ciphertextLength + 1]; // Adding 1 for null terminator
    
    for (i = 0; i < ciphertextLength; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            int shift = key[i % keyLength];
            plaintext[i] = ((ciphertext[i] - base - shift + ALPHABET_SIZE) % ALPHABET_SIZE) + base;
        } else {
            // Non-alphabetic characters remain unchanged
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[ciphertextLength] = '\0'; // Null terminator
    printf("Plaintext: %s\n", plaintext);
}

int main() {
    char plaintext[] = "sendmoremoney";
    int key_a[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    int keyLength_a = sizeof(key_a) / sizeof(key_a[0]);

    // Encrypt plaintext using the given key stream
    printf("Encrypting plaintext...\n");
    encrypt(plaintext, key_a, keyLength_a);

    // Given ciphertext
    char ciphertext[] = "UTQTGSQVZVUYC";
    int key_b[keyLength_a]; // To be determined

    // Decrypt the given ciphertext to find the key
    printf("\nDecrypting ciphertext...\n");
    decrypt(ciphertext, key_b, keyLength_a);

    return 0;
}
