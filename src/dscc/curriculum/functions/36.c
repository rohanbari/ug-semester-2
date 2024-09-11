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
 * @file 36.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes weight in pounds as an input from the user,
 * converts it into kilograms, then displays it on the screen.
 * @version 0.1
 * @date 07-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

/**
 * @brief Converts a given input in pounds to kilograms.
 * 
 * @param pounds Weight in pounds
 * @return double Weight in kilograms
 */
double to_kilogram(const double pounds)
{
    return pounds * 0.45359237;
}

int main(void)
{
    double pounds = 0.0;

    printf("Input weight (in pounds): ");

    while (scanf("%lf", &pounds) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (pounds < 0) {
        perror("error: Input cannot be negative.\n");
        return EXIT_FAILURE;
    }

    printf("The converted weight is %.3lf kg.\n", to_kilogram(pounds));

    return EXIT_SUCCESS;
}