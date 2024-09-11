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
 * @file s9.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes two input from the user, compares, and prints the
 * greatest one. If equal, then prints 'Equal.'
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
    int num_1 = 0;
    int num_2 = 0;

    printf("Enter two numbers (sep. by space): ");

    // Validating the input values
    while (scanf("%d %d", &num_1, &num_2) != 2) {
        perror("error: Invalid input. Please try again.\n");
        clear_stdin();
    }

    printf("Status: ");
    if (num_1 == num_2) {
        printf("Equal.\n");
    } else {
        int greater = (num_1 > num_2) ? num_1 : num_2;
        printf("%d\n", greater);
    }

    return EXIT_SUCCESS;
}