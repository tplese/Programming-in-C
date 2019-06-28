#include <stdio.h>

int main (void)
{
    int P[151] = {0};
    int i, j;
    int n = 150;

    for (i = 2; i <= n; ++i)
    {
        for (j = 2; i * j <= n; ++j)
        {
            P[i * j] = 1;
        };
        
        if (P[i] == 0)
        {
            printf ("%i  ", i);
        };
    };
    
    printf ("\n");
    
    return 0;
}