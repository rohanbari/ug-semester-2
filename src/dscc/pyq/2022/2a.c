#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[256];

    printf("Input a sentence: ");
    fgets(str, sizeof str, stdin);

    // Omitting the newline
    str[strcspn(str, "\n")] = 0;

    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}