// A program in C to determine whether a particular positive integer is a
// perfect, deficient, or abundant number or not.

#include <stdio.h>

// Function to classify the number.
void classifyNumber(int num)
{
    int sum = 0;
    for (int i = 1; i <= num / 2; i++)
        if (num % i == 0)
            sum += i;

    printf("\n\t\t");
    if (sum == num)
        printf("%d is a perfect number.\n\n", num);
    else if (sum < num)
        printf("%d is a deficient number.\n\n", num);
    else
        printf("%d is an abundant number.\n\n", num);
}

int main()
{
    int num;
    printf("\n\n\t\tEnter a positive integer: ");
    scanf("%d", &num);

    if (num <= 0)
        printf("\n\t\tPlease enter a positive integer.\n");
    else
        classifyNumber(num);

    return 0;
}
