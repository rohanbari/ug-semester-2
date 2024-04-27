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
 * @file s23.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes two input: A, B, from the user. Then it performs
 * division or multiplication along with explaining the process.
 * @version 0.1
 * @date 27-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

typedef enum {
    QUIT,
    DIVISION,
    MULTIPLICATION,
} choice;

void division(int a, int b)
{
    int quotient = 0;
    int rem = 0;

    while (true) {
        if (a >= b) {
            printf("Performing %d - %d, quotient in hand: %d.\n",
                a, b, quotient);
            quotient++;
            a -= b;
        } else {
            break;
        }
    }

    rem = a;
    printf("The division results: quotient %d, remainder %d.\n", quotient, rem);
}

/**
 * @brief The multiplication process with explaining behavior.
 *
 * @param a The first value
 * @param b The second value
 */
void multiplication(int a, int b)
{
    int sum = 0;

    while (b >= 1) {
        printf("Performing %d + %d = ", sum, a);
        sum += a;
        printf("%d.\n", sum);

        b--;
    }
}

int main(void)
{
    int input = 0;

    while (true) {
        printf("[0] QUIT\n[1] Division\n[2] Multiplication\n\t==> ");

        while (scanf("%d", &input) != 1) {
            perror("error: Input invalid.\n");
            clear_stdin();
        }

        if (input < 0 || input > 2) {
            perror("error: Input out of range.\n");
            return EXIT_FAILURE;
        }

        if (input == QUIT) {
            break;
        }

        int a = 0;
        int b = 0;

        printf("Input two values (sep. by space): ");

        while (scanf("%d %d", &a, &b) != 2) {
            perror("error: Invalid input.\n");
            clear_stdin();
        }

        switch ((choice)input) {
        case DIVISION:
            if (a < 0 || b <= 0) {
                perror("error: Please provide a >= 0, b > 0.\n\n");
                continue;
            }
            division(a, b);
            break;

        case MULTIPLICATION:
            multiplication(a, b);
            break;

        default:
            perror("error: Invalid choice.\n");
            break;
        }

        putc('\n', stdout);
    }

    return EXIT_SUCCESS;
}