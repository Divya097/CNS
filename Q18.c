#include <stdio.h>
#include <stdint.h>

// Define the initial key (64 bits)
uint64_t initial_key = 0x0F1571C947D9E859; // Example key

// Permuted choice 1 (PC1) table for key generation
const int pc1_table[] = {
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4
};

// Permuted choice 2 (PC2) table for key generation
const int pc2_table[] = {
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

// Key schedule for DES
void generate_subkeys(uint64_t key) {
    uint64_t pc1_key = 0, left_half = 0, right_half = 0;
    int i;

    // Apply Permuted Choice 1 (PC1) to the initial key
    for (i = 0; i < 56; i++) {
        int bit_pos = 64 - pc1_table[i];
        pc1_key |= ((key >> (bit_pos - 1)) & 1) << (55 - i);
    }

    // Split the PC1 key into left and right halves
    left_half = pc1_key >> 28;
    right_half = pc1_key & 0x0FFFFFFF;

    // Perform 16 rounds of key generation
    for (i = 0; i < 16; i++) {
        // Perform circular left shifts on the halves
        left_half = ((left_half << 1) | (left_half >> 27)) & 0x0FFFFFFF;
        right_half = ((right_half << 1) | (right_half >> 27)) & 0x0FFFFFFF;

        // Combine the halves and apply Permuted Choice 2 (PC2)
        uint64_t combined_half = (left_half << 28) | right_half;
        uint64_t subkey = 0;
        for (int j = 0; j < 48; j++) {
            int bit_pos = 56 - pc2_table[j];
            subkey |= ((combined_half >> (bit_pos - 1)) & 1) << (47 - j);
        }

        // Output the subkey
        printf("Subkey %d: %016llx\n", i+1, subkey);
    }
}

int main() {
    printf("Initial Key: %016llx\n", initial_key);
    printf("Subkeys:\n");
    generate_subkeys(initial_key);
    return 0;
}
