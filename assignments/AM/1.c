// A program in C to evaluate the following sum:
// S = 1 + x - x^2/2 + x^3/3! + ... + x^n/n!

#include <stdio.h>

// Function to calculate factorial iteratively.
long long factorial(int n)
{
    long long product = 1;
    for (int i = 1; i <= n; i++)
        product *= i;

    return product;
}

int main(void)
{
    // Initializing variables x and n to zero
    int n = 0;
    double x = 0.0;

    printf("\n\n\t\tInput the value of x and n: ");

    // Input validation for x and n
    while (scanf("%lf %d", &x, &n) != 2 || n <= 0) {
        fprintf(stderr, "\t\terror: The value of N must be a +ve integer.\n");
        printf("\n\t\tInput the value of x and n: ");
        while (getchar() != '\n')
            ; // Clear input buffer
    }

    double sum = 1.0; // Summation starts with 1
    double term = 1.0; // To calculate each term iteratively

    for (int i = 1; i <= n; i++) {
        term *= x / i; // Calculate current term as (previous term * x / i)
        // Subtracting the even powers from the sum and adding the odd powers

        if (i % 2 == 0) sum -= term;
        else sum += term;
    }

    printf("\n\t\t===============================\n");
    printf("\n\t\tThe sum of the series is: %.3lf\n\n", sum);

    return 0;
}