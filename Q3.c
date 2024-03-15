#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MATRIX_SIZE 5

// Function to generate Playfair matrix from a keyword
void generateMatrix(char *key, char matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j;
    char *ptr = key;
    char alphabet[26] = {0}; // Array to keep track of used letters
    int index = 0;

    // Fill matrix with the keyword
    for (i = 0; i < strlen(key); i++) {
        if (isalpha(*ptr)) {
            *ptr = toupper(*ptr);
            if (*ptr == 'J')
                *ptr = 'I'; // Replace 'J' with 'I'
            if (alphabet[*ptr - 'A'] == 0) {
                matrix[index / MATRIX_SIZE][index % MATRIX_SIZE] = *ptr;
                alphabet[*ptr - 'A'] = 1;
                index++;
            }
        }
        ptr++;
    }

    // Fill the remaining matrix with the rest of the alphabet
    for (i = 0; i < 26; i++) {
        if (i != ('J' - 'A')) {
            if (alphabet[i] == 0) {
                matrix[index / MATRIX_SIZE][index % MATRIX_SIZE] = 'A' + i;
                alphabet[i] = 1;
                index++;
            }
        }
    }
}

// Function to find the row and column of a letter in the matrix
void findPosition(char matrix[MATRIX_SIZE][MATRIX_SIZE], char letter, int *row, int *col) {
    int i, j;

    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt plaintext using Playfair cipher
void playfairEncrypt(char *plaintext, char matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, row1, col1, row2, col2;
    char ch1, ch2;
    char *ptr = plaintext;

    while (*ptr) {
        // Remove non-alpha characters and convert 'J' to 'I'
        if (!isalpha(*ptr) || *ptr == ' ')
            ptr++;
        else {
            ch1 = *ptr++;
            ch1 = toupper(ch1);
            if (ch1 == 'J')
                ch1 = 'I';

            // Skip non-alpha characters and convert 'J' to 'I'
            while (!isalpha(*ptr) && *ptr != '\0') {
                if (*ptr == ' ')
                    ptr++;
                else
                    ptr++;
            }

            // If end of string, pad with 'X'
            if (*ptr == '\0')
                ch2 = 'X';
            else {
                ch2 = *ptr++;
                ch2 = toupper(ch2);
                if (ch2 == 'J')
                    ch2 = 'I';
            }

            // If both letters are the same, pad with 'X'
            if (ch1 == ch2)
                ch2 = 'X';

            // Find positions of the letters in the matrix
            findPosition(matrix, ch1, &row1, &col1);
            findPosition(matrix, ch2, &row2, &col2);

            // Encrypt the pair of letters
            if (row1 == row2) {
                printf("%c%c", matrix[row1][(col1 + 1) % MATRIX_SIZE], matrix[row2][(col2 + 1) % MATRIX_SIZE]);
            } else if (col1 == col2) {
                printf("%c%c", matrix[(row1 + 1) % MATRIX_SIZE][col1], matrix[(row2 + 1) % MATRIX_SIZE][col2]);
            } else {
                printf("%c%c", matrix[row1][col2], matrix[row2][col1]);
            }
        }
    }
    printf("\n");
}

int main() {
    char key[100];
    char plaintext[100];
    char matrix[MATRIX_SIZE][MATRIX_SIZE];
    
    printf("Enter the keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character
    
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    generateMatrix(key, matrix);

    printf("Encrypted text: ");
    playfairEncrypt(plaintext, matrix);

    return 0;
}
