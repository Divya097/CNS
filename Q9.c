#include <stdio.h>
#include <string.h>

// Function to find the coordinates of a character in the key square
void findChar(char key[5][5], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // Replace 'J' with 'I'
    for (*row = 0; *row < 5; (*row)++) {
        for (*col = 0; *col < 5; (*col)++) {
            if (key[*row][*col] == ch) {
                return;
            }
        }
    }
}

// Function to decrypt the Playfair cipher
void decryptPlayfair(char key[5][5], char message[]) {
    int i, row1, row2, col1, col2;
    for (i = 0; i < strlen(message); i += 2) {
        char ch1 = message[i];
        char ch2 = message[i + 1];

        // Find the positions of both characters in the key square
        findChar(key, ch1, &row1, &col1);
        findChar(key, ch2, &row2, &col2);

        // If both characters are in the same row, replace them with the characters to their immediate right
        if (row1 == row2) {
            col1 = (col1 - 1 + 5) % 5;
            col2 = (col2 - 1 + 5) % 5;
        }
        // If both characters are in the same column, replace them with the characters below them
        else if (col1 == col2) {
            row1 = (row1 - 1 + 5) % 5;
            row2 = (row2 - 1 + 5) % 5;
        }
        // If neither, form a rectangle and replace them with the characters in the opposite corners of the rectangle
        else {
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }

        // Output the decrypted characters
        printf("%c%c", key[row1][col1], key[row2][col2]);
    }
}

int main() {
    char key[5][5] = {
        {'K', 'X', 'J', 'E', 'Y'},
        {'U', 'R', 'E', 'B', 'Z'},
        {'W', 'H', 'R', 'Y', 'T'},
        {'U', 'H', 'E', 'Y', 'F'},
        {'S', 'K', 'R', 'G', 'O'}
    };

    char message[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";

    printf("Decoded message:\n");
    decryptPlayfair(key, message);

    return 0;
}
