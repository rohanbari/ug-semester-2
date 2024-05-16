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
 * @file 49.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program shows how static variables work.
 * @version 0.1
 * @date 16-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

/**
 * @brief Number of times counter() will be called.
 *
 */
#define CALL_COUNT 25

/**
 * @brief This function adds one to the previous count when the function is
 * instigated. Unlike ordinary variables, static variables do not go out of
 * scope. Its scope is extended up to the lifetime of the program.
 *
 */
void counter(void)
{
    static int count = 0;
    count++;

    printf("Counting sequence: %d.\n", count);
    return;
}

int main(void)
{
    for (int i = 1; i <= CALL_COUNT; i++) {
        counter();
    }

    return EXIT_SUCCESS;
}