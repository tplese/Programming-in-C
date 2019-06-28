// Calculates triangular numbers up to 200th

#include <stdio.h>

int main (void)
{
    int n, triangularNumber;
    triangularNumber = 0;
    
    for ( n = 1; n <= 200; n = n + 1 )
    {
        triangularNumber += n;
        
        printf ("%-2i     %i\n", n, triangularNumber);
    };
    
    printf ("\nThe 200th triangular number is %i\n", triangularNumber); 
    
    return 0;
}