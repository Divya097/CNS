#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a message using Vigenère Cipher
void vigenereEncrypt(char message[], char key[]) {
    int msgLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;

        // Convert characters to uppercase for consistency
        message[i] = toupper(message[i]);
        key[j] = toupper(key[j]);

        // Encrypt only alphabetic characters
        if (isalpha(message[i])) {
            // Perform Vigenère encryption
            message[i] = ((message[i] - 'A') + (key[j] - 'A')) % 26 + 'A';
        }
    }
}

int main() {
    char message[100], key[100];

    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from input
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the message using Vigenère Cipher
    vigenereEncrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
