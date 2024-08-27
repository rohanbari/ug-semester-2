#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256
#define MAX_STUDENTS 1024

int compare_names(const void* a, const void* b)
{
    // Cast the void pointers to char** (pointer to string)
    const char* name1 = *(const char**)a;
    const char* name2 = *(const char**)b;

    // Compare the two strings and return the result
    return strcmp(name1, name2);
}

int main(void)
{
    int total_students = 0;

    printf("Input the number of students: ");
    scanf("%d", &total_students);

    // Size validation
    if (total_students < 0 || total_students > MAX_STUDENTS) {
        fprintf(stderr, "error: Invalid range.\n");
        return EXIT_FAILURE;
    }

    char** names = (void*)malloc(total_students);
    for (int i = 0; i < total_students; i++)
        names[i] = (void*)malloc(sizeof(char) * BUFSIZE);

    for (int i = 0; i < total_students; i++) {
        printf("Input the name of %dth student (underscored): ", i + 1);
        scanf("%255s", names[i]);
    }

    qsort(names, total_students, sizeof(char*), compare_names);
    for (int i = 0; i < total_students; i++)
        printf("%s\n", names[i]);

    // It's our responsibility to clean-up the shit in C
    for (int i = 0; i < total_students; i++)
        free(names[i]);

    free(names);

    return EXIT_SUCCESS;
}