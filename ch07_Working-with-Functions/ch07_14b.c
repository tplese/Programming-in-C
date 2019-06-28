/** Rewrite the functions developed in the last four exercises to use global variables instead of arguments.
 * For example, the preceding exercise should now sort a globally defined array.
 *
 * b. REWRITE OF ch07_11.c
 */

/** Write a function called arraySum() that takes two arguments: an integer array and the number of elements in the array.
 * Have the function return as its result the sum of the elements in the array.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arraySize;

int theArray [32767];

int main (void)
{
    int askArraySize (void);
    void populateArray (void);
    long int arraySum (void);

    arraySize = askArraySize () - 1;
    //printf ("theArraySize = %i\n", arraySize);

    populateArray ();

    printf ("The sum of all array elements is: %li\n", arraySum ());


    return 0;
}


// Get from user the number of elements the array will have
int askArraySize (void)
{
    arraySize = -1;

    do
    {
        printf ("How many elements for array? (1 - 32767)  ");
        scanf ("%i", &arraySize);
        while (getchar() != '\n');
    }
    while (arraySize <= 0 || arraySize > 32767);

    return arraySize;
}



// Populate the array with random numbers - up to size user specified
void populateArray (void)
{
    srand(time(NULL));

    for (int i = 0; i <= arraySize; i++)
    {
        theArray [i] = rand() % (32767 + 1 - 0) + 0;
        printf ("array [%i] = %i\n", i, theArray [i]);
    };
}


// Add all the numbers in the array
long int arraySum (void)
{
    long int sumOfElements = 0;

    for (int i = 0; i <= arraySize; i++)
    {
        sumOfElements += theArray [i];
    };

    return sumOfElements;
}