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
 * @file 62.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief The question is asked about writing a program in C to accept students’
 * data from the user. Check if the student stream is science, commerce or arts.
 * If the stream is arts, then print the class of students. If the stream is
 * science, then print the grade and if the stream is commerce, then print the
 * percentage.
 * @version 0.1
 * @date 20-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common.h"

struct student {
    char name[1024];
    char stream[16];

    int class;
    char grade;
    double percentage;
};

int main(void)
{
    int no_of_stds = 0;

    printf("How many students? ");

    while (scanf("%d", &no_of_stds) != 1) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (no_of_stds <= 0) {
        perror("error: The input should be non-negative.\n");
        return EXIT_FAILURE;
    }

    struct student* students = malloc(no_of_stds * sizeof(struct student));

    if (students == NULL) {
        perror("error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    printf("Input format: <Name_Unspaced> <Stream> <Class> <Grade> <%%age>:\n");
    for (int i = 0; i < no_of_stds; i++) {
        printf("\nData for student %d ---\n", i + 1);

        while (scanf("%1023s %15s %d %c %lf",
                   students[i].name, students[i].stream,
                   &students[i].class, &students[i].grade,
                   &students[i].percentage)
            != 5) {
            perror("error: Invalid input.\n");
            clear_stdin();
        }

        clear_stdin();
    }

    printf("\n===== Displaying the necessary data =====\n");
    for (int i = 0; i < no_of_stds; i++) {
        printf("Student %d === ", i + 1);

        if (strcmp(students[i].stream, "Science") == 0) {
            printf("Grade: %c\n", students[i].grade);
        } else if (strcmp(students[i].stream, "Arts") == 0) {
            printf("Class: %d\n", students[i].class);
        } else if (strcmp(students[i].stream, "Commerce") == 0) {
            printf("Percentage: %.2lf\n", students[i].percentage);
        } else {
            perror("error: The stream is unrecognized.\n");
            return EXIT_FAILURE;
        }
    }

    free(students);

    return EXIT_SUCCESS;
}