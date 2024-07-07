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
 * @file code.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This file is dedicated to solving assignment problems.
 * @version 0.1
 * @date 07-07-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

int main(void)
{
    int num1 = 0;
    int num2 = 0;
    int result = 0;

    printf("Input two numbers: ");

    // Input validation
    if (scanf("%d%d", &num1, &num2) != 2) {
        perror("error: Invalid input.\n");
        return 1;
    }

    printf("\nMultiplying %d and %d using Russian Peasant method:\n", num1, num2);
    printf("=============================================\n");
    printf("%15s%15s%15s\n", "Value 1", "Value 2", "Result");
    printf("=============================================\n");

    while (num2 > 0) {
        // If the number is an odd number, then the sum is to be added.
        if (num2 % 2 == 1)
            result += num1;

        printf("%15d%15d%15s\n", num1, num2, (num2 % 2 == 0) ? "(struck off)" : "");

        // Double the first number and halve the second number.
        num1 *= 2;
        num2 /= 2;
    }

    printf("=============================================\n");
    printf("%15s%30d\n", "RESULT", result);
    printf("=============================================\n");

    return 0;
}