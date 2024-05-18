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
 * @file 57.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program uses a pointer to simulate a dynamic-sized array.
 * @version 0.1
 * @date 18-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

int main(void)
{
    int size = 0;

    printf("Input the size of the array: ");

    while (scanf("%d", &size) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (size <= 0) {
        perror("error: Size must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    int* array = (void*)malloc(sizeof(int) * size);

    if (array == NULL) {
        perror("error: Failed to allocate memory.\n");
        return EXIT_FAILURE;
    }

    printf("Input %d no. of values (sep. by space or enter):\n", size);
    for (int i = 0; i < size; i++) {
        while (scanf("%d", &array[i]) != 1) {
            perror("error: Invalid input.\n");
            clear_stdin();
        }
    }

    printf("Inputted values:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    putc('\n', stdout);

    return EXIT_SUCCESS;
}