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
 * @file 35.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program prints all Armstrong numbers ranging [1, 500].
 * @version 0.1
 * @date 05-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

#define LOWER 1
#define UPPER 500

/**
 * @brief Validates whether the passed number is an Armstrong number or not.
 *
 * @param num The number to be validated
 * @return boolean
 */
boolean is_armstrong(const int num)
{
    int temp = num;
    int sum = 0;

    while (temp > 0) {
        int t = temp % 10;
        sum += t * t * t;
        temp /= 10;
    }

    return sum == num;
}

int main(void)
{
    for (int i = LOWER; i <= UPPER; i++) {
        // All single-digit numbers are Armstrong numbers.
        if (i <= 9) {
            printf("%d ", i);
            continue;
        }

        if (is_armstrong(i)) {
            printf("%d ", i);
        }
    }
    putc('\n', stdout);

    return EXIT_SUCCESS;
}