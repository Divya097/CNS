#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>

#define BLOCK_SIZE 8

void encrypt_cbc_3des(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, const unsigned char *iv) {
    DES_cblock key1, key2, key3;
    DES_key_schedule ks1, ks2, ks3;

    // Split the 3DES key into three subkeys
    memcpy(key1, key, 8);
    memcpy(key2, key + 8, 8);
    memcpy(key3, key + 16, 8);

    // Set the key schedules
    DES_set_key(&key1, &ks1);
    DES_set_key(&key2, &ks2);
    DES_set_key(&key3, &ks3);

    // Initialize the IV
    DES_cblock ivec;
    memcpy(ivec, iv, 8);

    // Encrypt the plaintext in CBC mode
    int len = 0;
    unsigned char *encrypted_data = malloc(plaintext_len);
    DES_ede3_cbc_encrypt(plaintext, encrypted_data, plaintext_len, &ks1, &ks2, &ks3, &ivec, DES_ENCRYPT);

    // Print the encrypted data
    printf("Encrypted CBC 3DES data: ");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02X ", encrypted_data[i]);
    }
    printf("\n");

    free(encrypted_data);
}

int main() {
    // Example plaintext, key, and IV
    unsigned char plaintext[] = "Hello, world!";
    unsigned char key[] = "0123456789abcdef0123456789abcdef0123456789abcdef";
    unsigned char iv[] = "abcdefgh";

    printf("Plaintext: %s\n", plaintext);

    encrypt_cbc_3des(plaintext, strlen((char *)plaintext), key, iv);

    return 0;
}

