#include <stdio.h>
#include <string.h>

int main(void) {
    char str[256];

    printf("Input a string: ");
    fgets(str, sizeof str, stdin);

    // Omitting the extra newline character
    str[strcspn(str, "\n")] = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            printf("%c", str[i] - 32);
        } else if (str[i] == ' ') {
            printf(" ");
        }
    }

    return 0;
}