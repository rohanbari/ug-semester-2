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
 * @file s24.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, and prints Fibonacci
 * sequence up to the asked limit.
 * @version 0.1
 * @date 28-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

int main(void)
{
    int terms = 0;

    printf("Input the number of terms: ");

    while (scanf("%d", &terms) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (terms <= 0) {
        perror("error: Number of terms should be > 0.\n");
        return EXIT_FAILURE;
    }

    int a = 0;
    int b = 1;
    int c = 1;

    for (int i = 2; i <= terms; i++) {
        printf("%d ", a);
        
        a = b;
        b = c;
        c = a + b;
    }
    putc('\n', stdout);

    return EXIT_SUCCESS;
}