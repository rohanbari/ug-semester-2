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
 * @file 63.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program writes a file that contains a number and their respective
 * square values. It does not take any input from the user.
 * @version 0.1
 * @date 21-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

#define FILE_NAME "squares.txt"

#define LOWER 1
#define UPPER 20

int main(void)
{
    FILE* fp = fopen(FILE_NAME, "w+");

    if (fp == NULL) {
        perror("error: Unable to read/write the file.\n");
        return EXIT_FAILURE;
    }

    for (int i = LOWER; i <= UPPER; i++) {
        fprintf(fp, "%d\t%d\n", i, i * i);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}