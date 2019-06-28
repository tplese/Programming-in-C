#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    float token_array [10];
    float array_sum = 0;
    int i;
    int array_size = 10;
    
    printf ("Random numbers: ");
    
    for (i = 0; i < array_size; ++i)
    {
        token_array[i] = (float) rand() / (float) RAND_MAX;
        printf ("[%i] %g, ", i, token_array[i]);
        array_sum += token_array[i];
    };
    
    printf ("\n");
    
    printf ("Average of the array is: %g\n", array_sum / (float) array_size);
}