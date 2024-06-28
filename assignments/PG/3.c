// A program in C to determine the roots of a quadratic equation:
// ax^2 + bx + c = 0, where a, b, and c are real numbers.

#include <math.h>
#include <stdio.h>

int main(void)
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    printf("\n\t\tThe accepted expression is: ax^2 + bx + c.\n");
    printf("\n\t\tPlease provide the values of a, b, c: ");

    // Getting values until satisfied
    while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
        perror("error: Invalid input. Please try again.\n");

    double discriminant = b * b - 4 * a * c; // Calculating the discriminant

    printf("\n\t\t==============================================\n\n\t\t");
    if (discriminant > 0) {
        // If the roots are real and inequal
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);

        printf("The roots of the equation are: %.2lf and %.2lf.\n", root1, root2);
    } else if (discriminant == 0) {
        // If the roots are real and equal
        double root = -b / (2 * a);
        printf("The root of the equation is: %.2lf.\n", root);
    } else {
        // If the roots are imaginary
        double real = -b / (2 * a);
        double imag = sqrt(-discriminant) / (2 * a);

        printf("The roots of the equation are: %.2lf + %.2lfi and %.2lf - %.2lfi.\n",
            real, imag, real, imag);
    }
    putc('\n', stdout);

    return 0;
}