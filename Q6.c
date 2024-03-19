#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the multiplicative inverse using Extended Euclidean Algorithm
int findMultiplicativeInverse(int a) {
    for (int x = 1; x < ALPHABET_SIZE; x++) {
        if ((a * x) % ALPHABET_SIZE == 1)
            return x;
    }
    return -1;
}

// Function to decrypt the ciphertext using the given keys
void decryptAffineCipher(char *ciphertext, int a, int b) {
    int a_inverse = findMultiplicativeInverse(a);
    if (a_inverse == -1) {
        printf("Multiplicative inverse does not exist.\n");
        return;
    }

    int text_length = strlen(ciphertext);
    for (int i = 0; i < text_length; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int decrypted_char = (a_inverse * (ciphertext[i] - 'A' - b + ALPHABET_SIZE)) % ALPHABET_SIZE;
            printf("%c", (char)(decrypted_char + 'A'));
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "PUT_YOUR_CIPHERTEXT_HERE";
    
    // Assuming B is mapped to 'E' and U is mapped to 'T'
    // E is the 4th letter of the alphabet, T is the 20th letter of the alphabet
    int frequency_b = ciphertext['B' - 'A'];
    int frequency_u = ciphertext['U' - 'A'];

    // Frequency analysis reveals that 'B' corresponds to 'E' and 'U' corresponds to 'T'
    // Using this information, we can deduce the keys
    int a = 5; // Multiplicative key
    int b = ('B' - 'A' - 4 * a + ALPHABET_SIZE) % ALPHABET_SIZE; // Additive key
    
    decryptAffineCipher(ciphertext, a, b);

    return 0;
}
