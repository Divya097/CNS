#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to initialize the Playfair matrix
void initializeMatrix(char matrix[SIZE][SIZE], char key[]) {
    int i, j, k = 0;
    int len = strlen(key);
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // Skipping 'J'

    // Fill the key in the matrix
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (k < len) {
                matrix[i][j] = toupper(key[k]);
                k++;
            } else {
                // Fill remaining alphabet characters
                while (strchr(key, alphabet[k]) != NULL)
                    k++;
                matrix[i][j] = alphabet[k];
                k++;
            }
        }
    }
}

// Function to display the Playfair matrix
void displayMatrix(char matrix[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the position of a character in the matrix
void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a message using Playfair cipher
void encryptMessage(char matrix[SIZE][SIZE], char message[]) {
    int len = strlen(message);
    int i, row1, col1, row2, col2;
    char encryptedMessage[2 * len];
    int k = 0;

    for (i = 0; i < len; i += 2) {
        findPosition(matrix, toupper(message[i]), &row1, &col1);
        findPosition(matrix, toupper(message[i + 1]), &row2, &col2);

        if (row1 == row2) {
            // Same row
            encryptedMessage[k++] = matrix[row1][(col1 + 1) % SIZE];
            encryptedMessage[k++] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            // Same column
            encryptedMessage[k++] = matrix[(row1 + 1) % SIZE][col1];
            encryptedMessage[k++] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            // Form a rectangle
            encryptedMessage[k++] = matrix[row1][col2];
            encryptedMessage[k++] = matrix[row2][col1];
        }
    }
    encryptedMessage[k] = '\0';
    printf("Encrypted Message: %s\n", encryptedMessage);
}

int main() {
    char matrix[SIZE][SIZE];
    char key[] = "MFHIJKUNOPQZVWXYELABRGCSDT";

    char message[] = "Must see you over Cadogan West. Coming at once.";

    printf("Playfair Matrix:\n");
    initializeMatrix(matrix, key);
    displayMatrix(matrix);

    printf("\nOriginal Message: %s\n", message);
    encryptMessage(matrix, message);

    return 0;
}
