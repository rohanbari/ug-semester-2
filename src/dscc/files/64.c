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
 * @file 64.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program writes some text into a file, reopens it into read mode,
 * and displays the text containing in the file on the screen using fputc().
 * @version 0.1
 * @date 22-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

#define FILE_NAME "output.dat"

int main(void)
{
    FILE* fp = fopen(FILE_NAME, "w+");

    if (!fp) {
        perror("error: File could not be accessed.\n");
        return EXIT_FAILURE;
    }

    fprintf(fp, "Hello, world! What's up?\n");

    fclose(fp);
    fp = fopen(FILE_NAME, "r");

    int c = 0;
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, stdout);
    }

    return EXIT_SUCCESS;
}