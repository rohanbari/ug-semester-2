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
 * @file s15.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, identifies whether the
 * number is a prime or not, then displays its judgment.
 * @version 0.1
 * @date 25-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

/**
 * @brief Prime number validator.
 *
 * @param n The number
 */
boolean validate_prime(const int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && i != n)
            return false;
    }

    return true;
}

int main(void)
{
    int n = 0;

    printf("Enter a number: ");

    while (scanf("%d", &n) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (n <= 0) {
        perror("error: The number cannot be negative.\n");
        return EXIT_FAILURE;
    }

    printf("The number is a %s number.\n",
        validate_prime(n) ? "PRIME" : "COMPOSITE");

    return EXIT_SUCCESS;
}