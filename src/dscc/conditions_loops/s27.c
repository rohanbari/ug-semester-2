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
 * @file s27.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, then prints a progressive-
 * numeric pyramid on the screen.
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
    int num = 0;

    printf("Enter a number: ");

    while (scanf("%d", &num) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%3d", j);
        }
        putc('\n', stdout);
    }

    return EXIT_SUCCESS;
}