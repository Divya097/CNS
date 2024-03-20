#include <stdio.h>
#include <ctype.h>

// Function to encrypt plaintext using the affine Caesar cipher
void affine_caesar_encrypt(const char *plaintext, int a, int b) {
    printf("Encrypted Text: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char encrypted_char;
        if (isalpha(plaintext[i])) {
            int p = tolower(plaintext[i]) - 'a';
            encrypted_char = (a * p + b) % 26 + 'a';
        } else {
            encrypted_char = plaintext[i]; // Non-alphabetic characters remain unchanged
        }
        printf("%c", encrypted_char);
    }
    printf("\n");
}

int main() {
    char plaintext[] = "Hello, world!"; // Input plaintext
    int a = 5; // Affine parameter 'a'
    int b = 8; // Affine parameter 'b'

    printf("Plaintext: %s\n", plaintext);
    printf("Affine Parameters: a = %d, b = %d\n", a, b);

    affine_caesar_encrypt(plaintext, a, b);

    return 0;
}
