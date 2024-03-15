#include <stdio.h>
#include <ctype.h>
#include <string.h> // Add this line to include string.h header

// Function to encrypt a single character using the affine Caesar cipher
char encrypt(char p, int a, int b) {
    if (isalpha(p)) {
        char base = islower(p) ? 'a' : 'A';
        return ((a * (p - base) + b) % 26) + base;
    }
    return p;
}

// Function to encrypt a plaintext using the affine Caesar cipher
void affineCaesarEncrypt(char *plaintext, char *ciphertext, int a, int b) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = encrypt(plaintext[i], a, b);
    }
    ciphertext[strlen(plaintext)] = '\0'; // Fix the warning by including string.h
}

int main() {
    char plaintext[1000];
    char ciphertext[1000];
    int a, b;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter values of a and b (comma-separated): ");
    scanf("%d,%d", &a, &b);

    // Remove newline character from input
    plaintext[strcspn(plaintext, "\n")] = '\0';

    affineCaesarEncrypt(plaintext, ciphertext, a, b);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
