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
 * @file 61.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes two date inputs from the user, validates them, and
 * identifies if they are different.
 * @version 0.1
 * @date 20-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

struct date {
    int day;
    int month;
    int year;
};

boolean validate_date(const struct date d)
{
    if (d.day > 31 || d.day < 1)
        return false;

    if (d.month > 12 || d.month < 1)
        return false;

    if (d.year < 0)
        return false;

    return true;
}

int main(void)
{
    struct date date1 = { 0, 0, 0 };
    struct date date2 = { 0, 0, 0 };

    printf("Input two dates in DD/MM/YYYY (sep. by newline):\n");

    while (scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year) != 3) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    while (scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year) != 3) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    if (!validate_date(date1)) {
        perror("error: The first date is erroneous.\n");
        return EXIT_FAILURE;
    }

    if (!validate_date(date2)) {
        perror("error: The second date is erroneous.\n");
        return EXIT_FAILURE;
    }

    boolean is_identical = date1.day == date2.day
        && date1.month == date2.month
        && date1.year == date2.year;

    printf("The two dates are %sidentical.\n", is_identical ? "" : "not ");

    return EXIT_SUCCESS;
}