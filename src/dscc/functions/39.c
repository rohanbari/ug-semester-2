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
 * @file 39.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes several input from the user, evaluates the roots
 * of the quadratic equation [ax^2 + bx + c = 0].
 *
 * @version 0.1
 * @date 11-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <math.h>
#include <stdio.h>

#include "../common.h"

int main(void)
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    printf("The accepted expression is: ax^2 + bx + c.\n");
    printf("Please provide the values of a, b, c: ");

    while (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    // Expression for the discriminant
    double D = b * b - 4 * a * c;

    if (D < 0) {
        printf("The roots are imaginary.\n");
        return EXIT_SUCCESS;
    }

    // Evaluation of the roots
    double x1 = (-b + sqrt(D)) / (2 * a);
    double x2 = (-b - sqrt(D)) / (2 * a);

    printf("The roots are %.2lf and %.2lf respectively.\n", x1, x2);

    return EXIT_SUCCESS;
}