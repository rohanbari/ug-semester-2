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
 * @file 47_main.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This is the main program. It shows how 'extern' variables work.
 * @version 0.1
 * @date 16-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

// These variables will be defined through external sources.

extern int x;
extern int y;
extern int sum;

/**
 * @brief Gets the input variables.
 *
 */
void get_input(void);

/**
 * @brief Calculates the sum of the input variables.
 *
 */
void calculate_sum(void);

/**
 * @brief Displays the sum of the input variables.
 *
 */
void display(void);

int main(void)
{
    get_input();
    calculate_sum();
    display();

    return 0;
}