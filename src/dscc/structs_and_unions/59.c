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
 * @file 59.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program shows how a structure works for an individual collection
 * of data types containing the data.
 * @version 0.1
 * @date 19-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <string.h>

#include "../common.h"

#define BUFSIZE 512

struct student {
    char name[BUFSIZE];
    int marks;
};

int main(void)
{
    struct student std = { "", 0 };

    printf("Enter the name of the student, marks to be followed by newline.\n");

    if (fgets(std.name, sizeof std.name, stdin) == NULL) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (scanf("%d", &std.marks) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    std.name[strcspn(std.name, "\n")] = 0;

    printf("Name: %s\n", std.name);
    printf("Marks: %d\n", std.marks);

    return 0;
}