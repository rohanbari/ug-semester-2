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
 * @file 43.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program does NOT take any input from the user. It calculates the
 * cubes of numbers ranging [10, 20].
 * @version 0.1
 * @date 11-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

#define LOWER 10
#define UPPER 20

void cube(const int p)
{
    if (p > UPPER) {
        return;
    }

    int res = p * p * p;
    printf("%d ", res);

    cube(p + 1);
}

int main(void)
{
    cube(LOWER);
    fputc('\n', stdout);

    return EXIT_SUCCESS;
}