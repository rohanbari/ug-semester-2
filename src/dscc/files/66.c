/*
 Copyright 2024 Rohan Bari <rohanbari@outlook.com>

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#include <stdio.h>

#include "../common.h"

#define FILE_NAME "output.dat"

int main(void)
{
    FILE* fp = fopen(FILE_NAME, "rw+");

    if (!fp) {
        perror("error: Error opening the file.\n");
        return EXIT_FAILURE;
    }

    fprintf(fp, "Hello, world!\n");

    // Setting the cursor to the beginning of the file
    rewind(fp);

    int ch = 0;
    while ((ch = getc(fp)) != EOF) {
        if (ch == '!') {
            // This will only simulate the alternation. To actually modify, we
            // have to use fputc() to do so.
            ungetc('.', fp);
            ch = getc(fp);
        }

        putc(ch, stdout);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}