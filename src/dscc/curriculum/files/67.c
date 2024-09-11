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
 * @file 67.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program demonstrates the usage of I/O of files.
 * @version 0.1
 * @date 23-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

#define DB_FILE "database.txt"

struct student {
    char name[256];

    int class;
    int roll;

    double marks;
};

int main(void)
{
    int total = 0;

    printf("How many students? ");

    while (scanf("%d", &total) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (total <= 0) {
        perror("error: The input must be a +ve integer.\n");
        return EXIT_FAILURE;
    }

    FILE* fp = fopen(DB_FILE, "a+");

    if (!fp) {
        perror("error: File cannot be opened.\n");
        return EXIT_FAILURE;
    }

    printf("Data entry section\n");
    printf("==================\n");
    printf("Input format: <Student_Name> <Class> <Roll> <Aggregate>\n");

    struct student std = { "", 0, 0, 0.0 };

    for (int i = 0; i < total; i++) {

        printf("\nStudent %d:\n", i + 1);
        printf("------------------\n");

        while (scanf("%255s %d %d %lf", std.name, &std.class,
                   &std.roll, &std.marks)
            != 4) {
            perror("error: Invalid input.\n");
            clear_stdin();
        }

        fprintf(fp, "%s %d %d %.2lf\n", std.name, std.class, std.roll, std.marks);
    }

    rewind(fp);

    printf("\n===== Retrieving Information =====\n\n");
    while (fscanf(fp, "%s %d %d %lf", std.name, &std.class, &std.roll, &std.marks) == 4) {
        printf("Name: %s\n", std.name);
        printf("Class: %d\n", std.class);
        printf("Roll: %d\n", std.roll);
        printf("Aggregate: %.2lf\n\n", std.marks);

        if (feof(fp)) {
            printf("info: END OF FILE REACHED.\n");
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}