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
 * @file 54.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program will teach the reader the differences in pass-by-value
 * and pass-by-reference parameters.
 *
 * Please note that pass-by-reference (symbol &) is a feature of C++. In C, we
 * use pointers to fetch the original data of a variable to alter it.
 *
 * @version 0.1
 * @date 17-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

/**
 * @brief It alters the variable locally.
 *
 * @param x The variable
 */
void pass_by_value(int x)
{
    x = 10;
}

/**
 * @brief It alters data at the original variable's memory.
 *
 * @param x The variable
 */
void pass_by_reference(int* x)
{
    *x = 10;
}

int main(void)
{
    int x = 5;

    pass_by_value(x);
    printf("After pass_by_value():     %d\n", x);

    pass_by_reference(&x);
    printf("After pass_by_reference(): %d\n", x);

    return EXIT_SUCCESS;
}