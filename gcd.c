#include <stdio.h>

// Euclid’s Method
int gcdEuclid(int m, int n) {
    while (n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

// Consecutive Integer Checking Method
int gcdConsecutive(int m, int n) {
    int min = (m < n) ? m : n;
    while (min > 0) {
        if (m % min == 0 && n % min == 0)
            return min;
        min--;
    }
    return 1;
}

// Middle School Method (Prime Factorization)
int gcdMiddleSchool(int m, int n) {
    int gcd = 1, i;
    for (i = 2; i <= m && i <= n; i++) {
        while (m % i == 0 && n % i == 0) {
            gcd *= i;
            m /= i;
            n /= i;
        }
    }
    return gcd;
}

int main() {
    int m, n, choice, result;

    printf("Enter two positive integers: ");
    scanf("%d %d", &m, &n);

    printf("\nChoose GCD Method:\n");
    printf("1. Euclid's Method\n");
    printf("2. Consecutive Integer Checking Method\n");
    printf("3. Middle School Method\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = gcdEuclid(m, n);
            printf("GCD (Euclid's Method): %d\n", result);
            break;
        case 2:
            result = gcdConsecutive(m, n);
            printf("GCD (Consecutive Integer Checking): %d\n", result);
            break;
        case 3:
            result = gcdMiddleSchool(m, n);
            printf("GCD (Middle School Method): %d\n", result);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}