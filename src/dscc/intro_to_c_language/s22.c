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

/**
 * @file s22.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, reverses it, and inverses
 * the case of the inputted word. Finally, it shows up.
 * @version 0.1
 * @date 27-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "../common.h"

#define BUFSIZE 512

int main(void)
{
    char input[BUFSIZE] = "";
    char out[BUFSIZE] = "";

    printf("Enter a word: ");

    while (fgets(input, BUFSIZE, stdin) == NULL) {
        perror("error: Error reading input.\n");
        clear_stdin();
    }

    size_t input_size = strlen(input);

    // Omitting the new-line character before the end of actual null-terminator
    input[strcspn(input, "\n")] = 0;

    for (int i = input_size - 1; i >= 0; i--) {
        // Basically out[0], out[1], ...
        int j = input_size - i - 2;
        out[j] = input[i];

        // Running specific checks
        if (isupper(out[j])) {
            out[j] = tolower(out[j]);
        } else if (islower(out[j])) {
            out[j] = toupper(out[j]);
        } else {
            continue;
        }
    }

    printf("   Processed: %s\n", out);

    return EXIT_SUCCESS;
}