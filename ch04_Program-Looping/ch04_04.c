#include <stdio.h>

int main (void)
{
    printf ("   n\tfactorial\n-------------------\n");
    
    int factorial;
    
    for (int n = 1; n <= 10; ++n)
    {
        factorial = 1;
        
        for (int i = n; i > 0; --i)
        {
            factorial *= i;
        };
        
        printf ("  %2i\t%6i\n", n, factorial);
    };
}