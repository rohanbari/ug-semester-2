#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 0;
    int b = 0;

    printf("Input two values: ");
    scanf("%d %d", &a, &b);

    printf("Before: %d %d\n", a, b);
    swap(&a, &b);
    printf("Before: %d %d\n", a, b);

    return 0;
}