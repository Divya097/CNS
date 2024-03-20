#include <stdio.h>

// Extended Euclidean Algorithm
int extendedEuclidean(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

// Modulo Inverse Function
int moduloInverse(int a, int m) {
    int x, y;
    int gcd = extendedEuclidean(a, m, &x, &y);
    if (gcd != 1) {
        printf("Inverse does not exist\n");
        return -1;
    }
    return (x % m + m) % m;
}

int main() {
    int e = 31; // Public key
    int n = 3599; // Public key

    // Trial and error to find p and q
    int p, q;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            break;
        }
    }

    // Calculate phi(n)
    int phi_n = (p - 1) * (q - 1);

    // Calculate private key (d)
    int d = moduloInverse(e, phi_n);

    printf("Private Key (d): %d\n", d);

    return 0;
}
