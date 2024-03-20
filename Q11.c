#include <stdio.h>

// Function to calculate the number of effectively unique keys
unsigned long long uniqueKeys() {
    // Number of ways to select the first letter of the key matrix
    unsigned long long ways_first_letter = 25;
    
    // Number of ways to select the second letter of the key matrix (without repetition)
    unsigned long long ways_second_letter = 24;
    
    // For the rest of the letters in the key matrix, the order doesn't matter,
    // so we divide by 2 (to account for symmetry) for each pair of letters
    unsigned long long ways_rest = 1;
    for (int i = 2; i <= 12; i++) {
        ways_rest *= i;
    }
    
    // Total number of effectively unique keys
    unsigned long long total_unique_keys = ways_first_letter * ways_second_letter * ways_rest;
    
    return total_unique_keys;
}

int main() {
    unsigned long long num_unique_keys = uniqueKeys();
    
    printf("Number of effectively unique keys for the Playfair cipher: %llu\n", num_unique_keys);
    
    return 0;
}
