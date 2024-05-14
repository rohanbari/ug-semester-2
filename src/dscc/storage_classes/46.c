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
 * @file 46.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program accepts a number from the user, then displays its
 * factorial on the screen. The only difference is that the variables use the
 * 'auto' keyword, which is redundant. However, it is asked to do.
 * @version 0.1
 * @date 14-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

int main(void)
{
    int number = 0;

    printf("Input a number: ");

    while (scanf("%d", &number) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    auto long fact = 1L;
    for (int i = 1; i <= number; i++) {
        fact *= i;
    }

    printf("The factorial of %d is %ld.\n", number, fact);

    return EXIT_SUCCESS;
}