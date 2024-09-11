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
 * @file 50.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes indefinite input (until a negative number is
 * encountered), evaluates their summation, and displays it.
 * @version 0.1
 * @date 16-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

void program()
{
    static int sum = 0;

    while (true) {
        int input = 0;
        while (scanf("%d", &input) != 1) {
            perror("error: Invalid input.\n");
            clear_stdin();
        }

        if (input < 0) {
            break;
        }

        sum += input;
    }

    printf("The sum is %d.\n", sum);
}

int main(void)
{
    program();

    return EXIT_SUCCESS;
}