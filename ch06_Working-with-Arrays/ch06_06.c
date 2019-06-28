// Program to generate the first 15 Fibonacci numbers

#include <stdio.h>

int main (void) 
{ 
    int fibonacci_current, i;
    int fibonacci_minus2 = 0;
    int fibonacci_minus1 = 1;
    
    printf ("%i  %i  ", fibonacci_minus2, fibonacci_minus1);
    
    for (i = 0; i < 13; ++i)
    {
        fibonacci_current = fibonacci_minus2 + fibonacci_minus1;
        fibonacci_minus2 = fibonacci_minus1;
        fibonacci_minus1 = fibonacci_current;
        printf ("%i  ", fibonacci_current);
    };
    
    printf ("\n");
    
    return 0; 
    
}