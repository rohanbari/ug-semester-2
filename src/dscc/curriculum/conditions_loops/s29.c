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
 * @file s29.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes three input from the user, then identifies whether
 * it is an equilateral, isosceles, or scalene triangle.
 * @version 0.1
 * @date 28-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

struct side {
    double a;
    double b;
    double c;
};

enum triangle {
    EQUILATERAL,
    ISOSCELES,
    SCALENE,
    NOT_A_TRIANGLE
};

/**
 * @brief This function identifies type of the triangle with its given sides.
 *
 * @param sides The given sides
 * @return enum triangle
 */
enum triangle identify_triangle(const struct side s)
{
    if ((s.a + s.b) < s.c) {
        return NOT_A_TRIANGLE;
    }

    if (s.a == s.b && s.b == s.c) {
        return EQUILATERAL;
    } else if (s.a == s.b && s.b != s.c) {
        return ISOSCELES;
    } else if (s.a != s.b && s.b != s.c) {
        return SCALENE;
    }

    return NOT_A_TRIANGLE;
}

int main(void)
{
    struct side s = { 0.0, 0.0, 0.0 };

    printf("Input the three sides (sep. by space): ");

    while (scanf("%lf %lf %lf", &s.a, &s.b, &s.c) != 3) {
        perror("error: Invalid input(s).\n");
        clear_stdin();
    }

    switch (identify_triangle(s)) {
    case EQUILATERAL:
        printf("The triangle is equilateral.\n");
        break;
    case ISOSCELES:
        printf("The triangle is isosceles.\n");
        break;
    case SCALENE:
        printf("The triangle is scalene.\n");
        break;
    case NOT_A_TRIANGLE:
        printf("The triangle is not a triangle.\n");
        break;
    }

    return EXIT_SUCCESS;
}