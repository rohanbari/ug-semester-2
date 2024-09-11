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
 * @file s32.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes two input, simulates them as matrices, performs a
 * matrix addition, then shows the output.
 * @version 0.1
 * @date 30-04-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>

#include "../common.h"

#define ROW 3
#define COL 3

/**
 * @brief Takes user input ROW*COL times and fills the matrix.
 * 
 * @param mat The matrix to fill
 */
void fill_matrix(int mat[ROW][COL])
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            while (scanf("%d", &mat[i][j]) != 1) {
                perror("error: Invalid input.\n");
                clear_stdin();
            }
        }
    }
}

/**
 * @brief Adds two matrices.
 *
 * @param A First matrix
 * @param B Second matrix
 * @param S The sum of both matrices
 */
void add_matrix(int A[ROW][COL], int B[ROW][COL], int S[ROW][COL])
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            S[i][j] = A[i][j] + B[i][j];
        }
    }
}

/**
 * @brief Displays the matrix.
 *
 * @param mat The matrix
 */
void show_matrix(int mat[ROW][COL])
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%4d", mat[i][j]);
        }
        putc('\n', stdout);
    }
}

int main(void)
{
    int A[ROW][COL];
    int B[ROW][COL];

    int S[ROW][COL];

    printf("Please fill the 1st matrix below:\n");
    fill_matrix(A);

    printf("Please fill the 2nd matrix below:\n");
    fill_matrix(B);

    add_matrix(A, B, S);

    printf("Summation result:\n");
    show_matrix(S);

    return EXIT_SUCCESS;
}