#include <stdio.h>

/*
 * This is a simple C program that demonstrates
 * the basic structure of a C program
 */

int main() {
    // Print a message to the console
    printf("Hello, World!\n");
    
    // Declare and initialize variables
    int number = 10;
    float decimal = 3.14;
    char letter = 'A';
    
    // Display the variables
    printf("Integer: %d\n", number);
    printf("Float: %.2f\n", decimal);
    printf("Character: %c\n", letter);
    
    // Simple calculation
    int sum = number + 5;
    printf("Sum of %d + 5 = %d\n", number, sum);
    
    // Return 0 indicates successful execution
    return 0;
} 