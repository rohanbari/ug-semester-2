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
 * @file s10.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an indefinite number of inputs from the user,
 * compares them, and displays the greatest and the third greatest number on
 * the screen.
 * @version 0.1
 * @date 25-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

int main(void)
{
    int greatest = 0;
    int second_greatest = 0;
    int third_greatest = 0;

    int input = 0;

    printf("info: To stop, input anything except a valid integer.\n\n");

    while (true) {
        printf("Enter a number: ");

        if (scanf("%d", &input) != 1) {
            clear_stdin();
            break;
        }

        if (input > greatest) {
            third_greatest = second_greatest;
            second_greatest = greatest;
            greatest = input;
        } else if (input > second_greatest) {
            third_greatest = second_greatest;
            second_greatest = input;
        } else if (input > third_greatest) {
            third_greatest = input;
        } else {
            continue;
        }
    }

    printf("Greatest: %d\nThird Greatest: %d\n", greatest, third_greatest);

    return EXIT_SUCCESS;
}