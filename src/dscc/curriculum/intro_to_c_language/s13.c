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
 * @file s13.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, calculates the integral
 * factors, then displays it on the screen.
 * @version 0.1
 * @date 25-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

int abs(const int n)
{
    return ((n < 0) ? -1 : 1) * n;
}

/**
 * @brief Prints the factors on the screen.
 *
 * @param n Whose factors to be calculated
 */
void generate_factors(const int n)
{
    // If the number is a negative integer, then the modulus operator cannot be
    // incorporated unless the negative sign is handled manually.
    if (n < 0) {
        printf("-1 ");
    }

    for (int i = 1; i <= abs(n); i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    putc('\n', stdout);
}

int main(void)
{
    int n = 0;

    printf("Enter a number: ");

    while (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        clear_stdin();
    }

    generate_factors(n);

    return EXIT_SUCCESS;
}