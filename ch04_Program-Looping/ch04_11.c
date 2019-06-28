#include <stdio.h>

int main (void)
{
    int number;
    
    printf ("Please provide a positive integer.\n");
    scanf ("%i", &number);
    
    int last_digit;
    int sum = 0;
    
    while (number != 0)
    {
        last_digit = number % 10;
        // printf ("last_digit: %i\n", last_digit);
        sum += last_digit;
        number /= 10;
    };
    
    printf ("Sum of your number's digits is: %i\n", sum);
}