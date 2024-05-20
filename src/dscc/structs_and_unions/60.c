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
 * @file 60.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program shows how a structure works for an a set of collection
 * of data types containing the data.
 * @version 0.1
 * @date 19-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common.h"

#define BUFSIZE 512

struct student {
    char name[BUFSIZE];
    int marks;
};

int main(void)
{
    int quantity = 0;

    printf("How many students? ");

    while (scanf("%d", &quantity) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    struct student* std = malloc(sizeof(struct student) * quantity);

    if (std == NULL) {
        perror("error: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the name of the student, marks to be followed by newline.\n");

    for (int i = 0; i < quantity; i++) {
        printf("Data for Student %d:\n", i + 1);

        clear_stdin();

        while (fgets(std[i].name, sizeof std[i].name, stdin) == NULL) {
            perror("error: Invalid input.\n");
            clear_stdin();
        }

        // Omitting the newline character
        std[i].name[strcspn(std[i].name, "\n")] = 0;

        while (scanf("%d", &std[i].marks) != 1) {
            perror("error: Invalid input.\n");
            clear_stdin();
        }
    }

    printf("\n===== Displaying the results =====\n");

    double sum = 0.0;

    for (int i = 0; i < quantity; i++) {
        printf("Name: %s\n", std[i].name);
        printf("Marks: %d\n\n", std[i].marks);

        sum += std[i].marks;
    }

    printf("Total average is %.2lf marks.\n", sum / quantity);

    free(std);

    return 0;
}