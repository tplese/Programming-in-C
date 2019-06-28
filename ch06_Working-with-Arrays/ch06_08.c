#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int array_size;
    
    printf ("How big do you want the arry to be?\n");
    do
    {
        scanf ("%i", &array_size);
    }
    while (array_size <= 0);
    
    int variable_size[array_size];
    
    for (int i = 0; i < array_size; ++i)
    {
        variable_size[i] = rand() % 50;
        printf ("[%.2i]= %.3i \t", i, variable_size[i]);
    };
    
    printf ("\n");
    
}