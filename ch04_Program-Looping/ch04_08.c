#include <stdio.h>

int main (void) 
{ 
    int n, number, triangularNumber, counter, repeat_num; 
    
    printf ("How many repeats do you want to do?  ");
    do
    {
        scanf ("%i", &repeat_num);
    }
    while (repeat_num < 1);
    
    for ( counter = 1; counter <= repeat_num; ++counter ) 
    { 
        printf ("What triangular number do you want? "); 
        scanf ("%i", &number); triangularNumber = 0; 
        
        for ( n = 1; n <= number; ++n ) 
            triangularNumber += n; 
            
        printf ("Triangular number %i is %i\n\n", number, triangularNumber); 
    } 
    
    return 0; 
}