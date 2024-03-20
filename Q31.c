#include <stdio.h>
#include <stdint.h>

// Function to generate subkeys for CMAC
void generate_subkeys(uint8_t *block_cipher_result, int block_size) {
    // Constants for block sizes of 64 and 128 bits
    uint8_t constant_64[8] = {0x1B, 0, 0, 0, 0, 0, 0, 0}; // For block size 64 bits
    uint8_t constant_128[16] = {0x87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // For block size 128 bits
    
    // Left shift the block cipher result by one bit
    uint8_t subkey[block_size / 8];
    uint8_t carry = 0;
    for (int i = block_size / 8 - 1; i >= 0; i--) {
        subkey[i] = (block_cipher_result[i] << 1) | carry;
        carry = (block_cipher_result[i] & 0x80) ? 1 : 0; // Check if MSB is 1
    }
    
    // XOR with the constant
    if (block_size == 64) {
        for (int i = 0; i < 8; i++) {
            subkey[i] ^= constant_64[i];
        }
    } else if (block_size == 128) {
        for (int i = 0; i < 16; i++) {
            subkey[i] ^= constant_128[i];
        }
    }
    
    // Print the generated subkey
    printf("Generated Subkey:\n");
    for (int i = 0; i < block_size / 8; i++) {
        printf("%02X ", subkey[i]);
    }
    printf("\n");
}

int main() {
    // Assuming block size of 64 bits
    uint8_t block_cipher_result_64[8] = {0}; // Initialize with all zeros
    generate_subkeys(block_cipher_result_64, 64);
    
    // Assuming block size of 128 bits
    uint8_t block_cipher_result_128[16] = {0}; // Initialize with all zeros
    generate_subkeys(block_cipher_result_128, 128);
    
    return 0;
}
