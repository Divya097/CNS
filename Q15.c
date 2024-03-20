#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to count the frequency of each letter in the given text
void countFrequency(char text[], int frequency[]) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            int index = tolower(text[i]) - 'a';
            frequency[index]++;
        }
    }
}

// Function to perform additive decryption with a given key
void decrypt(char ciphertext[], int key) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            ciphertext[i] = ((ciphertext[i] - base - key + ALPHABET_SIZE) % ALPHABET_SIZE) + base;
        }
    }
}

// Function to rank possible plaintexts based on letter frequency
void rankPlaintexts(int frequency[], char plaintexts[][ALPHABET_SIZE + 1], int numPlaintexts) {
    int i, j;
    for (i = 0; i < numPlaintexts; i++) {
        // Find the most frequent letter in the ciphertext
        int maxFreq = 0, maxIndex = 0;
        for (j = 0; j < ALPHABET_SIZE; j++) {
            if (frequency[j] > maxFreq) {
                maxFreq = frequency[j];
                maxIndex = j;
            }
        }
        // Decrypt the ciphertext assuming the most frequent letter corresponds to 'e'
        int key = (maxIndex + ALPHABET_SIZE - ('e' - 'a')) % ALPHABET_SIZE;
        decrypt(plaintexts[i], key);
        // Reset frequency for the next iteration
        frequency[maxIndex] = 0;
    }
}

int main() {
    char ciphertext[] = "Jgkpgu lv xchx acpj, oaw xchx tynpi, zwmew yj abxg.";
    int frequency[ALPHABET_SIZE] = {0};
    char plaintexts[10][ALPHABET_SIZE + 1]; // Array to store top 10 possible plaintexts

    // Calculate letter frequency in the ciphertext
    countFrequency(ciphertext, frequency);

    // Generate possible plaintexts
    int i;
    for (i = 0; i < 10; i++) {
        strcpy(plaintexts[i], ciphertext); // Copy ciphertext to plaintexts array
    }

    // Rank possible plaintexts based on letter frequency
    rankPlaintexts(frequency, plaintexts, 10);

    // Display top 10 possible plaintexts
    printf("Top 10 possible plaintexts:\n");
    for (i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, plaintexts[i]);
    }

    return 0;
}
