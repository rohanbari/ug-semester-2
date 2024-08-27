#include <stdio.h>

#define FILE_NAME "test_content.txt"

long number_of_lines(FILE* fp)
{
    long lines = 0L;
    long pos = ftell(fp);

    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }

    if (lines == 0 && ftell(fp) > 0)
        lines++;

    // Reset the cursor to the beginning
    fseek(fp, pos, SEEK_SET);

    return lines;
}

long number_of_chars(FILE* fp)
{
    long chars = 0L;
    long pos = ftell(fp);

    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        // Newlines are not counted
        if (ch != '\n' || ch != '\r' || ch != '\t') {
            chars++;
        }
    }

    // Reset the cursor to the beginning
    fseek(fp, pos, SEEK_SET);

    return chars;
}

long number_of_words(FILE* fp)
{
    long words = 0L;
    long pos = ftell(fp);

    short in_word = 0;

    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    fseek(fp, pos, SEEK_SET);

    return words;
}

int main(void)
{
    FILE* fp = fopen(FILE_NAME, "r");

    if (!fp) {
        fprintf(stderr, "error: The file does not exist.\n");
        return 1;
    }

    printf("No of lines: %ld\n", number_of_lines(fp));
    printf("No of words: %ld\n", number_of_words(fp));
    printf("No of chars: %ld\n", number_of_chars(fp));

    fclose(fp);

    return 0;
}