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
 * @brief This header file contains the necessary definitions which are common
 * to all the files.
 *
 * DO NOT TOUCH IT.
 *
 */

#ifndef __BOOL_H__
#define __BOOL_H__

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef enum {
    false,
    true
} boolean;

/**
 * @brief Flushes the STDIN safely.
 *
 */
void clear_stdin(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

#endif