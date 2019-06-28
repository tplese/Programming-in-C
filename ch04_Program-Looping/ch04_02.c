#include <stdio.h>

int main (void)
{
    printf ("  n\t n^2\n-----------------\n");
    
    int n, n_sqr;
    
    for (n = 1; n <= 10; ++n)
    {
        n_sqr = n * n;
        printf ("%3i\t%3i\n", n, n_sqr);
    };
    
    return 0;
}