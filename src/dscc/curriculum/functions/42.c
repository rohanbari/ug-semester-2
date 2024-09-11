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
 * @file 42.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, then prints odd/even
 * numbers through recursion.
 * @version 0.1
 * @date 11-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

void print_even(const int value)
{
    if (value == 0) {
        return;
    }

    print_even(value - 2);
    printf("%d ", value);
}

void print_odd(const int value)
{
    if (value < 0) {
        return;
    }

    print_odd(value - 2);
    printf("%d ", value + 1);
}

int main(void)
{
    int input = 0;

    printf("Input a number: ");

    while (scanf("%d", &input) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    print_even(input);
    putc('\n', stdout);
    print_odd(input - 2);
    putc('\n', stdout);

    return EXIT_SUCCESS;
}