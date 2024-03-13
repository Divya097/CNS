#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void caesarCipher(char *plaintext, int key) {
    int i;
    char ch;
    
    for(i = 0; plaintext[i] != '\0'; ++i) {
        ch = plaintext[i];
        
        if(isalpha(ch)) {
            if(isupper(ch)) {
                ch = ((ch - 'A' + key) % ALPHABET_SIZE) + 'A';
            }
            else {
                ch = ((ch - 'a' + key) % ALPHABET_SIZE) + 'a';
            }
        }
        plaintext[i] = ch;
    }
}

int main() {
    char plaintext[100], encrypted[100];
    int key;  
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    strcpy(encrypted, plaintext);   
    printf("Enter the key (a number between 0 and 25): ");
    scanf("%d", &key);  
    caesarCipher(plaintext, key);   
    printf("Original plaintext: %s", encrypted);
    printf("Cipher text: %s\n", plaintext);
    caesarCipher(plaintext, ALPHABET_SIZE - key);  
    printf("Decrypted text: %s\n", plaintext);  
    return 0;
}
