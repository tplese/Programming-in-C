#include <stdio.h>

int main (void)
{
    int num1 = 0;
    int num2 = 0;
    
    do
    {
        printf ("Please give me 2 integers.\n");
        scanf ("%i %i", &num1, &num2);
    }
    while (num1 <= 0 || num2 <= 0);
    
    if (num1 % num2 == 0)
    {
        printf ("Number %i is evenly divisible by %i.\n", num1, num2);
    }
    else
    {
        printf ("Number %i is NOT evenly divisible by %i.\n", num1, num2);
    };
}