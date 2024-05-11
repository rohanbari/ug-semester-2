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
 * @file 38.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes two input from the user: a base and a power, then
 * it evaluates a base-raised-to-the-power operation in O(1) time complexity,
 * and shows it to the user.
 *
 * @version 0.1
 * @date 11-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <math.h>
#include <stdio.h>

#include "../common.h"

/**
 * @brief This function evaluates the results in the known expression of
 * e^(n * log(x)), which is identical to x^n. However, e^m (m: any number) is
 * O(1) in time complexity, and so does the log(m) function. Therefore, the
 * entire expression is O(1).
 *
 * @param x The base
 * @param n The power
 * @return double x^n
 */
double power(const int x, const int n)
{
    double res = exp(n * log(x));
    return round(res);
}

int main(void)
{
    int base = 0;
    int n = 0;

    printf("Input the base and the power (sep. by a space): ");

    while (scanf("%d %d", &base, &n) != 2) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    printf("The result is %.2lf.\n", power(base, n));

    return EXIT_SUCCESS;
}