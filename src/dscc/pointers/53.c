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
 * @file 53.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes two input from the user, saves them to variables,
 * swaps their values, and displays the result.
 * @version 0.1
 * @date 17-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

/**
 * @brief Swapping two values globally. (Method 1)
 *
 * @param a First value
 * @param b Second value
 */
void swap_1(int* a, int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

/**
 * @brief Swapping two values globally. (Method 2)
 *
 * @param a First value
 * @param b Second value
 */
void swap_2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 0;
    int b = 0;

    printf("Input two values (sep. by a space): ");

    while (scanf("%d %d", &a, &b) != 2) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    swap_1(&a, &b);
    printf("swap_1(): %d %d\n", a, b);

    swap_2(&a, &b);
    printf("swap_2(): %d %d\n", a, b);

    return EXIT_SUCCESS;
}