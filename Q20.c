#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

// ECB Encryption
void encrypt_ecb(const unsigned char *plaintext, const unsigned char *key, unsigned char *ciphertext) {
    // Dummy encryption (replace with actual encryption algorithm)
    memcpy(ciphertext, plaintext, BLOCK_SIZE);
}

// CBC Encryption
void encrypt_cbc(const unsigned char *plaintext, const unsigned char *key, const unsigned char *iv, unsigned char *ciphertext) {
    unsigned char xor_block[BLOCK_SIZE];
    memcpy(xor_block, iv, BLOCK_SIZE);

    for (int i = 0; i < BLOCK_SIZE; i++) {
        xor_block[i] ^= plaintext[i];
    }

    // Dummy encryption (replace with actual encryption algorithm)
    memcpy(ciphertext, xor_block, BLOCK_SIZE);
}

// Main function
int main() {
    unsigned char plaintext[][BLOCK_SIZE] = {
        "This is P1!!!!!",
        "This is P2!!!!!",
        "This is P3!!!!!"
    };

    unsigned char key[BLOCK_SIZE] = "0123456789abcdef";
    unsigned char iv[BLOCK_SIZE] = "abcdefghijklmnop";
    unsigned char ciphertext[BLOCK_SIZE];

    // ECB mode
    printf("ECB Mode:\n");
    for (int i = 0; i < sizeof(plaintext) / BLOCK_SIZE; i++) {
        encrypt_ecb(plaintext[i], key, ciphertext);
        printf("P%d: %s\nC%d: ", i + 1, plaintext[i], i + 1);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            printf("%02X", ciphertext[j]);
        }
        printf("\n");
    }
    printf("\n");

    // CBC mode
    printf("CBC Mode:\n");
    for (int i = 0; i < sizeof(plaintext) / BLOCK_SIZE; i++) {
        encrypt_cbc(plaintext[i], key, iv, ciphertext);
        printf("P%d: %s\nC%d: ", i + 1, plaintext[i], i + 1);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            printf("%02X", ciphertext[j]);
        }
        printf("\n");
    }

    return 0;
}
