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
 * @file s18.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, calculates the sum of the
 * harmonic series up to the asked limit, then displays it.
 * @version 0.1
 * @date 26-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

/**
 * @brief Calculates the HP sum.
 *
 * @param n Number of terms
 * @return double Sum
 */
double generate_harmonic_sum(const int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }

    return sum;
}

int main(void)
{
    printf("Enter an inclusive limit for the harmonic series: ");

    int n = 0;
    while (scanf("%d", &n) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    // Edge case: When the denominator could be zero
    if (n <= 0) {
        printf("error: The value should not be <= 0.\n");
        return EXIT_FAILURE;
    }

    printf("Harmonic sum is %.3lf.\n", generate_harmonic_sum(n));

    return EXIT_SUCCESS;
}