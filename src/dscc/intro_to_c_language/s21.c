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
 * @file s21.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program categorizes characters as alphabets, digits, punctuation,
 * or special characters.
 * @version 0.1
 * @date 27-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <ctype.h>
#include <stdio.h>

#include "../common.h"

int main(void)
{
    int c = 0;

    printf("Input: ");
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            printf("info: An alphabet.\n");
        } else if (isdigit(c)) {
            printf("info: A digit.\n");
        } else if (ispunct(c)) {
            printf("info: A punctuation.\n");
        } else {
            printf("info: A special character.\n");
        }

        // This is necessary to ensure the stability of the I/O sequence
        clear_stdin();
        printf("Input: ");
    };

    return EXIT_SUCCESS;
}