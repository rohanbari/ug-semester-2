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
 * @file s34.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief
 * @version 0.1
 * @date 04-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <string.h>

#include "../common.h"

#define BUFSIZE 512

void display_triangle_pattern(const char* str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            printf("%-2c", str[j]);
        }
        printf("\n");
    }

    for (int i = len; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("%-2c", str[j]);
        }
        printf("\n");
    }
}

int main(void)
{
    char input[BUFSIZE];

    printf("Input a string: ");

    while (fgets(input, sizeof input, stdin) == NULL) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    // Removing the trailing newline character.
    input[strcspn(input, "\n")] = '\0';

    display_triangle_pattern(input);

    return EXIT_SUCCESS;
}