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
 * @file s17.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program asks the user for an input, then converts it to Celsius
 * or Fahrenheit, as asked.
 * @version 0.1
 * @date 26-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

typedef enum {
    C_QUIT,
    C_FAHRENHEIT,
    C_CELSIUS
} choice;

int main(void)
{
    int input;

    while (true) {
        printf("[1] Celsius to Fahrenheit\n"
               "[2] Fahrenheit to Celsius\n"
               "[0] QUIT\n\n"
               "Input: ");

        while (scanf("%d", &input) != 1) {
            perror("error: The value must be a valid integer.\n");
            clear_stdin();
        }

        if (input < 0 || input > 3) {
            perror("error: Invalid input range.\n");
            clear_stdin();

            continue;
        }

        if (input == C_QUIT) {
            break;
        }

        printf("Value to Convert: ");

        double value = 0;
        while (scanf("%lf", &value) != 1) {
            perror("error: The value must be a valid decimal.\n");
            clear_stdin();
        }

        if (input == C_FAHRENHEIT) {
            double fahr = 9 * value / 5.0 - 32;
            printf("The conversion result is %.2lf degrees F.\n", fahr);
        } else if (input == C_CELSIUS) {
            double celsius = 5 * (value - 32) / 9;
            printf("The conversion result is %.2lf degrees C.\n", celsius);
        }
    }

    return EXIT_SUCCESS;
}