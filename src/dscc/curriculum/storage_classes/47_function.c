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
 * @file 47_function.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This is a supplementary program that uses the 'extern' variables
 * defined under 47_main.c program.
 * @version 0.1
 * @date 16-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

int x;
int y;
int sum;

void get_input(void)
{
    printf("Input two values (sep. by a space): ");

    while (scanf("%d %d", &x, &y) != 2) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }
}

void calculate_sum(void)
{
    sum = x + y;
}

void display(void)
{
    printf("The sum of %d and %d is %d.\n", x, y, sum);
}