/** Write a function called arraySum() that takes two arguments: an integer array and the number of elements in the array.
 * Have the function return as its result the sum of the elements in the array.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void)
{
    int askArraySize ();
    void populateArray (int x, int array []);
    long int arraySum (int x, int array []);

    int arraySize = askArraySize ();
    int theArray [arraySize];
    printf ("theArraySize = %i\n", arraySize);

    populateArray (arraySize, theArray);

    printf ("The sum of all array elements is: %li\n", arraySum (arraySize, theArray));


    return 0;
}


int askArraySize ()
{
    int userNumber = -1;

    do
    {
        printf ("How many elements for array? (1 - 32767)  ");
        scanf ("%i", &userNumber);
        while (getchar() != '\n');
    }
    while (userNumber <= 0 || userNumber > 32767);

    return userNumber - 1;
}



void populateArray (int x, int array [])
{
    srand(time(NULL));

    for (int i = 0; i <= x; i++)
    {
        array [i] = rand() % (32767 + 1 - 0) + 0;
        printf ("array [%i] = %i\n", i, array [i]);
    };
}


long int arraySum (int x, int array [])
{
    long int sumOfElements = 0;

    for (int i = 0; i <= x; i++)
    {
        sumOfElements += array [i];
    };

    return sumOfElements;
}