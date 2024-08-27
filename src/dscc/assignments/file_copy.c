#include <stdio.h>

/* ./a.out <source_file> <dest_file> */
#define MAX_ARGS 2

short validate_args(int argc, char* p)
{
    if (argc != MAX_ARGS) {
        fprintf(stderr, "Usage: ./%s <source_file> <dest_file>\n", p);
        return 1;
    }

    return 0;
}

int main(int argc, char** argv)
{
    if (!validate_args(argc, argv[0])) {
        return 1;
    }

    FILE* fp_reader = fopen(argv[1], "r"); // To read from
    FILE* fp_writer = fopen(argv[2], "a"); // To write into

    if (!fp_reader) {
        fprintf(stderr, "error: File does not exist.\n");
        return 1;
    }

    // Putting char by char
    char ch;
    while ((ch = fgetc(fp_reader)) != EOF) {
        fputc(ch, fp_writer);
    }

    fclose(fp_reader);
    fclose(fp_writer);

    return 0;
}