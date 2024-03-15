#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Function to encrypt text using the Caesar cipher
void caesarCipherEncrypt(char *text, int shift) {
    int i;
    char ch;

    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z')
            text[i] = ((ch - 'A' + shift) % ALPHABET_SIZE) + 'A';

        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z')
            text[i] = ((ch - 'a' + shift) % ALPHABET_SIZE) + 'a';
    }
}

int main() {
    char text[100];
    int shift, i;

    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the shift value (1 to 25): ");
    scanf("%d", &shift);

    // Adjust shift value to be within the range 1 to 25
    shift = shift % ALPHABET_SIZE;

    caesarCipherEncrypt(text, shift);

    printf("Encrypted text: %s\n", text);

    return 0;
}
