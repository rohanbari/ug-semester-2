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
 * @file 58.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, uses a pointer to store it
 * dynamically, and displays whether the string is a palindrome or not.
 * @version 0.1
 * @date 18-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common.h"

#define SIZE 512

/**
 * @brief It uses two-pointer approach to identify whether the string is a
 * palindrome or not.
 *
 * @param str The string
 * @param len Length of the string
 * @return boolean
 */
boolean is_palindrome(const char* str, const size_t len)
{
    size_t i = 0;
    while (i < len / 2) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
        i++;
    }

    return true;
}

int main(void)
{
    char* str = (void*)malloc(sizeof(char) * SIZE);

    if (str == NULL) {
        perror("error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    printf("Input a string: ");

    while (fgets(str, SIZE, stdin) == NULL) {
        perror("error: Input failed.\n");
        clear_stdin();
    }

    // Omission of the trailing newline by fgets().
    str[strcspn(str, "\n")] = 0;

    printf("%s\n", str);

    boolean is_pal = is_palindrome(str, strlen(str));
    printf("The string is %sa palindrome.\n", is_pal ? "" : "not ");

    // A good practice is to clean your own mess.
    free(str);

    return EXIT_SUCCESS;
}