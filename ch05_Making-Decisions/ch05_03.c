#include <stdio.h>

int main (void)
{
    int num1 = 0;
    int num2 = 0;
    
    do
    {
        printf ("Please provide 2 integers.\n");
        scanf ("%i %i", &num1, &num2);
        if (num2 == 0)
        {
            printf ("Second integer can't be zero.\n");
        }
    }
    while (num2 == 0);
    
    printf ("%i devided by %i equals %.3f.\n", num1, num2, ((float)num1 / num2));
}