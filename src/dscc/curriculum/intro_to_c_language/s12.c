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
 * @file s12.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, calculates the sum of the
 * inputted number of natural numbers, then prints it on the screen.
 * @version 0.1
 * @date 25-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

int main(void)
{
    int n = 0;

    printf("Input the value of N: ");

    while (scanf("%d", &n) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    int sum = 0;
    if (n > 0)
        sum = n * (n + 1) / 2;
    else
        sum = n * (1 - n) / 2;

    printf("Summation up to %d: %d\n", n, sum);

    return EXIT_SUCCESS;
}