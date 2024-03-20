#include <stdio.h>
#include <math.h>

double factorial(int n) {
    if (n == 0) return 1;
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = 25; // Number of available slots
    double permutations = factorial(n);
    double approximate_power_of_2 = log2(permutations);
    
    printf("Number of possible keys for Playfair cipher: %.0lf\n", permutations);
    printf("Approximate power of 2: %.0lf\n", approximate_power_of_2);
    
    return 0;
}
