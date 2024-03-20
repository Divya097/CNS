#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to generate the cipher sequence based on the keyword
void generateCipherSequence(char *keyword, char *cipherSequence) {
    int i, j;
    int keywordLength = strlen(keyword);
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";

    // Copy the keyword to the beginning of the cipher sequence
    strcpy(cipherSequence, keyword);

    // Remove duplicate letters from the keyword
    for (i = 0; i < keywordLength; i++) {
        for (j = i + 1; keyword[j] != '\0';) {
            if (cipherSequence[i] == cipherSequence[j]) {
                for (int k = j; cipherSequence[k] != '\0'; k++) {
                    cipherSequence[k] = cipherSequence[k + 1];
                }
            } else {
                j++;
            }
        }
    }

    // Append remaining letters of the alphabet to the cipher sequence
    int index = strlen(cipherSequence);
    for (i = 0; i < 26; i++) {
        if (!strchr(keyword, alphabet[i])) {
            cipherSequence[index++] = alphabet[i];
        }
    }
    cipherSequence[index] = '\0';
}

// Function to encrypt the plaintext using the generated cipher sequence
void encrypt(char *plaintext, char *cipherSequence) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (islower(plaintext[i])) {
                printf("%c", tolower(cipherSequence[plaintext[i] - 'a']));
            } else {
                printf("%c", toupper(cipherSequence[tolower(plaintext[i]) - 'a']));
            }
        } else {
            printf("%c", plaintext[i]);
        }
    }
}

int main() {
    char keyword[] = "CIPHER";
    char cipherSequence[26];
    char plaintext[] = "Hello, World!";

    // Generate the cipher sequence
    generateCipherSequence(keyword, cipherSequence);

    // Encrypt the plaintext using the generated cipher sequence
    printf("Plaintext: %s\n", plaintext);
    printf("Cipher: ");
    encrypt(plaintext, cipherSequence);
    printf("\n");

    return 0;
}
