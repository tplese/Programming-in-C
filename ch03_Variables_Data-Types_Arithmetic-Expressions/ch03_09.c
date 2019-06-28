#include <stdio.h>

int main (void)
{
    int i, j;
    
    // 365 and 7
    i = 365, j = 7;
    printf ("Next largest multiple of %i and %i is equal to: %i\n", i, j, (i + j - i % j));

        // 12258 and 23
    i = 12258, j = 23;
    printf ("Next largest multiple of %i and %i is equal to: %i\n", i, j, (i + j - i % j));

    // 996 and 4
    i = 996, j = 4;
    printf ("Next largest multiple of %i and %i is equal to: %i\n", i, j, (i + j - i % j));

}