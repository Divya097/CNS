#include <stdio.h>

// Greatest Common Divisor (GCD) function
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    // Given values
    int n = 3233; // n = pq
    int e = 17;   // Public key
    int plaintext_block = 1111; // Sample plaintext block

    // Suppose someone knows a plaintext block with a common factor with n
    // Check if plaintext_block has a common factor with n
    int common_factor = gcd(plaintext_block, n);

    // If the common factor is not 1, then it might reveal a factor of n
    if (common_factor != 1) {
        printf("Plaintext block has a common factor with n: %d\n", common_factor);
    } else {
        printf("Plaintext block does not have a common factor with n.\n");
    }

    return 0;
}
