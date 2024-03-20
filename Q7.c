#include <stdio.h>
#include <string.h>

// Function to decrypt the ciphertext
void decrypt(char *ciphertext) {
    // Define the substitution key based on the hints given
    char key[128] = {0};
    key['5'] = 'e'; // The character '5' is likely to stand for 'e'
    key['8'] = 't'; // Based on the frequency of 't' in the word "the"
    key['4'] = 'h'; // Based on the frequency of 'h' in the word "the"
    // You can add more substitutions based on additional deductions
    
    // Decrypt the ciphertext using the substitution key
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (key[ciphertext[i]] != 0) {
            printf("%c", key[ciphertext[i]]);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
}

int main() {
    // Provide the ciphertext
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 \
(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* \
;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";

    // Decrypt and print the plaintext
    decrypt(ciphertext);

    return 0;
}
