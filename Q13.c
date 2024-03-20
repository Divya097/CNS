#include <stdio.h>

#define MOD 26

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
            decryptedtext[i + j] = sum % MOD;
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
    // Key matrix (known to the attacker)
    int key[2][2] = {{9, 4}, {5, 7}};
    // Inverse key matrix
    int invKey[2][2];

    // Plaintext (known to the attacker)
    int plaintext[] = {12, 4, 4, 19, 12, 4, 0, 19}; // Partial plaintext (8 characters)
    int n = sizeof(plaintext) / sizeof(plaintext[0]);

    // Ciphertext (known to the attacker)
    int ciphertext[] = {24, 24, 12, 6, 16, 16, 1, 5}; // Corresponding partial ciphertext (8 characters)

    // Inverse matrix calculation
    inverse(key, invKey);

    // Decryption
    decrypt(ciphertext, invKey, n);

    return 0;
}
