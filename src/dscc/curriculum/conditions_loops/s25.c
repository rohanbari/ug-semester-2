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
 * @file s25.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, sums up its digits until
 * there is only one decimal place left, then displays it on the screen.
 * @version 0.1
 * @date 28-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

static int sum;

/**
 * @brief Breaks down the given number by summing up its digit(s).
 *
 * @param num The number
 * @return Broken down to one-decimal place
 */
void breakdown(int num)
{
    sum = 0;
    int temp = num;

    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    if (sum < 10) {
        printf("The answer is %d.\n", sum);
        return;
    }

    breakdown(sum);
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
        perror("error: Please enter positive integers only.\n");
        return EXIT_FAILURE;
    }

    breakdown(num);

    return EXIT_SUCCESS;
}