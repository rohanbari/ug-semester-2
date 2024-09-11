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
 * @file 40.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, then displays the original
 * as well as the reversed version of the input on the screen.
 *
 * @version 0.1
 * @date 11-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

/**
 * @brief This is my way to evaluate the length of a given string.
 *
 * @param str The given string
 * @return size_t Length of the given string
 */
size_t _strlen(const char* str)
{
    size_t len = 0L;
    while (str[++len] != '\0')
        ;

    return len;
}

/**
 * @brief This reverses the original string and replaces it.
 *
 * @param str The original string
 */
void reverse_str(char* str, int idx, int len)
{
    if (idx < len) {
        char temp = str[idx];
        str[idx] = str[len];
        str[len] = temp;

        reverse_str(str, ++idx, --len);
    }
}

int main(void)
{
    char str[BUFSIZ];

    printf("Input a string: ");

    while (fgets(str, sizeof str, stdin) == NULL) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    // Eliminating the newline character at the end
    str[_strlen(str) - 1] = '\0';

    printf("Original string: %s\n", str);

    reverse_str(str, 0, _strlen(str) - 1);
    printf("Reversed string: %s\n", str);

    return EXIT_SUCCESS;
}