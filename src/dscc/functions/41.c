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
 * @file 41.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, then finds its factorial
 * through a recursive function.
 * @version 0.1
 * @date 11-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

void factorial(int num)
{
    static long fact = 1L;

    if (num == 1) {
        printf("Factorial: %ld.\n", fact);
        return;
    }

    fact *= num;
    factorial(num - 1);
}

int main(void)
{
    int num = 0;

    printf("Input a number: ");

    while (scanf("%d", &num) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (num < 0) {
        printf("-1 ");
    }

    factorial(num);

    return EXIT_SUCCESS;
}