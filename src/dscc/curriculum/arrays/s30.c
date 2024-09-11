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
 * @file s30.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, stores it into a character-
 * array, identifies if it is a palindrome, then displays the evaluation.
 * @version 0.1
 * @date 29-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

#define BUFSIZE 1024

/**
 * @brief Custom strlen function by me.
 *
 * @param str The string
 * @return size_t
 */
size_t _strlen(const char* str)
{
    size_t len = 0;
    while (str[len] != '\0')
        len++;

    return len;
}

/**
 * @brief This function identifies whether a string is a palindrome or not.
 *
 * @param str The string
 * @param n Size of the string
 * @return boolean
 */
boolean is_palindrome(const char* str, const size_t n)
{
    for (size_t i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    char input[BUFSIZE];

    printf("Enter a string: ");

    while (fgets(input, sizeof input, stdin) == NULL) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    printf("The string is %sa palindrome.\n",
        is_palindrome(input, _strlen(input) - 1) ? "" : "not ");

    return EXIT_SUCCESS;
}