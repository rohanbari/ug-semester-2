#include <stdio.h>

int main(void)
{
    int num = 0;

    printf("Input a number: ");
    scanf("%d", &num);

    int temp = num;
    int sum = 0;

    while (temp > 0) {
        int x = temp % 10;
        sum += x * x * x;

        temp /= 10;
    }

    printf("The number is %san Armstrong number.\n", (sum == num) ? "" : "not ");

    return 0;
}