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
 * @file s31.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an array of input from the user, stores it in an
 * array, sorts the elements in ascending order, then displays it.
 * @version 0.1
 * @date 29-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

/**
 * @brief Swaps between two integers.
 *
 * @param a A
 * @param b B
 */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief The Bubble-sort algorithm.
 *
 * @param array The array to sort
 * @param n Size of the array
 */
void sort(int* array, const int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main(void)
{
    int n = 0;

    printf("How many elements? Input: ");

    while (scanf("%d", &n) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (n <= 0) {
        perror("error: The input must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Initializing a dynamic array. See malloc(3) for documentation.
    int* array = (void*)malloc(sizeof(int) * n);

    if (array == NULL) {
        perror("error: Failed to allocate memory.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);

        while (scanf("%d", &array[i]) != 1) {
            perror("error: Invalid input. Please try again.\n");
            clear_stdin();
        }
    }

    sort(array, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", array[i]);

    free(array);

    return EXIT_SUCCESS;
}