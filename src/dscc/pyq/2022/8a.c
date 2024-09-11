#include <stdio.h>

int sum_even_to(int num)
{
    static int sum = 0;

    if (num == 0) {
        return sum;
    }

    if (num % 2 == 0) {
        sum += num;
    }

    return sum_even_to(--num);
}

int main(void)
{
    printf("2 + 4 + 6 ... + 20 = %d\n", sum_even_to(20));

    return 0;
}