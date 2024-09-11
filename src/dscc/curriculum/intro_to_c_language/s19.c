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
 * @file s19.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes a floating-point input from the user, then displays
 * the least-significant digit of its integral part.
 * @version 0.1
 * @date 27-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

int main(void)
{
    // Note that we should prefer 'double' instead of 'float' variables in
    // general. We are using the 'float' type only because it is specifically
    // asked in this problem.
    float input = 0.0F;

    printf("Input a value: ");

    while (scanf("%f", &input) != 1) {
        perror("error: Not a valid floating-point number.\n");
        clear_stdin();
    }

    // Performing an explicit-cast to int in order to truncate the decimal part,
    // followed by a modulus-by-10 operation to obtain the end part.
    int last_part = (int)input % 10;

    printf("The right-most digit of the integral part is %d.\n", last_part);

    return EXIT_SUCCESS;
}