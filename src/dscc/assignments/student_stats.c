#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256
#define MAX_STUDENTS 1000

typedef struct {
    int roll;

    double m1;
    double m2;

    char name[128];
} student;

void validate_ptr(void* ptr)
{
    if (ptr == NULL) {
        fprintf(stderr, "error: malloc() failed.\n");
        exit(1);
    }
}

int main(void)
{
    int rolls = 0;
    student* students = NULL;

    printf("\n===== TOTAL STUDENTS =====\n\n");

    printf("How many students to enroll? => ");
    if (scanf("%d", &rolls) != 1) {
        fprintf(stderr, "error: Failed to read the number of students.\n");
        return 1;
    }

    // Validate the number of students
    if (rolls <= 0 || rolls > MAX_STUDENTS) {
        fprintf(stderr, "error: Invalid count. Number of students must be between 1 and %d.\n", MAX_STUDENTS);
        return 1;
    }

    students = malloc(sizeof(student) * rolls);
    validate_ptr(students);

    // Clear input buffer after scanf
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    printf("\n===== INPUT SECTION =====\n\n");

    for (int i = 0; i < rolls; i++) {
        printf("Input the <roll> <name_with_underscore> <mark_1> <mark_2>:\n");
        if (scanf("%d %127s %lf %lf", &students[i].roll, students[i].name,
                &students[i].m1, &students[i].m2)
            != 4) {
            fprintf(stderr, "error: Invalid input(s)!\n");
            free(students);
            return 1;
        }
    }

    // Clear input buffer after last scanf
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    int option = 0;

    printf("\n===== OPERATION(S) SECTION =====\n\n");

    do {
        printf("You can perform the following operations:\n");
        printf("[1] Find details about a particular student\n");
        printf("[2] Find average marks in each subject\n");
        printf("[3] Find details of the student who topped in each subject\n");
        printf("[0] Quit program\n\n");

        printf("[ ] Input => ");
        if (scanf("%d", &option) != 1) {
            fprintf(stderr, "error: Failed to read the option.\n");
            free(students);
            return 1;
        }

        // Clear input buffer after scanf
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        printf("\n");

        switch (option) {
        case 0:
            goto flag;
            break;
        case 1: {
            int specific_roll = 0;
            printf("Input the roll no.: ");
            if (scanf("%d", &specific_roll) != 1) {
                fprintf(stderr, "error: Failed to read the roll number.\n");
                free(students);
                return 1;
            }

            // Clear input buffer after scanf
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;

            // Validate specific_roll
            if (specific_roll <= 0 || specific_roll > rolls) {
                fprintf(stderr, "error: Roll number is out of range.\n");
                free(students);
                return 1;
            }

            // Assuming roll numbers are from 1 to 'rolls' and correspond to array indices
            // Alternatively, search for the student with the given roll number
            int found = 0;
            for (int i = 0; i < rolls; i++) {
                if (students[i].roll == specific_roll) {
                    printf("Student name: %s\nStudent marks: %.2lf %.2lf\n",
                        students[i].name, students[i].m1, students[i].m2);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                fprintf(stderr, "error: No student found with roll number %d.\n", specific_roll);
            }
            break;
        }
        case 2: {
            if (rolls == 0) {
                printf("No students to calculate averages.\n");
                break;
            }

            double avg1 = 0.0;
            double avg2 = 0.0;

            for (int i = 0; i < rolls; i++) {
                avg1 += students[i].m1;
                avg2 += students[i].m2;
            }

            avg1 /= rolls;
            avg2 /= rolls;

            printf("Average marks in m1 and m2 subjects: %.2lf, %.2lf\n", avg1, avg2);
            break;
        }
        case 3: {
            if (rolls == 0) {
                printf("No students to determine toppers.\n");
                break;
            }

            double max1 = -DBL_MAX;
            double max2 = -DBL_MAX;
            int index_max1 = -1;
            int index_max2 = -1;

            for (int i = 0; i < rolls; i++) {
                if (max1 < students[i].m1) {
                    max1 = students[i].m1;
                    index_max1 = i;
                }

                if (max2 < students[i].m2) {
                    max2 = students[i].m2;
                    index_max2 = i;
                }
            }

            if (index_max1 != -1) {
                printf("Highest marks %.2lf in m1 is achieved by %s (roll: %d)\n",
                    max1, students[index_max1].name, students[index_max1].roll);
            }

            if (index_max2 != -1) {
                printf("Highest marks %.2lf in m2 is achieved by %s (roll: %d)\n",
                    max2, students[index_max2].name, students[index_max2].roll);
            }

            break;
        }
        default:
            fprintf(stderr, "error: Invalid option.\n");
            break;
        }

        printf("\n==============================\n");
    } while (option != 0);

flag:
    printf("\n\t=== Thank you for using this program ===\n\n");
    free(students);
    return 0;
}
