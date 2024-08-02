#include <stdio.h>
#include <string.h> // To use string manipulation methods...

// Function to convert an integer to a Roman numeral
void intToRoman(int num, char *roman) {
    // Arrays for Roman numerals and their corresponding values
    char *romanNumerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    // Index for Roman numeral array
    int i = 0;
    
    // Convert integer to Roman numeral
    while (num > 0) {
        // Check if the value can be subtracted from the number
        while (num >= values[i]) {
            // Append the Roman numeral to the result
            strcat(roman, romanNumerals[i]);
            // Subtract the value from the number
            num -= values[i];
        }
        // Move to the next value
        i++;
    }
}

int main(void) {
    int num;
    char roman[20] = ""; // String to store the Roman numeral

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Convert the integer to Roman numeral
    intToRoman(num, roman);

    // Display the Roman numeral
    printf("Roman numeral: %s\n", roman);

    return 0;
}