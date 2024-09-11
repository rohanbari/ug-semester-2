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
 * @file s28.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, then judges whether the
 * given input is an Armstrong number or not.
 *
 * An "Armstrong number" is a number whose cube of its digits is equal to that
 * number itself.
 *
 * @version 0.1
 * @date 28-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

int cube_digits(const int num)
{
    int sum = 0;
    int temp = num;

    while (temp > 0) {
        int rem = temp % 10;
        sum += rem * rem * rem;
        temp /= 10;
    }

    return sum;
}

int main(void)
{
    int num = 0;

    printf("Enter a number: ");

    while (scanf("%d", &num) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (num < 0) {
        perror("error: The number should be a positive integer.\n");
        return EXIT_FAILURE;
    }

    int sum = cube_digits(num);

    printf("info: It is %san Armstrong number.\n", (num == sum) ? "" : "not ");

    return EXIT_SUCCESS;
}