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
 * @file 56.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program purposefully demonstrates the usage of a constant-sized
 * compile-time defined array.
 * @version 0.1
 * @date 18-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

#define ARRAY_SIZE 10

int main(void)
{
    int array[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Input %dth number: ", i);

        int input = 0;
        while (scanf("%d", &input) != 1) {
            perror("error: Invalid input.\n");
            clear_stdin();
        }
        array[i] = input;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Value at %dth index: %d\n", i, array[i]);
    }

    return EXIT_SUCCESS;
}