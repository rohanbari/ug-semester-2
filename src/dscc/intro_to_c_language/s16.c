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
 * @file s16.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, asks the same number of
 * times for integer values, calculates the average of them, then prints it on
 * the screen.
 * @version 0.1
 * @date 26-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

/**
 * @brief Calculates the average value of the given array.
 *
 * @param array The given array
 * @param n Number of terms in the array
 * @return double Average
 */
double calculate_average(const int* array, const int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += array[i];

    return sum / n;
}

int main(void)
{
    printf("Input the number of values to consider. ");

    int size = 0;
    while (scanf("%d", &size) != 1) {
        perror("error: The input must be an integer.\n");
        clear_stdin();
    }

    if (size <= 0) {
        perror("error: The input must be greater than 0.\n");
        return EXIT_FAILURE;
    }

    int* array = (void*)malloc((sizeof(int) * size));

    for (int i = 0; i < size; i++) {
        printf("Input the %dth value: ", i + 1);

        int temp = 0;
        while (scanf("%d", &temp) != 1) {
            perror("error: The input must be an integer.\n");
            clear_stdin();
        }

        array[i] = temp;
    }

    printf("The average of these is %.2f.\n", calculate_average(array, size));

    return EXIT_SUCCESS;
}