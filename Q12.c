#include <stdio.h>

// Function to encrypt using Hill Cipher
void encrypt(int plaintext[], int key[][2], int n) {
    int i, j, k, sum;
    int ciphertext[n];
    // Perform matrix multiplication
    for (i = 0; i < n; i += 2) {
        for (j = 0; j < 2; j++) {
            sum = 0;
            for (k = 0; k < 2; k++) {
                sum += key[j][k] * plaintext[i + k];
            }
            ciphertext[i + j] = sum % 26;
        }
    }
    // Print ciphertext
    printf("Encrypted ciphertext: ");
    for (i = 0; i < n; i++) {
        printf("%c", ciphertext[i] + 'a');
    }
    printf("\n");
}

// Function to find the inverse of a 2x2 matrix
void inverse(int key[][2], int invKey[][2]) {
    int det, detInv;
    det = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    // Calculate determinant inverse modulo 26
    for (detInv = 1; detInv < 26; detInv++) {
        if ((det * detInv) % 26 == 1)
            break;
    }
    // Calculate the elements of the inverse matrix modulo 26
    invKey[0][0] = (detInv * key[1][1]) % 26;
    invKey[0][1] = (-detInv * key[0][1]) % 26;
    invKey[1][0] = (-detInv * key[1][0]) % 26;
    invKey[1][1] = (detInv * key[0][0]) % 26;
    // Adjust negative values
    if (invKey[0][1] < 0) invKey[0][1] += 26;
    if (invKey[1][0] < 0) invKey[1][0] += 26;
}

// Function to decrypt using Hill Cipher
void decrypt(int ciphertext[], int invKey[][2], int n) {
    int i, j, k, sum;
    int decryptedtext[n];
    // Perform matrix multiplication
    for (i = 0; i < n; i += 2) {
        for (j = 0; j < 2; j++) {
            sum = 0;
            for (k = 0; k < 2; k++) {
                sum += invKey[j][k] * ciphertext[i + k];
            }
            decryptedtext[i + j] = sum % 26;
        }
    }
    // Print decrypted plaintext
    printf("Decrypted plaintext: ");
    for (i = 0; i < n; i++) {
        printf("%c", decryptedtext[i] + 'a');
    }
    printf("\n");
}

int main() {
    // Key matrix
    int key[2][2] = {{9, 4}, {5, 7}};
    // Inverse key matrix
    int invKey[2][2];

    // Plaintext (lowercase, non-alphabetic characters removed)
    int plaintext[] = {
        12, 4, 4, 19, 12, 4, 0, 19, 19, 0, 11, 19, 0, 2, 0, 18, 11, 19, 4, 8, 18, 0, 13, 13,
        19, 20, 0, 19, 4, 13, 22, 4, 6, 7, 7, 19, 7, 13, 4, 19, 4, 6, 7, 19, 14, 7, 20, 7, 0,
        13, 2, 17, 11, 4, 17, 6
    };
    int n = sizeof(plaintext) / sizeof(plaintext[0]);

    // Encryption
    encrypt(plaintext, key, n);

    // Inverse matrix calculation
    inverse(key, invKey);

    // Ciphertext (encrypted plaintext)
    int ciphertext[] = {
        24, 24, 12, 6, 16, 16, 1, 5, 10, 18, 7, 7, 22, 0, 16, 12, 6, 19, 6, 18, 22, 12, 18, 12,
        18, 3, 2, 24, 3, 19, 0, 15, 3, 10, 4, 24, 20, 3, 10, 4, 20, 10, 8, 17, 18, 0, 5, 3, 18,
        20, 15, 10, 15, 10, 18, 18, 11
    };

    // Decryption
    decrypt(ciphertext, invKey, n);

    return 0;
}
