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
 * @file 44.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program has the ability to calculate the GCD of variable numbers!
 * And of course, it displays the result on the screen.
 * @version 0.1
 * @date 12-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

/**
 * @brief Finds the greatest common divisor of two numbers.
 *
 * @param a The first number
 * @param b The second number
 * @return int GCD of the two numbers
 */
int GCD(const int a, const int b)
{
    int gcd = 1;

    for (int i = 1; i <= a; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

int main(void)
{
    int size = 0;

    printf("How many numbers do you wish to have? ");

    while (scanf("%d", &size) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (size <= 0) {
        perror("error: The input must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    int* array = (void*)malloc(sizeof(int) * size);

    if (array == NULL) {
        perror("error: malloc() failed.\n");
        return EXIT_FAILURE;
    }

    printf("Please provide with the input(s): ");
    for (int i = 0; i < size; i++) {
        while (scanf("%d", &array[i]) != 1) {
            perror("error: Invalid input.\n");
            clear_stdin();
        }
    }

    int total_gcd = array[0];
    for (int i = 1; i < size; i++) {
        total_gcd = GCD(array[i], total_gcd);
    }

    printf("The GCD of these is %d.\n", total_gcd);

    return EXIT_SUCCESS;
}