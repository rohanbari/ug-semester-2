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
 * @file 45.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes an input from the user, then generates the possible
 * combinations with each digit present in the number, and displays on the
 * screen.
 * @version 0.1
 * @date 14-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <string.h>

#include "../common.h"

/**
 * @brief Swaps two characters.
 *
 * @param x First char
 * @param y Second char
 */
void swap(char* x, char* y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void generate(char* num, int l, int r)
{
    if (l == r) {
        printf("%s\n", num);
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&num[l], &num[i]);
        generate(num, l + 1, r);

        // Backtrack
        swap(&num[l], &num[i]);
    }
}

int main(void)
{
    char num[] = "1234";
    int n = strlen(num);

    generate(num, 0, n - 1);

    return EXIT_SUCCESS;
}