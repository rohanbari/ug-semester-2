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
 * @file s33.c
 * @author rohanbari <rohanbari@outlook.com>
 * @brief This program takes two matrices as input, determines if they are
 * multiplicable. If so, then multiplies and displays the product.
 * @version 0.1
 * @date 04-05-2024
 *
 * Copyright (c) 2024 Rohan Bari
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../common.h"

/**
 * @brief Data structure of a 2-D matrix.
 *
 */
typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

/**
 * @brief Validates whether the matrix has been allocated properly or not.
 *
 * @param m The matrix
 */
void validate_ptr(void* m)
{
    if (m == NULL) {
        perror("error: malloc() failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Initializes the passed matrix.
 *
 * @param m The matrix
 */
Matrix init_matrix(void)
{
    Matrix m = { 0, 0, NULL };

    printf("Enter the (rows cols) ");

    while (scanf("%d %d", &m.rows, &m.cols) != 2) {
        perror("error: Invalid input.\n");
        clear_stdin();
    }

    // The rows and columns must not be negative.
    if (m.rows <= 0 || m.cols <= 0) {
        perror("error: Rows/columns should be a +ve non-zero number.\n");
        exit(EXIT_FAILURE);
    }

    // Initializing the matrix.
    m.data = (int**)malloc(sizeof(int*) * m.rows);
    validate_ptr(m.data);

    for (int i = 0; i < m.rows; i++) {
        m.data[i] = (int*)malloc(sizeof(int) * m.cols);
        validate_ptr(m.data[i]);
    }

    printf("Input the data in %dx%d order:\n", m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            while (scanf("%d", &m.data[i][j]) != 1) {
                perror("error: Invalid input.\n");
                clear_stdin();
            }
        }
    }

    return m;
}

/**
 * @brief Validates whether two matrices are multiplicable or not.
 *
 * @param m1 1st matrix
 * @param m2 2nd matrix
 */
boolean is_multiplicable(Matrix m1, Matrix m2)
{
    return (m1.cols == m2.rows);
}

/**
 * @brief Multiplies two multiplicable matrices.
 *
 * @param m1 The first matrix
 * @param m2 The second matrix
 * @return Product of two matrices
 */
Matrix multiply(Matrix m1, Matrix m2)
{
    Matrix C;

    C.rows = m1.rows;
    C.cols = m2.cols;

    C.data = (int**)malloc(sizeof(int*) * C.rows);
    validate_ptr(C.data);

    for (int i = 0; i < C.rows; i++) {
        C.data[i] = (int*)malloc(sizeof(int) * C.cols);
        validate_ptr(C.data[i]);
    }

    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            C.data[i][j] = 0;
            for (int k = 0; k < m1.cols; k++) {
                C.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }

    return C;
}

/**
 * @brief Displays the matrix on the screen.
 *
 * @param m The matrix
 */
void display_matrix(const Matrix m)
{
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%-4d", m.data[i][j]);
        }
        putc('\n', stdout);
    }
}

int main(void)
{
    Matrix A = init_matrix();
    Matrix B = init_matrix();

    if (!is_multiplicable(A, B)) {
        perror("error: The matrices are not multiplicable.\n");
        return EXIT_SUCCESS;
    }

    Matrix C = multiply(A, B);
    display_matrix(C);

    free(A.data);
    free(B.data);
    free(C.data);

    return EXIT_SUCCESS;
}