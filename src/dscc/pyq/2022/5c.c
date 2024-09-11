#include <stdio.h>

int main(void)
{
    int n = 0;

    printf("Input n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("error: n must be > 0.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j >= 1; j--) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}