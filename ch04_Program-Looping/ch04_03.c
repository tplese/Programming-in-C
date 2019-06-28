#include <stdio.h>

int main (void)
{
    printf ("   n\ttrinag\n----------------------\n");
    
    int n, triang_num;
    for (n = 5; n <= 50; n += 5)
    {
        triang_num = n * (n + 1) / 2;
        printf ("  %3i\t %4i\n", n, triang_num);
    };

    return 0;
}