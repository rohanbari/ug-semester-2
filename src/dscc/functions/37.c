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
 * @file 37.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program displays all the "Perfect Numbers" ranging from LOWER to
 * UPPER. By default, in [1, 100] range.
 *
 * In number theory, a perfect number is a positive integer that is equal
 * to the sum of its positive proper divisors, that is, divisors excluding the
 * number itself. For instance, 6 has proper divisors 1, 2 and 3, and
 * 1 + 2 + 3 = 6, so 6 is a perfect number. [Source: Wikipedia]
 *
 * @version 0.1
 * @date 07-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

#define LOWER 1
#define UPPER 100

/**
 * @brief Finds the sum of the factorial of a number.
 *
 * @param val The number
 * @return int Factorial sum
 */
int factorial_sum(const int val)
{
    int sum = 0;

    for (int i = 1; i < val; i++) {
        if (val % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int main(void)
{
    if (LOWER < 0 || UPPER < 0 || UPPER < LOWER)
        return EXIT_FAILURE;

    for (int i = LOWER; i <= UPPER; i++) {
        int sum = factorial_sum(i);
        if (sum == i) {
            printf("%d ", sum);
        }
    }
    putc('\n', stdout);

    return EXIT_SUCCESS;
}