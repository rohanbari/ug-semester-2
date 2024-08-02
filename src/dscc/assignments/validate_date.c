#include <stdio.h>

#define MIN_YEAR 1583
#define MAX_YEAR 9999

int main(void)
{
    int year = 0;
    int month = 0;
    int day = 0;

    printf("Input a date in DD/MM/YYYY format: ");

    // Check if the input date is valid
    if (scanf("%d/%d/%d", &day, &month, &year) != 3) {
        perror("error: Invalid input.\n");
        return 1;
    }

    // Check if the year is within the valid range
    if (year < MIN_YEAR || year > MAX_YEAR) {
        printf("error: Year must be between %d and %d.\n", MIN_YEAR, MAX_YEAR);
        return 1;
    }

    // Check if the month is valid
    if (month < 1 || month > 12) {
        printf("error: Month must be between 1 and 12.\n");
        return 1;
    }

    // Exceptional case: leap year
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
        daysInMonth[month - 1] = 29;

    // Check if the day is within the valid range for the given month and year
    if (day < 1 || day > daysInMonth[month - 1]) {
        printf("error: Invalid day for the given month and year.\n");
        return 1;
    }

    // If all the tests pass, then it is a valid date
    printf("The date is a valid date.\n");

    return 0;
}