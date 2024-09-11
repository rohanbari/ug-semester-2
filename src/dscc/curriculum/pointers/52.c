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
 * @file 52.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes two numeric input from the user, swaps them, and
 * displays the final result.
 * @version 0.1
 * @date 17-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "../common.h"

#define MAX_LEN 256

void swap(char* num1, char* num2)
{
    char temp[MAX_LEN];

    strcpy(temp, num1);
    strcpy(num1, num2);
    strcpy(num2, temp);
}

int main(void)
{
    char num1[MAX_LEN];
    char num2[MAX_LEN];

    printf("Input two numbers (sep. by space): ");

    while (scanf("%255s %255s", num1, num2) != 2) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (!isdigit(num1) || !isdigit(num2)) {
        perror("error: The input must be a number.\n");
        return EXIT_FAILURE;
    }

    swap(num1, num2);

    printf("Swapped values: %s %s\n", num1, num2);

    return EXIT_SUCCESS;
}