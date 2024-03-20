#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to generate a random prime number
int generatePrime(int min, int max) {
    int num;
    do {
        num = rand() % (max - min + 1) + min;
    } while (!isPrime(num));
    return num;
}

// Function to calculate Euler's totient function
int phiFunction(int p, int q) {
    return (p - 1) * (q - 1);
}

// Function to calculate the modular inverse
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to generate RSA keys
void generateRSAKeys(int *e, int *d, int *n) {
    int p, q, phi;

    // Randomly generate two distinct prime numbers
    srand(time(NULL));
    do {
        p = generatePrime(100, 1000);
        q = generatePrime(100, 1000);
    } while (p == q);

    // Calculate n and Euler's totient function
    *n = p * q;
    phi = phiFunction(p, q);

    // Choose a public exponent e (common choices: 3, 65537)
    *e = 65537;

    // Calculate the modular inverse of e modulo phi
    *d = modInverse(*e, phi);
}

int main() {
    int e, d, n;

    // Generate RSA keys
    generateRSAKeys(&e, &d, &n);

    // Display the generated keys
    printf("Public Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d): %d\n", d);

    return 0;
}
