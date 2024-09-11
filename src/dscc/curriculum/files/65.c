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
 * @file 65.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief
 * @version 0.1
 * @date 22-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

#define FILE_NAME "result.dat"

#define ODD_FILE "odd.dat"
#define EVEN_FILE "even.dat"

#define LOWER 1
#define UPPER 50

int main(void)
{
    FILE* fp = fopen(FILE_NAME, "a+");

    if (fp == NULL) {
        perror("error: Unable to read/write the file.\n");
        return EXIT_FAILURE;
    }

    for (int i = LOWER; i <= UPPER; i++) {
        fprintf(fp, "%d\n", i);
    }

    fclose(fp);
    fp = fopen(FILE_NAME, "r");

    FILE* fp2 = fopen(ODD_FILE, "a+");
    FILE* fp3 = fopen(EVEN_FILE, "a+");

    int c = 0;
    while (fscanf(fp, "%d", &c) == 1) {
        if (c % 2 == 1) {
            fprintf(fp2, "%d\n", c);
        } else {
            fprintf(fp3, "%d\n", c);
        }
    }

    fclose(fp);
    fclose(fp2);
    fclose(fp3);

    return EXIT_SUCCESS;
}