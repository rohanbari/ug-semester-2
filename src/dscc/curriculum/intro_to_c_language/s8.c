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
 * @file s8.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes two input from the user, calculates the sum and the
 * product, then prints it.
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

    printf("Please provide two integers: ");

    // Validating the input values
    while (scanf("%d %d", &num_1, &num_2) != 2) {
        perror("error: Invalid input. Please try again.\n");
        clear_stdin();
    }

    int sum = num_1 + num_2;
    int product = num_1 * num_2;

    printf("Summation: \t%d\nProduct: \t%d\n", sum, product);

    return EXIT_SUCCESS;
}