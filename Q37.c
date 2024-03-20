#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define TOP_PLAINTEXTS 10

// English letter frequency table (source: Wikipedia)
const double english_freq[ALPHABET_SIZE] = {
    0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015,  // a-g
    0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749,  // h-n
    0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758,  // o-u
    0.00978, 0.02360, 0.00150, 0.01974, 0.00074, 0.00074            // v-z
};

// Structure to represent a character frequency
typedef struct {
    char character;
    double frequency;
} CharFrequency;

// Function to calculate the frequency of each character in the ciphertext
void calculate_frequency(const char *ciphertext, CharFrequency *frequency) {
    int total_count = 0;
    int count[ALPHABET_SIZE] = {0};

    // Count occurrences of each letter in the ciphertext
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            count[tolower(ciphertext[i]) - 'a']++;
            total_count++;
        }
    }

    // Calculate frequency of each letter
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        frequency[i].character = 'a' + i;
        frequency[i].frequency = (double)count[i] / total_count;
    }
}

// Function to compare frequencies for sorting
int compare_frequency(const void *a, const void *b) {
    CharFrequency *freq_a = (CharFrequency *)a;
    CharFrequency *freq_b = (CharFrequency *)b;
    return (freq_b->frequency - freq_a->frequency) * 10000; // Multiply by 10000 to preserve precision
}

// Function to perform letter frequency attack
void frequency_attack(const char *ciphertext, int top_plaintexts) {
    CharFrequency ciphertext_freq[ALPHABET_SIZE];
    calculate_frequency(ciphertext, ciphertext_freq);

    // Sort the character frequencies in descending order
    qsort(ciphertext_freq, ALPHABET_SIZE, sizeof(CharFrequency), compare_frequency);

    printf("Top %d possible plaintexts:\n", top_plaintexts);
    for (int i = 0; i < top_plaintexts; i++) {
        printf("%2d. ", i + 1);

        // Calculate the mapping of ciphertext letters to plaintext letters
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            char plaintext_char = (ciphertext_freq[j].character - 'a' + i) % ALPHABET_SIZE + 'a';
            printf("%c", plaintext_char);
        }

        printf("\n");
    }
}

int main() {
    char ciphertext[] = "Gwc uivioml bw nqvl bpm zqopb apqnb";
    int top_plaintexts = TOP_PLAINTEXTS;

    printf("Ciphertext: %s\n", ciphertext);
    printf("Performing letter frequency attack...\n\n");

    frequency_attack(ciphertext, top_plaintexts);

    return 0;
}
