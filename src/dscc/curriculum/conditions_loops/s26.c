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
 * @file s26.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, then displays all the prime
 * numbers up to the given input.
 * @version 0.1
 * @date 28-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

/**
 * @brief Generates and displays the prime numbers up to incl. N.
 *
 * @param n The limit (not terms)
 */
void display_prime_numbers(const int n)
{
    if (n == 0 || n == 1) {
        printf("%d ", n);
    }

    // Time complexity: O(n^2)
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            if (i == j) {
                printf("%d ", i);
            } else if (i % j == 0) {
                break;
            }
        }
    }

    putc('\n', stdout);
}

int main(void)
{
    int n = 0;

    printf("Enter the limit: ");

    while (scanf("%d", &n) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (n < 0) {
        perror("error: The limit should be > 0.\n");
        return EXIT_FAILURE;
    }

    display_prime_numbers(n);

    return EXIT_SUCCESS;
}