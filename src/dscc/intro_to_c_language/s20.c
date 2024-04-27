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
 * @file s20.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes two input: length, breadth, from the user. Based on
 * these values, it calculates the area and perimeter of the shape, and also
 * determines whether it is a rectangle or a square, then displays everything.
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
    double length = 0.0;
    double breadth = 0.0;

    printf("Input the length and the breadth (sep. by space): ");

    while (scanf("%lf %lf", &length, &breadth) != 2) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    double perimeter = 2 * (length + breadth);
    double area = length * breadth;

    printf("The perimeter is %.2lf and the area is %.2lf.\n", perimeter, area);
    printf("The shape is %s.\n", (length == breadth) ? "square" : "rectangle");

    return EXIT_SUCCESS;
}