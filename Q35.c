#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_SIZE 1000

// Function to encrypt plaintext using the one-time pad Vigenère cipher
void vigenere_one_time_pad_encrypt(const char *plaintext, const int *key, int key_length) {
    int i, j;
    char encrypted_char;

    printf("Encrypted Text: ");

    for (i = 0, j = 0; plaintext[i] != '\0'; i++, j = (j + 1) % key_length) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                encrypted_char = 'A' + ((plaintext[i] - 'A' + key[j]) % 26);
            } else {
                encrypted_char = 'a' + ((plaintext[i] - 'a' + key[j]) % 26);
            }
        } else {
            encrypted_char = plaintext[i]; // Non-alphabetic characters remain unchanged
        }
        printf("%c", encrypted_char);
    }

    printf("\n");
}

int main() {
    char plaintext[] = "Hello, world!"; // Input plaintext
    int key[] = {3, 19, 5}; // Key stream (example key)
    int key_length = sizeof(key) / sizeof(key[0]); // Length of key stream

    printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for (int i = 0; i < key_length; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");

    vigenere_one_time_pad_encrypt(plaintext, key, key_length);

    return 0;
}
